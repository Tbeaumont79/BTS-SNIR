#include <stdio.h>

int main(void)
{
    int x;
    int y;
    int z;

    x = -3 + 4 * 5 - 6;
    printf("1:x=%d\n",x);
    x = -3 * 4 % -6 / 5;
    printf("2:x=%d\n",x);
    x = 2;
    x *= 3 + 2;
    printf("3:x=%d\n",x);
    x *= y = z = 4;
    printf("4:x=%d\n",x);

}
