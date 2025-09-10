#include <stdio.h>
#include <string.h>
#define size_avions 100
#define size_aeroport 50

// date structur
typedef struct
{
    int d;
    int m;
    int y;
} date;
// struct of the avion
typedef struct
{
    int idAvion;
    char model[20];
    int capacite;
    char status[20];
    date dtEntree;
} avion;
// struct of the earoport
typedef struct
{
    char nom[50]; // unique
    avion avions[100];
    int nbrAvions;
} aeroport;

// proc to add a new aeroport
void addAeroport(aeroport arports[size_aeroport])
{
    char nom[50];
    printf("donner moi le nom de l'aeroport:");
    scanf(" %[^\n] ", nom);
    for (int i = 0; i < size_aeroport; i++)
    {
        if (strcmp(arports[i].nom, nom) == 0)
        {
            printf("this eroport already exist\n");
            return;
        }
    }
    for (int i = 0; i < size_aeroport; i++)
    {
        if (arports[i].nom[0] == '\0')
        {
            int nbrAvions = 0;
            strcpy(arports[i].nom, nom);
            arports[i].nbrAvions = nbrAvions;
            return;
        }
    }
}

// void to list all aeroports
void listAeroports(aeroport arports[size_aeroport])
{
    for (int i = 0; i < size_aeroport; i++)
    {
        if (arports[i].nom[0] == '\0')
        {
            break;
        }
        else
        {
            printf(" --> l'areport %s contient %d avions\n", arports[i].nom, arports[i].nbrAvions);
        }
    }
}
