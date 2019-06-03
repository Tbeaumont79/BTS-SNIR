#include "cdate.h"
TMonth CDate::getMonth() const
{
    return (TMonth)month ;
}
void CDate::setMonth(TMonth month )
{
    if ( month < JAN ) month = JAN ;
    if ( month > DEC ) month = DEC ;
    this->month = (unsigned)month ;
}
void CDate::setYear(unsigned year)
{
    if (year < 0)
        year = 0;
    if (year > 2500)
        year = 2499;
    this->year = year;
}

void CDate::setDay(unsigned day)
{
    if (day < 0)
        day = 0;
    if (day > 31)
        day = 31;
    this->day = day;

}

void CDate::set(unsigned day, TMonth month, unsigned year )
{
    this->day = day;
    this->month = month;
    this->year = year;
}
std::ostream& operator << (std::ostream& s, const CDate& date )
{
    s << date.print() ;
    return s ;
}
std::string CDate::print() const
{
    std::ostringstream oss ;
    oss << std::setfill('0') ;
    oss << std::setw(2) << day << '/' ;
    oss << std::setw(2) << month << '/' ;
    oss << std::setw(4) << year ;
    return oss.str() ;
}
std::string CDate::printLong() const
{
    std::ostringstream oss ;
    oss << std::setfill('0') ;
    oss << std::setw(2) << day << '/' ;
    oss << std::setw(2) << strMonth((TMonth)month) << '/' ;
    oss << std::setw(4) << year ;
    return oss.str() ;
}
