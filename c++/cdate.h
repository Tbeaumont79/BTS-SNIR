#ifndef CDATE_H
#define CDATE_H

#include "tmonth.h"
#include <string>
#include <sstream>
#include <iomanip>
#include <ostream>
#include <iostream>
using namespace std;
class CDate { 
    private : 
        unsigned day ;
        unsigned month ;
        unsigned year ;
    public : 
        CDate() { set(1, JAN, 1900 ) ; } 
        CDate(unsigned day, TMonth month, unsigned year )
        {
            set(day, month, year ) ;
        }
        std::string print() const ;
        std::string printLong() const;
        TMonth getMonth() const ; 
        void setMonth(TMonth month ) ;
        void setYear(unsigned year);
        void setDay(unsigned day);
        void set(unsigned day, TMonth month, unsigned year ) ; 
} ;
std::ostream& operator << (std::ostream& s, const CDate& date ) ;
#endif
