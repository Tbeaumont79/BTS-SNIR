#include <stdio.h>
#include <unistd.h>

char lettre;
int main(void)
{
    scanf("%c",&lettre);
    if (lettre == 0)
    {
        printf("appui sur controle + D");
        return (0);
    }
    printf(" Lettre en ascii %c en decimal %d",lettre,lettre);
}
