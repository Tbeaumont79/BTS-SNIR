#include "argv.h"

int     main(int argc, char **argv)
{
    unsigned char v;

    if ( NumberOfArg != 1 )
        return (BadNumberOfArg);
    v = IntegerArg(1);

    char result[] = "00000000";
    int indice;

    for(indice = 7; result[indice] != '\0'; indice--)
    {
        if (v % 2 == 0)
            result[indice] = '0';
        else 
            result[indice] = '1';
        v = v / 2;
    }
    puts(result);
    printf("%lu \nla valeur en est : ", sizeof(result) * 8);
    return (0);
}


