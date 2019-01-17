//
//  enplus.c
//  agenda
//
//  Created by maylaender patrick on 02/03/2015.
//  Copyright (c) 2015 maylaender patrick. All rights reserved.
//


#include "enplus.h"

//fonction de saisie a rajouter
/**     \fn void saisie(char *buf, int tmax)
 \brief saisie dans buf une chaine au clavier, de taille tmax octets
 \param[in] 1 buffer de stockage
 \param[in] 2 taille max a saisir
 \return neant
 
 */
void saisie(char *buf, int tmax)
{
    char temp[tmax];
    fgets(temp,tmax,stdin)  ; /* lecture sur la clavier */
    
    
    temp[strlen(temp)-1] = 0;  /* mise du fin chaine */
    
    strcpy(buf,temp);
    
}
