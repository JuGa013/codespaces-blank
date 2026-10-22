#include <stdio.h>
#include <unistd.h>

int RELEVE_VITESSE() {
    int vitesse;
    printf("\nReleve de vitesse actuel (en km/h) : ");
    scanf("%d", &vitesse);
    return vitesse;
}

int main() {
    int vitesse_actuelle;
    int limite = 90;

    printf("=== Système de gestion du limitateur de vitesse (90 km/h) ===\n");
    printf("Entrez 0 pour arrêter la simulation.\n");

    while (1) {
        vitesse_actuelle = RELEVE_VITESSE();

        if (vitesse_actuelle == 0) {
            printf("Arret du véhicule / Fin de la simulation.\n");
            break;
        }

        if (vitesse_actuelle > limite) {
            printf("/!\\ ALERTE TABLEAU DE BORD : Vitesse limite de 90km/h dépassée ! /!\\ \n");

            while (vitesse_actuelle > limite) {
                printf("ALARME SONORE : BIP ! BIP !\n");
                sleep(5);

                vitesse_actuelle = RELEVE_VITESSE();
                
                if (vitesse_actuelle <= limite) {
                    printf("Retour sous la limite de 90 km/h. Arr6et de l'alarme et disparition du message.\n");
                }
            }
        } else {
            sleep(5);
        }
    }

    return 0;
}