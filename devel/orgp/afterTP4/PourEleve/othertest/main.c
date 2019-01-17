#include "indiv.h"

int main(int argc,char **argv)
{
    if (argc > 1)
    {

        char* nf = argv[1];
        int ret;
        int nbr;
        INDIV *li = createUser();
        if (!(is_empty_li(li)))
        {
            ret = open(nf,O_RDONLY);
            if (ret == -1)
            {
                fputs("Contact : data file not find ...",stderr);
                return (-1);
            }
            nbr = chargement(nf);
            print_list(li);
            afficheid(li); 
            write_to_file(li);
            afficherTout(nbr);
        free(li);
        return (0);
    }
    else
        printf("no arguments found\n");
    return (0);
}
}
