#include <stdio.h>
#include "functions.h"

void avionsMenu(aeroport arpts[size_aeroport], char nom[50]);

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
            scanf(" %[^\n]", name);
            avionsMenu(arpts, name);
            break;
        }
        case 4:
        {
            return;
        }
        }
    }
}

void avionsMenu(aeroport arpts[size_aeroport], char nom[50])
{
    while (1)
    {
        printf("#=================================================================================================================#\n");
        printf("########################################  la gestion de l'eroport %s  #########################################\n", nom);
        printf("#=================================================================================================================#\n");
        printf("#  choser un choix:                                                                                               #\n");
        printf("#    1-afficher tout les avions                                                                                   #\n");
        printf("#    2-ajouter un avion                                                                                           #\n");
        printf("#    3-Modifier un avion                                                                                          #\n");
        printf("#    4-Supprimer un avion.                                                                                        #\n");
        printf("#    7-Trier les avions par la capacite                                                                           #\n");
        printf("#    8-Trier les avions par modele alphabetique                                                                   #\n");
        printf("#    5-Rechercher un avion par id                                                                                 #\n");
        printf("#    6-Rechercher un avion par modele                                                                             #\n");
        printf("#    9-retourn a l'menu des eroports                                                                              #\n");
        printf("#    0-quitter le program                                                                                         #\n");
        printf("#=================================================================================================================#\n");
        printf("#taper votre choix ici:");
        int ch;
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
        {
            list_avions(arpts, nom);
            continue;
        }
        case 2:
        {
            add_avion(arpts, nom);
            continue;
        }
        case 3:
        {
            updateAvion(arpts, nom);
            continue;
        }
        case 4:
        {
            deletAvion(arpts, nom);
            continue;
        }
        case 5:
        {
            searachById(arpts, nom);
            continue;
        }
         case 5:
        {
            searsearachByModelachById(arpts, nom);
            continue;
        }
        case 0:
        {
            return;
        }
        case 9:
        {
            aeroportsMenu(arpts);
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