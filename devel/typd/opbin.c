#include <stdio.h>

int     main()
{
    unsigned char a;
    unsigned char b;

    a = 0x6c;
    b = 0x55;

    printf("a&b = %02x\n",a & -b);
    return (0);
}
