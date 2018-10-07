#include <stdio.h>

int     main()
{
    char s1[5] = "veni";
    char s2[4] = "vedi";
    char s3[3] = "vici";

    printf("s1: %p, %lu octects",s1,sizeof(s1));
    printf(",\"%s\"\n",s1);
    printf(",\"%s\"\n",s2);
    printf(",\"%s\"\n",s3);
    return (0);
}
