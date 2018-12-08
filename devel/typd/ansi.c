#include <stdio.h>
#include <stdlib.h>
int main()
{
    printf("\x1b[31;43;5m");
    puts(" American National Standards Institute ");
    printf("\x1b[0m");
    char txt = "\x1b[0m";
    printf("%d",strlen(txt))
    return (0);
}
