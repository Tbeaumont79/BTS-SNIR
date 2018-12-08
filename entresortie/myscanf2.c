#include <unistd.h>
#include <stdio.h>

int main(void)
{

    char *buffer;
    char lettre = '0'; 
    int i = 0;


    while (lettre > '\n')
    {
        buffer[i] = lettre;
        i++;
        scanf("%s",buffer);
    }
    printf("%s",buffer);
    buffer[i] = 0;
}
