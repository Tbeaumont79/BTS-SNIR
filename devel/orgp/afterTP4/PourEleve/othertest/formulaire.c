#include "indiv.h"

int value;

INDIV    *createUser()
{
    INDIV *user;
    INDIV *li;
    li = (char *)malloc(sizeof(INDIV*));
    user = malloc(sizeof(INDIV*));
    if (user == NULL || li == NULL)
        perror("probleme allocation\n");
    printf("NOM         ? ");
    li = fgets(user->nom,TNOM,stdin);
    printf("PRENOM         ? ");
    li->next = fgets(user->prenom,TPRENOM,stdin);
    printf("ADRESSE         ? ");
    li->next->next = fgets(user->adresse,TADR,stdin);
    printf("TELEPHONE         ? ");
    li->next->next->next = fgets(user->tel,TTEL,stdin);
    printf("EMAIL        ? ");
    li->next->next->next->next = fgets(user->email,TMAIL,stdin);
    printf("entre ton id  : ");
    li->next->next->next->next->next = fgets(&user->indice,255,stdin);
    return (li);
}
int write_to_file(INDIV *li)
{
    FILE *file = fopen("contact.txt","a");
    if (file == NULL)
        perror("probleme d'ouverture");
    fprintf(file,"%s \t",li->nom);
    fprintf(file,"%s \t",li->prenom);
    fprintf(file,"%s \t",li->adresse);
    fprintf(file,"%s \t",li->tel);
    fprintf(file,"%s \n",li->email);
    fprintf(file,"%d \n",atoi(&li->indice));
    value = li->indice;
    printf("LA VALEUR DE VALUE EST DE %d ",value);
    fclose(file);
    return (0);
}
int     is_empty_li(INDIV *li)
{
    if (li == NULL)
        return (1);

    return (0);
}
int     afficheid(INDIV *li)
{
    int i;
    
    i = 0;
    while (li->next != NULL)
    {
        printf("je passe par la\n");
        if (i == value)
        {
            printf("trés bien vous avez selectionner l'user : %s",li->nom);
            return (i);
        }
        i++;
        li = li->next;
    }
    printf("cette fiche n'existe pas.\n");

    return (0);
}
INDIV *edition(INDIV *li)
{
    int value = afficheid(li);
    printf("%d",value);
    return (li);
}
void    print_list(INDIV *li)
{
    if (!(is_empty_li(li)))
    {
        printf("\t%s\t",li);
        while (li->next != NULL)
        {
            li = li->next;
            printf("%s\t",li);
        }
    }
}
