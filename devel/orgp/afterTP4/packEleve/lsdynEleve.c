/*  ---------------------------------------------------------------------------
 *  nom         :   lsdyn.c
 *  description :   projet 'contact2' : implémentation liste chaînée simple
 *  création    :   10/1998
 *  version/maj :   3.0  -  06/03/2007
 *  ---------------------------------------------------------------------------
 *  auteur(s)   :   Copyright 2007 A. Menu   <alain.menu@ac-creteil.fr>
 *  ---------------------------------------------------------------------------
 */

#include	"lsdyn.h"
#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>


typedef struct elem {

	TOBJ obj ; 							/* objet utile défini par le client */
	struct elem* suiv ; 				/* lien sur maillon suivant */

} ELEM ; 								/* type maillon */

ELEM* deb = NULL ; 						/* pointeur sur le début de liste */
ELEM* fin = NULL ; 						/* pointeur sur le dernier maillon */
int nbelem = 0 ; 						/* nombre courant de maillons */


void	ajouter( TOBJ* obj )
{
	ELEM*	p;
	// Allocation de l'ELEM

	// INIT de "suiv"


	// copy du TOBJ avec memcpy
	
	// placement de l'ELEM à la fin de la liste


	// incrémentation du nombre d'élément
}

int		taille( void )
{
	return nbelem ;
}

TOBJ*	maillon( int pos )
{
	ELEM*	p ;

	// parcours avec recherche du maillon
	
	
	 
}

void	detruire( void )
{
	// détruire tout
}

void	inserer(TOBJ* obj, int pos )
{
	ELEM*	p ;

	// Allocation de l'ELEM

	// INIT de "suiv"


	// copy du TOBJ avec memcpy
	
	// placement de l'ELEM au bon endroit


	// incrémentation du nombre d'élément
}

TOBJ*	extraire( int pos )
{
	// extraction de l'élément à la position pos

	// nbelem --
	
	// retour de l'élément

}
