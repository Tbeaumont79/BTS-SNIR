/*  ---------------------------------------------------------------------------
 *  nom         :   indiv.h
 *  description :   projet 'contact2' : définition des enregistrements
 *  création    :   10/1998
 *  version/maj :   3.0  -  06/03/2007
 *  ---------------------------------------------------------------------------
 *  auteur(s)   :   Copyright 2007 A. Menu   <alain.menu@ac-creteil.fr>
 *  ---------------------------------------------------------------------------
 */

#define TNOM	20
#define TPRENOM	20
#define TADR	40
#define TTEL	15
#define TMAIL	25

typedef struct {
	char nom[TNOM] ;
	char prenom[TPRENOM] ;
	char adresse[TADR] ;
	char tel[TTEL] ;
	char email[TMAIL] ;
} INDIV ;

typedef		INDIV	TOBJ ;
