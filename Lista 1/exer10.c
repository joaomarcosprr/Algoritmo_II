#include <stdio.h>
#include <string.h>

#define TAM 100

int main() {
    char frase[TAM];
    char l1, l2;

    printf("Digite uma frase: ");
    fgets(frase, sizeof(frase), stdin);

    frase[strcspn(frase, "\n")] = '\0';

    printf("Digite o caractere a ser substituido (L1): ");
    scanf(" %c", &l1);

    printf("Digite o novo caractere (L2): ");
    scanf(" %c", &l2);

    for (int i = 0; frase[i] != '\0'; i++) {
        if (frase[i] == l1) {
            frase[i] = l2;
        }
    }

    printf("\nString resultante: %s\n", frase);

    return 0;
}