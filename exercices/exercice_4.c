#include <stdio.h>

int main() {
    int nombre_visiteurs;
    int i;
    int age;
    int est_etudiant; 
    
    float prix_total = 0.0;
    int nb_cadeaux = 0;
    float prix_entree = 0.0;

    printf("Combien de visiteurs y a-t-il dans le groupe ? : ");
    scanf("%d", &nombre_visiteurs);

    for (i = 1; i <= nombre_visiteurs; i++) {      
        printf("Entrez l'age du visiteur %d : ", i);
        scanf("%d", &age);

        printf("Le visiteur est-il etudiant ? (0 = Non, 1 = Oui) : ");
        scanf("%d", &est_etudiant);

        prix_entree = 12.0;

        if (age < 12) {
            prix_entree = 0.0;
            nb_cadeaux = nb_cadeaux + 1; 
        } 
        else if (age > 65) {
            prix_entree = 0.0;
        } 
        else if (est_etudiant == 1) {
            prix_entree = 5.0;
        }

        prix_total = prix_total + prix_entree;
    }

    printf("Prix total des entrees : %.2f EUR\n", prix_total);
    printf("Nombre de cadeaux à distribuer : %d\n", nb_cadeaux);

    return 0;
}