//
//  nb_impair.c
//  
//
//  Created by maylaender patrick on 13/10/2016.
//
//

#include "nb_impair.h"

/* fonction qui saisie au clavier un nombre impair */

int saisir_nb_impair(int min, int max)
{
    int res = 0;
    int ok = 0 ; /* vu comme un booleen */
    while( !ok)
    {
        printf("valeur impaire ? entre %d et %d \n",min,max);
        scanf("%d",&res);
        ok = 1; /* supposé correct*/
        if( ( res < min) || (res > max) )
        {
            ok = 0;
        }
        if( res % 2 == 0)    ok = 0; /* faux car pair*/
    }
    return res;
}
