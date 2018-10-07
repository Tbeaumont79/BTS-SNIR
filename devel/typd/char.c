#include "argv.h"

int main(int argc, char **argv)
{
    char c = CharacterArg(1, 0);
    printf("%c %d (%02x)\n", c,c,c);
    return (0);
}
