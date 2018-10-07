#include <stdio.h>

int     main()
{
    int a;
    long  int b;
    char c;
    short int d;
    long long int e;
    float f;
    double g;
    long double h;

    printf("\033[32m type int = %lu bits\n",sizeof(a) * 8 );
    printf("type long int = %lu bits\n",sizeof(b) * 8 );
    printf("type char = %lu bits\n",sizeof(c) * 8 );
    printf("type short int = %lu bits\n",sizeof(d) * 8 );
    printf("type long long int = %lu bits\n",sizeof(e) * 8 );
    printf("type float = %lu bits\n",sizeof(f) * 8 );
    printf("type double = %lu bits\n",sizeof(g) * 8 );
    printf("type long double = %lu bits\n",sizeof(h) * 8 );
    return (0);
}
