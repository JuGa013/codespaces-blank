#include <stdio.h>
#include <unistd.h>

#define LIMITE 90

int releve_vitesse() {
    int vitesse;
    printf("\nReleve de vitesse actuel (en km/h) : ");
    scanf("%d", &vitesse);
    return vitesse;
}

int main() {
    int vitesse_actuelle;

    printf("=== Système de gestion du limitateur de vitesse (90 km/h) ===\n");
    printf("Entrez 0 pour arrêter la simulation.\n");

    while (1) {
        vitesse_actuelle = releve_vitesse();

        if (vitesse_actuelle == 0) {
            printf("Arret du véhicule / Fin de la simulation.\n");
            break;
        }

        if (vitesse_actuelle > LIMITE) {
            printf("/!\\ ALERTE TABLEAU DE BORD : Vitesse limite de 90km/h dépassée ! /!\\ \n");

            while (vitesse_actuelle > LIMITE) {
                printf("ALARME SONORE : BIP ! BIP !\n");
                sleep(5);

                vitesse_actuelle = RELEVE_VITESSE();
                
                if (vitesse_actuelle <= LIMITE) {
                    printf("Retour sous la limite de 90 km/h. Arr6et de l'alarme et disparition du message.\n");
                }
            }
        } else {
            sleep(5);
        }
    }

    return 0;
}
