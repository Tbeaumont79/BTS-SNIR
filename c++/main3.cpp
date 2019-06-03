#include "cdate.h"
int main(int argc, char** argv )
{
    CDate cdate1 ;
    cdate1.set(14, JUL, 1789 ) ;
    CDate cdate2(11, SEP, 2001 ) ;
    // ... ...
    //cdate2.setMonth( OCT ) ;
    //cdate2.setYear( 2011 ) ;
    cout << cdate1.printLong() << endl;
    cout << cdate2.printLong() << endl;
    cout << cdate1.print() << endl;
    cout << cdate2.print() << endl;
    // ... ...
    return 0 ;
}
