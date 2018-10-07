#include <stdio.h>

int     main()
{
    float f1 = 0.1;
    float f2 = 0.2;
    float x = 1e12;
    float y = 1e-11;

    if ( ( f1 + f2 ) == 0.3)
        puts("ok !" );
    else
        puts("Faux !");
    printf("%f\n", ( (x-x) + y ) / y );
    printf("%f\n", ( x + (y - x) ) / y );

    return (0);
}
