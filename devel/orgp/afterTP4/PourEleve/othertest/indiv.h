/*  ---------------------------------------------------------------------------
 *  nom         :   indiv.h
 *  description :   projet 'contact3' : programme d'application
 *  création    :   10/1998
 *  version/maj :   4.0  -  27/02/2015
 *  ---------------------------------------------------------------------------
 *  auteur(s)   :   Copyright 2007 A. Menu   <alain.menu@ac-creteil.fr>
 *  				V4.0	A. Facchin
 *  ---------------------------------------------------------------------------
 */
#ifndef indiv_h
#define indiv_h

#define TNOM 20
#define TPRENOM 20
#define TADR 40
#define TTEL 15
#define TMAIL 25
#define		DEFBASE		"contacts.dta"

#include	<stdio.h>
#include	<string.h>
#include	<ctype.h>
#include	<unistd.h>
#include	<fcntl.h>
#include 	<stdlib.h>
#include        <string.h>

typedef struct Pindiv {
    char nom[TNOM];
    char prenom[TPRENOM];
    char adresse[TADR];
    char tel[TTEL];
    char email[TMAIL];
    char indice;
    struct Pindiv *next;
    
}INDIV;

void ajouter(INDIV *p);
int chargement(char *file);
INDIV *createUser();
int write_to_file(INDIV *li);
int is_empty_li(INDIV *li);
int afficheid(INDIV *li);
INDIV *edition(INDIV *li);
void print_list(INDIV *li);
void afficher(INDIV *p);
void afficherTout(int size);


#endif
