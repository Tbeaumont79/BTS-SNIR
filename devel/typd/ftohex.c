#include "argv.h"

int     main(int argc, char **argv)
{
    float v;
    unsigned char *p;
    if (NumberOfArg != 1)
        return (BadNumberOfArg);

    v = FloatArg(1);
    p = (unsigned char*)(&v);
    printf("la valeur du float est %f et la valeur de la chaine de char est %s",v,p);
    return (0);
}
