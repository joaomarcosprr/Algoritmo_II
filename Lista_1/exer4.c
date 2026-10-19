#include <stdio.h>
#include <string.h>

#define TAM 100

int main() {
    int a, test, cont = 0;
    char frase[TAM];

    do {
        test = 0; 

        printf("Digite um numero binario: ");
        fgets(frase, sizeof(frase), stdin);

        frase[strcspn(frase, "\n")] = '\0';
        a = strlen(frase);

        if (a == 0) {
            test = 1;
        } else {
            for (int j = 0; j < a; j++) {
                if (frase[j] != '0' && frase[j] != '1') {
                    test = 1;
                    break;
                }
            }
        }

        if (test) {
            printf("\nEsse numero nao contem apenas 0 e 1, escreva outro valor.\n\n");
        }

    } while (test);

    for (int j = 0; j < a; j++) {
        if (frase[j] == '1') {
            cont++;
        }
    }

    printf("\nO numero tem %d valores 1\n", cont);

    return 0;
}