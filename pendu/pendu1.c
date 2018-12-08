/*
/*  pendu1.c
/*  
/*
/*  Created by maylaender patrick on 18/07/2014.
/*
/**/

#include <stdio.h>

#include <stdlib.h>


/* ------- GETCH ----------*/
#include <termios.h>
#include <unistd.h>
#include <math.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>



#define AUTO 123   /*commenter for debug */

#define NumberOfArg		(argc - 1 )
#define LengthOfArg(N) 		( argc > (N) ? strlen(argv[N]) : 0 )
#define IntegerArg(N) 		( argc > (N) ? atoi(argv[N]) : 0)
#define LengthOfArg(N) 		( argc > (N) ? strlen(argv[N]) : 0 )
#define FloatArg(N) 		( argc > (N) ? float(atof(argv[N]) : (float)0 ) )
#define DoubleArg(N) 		( argc > (N) ? (atof(argv[N]) : (double)0 ) )
#define StringArg(N) 		( argc > (N) ? (argv[N] : NULL) )
#define CharacterArg(N,I) 	( argc > (N) ? (argv[N][I] : '\0') )
#define BadNumberOfArg	(puts("mauvais nb d'arguments"), -1)
#define InvalidArg	(puts("argument non valide"), -2)

#define TBUF 236328
char buffer[TBUF] ;/*for dico2.txt en utf8   conversion avec iconv*/

/* A commenter pour faire sans liblister */
#define AVECLIB 1111     


#include "lister.h"

main(int argc, char**argv)
{
    
	int nbalea, i = 0, j = 0 ,nblus =0, taillefic = 0;
	int carOK = 0;
    
	char a_trouver[26] ;
	char lettre = '0' ;
	int nbErreur = 0, nbErreur1 = 0;
	int jouer = 1; /*, carOK = 0; */
    
    char en_cours[26]; /*mot le plus lg langue francaise
    
    /* Appel fonction de librairie */
  /*Q1 */
    nblus = lister("dico2.txt"); 
    
    srand(time(NULL));
    nbalea = (int) (random() %  TBUF );  /*   gene alaeatoire ds espace TBUF max*/

    
   
    
    j =0;  
    
    /* oncherche ds Buffer initialise par fonction de librairie liblister */
    i = nbalea;
    
    
    /*Q2 */
    
    
    
    
    printf("MOT qu'il faudra trouver (pour la demo) \n%s", en_cours);
	sleep(2);
    i=1; 
    
    /* mets des tirets */
    while( (i < (strlen(a_trouver) - 1 ))){
        en_cours[i] = '-';
        i++;
    }
    jouer = 1;
    nbErreur = 0;
    
    
    fflush(stdin);
 
    /*Q3  */  /* boucle de jeu*/

    
	scanf("%c",&lettre);
   
    /*   .... */
    
    
    if(nbErreur>=6) puts("Perdu");
    else
        printf("\n gagne\n");
    
    
    return 0;
    
}
