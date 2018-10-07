#include "argv.h"

void    decimal_to_binary(unsigned char octect);
int main(int argc, char **argv)
{
    if (argc > 1)
    {
        decimal_to_binary(atoi(argv[1]));
        return (0);
    }
}
void    decimal_to_binary(unsigned char octect)
{
    int oct;
    int bit;

    bit = 128;
    oct = octect;
}
