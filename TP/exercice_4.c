#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void initialiser(int *cailloux, int *premier_joueur) {
    printf("Avec combien de cailloux allons nous jouer ? ");
    scanf("%d", cailloux);

    printf("Qui commence la partie ? (0 - Humain | 1 - Machine) : ");
    scanf("%d", premier_joueur);
}

void utilisateur_joue(int *cailloux) {
    int pris;
    do {
        printf("Combien de cailloux voulez-vous retirer ? ");
        scanf("%d", &pris);
        if (pris < 1 || pris > 3 || pris > *cailloux) {
            printf("Coup invalide. Choisissez entre 1 et 3 cailloux (et pas plus qu'il n'en reste) :\n");
        }
    } while (pris < 1 || pris > 3 || pris > *cailloux);

    *cailloux -= pris;
}

void machine_joue(int *cailloux) {
    int pris = (rand() % 3) + 1;
    
    if (pris > *cailloux) {
        pris = *cailloux;
    }
    
    printf("Tour de la machine. Elle retire %d cailloux.\n", pris);
    *cailloux -= pris;
}

int main() {
    int cailloux;
    int joueur_actuel;

    srand(time(NULL));

    initialiser(&cailloux, &joueur_actuel);

    while (cailloux > 0) {
        printf("Il reste %d cailloux.\n", cailloux);

        if (joueur_actuel == 0) {
            utilisateur_joue(&cailloux);
            if (cailloux == 0) {
                printf("L'humain a pris le dernier caillou et a perdu !\n");
            }
            joueur_actuel = 1;
        } else {
            machine_joue(&cailloux);
            if (cailloux == 0) {
                printf("La machine a pris le dernier caillou et a perdu !\n");
            }
            joueur_actuel = 0;
        }
    }

    return 0;
}