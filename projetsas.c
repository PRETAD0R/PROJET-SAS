#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    int idclient;
    char nom[20];
    char prenom[20];
    char email[50];
    float solde;
}client;
typedef struct {
    int idproduit;
    char nom[50];
    char categorie[50];
    float prix;
    int stock ;
    char description[100];
}produit;
typedef struct {
    int jour ;
    int mois ;
    int annee ;
}date;
typedef struct {
    int produit_id;
    int quantite;
    float total;
    date date;
}achat;


void creer_profil(client *c){
    printf("Entrez le nom: ");
    scanf("%s", c->nom);
    printf("Entrez le prenom: ");
    scanf("%s", c->prenom);
    c->solde = 0.0;
    printf("\nProfil cree avec succes!\n");
    srand(time(NULL));
    c->idclient = rand() % 1000;
    printf("ID du client: %d\n", c->idclient);
    strcpy(c->email, c->prenom);
    strcat(c->email, ".");
    strcat(c->email, c->nom);
    strcat(c->email, "@client.com");
    printf("Email: %s\n", c->email);
}

void modifier_profil(client *c){
        printf("Modifier le nom (actuel: %s): ", c->nom);
        scanf("%s", c->nom);
        printf("Modifier le prenom (actuel: %s): ", c->prenom);
        scanf("%s", c->prenom);
        printf("Modifier l'email (actuel: %s): ", c->email);
        scanf("%s", c->email);
        printf("Profil modifie avec succes!\n");
    }

void consulter_profil(client *c){
        printf("ID du client: %d\n", c->idclient);
        printf("Nom: %s\n", c->nom);
        printf("Prenom: %s\n", c->prenom);
        printf("Email: %s\n", c->email);
        printf("Solde: %.2f MAD\n", c->solde);
    }

void consulter_solde(client *c){
        printf("\nVotre solde actuel est: %.2f MAD\n", c->solde);
    }

void depot_argent(client *c, float montant){
        if(montant > 0){
            c->solde += montant;
            printf("\nDepot de %.2f MAD effectue avec succes! Nouveau solde: %.2f MAD\n", montant, c->solde);
        }else{
            printf("\nMontant invalide. \n");
        }
    }

void afficher_produits(produit produits[], int size){
    int found = 0;
        printf("\n--Liste des produits--\n");
        for(int i = 0; i < size; i++){
            printf("\nID: %d, Nom: %s, Categorie: %s, Prix: %.2f MAD, Stock: %d\n", 
                   produits[i].idproduit, produits[i].nom, produits[i].categorie, 
                   produits[i].prix, produits[i].stock);
        }
    
}
void rechercher_categorie(produit produits[], int size, char categorie[]){
    int found = 0;
    for(int i = 0; i < size; i++){
        if(strcmp(produits[i].categorie, categorie) == 0){
            printf("\nProduit trouve: ID: %d, Nom: %s, Categorie: %s, Prix: %.2f MAD, Stock: %d\n", 
                   produits[i].idproduit, produits[i].nom, produits[i].categorie, 
                   produits[i].prix, produits[i].stock);
            found = 1;
            break;
        }
    }
    if(!found){
        printf("\nProduit non trouve.\n");
    }
}
void rechercher_produit(produit produits[], int size, char nom[]){
    int found = 0;
    for(int i = 0; i < size; i++){
        if(strcmp(produits[i].nom, nom) == 0){
            printf("\nProduit trouve: ID: %d, Nom: %s, Categorie: %s, Prix: %.2f MAD, Stock: %d\n", 
                   produits[i].idproduit, produits[i].nom, produits[i].categorie, 
                   produits[i].prix, produits[i].stock);
            found = 1;
            break;
        }
    }   
    if(!found){
        printf("\nProduit non trouve.\n");
    }
}
 
