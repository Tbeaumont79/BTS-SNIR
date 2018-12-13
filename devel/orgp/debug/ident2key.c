#include "fibonacci.h"

int main(int argc, char **argv)
{
    int narg = 1;
    int i;
    int len;

    while ( narg < argc )
    {
        len = 0;
        char *p = argv[narg];
        TObj obj;

        while ( *(p + len) )
        {
            if ( *(p + len) == ' ' )
                *(p + len) = '_';
            len++;
        }
        if (len > MAXLEN ) {
            len = MAXLEN;
            *(p + MAXLEN ) = 0;
        }
        memcpy(obj.ident, p, len + 1);
        obj.identValue = 0;
        for (i = 0; i < len; ++i)
            obj.identValue += (i + 1) * *( p + i );
        obj.identKey = fibonacci( obj.identValue ); 
        
        narg++;@
    }
//parcour liste chainé
    return (0);
}
