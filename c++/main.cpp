#include "tmonth.h"
#include <iostream>

using namespace std ;
int main(int argc, char** argv )
{
    for ( TMonth m = JAN ; m <= DEC ; m = (TMonth)(m + 1) ) {
        cout << strMonth(m) << endl ;
    }
    return 0 ;
}
