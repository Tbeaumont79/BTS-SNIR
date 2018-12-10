#define SIZE 20
#include <stdio.h>

void initTab(char *p, int s);
char *strTab(char *p, int s);

int main(int argc,char **argv)
{
    char *msg = "buggy";
    int size = SIZE;
    printf("%s\n",strTab(msg, size));
}

void initTab(char *p, int s)
{
    int i = 0;
    for (; i < s;i++)
    {
        p[i] = 'A' + i;
    }
}

char *strTab(char *p,int s)
{
    static char tab[SIZE + 1];
    int i;

    initTab(p,s);
    for (i = 0; i < s; ++i)
    {
        tab[i] = p[i];
    }
    tab[i] = 0;
    return tab;
}
