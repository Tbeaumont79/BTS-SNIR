#include <stdio.h>

int     main(int argc, char **argv)
{
    int i;

    for ( i = 0; i < argc ; i++)
    {
        printf("l'argument d'indice %03d est égale à  %d\n", i,argv[i] );
    }
    return (0);
}
