/************************************************
 * Auteur :                                    *
 * Nom prog :tristar2                             *
 * Role :  affichage triangle etoiles            *
 * Version : 2                                   *
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
    int ok = 1; /* vu comme un booleen */
    while(ok != 0)
    {

        printf("valeur impaire ? entre %d et %d \n",min,max);
        scanf("%d",&res);
        ok = 1; /* supposé correct*/
        if( ( res < min) || (res > max) )-
        {
            ok = 0;
        }
        if( res % 2 == 0)
            ok = 0; /* faux car pair*/
        else
            return (res);
    }
    return (0);
}

int main(int argc, char **argv)
{

    int col;
    int lig;
    int nb;
    int size;
    int i;

    lig = 1;
    nb = saisir_nb_impair(3, 15);
    size = nb;
    i = 0;
    while (lig <= size)
    {
        for (col = 1; col <= (nb - i) / 2;col++)
        {
            printf(" ");
        }
        for (col = 1; col <= lig;col++)
        {
            printf("*");
        }
        nb--;
        i++;
        lig += 2;
        printf("\n");
    }

    return (0);
}

