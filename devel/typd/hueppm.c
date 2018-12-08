#include "argv.h"
#include <stdio.h>
#define STEP 4
#define COLORS 6
#define WIDTH ( 256 / STEP * COLORS )
#define HEIGHT 64

int r[ COLORS ] = {255,0,0};
int g[ COLORS ] = {0,0,255};
int b[ COLORS ] = {0,255,0};

int main(int argc, char **argv)
{
    int raw = 0;
    if (NumberOfArg > 0)
    {
        if (CharacterArg(1,0) == '-')
        {
            if ( CharacterArg(1,1) == 'r' )
                raw = 1;
        }
        putchar('P');
        (raw == 0 ? printf("3"): printf("6"));
    }   
    return (0);
}
