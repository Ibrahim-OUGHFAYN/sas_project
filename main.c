#include <stdio.h>
#include "functions.h"


void aeroportsMenu(aeroport arpts[size_aeroport])
{
    while (1)
    {
        printf("#=================================================================================================================#\n");
        printf("########################################## Bienvenu a votre application ###########################################\n");
        printf("#=================================================================================================================#\n");
        printf("#  choser un choix:                                                                                               #\n");
        printf("#    1-afficher tout les aeroports                                                                                #\n");
        printf("#    2-ajouter un aeroport                                                                                        #\n");
        printf("#    3-gerer un aeroport                                                                                          #\n");
        printf("#    4-quitter le program                                                                                         #\n");
        printf("#=================================================================================================================#\n");
        printf("#taper votre choix ici:");

        int ch;
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
        {
            listAeroports(arpts);
            break;
        }
        case 2:
            addAeroport(arpts);
            break;
        case 3:
        {
            char name[50];
            printf("donner moi le nom de l'eroport :");
            scanf("%[^\n]", name);
            avionsMenu(name);
            break;
        }
        case 4:
        {
            return;
        }
        }
    }
}

void avionsMenu(char nom[50])
{
    while (1)
    {
        printf("#=================================================================================================================#\n");
        printf("##########################################  la gestion de l'eroport %s  ###########################################\n",nom);
        printf("#=================================================================================================================#\n");
        printf("#  choser un choix:                                                                                               #\n");
        printf("#    1-afficher tout les aeroports                                                                                #\n");
        printf("#    2-ajouter un aeroport                                                                                        #\n");
        printf("#    3-gerer un aeroport                                                                                          #\n");
        printf("#    4-quitter le program                                                                                         #\n");
        printf("#=================================================================================================================#\n");
        printf("#taper votre choix ici:");
        int ch;
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
        {
        }
        case 2:
        {
        }
        case 3:
        {
        }
        case 4:
        {
            return;
        }
        default:
        {
            printf("choix introuver!!!");
            continue;
        }
        }
    }
}

int main()
{
    aeroport arpts[size_aeroport];
    aeroportsMenu(arpts);
    return 0;
}