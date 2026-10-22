#include <stdio.h>

int main() {
    int annees_permis;
    int est_suspendu;
    int a_autorisation;

    printf("Entrez le nombre d'annees de permis de l'accompagnateur : ");
    scanf("%d", &annees_permis);

    printf("Le permis a-t-il deja ete suspendu ? (0 = Non, 1 = Oui) : ");
    scanf("%d", &est_suspendu);

    printf("A-t-il l'autorisation de l'assurance ? (0 = Non, 1 = Oui) : ");
    scanf("%d", &a_autorisation);

    // 2. Vérification des conditions requises
    // - Au moins 5 ans de permis (annees_permis >= 5)
    // - Jamais suspendu (est_suspendu == 0)
    // - Autorisation de l'assurance obtenue (a_autorisation == 1)
    if (annees_permis >= 5 && est_suspendu == 0 && a_autorisation == 1) {
        printf("\nResultat : La personne est un accompagnateur VALIDE.\n");
    } else {
        printf("\nResultat : La personne n'est PAS un accompagnateur valide.\n");
    }

    return 0;
}