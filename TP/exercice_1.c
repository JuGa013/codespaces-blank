#include <stdio.h>

void division(int a, int b, int *quotient, int *reste) {
    *quotient = a / b;
    *reste = a % b;
}

int main() {
    int a, b;
    int quotient, reste;

    printf("Saisissez a : ");
    scanf("%d", &a);
    
    printf("Saisissez b : ");
    scanf("%d", &b);

    division(a, b, &quotient, &reste);
    printf("La partie entière est %d\n", quotient);
    printf("Le reste est %d\n", reste);

    return 0;
}