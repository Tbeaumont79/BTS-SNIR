#ifndef TDATE_H
#define TDATE_H
#include "tmonth.h"

typedef struct {
    unsigned day ;
    TMonth month ;
    unsigned year ;
} TDate ;

TMonth getMonth(TDate* date );
TMonth setMonth(TDate* date, TMonth month );
unsigned int getDay (TDate *date);
void    setDay(TDate *date, unsigned day);
void        setyear(TDate *date, unsigned year);
#endif
