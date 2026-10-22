#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int date_du_jour() {
    char buffer[11];
    struct tm* to;
    time_t t;
    t = time(NULL);
    to = localtime(&t);
    strftime(buffer, sizeof(buffer), "%Y%m%d", to);

    int dateInt = atoi(buffer);

    return dateInt;
}

int est_premiere_semaine_decembre() {
    int aujourdhui = date_du_jour();

    int mois = (aujourdhui / 100) % 100;
    int jour = aujourdhui % 100;

    return (mois == 12 && jour >= 1 && jour <= 7);
}

void calcul_total(float montant_total, int promo_est_active) {
    float reduction = 0.0;
    float montant_final = montant_total;

    if (promo_est_active == 1
        && montant_total > 500.0
    ) {
        reduction = montant_total * 0.10; 
        montant_final = montant_total - reduction;
    }

    printf("Montant initial : %.2f EUR\n", montant_total);
    printf("Montant de la reduction : %.2f EUR\n", reduction);
    printf("Montant total paye : %.2f EUR\n", montant_final);
}

int main() {
    float prix_article;
    float montant_total = 0.0;
    int plafond_atteint = 0;

    int promo_est_active = est_premiere_semaine_decembre();

    printf("=== Saisie des articles (Entrez 0 pour terminer) ===\n\n");

    // Boucle de saisie des articles
    while (prix_article != 0) {
        printf("Prix de l'article : ");
        scanf("%f", &prix_article);

        if (prix_article > 0) {
            montant_total = montant_total + prix_article;

            if (promo_est_active == 1
                && plafond_atteint == 0 
                && montant_total > 500.0
            ) {
                printf("--> Bravo ! Vous avez atteint le plafond pour bénéficier des 10%% de réduction !\n");
                plafond_atteint = 1; 
            }
        }
    }

    calcul_total(montant_total, promo_est_active);

    return 0;
}