void trier_produits_par_prix(produit produits[], int size){
    printf("\nTrier les produits par prix...\n");
    printf("\n1. Prix croissant\n");
    printf("\n2. Prix decroissant\n");
    int choix;
    scanf("%d", &choix);
    switch(choix){
        case 1:
            for(int i = 0; i < size - 1; i++){
                for(int j = i + 1; j < size; j++){
                    if(produits[i].prix > produits[j].prix){
                        produit temp = produits[i];
                        produits[i] = produits[j];
                        produits[j] = temp;
                    }
                }
            }
            break;
        case 2:
            for(int i = 0; i < size - 1; i++){
                for(int j = i + 1; j < size; j++){
                    if(produits[i].prix < produits[j].prix){
                        produit temp = produits[i];
                        produits[i] = produits[j];
                        produits[j] = temp;
                    }
                }
            }
            break;
        default:
            printf("\nChoix invalide.\n");
            break;
    }
    printf("Produits tries par prix avec succes!\n");
    }
void trier_produits_par_nom(produit produits[], int size){
    printf("\nTrier les produits par nom...\n");
    printf("\n1. A -- Z\n");
    printf("\n2. Z -- A\n");
    int choix;
    scanf("%d", &choix);
    switch(choix){
        case 1:
            for(int i = 0; i < size - 1; i++){
                for(int j = i + 1; j < size; j++){
                    if(strcmp(produits[i].nom, produits[j].nom) > 0){
                        produit temp = produits[i];
                        produits[i] = produits[j];
                        produits[j] = temp;
                    }
                }
            }
            break;
        case 2:
            for(int i = 0; i < size - 1; i++){
                for(int j = i + 1; j < size; j++){
                    if(strcmp(produits[i].nom, produits[j].nom) < 0){
                        produit temp = produits[i];
                        produits[i] = produits[j];
                        produits[j] = temp;
                    }
                }
            }
            break;
        default:
            printf("\nChoix invalide.\n");
            break;
    }

    printf("\nProduits tries par nom avec succes!\n");
}
    void effectuer_achat(client *c, produit *p, int quantite, achat historique[], int *achats){
        printf("\n--Effectuer un achat--\n");
        printf("\nProduit selectionne: %s, Prix: %.2f MAD, Stock disponible: %d\n", p->nom, p->prix, p->stock);
        if(quantite > 0 && quantite <= p->stock){
            float total = p->prix * quantite;
            printf("Total a payer: %.2f MAD\n", total);
            printf("Continuer l'achat? \n 1. Oui \n 2. Non\n");
            int confirmation;
            scanf("%d", &confirmation);
            if(confirmation == 1){
                if(c->solde >= total){
                    c->solde -= total;
                    p->stock -= quantite;
                    printf("Achat effectue avec succes! \n Produit Achete: %s \n Quantite: %d \n Total: %.2f MAD, \n Nouveau solde: %.2f MAD\n", p->nom, quantite, total, c->solde);
                    historique[*achats].produit_id = p->idproduit;
                    historique[*achats].quantite = quantite;
                    historique[*achats].total = total;
                    time_t t = time(NULL);
                    struct tm tm = *localtime(&t);
                    historique[*achats].date.jour = tm.tm_mday;
                    historique[*achats].date.mois = tm.tm_mon + 1;
                    historique[*achats].date.annee = tm.tm_year + 1900;
                    (*achats)++;
                }else{
                    printf("Solde insuffisant pour cet achat.\n");
                }
            }
        }else{
            printf("Quantite invalide ou stock insuffisant.\n");
        }
    }

void historique_achats(achat historique[], int achats){
    printf("\n--historique des achats--\n");
    for(int i = 0; i < achats; i++){
        printf("Achat %d: Produit ID: %d, Quantite: %d, Total: %.2f MAD, Date: %02d/%02d/%04d\n", 
               i+1, historique[i].produit_id, historique[i].quantite, 
               historique[i].total, historique[i].date.jour, 
               historique[i].date.mois, historique[i].date.annee);
    }
}
    

