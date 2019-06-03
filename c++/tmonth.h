#ifndef TMONTH_H
#define TMONTH_H


typedef enum { JAN=1, FEV, MAR, AVR, MAI, JUI,
    JUL, AOU, SEP, OCT, NOV, DEC } TMonth ;

const char* strMonth(TMonth month );
#endif
