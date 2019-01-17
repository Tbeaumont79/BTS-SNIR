/*  ---------------------------------------------------------------------------
 *  nom         :   lsdyn.h
 *  description :   projet 'contact2' : interface liste chaînée simple
 *  création    :   10/1998
 *  version/maj :   3.0  -  06/03/2007
 *  ---------------------------------------------------------------------------
 *  auteur(s)   :   Copyright 2007 A. Menu   <alain.menu@ac-creteil.fr>
 *  ---------------------------------------------------------------------------
 */

#ifndef	LSDYN_H
#define	LSDYN_H

#include 	"indiv.h"

void	ajouter( TOBJ* obj ) ; 	/* ajout d'un maillon en fin de liste */
int		taille( void ) ; 		/* retourne le nombre courant de maillons */
TOBJ*	maillon( int pos ) ; 	/* pointeur sur données utiles d'un maillon */
void	detruire( void ) ; 		/* suppression de tous les maillons */

void	inserer(TOBJ* obj, int pos ) ;
TOBJ*	extraire( int pos ) ;

#endif
