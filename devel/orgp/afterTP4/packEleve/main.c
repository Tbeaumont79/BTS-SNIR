/*  ---------------------------------------------------------------------------
 *  nom         :   main.c
 *  description :   projet 'contact2' : programme d'application
 *  création    :   10/1998
 *  version/maj :   3.0  -  06/03/2007
 *  ---------------------------------------------------------------------------
 *  auteur(s)   :   Copyright 2007 A. Menu   <alain.menu@ac-creteil.fr>
 *  ---------------------------------------------------------------------------
 */

#include	<stdio.h>
#include	<string.h>
#include	<ctype.h>
#include	<unistd.h>
#include	<fcntl.h>
//#include	<sys\stat.h>

#define		DEFBASE		"contacts.dta"

#include	"lsdyn.h"

void afficher( INDIV* p )
{
	printf("%-12s %-8s ", p->nom, p->prenom ) ;
	printf("%s %s %s\n", p->adresse, p->tel, p->email ) ;
}

void ranger( INDIV* p )
{
	int		pos ;
	int		comp ;
	INDIV* 	q ;

	for ( pos = 0 ; pos < taille() ; pos++ ) {
		q = maillon( pos ) ;
		comp = strcasecmp( p->nom , q->nom ) ;
		if ( comp < 0 ) {
			inserer( p, pos ) ;
			return ;
		}
		if ( comp == 0 ) {
			if ( strcasecmp( p->prenom , q->prenom ) < 0 ) {
				inserer( p, pos ) ;
				return ;
			}
		}
	}
	ajouter( p ) ;
}

int	chargement( char* nf )
{
	int		nbr = 0 ;
	INDIV	indiv ;
	int		hfile = open( nf, O_RDONLY ) ;

	while ( read( hfile, &indiv, sizeof(INDIV) ) ) {
		nbr++ ;

//		printf("%2d : %s %s\n", nbr, indiv.nom, indiv.prenom ) ;

		ajouter( &indiv ) ;
//		ranger( &indiv ) ;
	}

	close( hfile ) ;
	return nbr ;
}

void	sauvegarde( char* nf )
{
	int	i ;
	int	hfile = open( nf, O_CREAT | O_WRONLY ) ;

	if ( hfile == -1 ) {
		fputs("Contacts : enable to write data file...", stderr ) ;
		return ;
	}

	for ( i = 0 ; i < taille() ; i++ ) {
		write( hfile, maillon( i ), sizeof( INDIV ) ) ;
	}
	close( hfile ) ;
}

void	parcours( void )
{
	int	i ;

	for ( i = 0 ; i < taille() ; i++ ) {
		INDIV*	p = maillon( i ) ;
//		printf("%2d : %s %s\n", i+1, p->nom, p->prenom ) ;
		printf("%2d : ", i+1 ) ;
		afficher( p ) ;
	}
	printf("total = %d\n", i ) ;
}

void	saisie( char* dest, int lmax )
{
	char	buf[80] ;

	fgets( buf, lmax, stdin ) ;

	if ( buf[0] != '\n' ) {
		buf[ strlen(buf) - 1 ] = '\0' ;
		strcpy(dest, buf ) ;
	}
}

void	nouveau( void )
{
	INDIV	indiv ;

	memset( &indiv, 0, sizeof( INDIV ) ) ;

	puts("Nouveau contact :" ) ;
	fflush( stdin ) ;
	printf("Nom     ? " ) ;	saisie( indiv.nom, TNOM ) ;
	printf("Prenom  ? " ) ;	saisie( indiv.prenom, TPRENOM ) ;
	printf("Adresse ? " ) ;	saisie( indiv.adresse, TADR ) ;
	printf("Tel     ? " ) ;	saisie( indiv.tel, TTEL ) ;
	printf("Email   ? " ) ;	saisie( indiv.email, TMAIL ) ;

	if ( indiv.nom[0] ) {
//		ajouter( &indiv ) ;
		ranger( &indiv ) ;
	}
}

int	idcontact( char* mess )
{
	int	num ;

	printf("Numero du contact a %s ? ", mess ) ;
	scanf("%d", &num ) ;
	fflush( stdin ) ;
	num -= 1 ;
	if ( ( num < 0 )||( num >= taille() ) ) {
		puts("id. incorrect !") ;
		return -1 ;
	}
	return num ;
}

void	edition( void )
{
	INDIV	indiv ;

	int	num = idcontact("editer") ;
	if ( num == -1 )	return ;

	memcpy( &indiv, extraire( num ), sizeof( INDIV ) ) ;

	printf("Nom     [%s] ? ", indiv.nom ) ;		saisie( indiv.nom, TNOM ) ;
	printf("Prenom  [%s] ? ", indiv.prenom ) ;	saisie( indiv.prenom, TPRENOM ) ;
	printf("Adresse [%s] ? ", indiv.adresse ) ;	saisie( indiv.adresse, TADR ) ;
	printf("Tel     [%s] ? ", indiv.tel ) ;		saisie( indiv.tel, TTEL ) ;
	printf("Email   [%s] ? ", indiv.email ) ;	saisie( indiv.email, TMAIL ) ;

	afficher( &indiv ) ;
	ranger( &indiv ) ;
}

void	suppression( void )
{
	int	num = idcontact("supprimer") ;
	if ( num == -1 )	return ;

	extraire( num ) ;
}

int main(int argc, char* argv[] )
{
	char*	nf = DEFBASE ;
	int		hfile ;
	int		nbr ;
	int		fin = 0 ;

	if ( argc > 1 )	nf = argv[1] ;
	hfile = open( nf, O_RDONLY ) ;
	if ( hfile == -1 ) {
		fputs("Contacts : data file not find...", stderr ) ;
		return -1 ;
	}
	close( hfile ) ;

	nbr = chargement( nf ) ;
//	printf("total : %d enregistrements\n", nbr ) ;

	do {
		printf("[L]ister [E]diter [A]jouter [S]upprimer [Q]uitter : " ) ;

		switch( toupper( getchar() ) ) {

			case 'L':	parcours() ;
						break ;
			case 'E' :	edition() ;
						break ;
			case 'S' :	suppression() ;
						break ;
			case 'A' :	nouveau() ;
						break ;
			case 'Q' :	fin = 1 ;
						break ;
			default :	putchar('\a') ;
		}

		fflush( stdin ) ;

	} while ( !fin ) ;

	sauvegarde( nf ) ;
	detruire() ;
	return 0 ;
}
