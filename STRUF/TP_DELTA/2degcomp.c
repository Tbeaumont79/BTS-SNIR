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
#include <ctype.h>

#include "argv.h"
int main(void)
{
    // déclaration de variable : 
    int a;
    int b;
    int c;
    float e;
    float d;
    float delta;
    float x1;
    float x2;

    printf("entrez la valeur de a : \n");
    scanf("%d",&a);
    printf("entrez la valeur de b : \n");
    scanf("%d",&b);
    printf("entrez la valeur de c : \n");
    scanf("%d",&c);
    delta = (b *b - 4 * a * c);
    printf("la valeur de delta est de : %f\n",delta);

    if (delta < 0)
    {
        puts("il n'y a pas de solution ! Dans les réels mais ils y en a deux dans les complexes");
        d = (-b /2*a);
        e = sqrt(-delta)/(2*a);
        printf(" racine x1 =%f + i %f ",e,d);
        printf("racine x2= %f- i%f",e,d);

    }
    else if (delta == 0)
    {
        x1 = (-b /2*a);
        printf("%f",x1);
    }
    else if (delta > 0)
    {
        x1 = ((-b - sqrt(delta))/(2*a));
        x2 = ((-b + sqrt(delta))/(2*a));
        printf("delta est superieur à zero il y a donc deux racines %f et %f",x1,x2);
    }
    return (0);
}
