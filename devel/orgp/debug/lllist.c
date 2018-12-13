#include "lllist.h"
#include "fibonacci.h"
typedef struct _item* PItem;

typedef struct _item {
    TObj obj;
    PItem next;
} TItem;
PItem first = NULL;
PItem other;

void newItem(TObj obj)
{

    PItem item = (PItem)malloc (sizeof(TItem));
    if (item == NULL)
        return ;
    memcpy(&(item->obj), &obj,sizeof(TObj));
    item->next = NULL;
    if (first == NULL)
    {
        first = item;
        return ;
    }
    if (CompareObjs(item->obj,first->obj) == -1)
    {
        item->next = first;
        first = item;
        return ;
    }
    PItem p = first;
    while (p->next != NULL)
    {
        if (CompareObjs(item->obj,first->obj) == -1)
        {
            item->next = p->next;
            p->next = item;
            return ;
        }
        p = p->next;
    }
    p->next = item;
}
TObj* firstItem()
{
    other = first;
    if (other == NULL)
        return (NULL);
    other = other->next;
    return (&(first->obj));
}
TObj* nextItem()
{
    PItem p = other;
    if (p == NULL)
        return (NULL);
    other = other->next;
    return (&(p->obj));
}
void freeAll()
{
    PItem p = first;
    while (p != NULL)
    {
        first = first->next;
        free(p);
        p = first;
    }
}
