#include "argv.h"

int     main(int argc, char **argv)
{
    int q;
    float ptht;

    if ( NumberOfArg < 3)       return(BadNumberOfArg);
    if ( LengthOfArg(1) != 7)   return(InvalidArg);
    if ( CharacterArg(1,2) != '-')      return(InvalidArg);

    q = IntegerArg(4);
    if (q == 0)
        q = 1;
    ptht = atof(argv[3]);
    printf("article : \"%s\"\n",StringArg(2));
    printf("Prix total hors taxe : %.2f\n",ptht);
    return (0);
}
