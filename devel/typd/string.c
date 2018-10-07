#include "argv.h"

int     main(int argc,char **argv)
{
    if (NumberOfArg != 1 )
        return BadNumberOfArg;
    char *p = StringArg(1);
    int i;

    i = 0;
    while (*(p + i) != 0 )
    {
        putchar(p[i]);
        i++;
    }
    printf("%d\n",i);
    putchar('\n');
    return (0);
}
