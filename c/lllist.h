#ifndef LLLIST_H
#define LLLIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Pelem
{
    int a;
    char *txt;
    Pelem next;
} item;

void Free_list();



#endif
