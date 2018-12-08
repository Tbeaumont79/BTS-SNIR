/************************************************
* Auteur :                                      *
* Nom prog :tristar                             *
* Role :  affichage triangle etoiles            *
* Version : 1                                   *
* Fabrication :  gcc -Wall -o tristar tristar.c *
* Date :  10/18                                 *
*************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "argv.h"

int saisir_nb_impair(int min, int max)
{
    int res = 0;
    int ok; /* vu comme un booleen */
    while(ok != 0)
    {

        printf("valeur impaire ? entre %d et %d \n",min,max);
        scanf("%d",&res);
        ok = 1; /* supposé correct*/
        if( ( res < min) || (res > max) )
        {
            ok = 0;
        }
        if( res % 2 == 0)    ok = 0; /* faux car pair*/
        else                 return (res);
    }
    return (0);
}
 
int main(int argc, char **argv)
{
    int lig;
    int col;
    int size;

    size = saisir_nb_impair(3, 15);
    lig = 1;
    while (lig <= size)
    {
        for(col = 0; col < lig; col++)
        {
            printf("*");
        }
        printf("\n");
        lig += 2;
    }

    return (0);
}
