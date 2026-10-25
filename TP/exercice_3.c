#include <stdio.h>
#include <stdbool.h>

void afficher_tetes_pattes(int moutons, int dindons) {
    int tetes = moutons + dindons;
    int pattes = (moutons * 4) + (dindons * 2);
    printf("Si moutons = %d et dindons = %d alors pattes = %d * 4 + %d * 2 = %d et tetes = %d + %d = %d.\n",
           moutons, dindons, moutons, dindons, pattes, moutons, dindons, tetes);
}

void calculer_tetes_pattes(int moutons, int dindons, int *tetes, int *pattes) {
    *tetes = moutons + dindons;
    *pattes = (moutons * 4) + (dindons * 2);
}

bool verifie_declaration(int tetes, int pattes, const char **message_erreur) {
    int moutons, dindons;
    int tetes_verif, pattes_verif;

    if (pattes % 2 != 0) {
        *message_erreur = "Le nombre total de pattes doit etre pair.";
        return false;
    }
    if (pattes < tetes * 2) {
        *message_erreur = "Pas assez de pattes ! Même si tout etait dindons, il faudrait plus de pattes.";
        return false;
    }
    if (pattes > tetes * 4) {
        *message_erreur = "Trop de pattes ! Même si tout etait moutons, il ne pourrait pas y en avoir autant.";
        return false;
    }

    moutons = (pattes - (tetes * 2)) / 2;
    dindons = tetes - moutons;
    calculer_tetes_pattes(moutons, dindons, &tetes_verif, &pattes_verif);

    bool calcul_valide = tetes_verif == tetes && pattes_verif == pattes;

    if (!calcul_valide) {
        *message_erreur = "Le nombre de pattes et de tetes est incohérent";
    }

    return calcul_valide;
}

int main() {
    int moutons, dindons;
    int tetes_declarees, pattes_declarees;
    const char *message_erreur = NULL;

    printf("Combien de tetes souhaitez vous déclarer ? ");
    scanf("%d", &tetes_declarees);

    printf("Combien de pattes souhaitez vous déclarer ? ");
    scanf("%d", &pattes_declarees);

    if (verifie_declaration(tetes_declarees, pattes_declarees, &message_erreur) == false) {
        printf("La déclaration du fermier est INCORRECTE !\n");
        printf("Raison : %s\n", message_erreur);
    } else {
        printf("La déclaration du fermier est CORRECTE !\n");

        moutons = (pattes_declarees - (tetes_declarees * 2)) / 2;
        dindons = tetes_declarees - moutons;

        afficher_tetes_pattes(moutons, dindons);
    }

    return 0;
}