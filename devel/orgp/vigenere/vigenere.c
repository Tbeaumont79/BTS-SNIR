/* ---------------------------------------------------------------------------
 *  Nom         :   vigenere.c
 *  Type        :   UTILITAIRE
 *  Sujet       :   chiffrage polyalphabétique de Vigenère 
 *
 *  Auteur      :   Beaumont Thibault
 *  Version     :   0.1
 *  Création    :   26/11/2018
 *  Dern. màj   :   26/11/2018
 *
 *  Fabrication :   gcc -Wall -o main main.c
 * ---------------------------------------------------------------------------
 */

#include "vigenere.h"

char key[MAXKEYSIZE + 1];
char buf[MAXKEYSIZE + 1];
int vigenereCleanText(char *txt);
const char *vigenereKey(int length)
{
    int i; 
    srand(time(NULL));
    i = 0;
    if (length < MINKEYSIZE || length > MAXKEYSIZE)
        length = DEFAULTKEYSIZE;

    while (i < length)
    {
        key[i] = 'A' + rand() % 26;
        i++;
    }
    key[length] = 0;
    return (key);
}

void vigenereError(const char *msg)//fonction privée
{
    fprintf(stderr, "Erreur : %s\n",msg);
}

int vigenereLoadKey(const char *keyfile)//fonction privée
{
    FILE *f;
    f = fopen(keyfile,"r");
    if (f == NULL)
    {
        vigenereError("vigenereLoadKey() : impossible de charger la clé");
        return (-1);
    }
    fgets(key,MAXKEYSIZE,f);
    fclose(f);

    return (vigenereCleanText(key));
}

int vigenereReadText(void)//fonction privée
{
    int c;
    int i;

    i = 0;

    while((c = fgetc(stdin)) != EOF)
    {
        if (i > MAXKEYSIZE)
            break;
        buf[i] = (char)c;
        i++;
    }
    buf[i] = 0;
    return (i);
}

char *vigenereEncoding(const char *keyfile) //fonction publique
{
    int i;
    int j;
    i = 0;
    j = 0;
    if (vigenereLoadKey(keyfile))
        return (NULL);

    vigenereError(key);
    vigenereReadText();
    if (vigenereCleanText(buf) != 0)
        return (NULL);
    while(buf[i])
    {
        buf[i] = 'A' + ((buf[i] + key[j]) % 26);
        if (key[++j] == 0)
            j = 0;
        i++;
    }

    return (buf);
}
int vigenereCleanText(char *txt)
{
    FILE *src;
    int i;
    src = fopen(".vigenere.tmp","w");
    if (src == NULL)
    {
        vigenereError("vigenereCleanText() : échec de création du fichier temporaire");
        return (-1);
    }
    fputs(txt,src);
    fclose(src);
    FILE *pp;

    pp = popen("cat .vigenere.tmp | iconv -f utf-8 -t ascii//TRANSLIT","r");
    if (pp == NULL)
    {
        vigenereError("vigenereCleanText() : échec lors de la conversion Ascii");
        return (-2);
    }
    fgets(txt,MAXKEYSIZE,pp);
    pclose(pp);
    i = 0;
    int j = 0;
    while (txt[i])
    {
        if (isalpha(txt[i]))
        {
            txt[j] = txt[i];
            j++;
        }
        i++;
    }
    txt[i] = 0;
    return (0);
}

char *vigenereDencoding(const char *keyfile) //fonction publique
{
    int i;
    int j;

    i = 0;
    j = 0;
    if (vigenereLoadKey(keyfile))
        return (NULL);
    vigenereError("clé = ");
    vigenereReadText();
    while(buf[i])
    {
        buf[i] = (26 +(buf[i] - key[j])) % 26 + 'A';
        if (key[++j] == 0)
            j = 0;
        i++;
    }
    return (buf);
}

char    *vigenereProcess(VigenereMode mode, char *argv)
{
    if (mode == ENCODING)
        return(vigenereEncoding(argv));
    else
     return(vigenereDencoding(argv));
}

