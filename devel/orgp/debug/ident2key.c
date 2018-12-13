#include "fibonacci.h"
#include "lllist.h"
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
        obj.identkey = fibonacci( obj.identValue ); 
        newItem(obj);        
        narg++;
    }
    TObj* p = firstItem();
    while (p != NULL)
    {
        printf("%-6s - %4u - %08x\n",p->ident,p->identValue,p->identkey);
        p = nextItem();
    }
    freeAll();
    return (0);
}
