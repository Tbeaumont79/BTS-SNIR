#ifndef LLLIST_H

#define LLLIST_H
#include "tobj.h"
#include <string.h>
void newItem(TObj obj);
TObj* firstItem();
TObj* nextItem();
void freeAll();

#endif
