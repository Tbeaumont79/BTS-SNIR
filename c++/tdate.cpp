#include "tdate.h"
#include <iostream>

TMonth getMonth(TDate* date )
{
    return date->month ;
}
TMonth setMonth(TDate* date, TMonth month )
{
    if ( month < JAN ) month = JAN ;
    if ( month > DEC ) month = DEC ;
    date->month = month ;
    return (date->month);
}
unsigned int getDay (TDate *date)
{
    return (date->day);
}

void    setDay(TDate *date, unsigned day)
{
    if (day <= 0) day = 1;
    if (day > 31) day = 31;
    date->day = day;

}

unsigned int getyear(TDate *date)
{
    return (date->year);
}

void        setyear(TDate *date, unsigned year)
{
    if (year < 0)
        year = 0;
    if (year > 2500)
        year = 2499;
    date->year = year;
}
