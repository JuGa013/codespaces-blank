#include <stdio.h>

float taux_vers_euro(int devise) {
    switch (devise) {
        case 2: // GBP
            return 0.85; 
        case 3: // USD
            return 1.12; 
        case 4: // JPY
            return 176.89; 
        default:
            return 1; // EURO
    }
}

float convertir_monnaie(float montant, int devise_depart, int devise_arrivee) {
    float taux_depart = taux_vers_euro(devise_depart);
    float taux_arrivee = taux_vers_euro(devise_arrivee);

    float montant_euros;
    float montant_final;

    montant_euros = montant / taux_depart;
    montant_final = montant_euros * taux_arrivee;

    return montant_final;
}

int main() {
    float montant_depart, resultat;
    int devise_depart, devise_arrivee;

    printf("=== CONVERTISSEUR DE MONNAIE ===\n");
    printf("1. EUR (Euro)\n");
    printf("2. GBP (Livre sterling)\n");
    printf("3. USD (Dollar americain)\n");
    printf("4. JPY (Yen japonais)\n\n");

    printf("Choisissez la devise de départ : ");
    scanf("%d", &devise_depart);

    printf("Entrez le montant à convertir : ");
    scanf("%f", &montant_depart);

    printf("Choisissez la devise d'arrivée : ");
    scanf("%d", &devise_arrivee);

    resultat = convertir_monnaie(montant_depart, devise_depart, devise_arrivee);

    printf("\n--- Resultat ---\n");
    printf("Le montant converti est : %.2f\n", resultat);

    return 0;
}