/* ---------------------------------------------------------------------------
 *  Nom         :   template.c
 *  Type        :   APPLICATION
 *  Sujet       :   modèle de point d'entrée programme console
 *
 *  Auteur      :   Beaumont Thibault
 *  Version     :   0.1
 *  Création    :   26/11/2018
 *  Dern. màj   :   26/11/2018
 *
 *  Fabrication :   gcc -Wall -o template template.c
 * ---------------------------------------------------------------------------
 */

#include <stdio.h>

#define AUTHOR "Thibault Beaumont"
#define VERSION "0.1"

char *appname(char* path)
{
    char *p = path;

    while (*path) {
        if (*path == '/')
            p = path + 1;
        path++;
    }
    return p;
}

int main(int argc, char **argv)
{
    printf("%s - vesion %s by %s\n",appname(argv[0]), VERSION, AUTHOR ); 
    return (0);
}
