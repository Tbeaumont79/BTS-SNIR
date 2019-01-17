#include "indiv.h"

INDIV *tab;

void ajouter(INDIV *p)
{
    tab = realloc(tab,sizeof(INDIV));
    memcpy(tab,p,sizeof(INDIV));
}

void afficher( INDIV* p )
{
    printf("%-12s %-8s ", p->nom, p->prenom ) ;
    printf("%s %s %s\n", p->adresse, p->tel, p->email ) ;
}


void afficherTout(int size){
    // boucle de parcours de tab et appel à afficher()
    int i= 0;
    while (i < size)
        afficher(&tab[i++]);

}

int chargement(char *file)
{
    int		nbr = 0 ;
    INDIV	indiv ;
    int		hfile = open( file, O_RDONLY ) ;
    while ( read( hfile, &indiv, sizeof(INDIV) ) ) {
        nbr++;
        ajouter( &indiv );
    }

    close( hfile ) ;
    return nbr ;
}
