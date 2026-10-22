#include <stdio.h>

int main() {
    int annees_permis;
    int est_suspendu;
    int a_autorisation;

    printf("Entrez le nombre d'années de permis de l'accompagnateur : ");
    scanf("%d", &annees_permis);

    printf("Le permis a-t-il dejà été suspendu ? (0 = Non, 1 = Oui) : ");
    scanf("%d", &est_suspendu);

    printf("A-t-il l'autorisation de l'assurance ? (0 = Non, 1 = Oui) : ");
    scanf("%d", &a_autorisation);

    if (annees_permis >= 5 && est_suspendu == 0 && a_autorisation == 1) {
        printf("\nResultat : La personne est un accompagnateur valide.\n");
    } else {
        printf("\nResultat : La personne n'est PAS un accompagnateur valide.\n");
    }

    return 0;
}