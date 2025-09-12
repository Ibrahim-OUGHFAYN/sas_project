#include <stdio.h>
#include <string.h>
#define size_avions 100
#define size_aeroport 50
int id = 0;
int nbrAvions = 0;

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
    printf("donner moi le nom de l'eroport:");
    scanf(" %[^\n]", nom);
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

// get index airoport by nom
int getibynom(aeroport arports[size_aeroport], char nom[50])
{
    for (int i = 0; i <= 0; i++)
    {
        if (strcasecmp(arports[i].nom, nom) == 0)
        {
            return i;
        }
    }
}
// afficher tout les avions
void list_avions(aeroport arports[size_aeroport], char nom[50])
{
    int a = getibynom(arports, nom);
    for (int i = 0; i <= nbrAvions; i++)
    {
        if (!arports[a].avions[i].idAvion)
        {
            return;
        }
        printf("%d- id: %d,model: %s,capacite: %d,status: %s,date entre: %d/%d/%d \n", i + 1, arports[a].avions[i].idAvion, arports[a].avions[i].model, arports[a].avions[i].capacite, arports[a].avions[i].status, arports[a].avions[i].dtEntree.d, arports[a].avions[i].dtEntree.m, arports[a].avions[i].dtEntree.y);
    }
}
// ajouter avion
void add_avion(aeroport arports[size_aeroport], char nom[50])
{
    id++;
    char model[20], status[20];
    int cap, d, m, y;
    printf("\ndonner moi le model de l'avion:");
    scanf(" %[^\n]", model);
    printf("donner moi le capacite de l'avion:");
    scanf(" %d", &cap);
    do
    {
        printf("donner moi le status de l'avion(desponible,En maintenance,En Vol):");
        scanf(" %[^\n]", status);
    } while (strcasecmp(status, "en vol") != 0 && strcasecmp(status, "en maintenance") != 0 && strcasecmp(status, "desponible") != 0);
    printf("donner moi la date d'entre de l'avion 'dd/mm/yyyy':");
    scanf("%d/%d/%d", &d, &m, &y);
    int a = getibynom(arports, nom);
    arports[a].avions[nbrAvions].idAvion = id;
    strcpy(arports[a].avions[nbrAvions].model, model);
    strcpy(arports[a].avions[nbrAvions].status, status);
    arports[a].avions[nbrAvions].capacite = cap;
    arports[a].avions[nbrAvions].dtEntree.d = d;
    arports[a].avions[nbrAvions].dtEntree.m = m;
    arports[a].avions[nbrAvions].dtEntree.y = y;
    nbrAvions++;
}
// modifier un avion modele capacite statut
void updateAvion(aeroport arports[size_aeroport], char nom[50])
{
    int idToUpdate;
    printf("donner moi l'id de l'avion qui vouv vouler modifier:");
    scanf("%d", &idToUpdate);
    int a = getibynom(arports, nom);
    for (int i = 0; i <= nbrAvions; i++)
    {
        if (arports[a].avions[i].idAvion == idToUpdate)
        {
            char mod[20], statut[20];
            int cap;
            printf("donner moi la nouvel modele: ");
            scanf(" %[^\n]", mod);
            printf("donner moi la nouvel statut(desponible,en maintenance,en vol): ");
            scanf(" %[^\n]", statut);
            printf("donner moi la nouvel capacite: ");
            scanf("%d", &cap);
            strcpy(arports[a].avions[i].model, mod);
            strcpy(arports[a].avions[i].status, statut);
            arports[a].avions[i].capacite = cap;
            printf("the avion updated succesfully!!\n");
            return;
        }
    }
}
// suppremer un avion
void deletAvion(aeroport arports[size_aeroport], char nom[50])
{
    int idTodelete;
    printf("donner moi l'id de l'avion qui vous vouler supprimer:");
    scanf("%d", &idTodelete);
    int a = getibynom(arports, nom);
    for (int i = 0; i <= nbrAvions; i++)
    {
        if (arports[a].avions[i].idAvion == idTodelete)
        {
            arports[a].avions[i].idAvion = arports[a].avions[i + 1].idAvion;
            strcpy(arports[a].avions[i].model, arports[a].avions[i + 1].model);
            strcpy(arports[a].avions[i].status, arports[a].avions[i + 1].status);
            arports[a].avions[i].capacite = arports[a].avions[i + 1].capacite;
            arports[a].avions[i].dtEntree.d = arports[a].avions[i + 1].dtEntree.d;
            arports[a].avions[i].dtEntree.m = arports[a].avions[i + 1].dtEntree.m;
            arports[a].avions[i].dtEntree.y = arports[a].avions[i + 1].dtEntree.y;
            printf("the avion deleted succesfully\n");
            nbrAvions--;
        }
    }
}
// search avion by id
void searachById(aeroport arports[size_aeroport], char nom[50])
{
    int idToResearch;
    int a = getibynom(arports, nom);
    printf("\nentrer l'id de l'avion qui vous rechercher:");
    scanf("%d", &idToResearch);
    for (int i = 0; i <= nbrAvions; i++)
    {
        if (arports[a].avions[i].idAvion == idToResearch)
        {
            printf("this is the avion that you looking for:\n");
            printf("%d- id: %d,model: %s,capacite: %d,status: %s,date entre: %d/%d/%d \n", i + 1, arports[a].avions[i].idAvion, arports[a].avions[i].model, arports[a].avions[i].capacite, arports[a].avions[i].status, arports[a].avions[i].dtEntree.d, arports[a].avions[i].dtEntree.m, arports[a].avions[i].dtEntree.y);
        }
    }
}
// search avions by model
void searachByModel(aeroport arports[size_aeroport], char nom[50])
{
    char model[20];
    int a = getibynom(arports, nom);
    printf("\nentrer le model de l'avion qui vous rechercher:");
    scanf(" %[^\n]", model);
    for (int i = 0; i <= nbrAvions; i++)
    {
        if (strcasecmp(arports[a].avions[i].model, model) == 0)
        {
            printf("voila les avion de model %s:\n", &model);
            printf("%d- id: %d,model: %s,capacite: %d,status: %s,date entre: %d/%d/%d \n", i + 1, arports[a].avions[i].idAvion, arports[a].avions[i].model, arports[a].avions[i].capacite, arports[a].avions[i].status, arports[a].avions[i].dtEntree.d, arports[a].avions[i].dtEntree.m, arports[a].avions[i].dtEntree.y);
        }
    }
}
// trier avion par capacite
void trierParCap(aeroport arports[size_aeroport], char nom[50])
{
    avion temp;
    int a = getibynom(arports, nom);
    for (int i = nbrAvions - 1; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (arports[a].avions[j].capacite > arports[a].avions[j + 1].capacite)
            {
                temp = arports[a].avions[j];
                arports[a].avions[j] = arports[a].avions[j + 1];
                arports[a].avions[j + 1] = temp;
            }
        }
    }
    printf("all avions now are sorted press 1 to show the new list\n");
}

