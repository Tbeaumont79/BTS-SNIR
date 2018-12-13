#ifndef TOBJ_H
#define TOBJ_H

#define MAXLEN 6

#define CompareObjs(A,B) ( (A).identValue > (B).identValue ? 1 : -1 )
typedef struct {
    char ident[ MAXLEN + 1 ];
    unsigned identValue;
    unsigned identkey;

}       TObj;

#endif
