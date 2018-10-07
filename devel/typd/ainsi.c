#include <stdio.h>

int main()
{
    printf("\x1b[H\x1b[2J");
    puts(" American National Standards Institute ");
    printf("\x1b[0m");
    return (0);
}
