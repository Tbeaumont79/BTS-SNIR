#include "argv.h"

int     main(int argc,char **argv)
{
    unsigned char x = IntegerArg(1);

    printf("%d\n",(unsigned char)(-x + 1) );
    return (0);
}
