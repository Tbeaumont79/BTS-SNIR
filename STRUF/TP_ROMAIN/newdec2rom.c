/************************************************
 * Auteur : Beaumont Thibault                    *
 * Nom prog : newDec2Rom                            *
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
    const char Symb_romain[][3] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
    const int Symb_arabe[] = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
    int reste;
    int i;

    i = 0;
    reste = value;
    while (reste > 0)
    {
        if (reste >= Symb_arabe[i])
        {
            printf("%s",Symb_romain[i]);
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

