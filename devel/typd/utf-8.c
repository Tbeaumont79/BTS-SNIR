#include <stdio.h>

int main()
{
    char s[] = "dès noël où un zéphyr haï "\
                "me vêt de glaçons würmiens "\
                "je dîne d'exquis rôtis de boeuf"\
                "au kir à l'aÿ d'âge mûr & caetera !";
    puts( s );
    printf("%lu octects\n",sizeof(s));
    return (0);
}
