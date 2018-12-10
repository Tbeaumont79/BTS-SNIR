#include <stdio.h>

int main(int argc, char **argv)
{
    int sum, ind = 0;
    while (ind <= atoi( argv[1] ))
    {
        sum += ind;
        ind++;
    }
    printf("%d\n",sum,ind);
    return 0;
}
