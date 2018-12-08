/************************************************
 * Auteur : Beaumont Thibault                    *
 * Nom prog : Dec2Rom                            *
 * Role :                                        *
 * Version : 1                                   *
 * Fabrication :  gcc -Wall -o                   *
 * Date :  10/18                                 *
 *************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "argv.h"

void   Dec2Rom(int value)
{
    const char *Symb_romain = {"MDCLXVI"};
    const int Symb_arabe[] = {1000,500,100,50,10,5,1};
    int reste;
    int i;

    i = 0;
    reste = value;
    while (reste > 0)
    {
        if (reste >= Symb_arabe[i])
        {
            printf("%c",*Symb_romain);
            reste -= Symb_arabe[i];
        }
        else
            i++;
    }
}       

int main(int argc, char **argv)
{
    int value;
    value = IntegerArg(1);
    if (!(value >= 1 && value <= 3999))
    {
        printf("entrer une valeur entre 1 et 3999\n");
        return (0);
    }
    else
    {
        printf("la valeur en décimale est : %d ",value);
        printf("conversion en chiffre romain : \n");
        Dec2Rom(value);
    }

    return (0);
}