int main(){
client clients;
produit produits[] = {
    {1, "Laptop", "Electronique", 999.99, 10, "Ordinateur portable haute performance"},
    {2, "Smartphone", "Electronique", 499.99, 20, "Smartphone"},
    {3, "Tablette", "Electronique", 299.99, 15, "Tablette tactile"},
    {4, "Casque Audio", "Accessoires", 79.99, 30, "Casque audio sans fil"},
    {5, "Imprimante", "Bureau", 150.00, 5, "Imprimante laser haute vitesse"}
};
achat historique[100];
int achats = 0;
int count = 0;
    int choix;
    int choix_produit;
    int choix_profil;
    int choix_solde;
    int choix_statistiques;
    int choix_achat;
    int quantite;
    int choix_tri;


do{
printf("\n=== SYSTME D'ACHAT CLIENT ===\n");
printf("1. Gestion du profil client\n");
printf("2. Gestion du solde virtuel\n");
printf("3. Consultation des produits\n");
printf("4. Effectuer un achat\n");
printf("5. Mes statistiques\n");
printf("0. Quitter l'application\n");
printf("\nEntrez votre choix: ");
scanf("%d", &choix);
switch(choix){
    case 1:
        printf("\n--Gestion du profil client--\n");
        printf("1. Creer un nouveau profil\n");
        printf("2. Modifier mon profil \n");
        printf("3. consulter mon profil\n");
        printf("0. Retour au menu principal\n");
        printf("\nEntrez votre choix: ");
        scanf("%d", &choix_profil);
        switch(choix_profil){
            case 1:
                creer_profil(&clients);
                break;
            case 2:
                modifier_profil(&clients);
                break;
            case 3:
                consulter_profil(&clients);
                break;
            case 0:
                break;
        }
        break;
    case 2:
        printf("--Gestion du solde virtuel--\n");
        printf("1. Consulter le solde\n");
        printf("2. depot d'argent\n");
        printf("0. Retour au menu principal\n");
        printf("\nEntrez votre choix: ");
        scanf("%d", &choix_solde);
        switch(choix_solde){
            case 1:
                consulter_solde(&clients);
                break;
            case 2:{
                float montant;
                printf("\nEntrez le montant a deposer: ");
                scanf("%f", &montant);
                depot_argent(&clients, montant);
            }
                 break;
            case 0:
                break;
        }
        break;
    case 3:
        printf("\n--Consultation des produits--\n");
        printf("1. Afficher tous les produits\n");
        printf("2. Rechercher un produit\n");
        printf("3. trier les produits par :\n");
        printf("0. Retour au menu principal\n");
        printf("\nEntrez votre choix: ");
        scanf("%d", &choix_produit);
    switch(choix_produit){
        case 1:{
                afficher_produits(produits, 5);
            }
                break;
            
        case 2:{
             char nom[50], categorie[50];
             int choix_recherche;
            printf("1. Rechercher par nom\n");
            printf("2. Rechercher par categorie\n");
            printf("Entrez votre choix: ");
            scanf("%d", &choix_recherche);
                if(choix_recherche == 1){
                    printf("Entrez le nom du produit a rechercher: ");
                    scanf("%s", nom);
                    rechercher_produit(produits, 5, nom);
                }else if(choix_recherche == 2){
                    printf("Entrez la categorie du produit a rechercher: ");
                    scanf("%s", categorie);
                    rechercher_categorie(produits, 5, categorie);
                }
            }
                break;
        case 3:
            
            printf("1. Trier par prix\n"); 
            printf("2. Trier par nom\n");
            printf("Entrez votre choix: ");
            scanf("%d", &choix_tri);
            if(choix_tri == 1){
            trier_produits_par_prix(produits, 5);
            afficher_produits(produits, 5);
            }else if(choix_tri == 2){
              trier_produits_par_nom(produits, 5);
              afficher_produits(produits, 5);
                    }
        
                break;
            case 0:
            
                break;            
    }
    break;
    case 4: 
        printf("\n--Effectuer un achat--\n");
        printf("Selectionnez le produit a acheter :\n");
        afficher_produits(produits, 5);
        printf("\nEntrez l'ID du produit: ");
        scanf("%d", &choix_achat);
        printf("\nEntrez la quantite: ");
        scanf("%d", &quantite);
        effectuer_achat(&clients, &produits[choix_achat - 1], quantite, historique, &achats);
    
        break;
    case 5:
        printf("\n--Mes statistiques--\n");
        printf("1. Historique des achats\n");
        historique_achats(historique, achats);

        printf("0. Retour au menu principal\n");
        scanf("%d", &choix_statistiques);
        break;
    case 0:
        printf("\nAu revoir \n");
        break;
    default:
        printf("Choix invalide. Veuillez reessayer.\n");
        break;
        }
}while(choix != 0);
    return 0;
}





