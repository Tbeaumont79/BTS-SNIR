#include "argv.h"

int     main(int argc, char **argv)
{
    int entier, motif = 0;
    unsigned long puiss = 1;
    int i, j;
    float numerateur;
    float denominateur;

    if (NumberOfArg != 1)
        return (BadNumberOfArg);
    entier = FloatArg(1);

    i = 0;
    while(CharacterArg(1,i) != 0)
    {
        if (CharacterArg(1,i ) == '.')
        {
            j = i;
        }
        i++;
    }
    for (i = i - 1;i > j;--i)
    {
        motif += (CharacterArg(1,i) - '0' ) * puiss;
        puiss *= 10;
    }
    numerateur = (FloatArg(1) * 10) - entier;
    denominateur = puiss - 1;
    printf("%0.f/%0.f\n%f",numerateur,denominateur,numerateur/denominateur);
    return (0);
}
