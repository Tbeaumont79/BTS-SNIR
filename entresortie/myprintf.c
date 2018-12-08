#include <unistd.h>

void    affichage(char c)
{
    write(1,&c,1);
}

int main()
{
    char *lettre;
    int i;

    i = 0;
    lettre = "bonjour je suis un test";
    while (lettre[i] != '\0')
    {
        affichage(lettre[i++]);
    }
}
