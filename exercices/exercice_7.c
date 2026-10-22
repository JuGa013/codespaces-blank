#include <stdio.h>
#include <float.h>

int main() {
    int compteur_jours = 0;
    int continuer;
    
    float temperature, precipitation;
    float temp_max = -FLT_MAX; 
    float temp_min = FLT_MAX;
    float somme_temp = 0.0;
    float precipitations_globales = 0.0;
    float moyenne_temp = 0.0;

    do {
        compteur_jours++;
        printf("Jour %d\n", compteur_jours);
        
        printf("Température (en °C) : ");
        scanf("%f", &temperature);
        
        printf("Précipitations (en mm) : ");
        scanf("%f", &precipitation);

        if (temperature > temp_max) {
            temp_max = temperature;
        }
        if (temperature < temp_min) {
            temp_min = temperature;
        }

        somme_temp = somme_temp + temperature;
        precipitations_globales = precipitations_globales + precipitation;
        
        printf("Voulez-vous ajouter un autre jour ? (1 = Oui, 0 = Non) : ");
        scanf("%d", &continuer);
        printf("\n");

    } while (continuer == 1);

    moyenne_temp = somme_temp / compteur_jours;

    printf("Température la plus haute : %.2f °C\n", temp_max);
    printf("Température la plus basse : %.2f °C\n", temp_min);
    printf("Température moyenne       : %.2f °C\n", moyenne_temp);
    printf("Précipitations globales   : %.2f mm\n", precipitations_globales);

    return 0;
}