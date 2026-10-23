#include <stdio.h>
#include <string.h>

#define CONVERSION_KM_MILES 1.609344

double km_en_miles(double km) {
    return km / CONVERSION_KM_MILES;
}

double miles_en_km(double miles) {
    return miles * CONVERSION_KM_MILES;
}

void table_conversion() {
    printf("Miles\t  -  \tKm\n");
    for (int miles = 5; miles <= 30; miles += 5) {
        printf("%d\t    \t%.2f\n", miles, miles_en_km(miles));
    }
}

int main() {
    int choix;

    printf("Que voulez-vous faire ? (1 - Convertir une distance | 2 - Afficher la table de conversion\n");
    scanf("%d", &choix);

    if (choix == 1) {
        double distance, conversion;
        char unite;

        printf("Saisir la distance à convertir : ");
        scanf("%lf", &distance);

        printf("Dans quelle unité ? ('k' pour km / 'm' pour miles) : ");
        scanf(" %c", &unite);

        switch (unite) {
            case 'k':
            case 'K':
                conversion = km_en_miles(distance);
                break;
            case 'm':
            case 'M':
                conversion = miles_en_km(distance);
                break;
            default:
                printf("\nUnité non valide. Veuillez entrer 'k' ou 'm'.\n");
                break;
        }
        printf("Après conversion la distance est de %.2f \n", conversion);
    } else {
        table_conversion();
    }

    return 0;
}