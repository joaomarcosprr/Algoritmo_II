#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define TAM 100

int main() {
    int a, test, cont = 0;
    char frase[TAM];

    printf("Digite uma frase: ");
    fgets(frase, sizeof(frase), stdin);

    frase[strcspn(frase, "\n")] = '\0';
    a = strlen(frase);
    for (int i = 0; frase[i] != '\0'; i++) {
        frase[i] = tolower((unsigned char)frase[i]);
    }

    for (int j = 0; j < a; j++) {
        if (frase[j] == 'a' || frase[j] == 'e' || frase[j] == 'i' || frase[j] == 'o' || frase[j] == 'u') {
            cont++;
        }
    }

    printf("\nFrase tem %d vogais\n", cont);

    return 0;
}