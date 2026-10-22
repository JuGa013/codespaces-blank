#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void localisation(char pays[]) {
    printf("Entrez le pays depuis lequel la commande est passée : ");
    scanf("%s", pays);
}

// Nombre random entre 1 et 100 utilisant le timestamp
int calcul_score_risque() {
    srand(time(NULL));
    int randomNumber = (rand() % 100) + 1;

    printf("Score risque : %d \n", randomNumber);

    return randomNumber;
}

int main() {
    float montant_achat;
    char pays_achat[50];
    int score_risque;

    printf("Entrez le montant de l'achat : ");
    scanf("%f", &montant_achat);

    localisation(pays_achat);
    score_risque = calcul_score_risque();

    if (montant_achat > 1000.0 || strcmp(pays_achat, "France") != 0 || score_risque > 80) {
        printf("ALERTE : Le système anti-fraude 3D Secure est déclenché !\n");
    }

    // inversion De Morgan
    // if (montant_achat <= 1000.0 && strcmp(pays_achat, "France") == 0 && score_risque <= 80) {
    //     printf("Pas de déclenchement du 3D Secure.\n");
    // }

    return 0;
}