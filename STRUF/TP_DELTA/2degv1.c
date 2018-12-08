/************************************************
* Auteur : Beaumont Thibault                    *
* Nom prog : 2degv1.c                           *
* Role :                                        *
* Version : 1                                   *
* Fabrication :  gcc -Wall -o                   *
* Date :  10/18                                 *
*************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "argv.h"

int main(int argc, char **argv)
{
    // déclaration de variable : 
    int a;
    int b;
    int c;
    float delta;
    float x1;
    float x2;

    if (NumberOfArg > 0)
    { 
        a = IntegerArg(1);
        b = IntegerArg(2);
        c = IntegerArg(3);
        delta = (b *b - 4 * a * c); //attribution de la valeur à Delta
        printf("la valeur de delta est de : %f\n",delta);
        if (delta < 0)
            puts("il n'y a pas de solution ! Dans les réels");
        else if (delta == 0)
        {
            x1 = (-b /2*a);//calcule de l'unique racine
            printf("%f",x1);
        }
        else if (delta > 0)
        {
            x1 = ((-b - sqrt(delta))/(2*a)); //calcule des 2 racines réel distinct.
            x2 = ((-b + sqrt(delta))/(2*a));
            printf("delta est superieur à zero il y a donc deux racines %f et %f",x1,x2);
        }
    }
    else
        puts("Nombre d'argument non valide !");

    return (0);
}
