/* ----------------------------------------------------------------------------
 |
 |	Nom :			rgbmap.c
 |
 |	Type :			DEPENDANCE
 |	Sujet :			rgbsys - gestion de la palette de couleurs RGB
 |
 |	Version :		2.1
 |	Création :		2001
 |	Mise à jour :	03/10/2014
 + ----------------------------------------------------------------------------
 |  Copyright 2001-2014 A. Menu   <alain.menu@ac-creteil.fr>
 | 
 |  This file is part of "rgbsys project"
 | 
 |  This program is free software ;  you can  redistribute it and/or  modify it
 |  under the terms of the  GNU General Public License as published by the Free
 |  Software Foundation ; either version 2 of the License, or  (at your option)
 |  any later version.
 |
 |  This program is distributed in the hope that it will be useful, but WITHOUT
 |  ANY WARRANTY ; without even the  implied  warranty  of  MERCHANTABILITY  or
 |  FITNESS FOR  A PARTICULAR PURPOSE. See the  GNU General Public License  for
 |  more details < http://www.gnu.org/licenses/gpl.txt >.
 + ------------------------------------------------------------------------- */

#include <rgbmap.h>

/*!
 *	\private
 */
 
typedef struct {
	byte	rgb[3] ;
	lword	mask[3] ;
	char	name[80] ;
	lword 	value ;
} Rgb ;

Rgb*		rgbMap[ MAXNUMOFRGB ] ;
static int 	rgbNum = 0 ;

/*!
 *	\fn		lword calcPixel(byte* rgb, lword* mask )
 *	\private
 *	\brief	calcule la valeur sur 32 bits d'un pixel de proportions \a rgb
 *			et de masques \a mask.
 *			8 plans : 3+3+2 bits, 16 plans : 5+6+5 bits, 24 plans : 8+8+8 bits
 *	\param	rgb	tableau des 3 proportions couleurs primaires
 *	\param	mask	tableau des 3 masques associés
 *	\return	valeur 32 bits du pixel
 */
 
lword calcPixel(byte* rgb, lword* mask )
{
	lword res = 0 ;
	lword bits, shift ;
	lword ma[3] = { mask[Red], mask[Green], mask[Blue] } ;
	int i ;

	for ( i = 0 ; i < 3 ; i++ ) {
		bits = shift = 0 ;
		while ( !( ma[i] & 1 ) ) 	{ ma[i] >>= 1 ; shift++ ; }
		while ( ma[i] & 1 )			{ ma[i] >>= 1 ; bits++ ;  }
		
		res |= ( ( rgb[i] >> ( 8 - bits ) ) << shift ) & mask[i] ;
	}
	return res ;
}

/*!
 *	\fn		int loadRgbDataFromFile(const char* path, lword* mask )
 *	\brief	charge les entrées RGB à partir d'un fichier type 'Unix rgb.txt'
 *	\details	le format des lignes du fichier doit être conforme au modèle : "rrr ggg bbb name",
 *				soit les 3 proportions RGB en décimal suivies par une chaine de caractères.
 				Les couleurs de mêmes proportions mais de noms différents sont regroupés
 				dans une seule entrée de palette.
 *	\param	path	chemin d'accès au fichier
 *	\param	mask	tableau des 3 masques associés pour le Visual courant
 *	\return	0 en cas de succès, ou une valeur négative en cas d'échec.
 */
 
int loadRgbDataFromFile(const char* path, lword* mask )
{
	FILE*	f ;
	char	buf[80] ;
	Rgb		co ;
	int 	i ;
	int 	nbl = 0 ;
	
	f = fopen(path, "r" ) ;
	if ( f == NULL ) return -1 ;

#ifdef VERBOSE
	printf("loading %s\n", path ) ;
#endif
	
	while ( fgets(buf, 80, f ) != NULL ) {
		if ( *buf == '!' )	continue ;
		nbl++ ;
		co.rgb[Red] = atoi( strtok(buf, " \t" ) ) ;
		co.rgb[Green] = atoi( strtok(NULL," \t" ) ) ;
		co.rgb[Blue] = atoi( strtok(NULL," \t" ) ) ;
		strcpy( co.name, strtok(NULL,"\t\n") ) ;

		co.mask[Red] = mask[Red] ;
		co.mask[Green] = mask[Green] ;
		co.mask[Blue] = mask[Blue] ;
		
		co.value = calcPixel(co.rgb, co.mask ) ;
		
		for ( i = 0 ; i < rgbNum ; ++i ) {
			if ( co.value == rgbMap[i]->value ) {
#ifdef VERBOSE
				printf("- merging \"%s\" with \"%s\"\n", co.name, rgbMap[i]->name ) ;
#endif
				strcat(rgbMap[i]->name, ", " ) ;
				strcat(rgbMap[i]->name, co.name ) ;
				break ;
			}
		}
		if ( i == rgbNum ) {
			rgbMap[rgbNum] = (Rgb*)malloc( sizeof(Rgb) ) ;
			memcpy(rgbMap[rgbNum], &co, sizeof(Rgb) ) ;
			if ( ++rgbNum >= MAXNUMOFRGB )	break ;
		}
	}
	fclose(f) ;
	
#ifdef VERBOSE
	printf("%d lines read\ndone.\n", nbl ) ;
#endif
	return 0 ;
}

/*!
 *	\fn		int numberOfRgb()
 *	\brief	retourne le nombre d'entrées présentes dans la palette
 *	\return	nombre d'entrées RGB
 */
 
int numberOfRgb()
{
	return rgbNum ;
}

/*!
 *	\fn		byte rgbColor(PrimaryColor pc, int id )
 *	\brief	retourne la proportion d'une des 3 couleurs primaires d'une entrée
 *	\param	pc couleur primaire souhaitée
 *	\param	id	indice de l'entrée dans la palette
 *	\return	proportion demandée
 */
 
byte rgbColor(PrimaryColor pc, int id )
{
	if ( id >= rgbNum )	return 0 ;
	return rgbMap[id]->rgb[ pc ] ;
}

/*!
 *	\fn		lword rgbMask(PrimaryColor pc, int id )
 *	\brief	retourne le masque courant d'une des 3 couleurs primaires d'une entrée
 *	\param	pc couleur primaire souhaitée
 *	\param	id	indice de l'entrée dans la palette
 *	\return	masque 32 bits demandé
 */
 
lword rgbMask(PrimaryColor pc, int id )
{
	if ( id >= rgbNum )	return 0 ;
	return rgbMap[id]->mask[ pc ] ;
}

/*!
 *	\fn		lword rgbValue(int id )
 *	\brief	retourne la couleur d'une entrée de palette, dépendante du nombre de plans
 *			du système d'affichage
 *	\param	id	indice de l'entrée dans la palette
 *	\return	couleur sous forme d'un mot long de 32 bits
 */
 
lword rgbValue(int id )
{
	if ( id >= rgbNum )	return 0 ;
	return rgbMap[id]->value ;
}

/*!
 *	\fn		const char* rgbName(int id )
 *	\brief	retourne le(s) nom(s) d'une entrée de palette
 *	\param	id	indice de l'entrée dans la palette
 *	\return	chaine de caractères avec séparateur virgule)
 */
 
const char* rgbName(int id )
{
	if ( id >= rgbNum )	return NULL ;
	return rgbMap[id]->name ;
}

/*!
 *	\fn		void freeColorMap()
 *	\brief	supprime toutes les entrées de la palette
 */
 
void freeColorMap()
{
	int i ;
	for ( i = 0 ; i < rgbNum ; ++i )	free( rgbMap[i] ) ;
}
