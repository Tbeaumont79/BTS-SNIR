#include <stdio.h>

int main()
{
    int ligne,colonne;

    for (ligne = 0; ligne < 16; ++ligne)
    {
        for (colonne = 0; colonne < 6; colonne++)
        {
            char c = 0x20+(0x10*colonne)+ligne;
            if (c < 127)
                printf("%c %d (%02x)\t", c,c,c);
        }
        putchar('\n');
    } 

    return (0);
}
