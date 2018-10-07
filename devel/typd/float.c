#include "argv.h"

int     main(int argc, char *argv[] )
{
    if ( NumberOfArg != 2 )
        return (BadNumberOfArg);
    float x = FloatArg(1);
    int n = IntegerArg(2);
    printf("%d %.f\n", n, x );

    return (0);
}
