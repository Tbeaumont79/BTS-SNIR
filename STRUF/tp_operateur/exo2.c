#include <stdio.h>

int main(void)
{
    int x;
    int y;
    int r;
    int z;
    x = 3;
    y = 2;
    z = 1;
    r = x | y & z;
    printf(" 1 r = %d \t x = %d \t y = %d \t z = %d\n",r,x,y,z);
    r = x&y&&z;
    printf(" 3 r = %d \t x = %d \t y = %d \t z = %d\n",r,x,y,z);
    r<<=3;
    printf(" 4 r = %d \t x = %d \t y = %d \t z = %d\n",r,x,y,z);
    r = z-2<<3;
    printf(" 5 r = %d \t x = %d \t y = %d \t z = %d\n",r,x,y,z);
    x = 1;
    y = 1;
    z = 1;
    x += y += z;
    r = (x < y ? y : x);
    printf(" 1 r = %d \t x = %d \t y = %d \t z = %d\n",r,x,y,z);
    r = (z += x < y ? ++x : ++y);
    printf(" 1 r = %d \t x = %d \t y = %d \t z = %d\n",r,x,y,z);
    x = 3;
    y = z = 4;
    r = ((z>=y >=x) ? 1 : 0);
    printf(" 1 r = %d \t x = %d \t y = %d \t z = %d\n",r,x,y,z);
    r = (++x || ++y && ++z);
    printf(" 1 r = %d \t x = %d \t y = %d \t z = %d\n",r,x,y,z);
    r = (x | ++y || (--z) - 1);
    printf(" 1 r = %d \t x = %d \t y = %d \t z = %d\n",r,x,y,z);

}