// trier avion par modele alphabetique
void trierParModel(aeroport arports[size_aeroport], char nom[50])
{
    avion temp;
    int a = getibynom(arports, nom);
    for (int i = nbrAvions - 1; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (strcasecmp(arports[a].avions[j].model, arports[a].avions[j + 1].model) > 0)
            {
                temp = arports[a].avions[j];
                arports[a].avions[j] = arports[a].avions[j + 1];
                arports[a].avions[j + 1] = temp;
            }
        }
    }
    printf("all avions now are sorted press 1 to show the new list\n");
}

// les satatistiques
void stats(aeroport arports[size_aeroport], char nom[50])
{
    avion temp;
    int a = getibynom(arports, nom);
    int nbrdespo = 0, nbrenmain = 0, nbrenvol = 0;
    printf("voila le nombre total des avions dans cette aeroport : %d\n", nbrAvions);
    for (int i = 0; i < nbrAvions; i++)
    {
        if (strcasecmp(arports[a].avions[i].status, "desponible") == 0)
        {
            nbrdespo++;
        }
        else if (strcasecmp(arports[a].avions[i].status, "en maintenance") == 0)
        {
            nbrenmain++;
        }
        else if (strcasecmp(arports[a].avions[i].status, "en vol") == 0)
        {
            nbrenvol++;
        }
    }
    printf("il y a %d avions desponible\n", nbrdespo);
    printf("il y a %d avions en maintenance\n", nbrenmain);
    printf("il y a %d avions en vol\n", nbrenvol);
    int totalcap=0;
    for(int i=0;i<nbrAvions;i++){
        totalcap+=arports[a].avions[i].capacite;
    }
    printf("le total capacite de tout les avions dans cette aeroport est: %d\n",totalcap);

    int maxcap=arports[a].avions[0].capacite;
    int indexmax=0;
    for(int i=1;i<nbrAvions;i++){
        if(maxcap < arports[a].avions[i].capacite){
            maxcap=arports[a].avions[i].capacite;
            indexmax=i;
            break;
        }
    }
    printf("l'avion %s c'est l'avion ayant la plust grand capacite %d\n",totalcap);

    int mincap=arports[a].avions[0].capacite;
}
