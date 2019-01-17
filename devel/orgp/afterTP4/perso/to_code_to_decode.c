#include "lib.h"

Titem   *to_code(char *txt)
{
    Titem *item;

    item = malloc(sizeof(Titem));
    if (item == NULL)
        return (NULL);
   while (item->next != NULL)
   {
    item = txt;
    item = item->next;
   } 
    return (item);
}

