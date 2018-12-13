#include "lllister.h"

item first;

void create_Element(item *new,item *contact)
{
    new->next = contact;
    contact = new;

    
}
