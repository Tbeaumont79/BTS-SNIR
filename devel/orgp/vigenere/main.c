/* ---------------------------------------------------------------------------
 *  Nom         :   main.c
 *  Type        :   APPLICATION
 *  Sujet       :   chiffrage polyalphabétique de Vigenère 
 *
 *  Auteur      :   Beaumont Thibault
 *  Version     :   0.1
 *  Création    :   26/11/2018
 *  Dern. màj   :   26/11/2018
 *
 *  Fabrication :   :gcc -Wall -o main main.c vigenere.c
 * ---------------------------------------------------------------------------
 */

#include "vigenere.h"

void    usage(const char *appname)
{
    printf("%s - version %s by %s\n",appname,VERSION,AUTHOR);
    puts("options: -h affiche cette aide");
    puts("      -k produit une clé de taille par défault");
    puts("      -k<len> produit une clé de taille <len>");
    puts("      -c permet de coder un message à partir d'une clé");
}

int     main(int argc,char **argv)
{
    char *result;
    for (int i = 1; i < argc; i++)
    {
        char *p = argv[i];
        if (*p == '-')
        {
            switch( *(p + 1))
            {
                case 'h':usage(argv[0]);
                         break;
                case 'k':
                         if (*(p + 2))
                             puts(vigenereKey(atoi(p+2)));
                         else {
                             if ((i + 1) < argc)
                                 puts(vigenereKey(atoi(argv[i + 1])));
                             else
                                 puts(vigenereKey(DEFAULTKEYSIZE));
                         }
                         break;
                case 'c':
                         mode = ENCODING;
                         if (*(p + 2))
                             result = vigenereProcess(mode, p + 2);
                         else
                         {
                             if ((i + 1) < argc)
                                result = vigenereProcess(mode, argv[i + 1]);
                             else
                             {
                                 fputs("Erreur : fichier clé absent", stderr);
                                 return (-1);
                             }
                         }
                    case 'd':
                         mode = DECODING;
                         if (*(p + 2))
                            result = vigenereProcess(mode,p + 2);
                         else
                         {
                            if ((i + 1) < argc)
                                result = vigenereProcess(mode,argv[i + 1]);
                         }
                         if (result != NULL)
                             puts(result);
                         break;
                default: printf("option %c non reconnue\n",*(p + 1));
            }
        }
    }
    return (0);
}
