#include <unistd.h>
#include <stdio.h>

int main(void)
{
    char lettre;
    char *buffer;
    int i;
    
    i = 0;
    while (lettre > '\n')
    {
        buffer[i] = lettre;
        i++;
        read(0,&lettre,1);
    }
    printf("%s",buffer);
    buffer[i] = 0;
}
