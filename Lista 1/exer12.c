#include <stdio.h>
#include <string.h>

#define TAM 200

int contar_ocorrencias(const char *frase, const char *palavra) {
    int cont = 0;
    int tam_frase = strlen(frase);
    int tam_palavra = strlen(palavra);

    if (tam_palavra == 0 || tam_palavra > tam_frase) {
        return 0;
    }

    for (int i = 0; i <= tam_frase - tam_palavra; i++) {
        if (strncmp(&frase[i], palavra, tam_palavra) == 0) {
            cont++;
        }
    }

    return cont;
}

int main() {
    char frase[TAM];
    char palavra[TAM];
    char opcao;

    do {
        printf("Digite a frase: ");
        fgets(frase, sizeof(frase), stdin);
        frase[strcspn(frase, "\n")] = '\0';

        printf("Digite a palavra a ser buscada: ");
        fgets(palavra, sizeof(palavra), stdin);
        palavra[strcspn(palavra, "\n")] = '\0';

        int total = contar_ocorrencias(frase, palavra);
        printf("A palavra \"%s\" ocorre %d vez(es) na frase.\n", palavra, total);

        printf("\nDeseja testar outra frase? (S/N): ");
        scanf(" %c", &opcao);

        int c;
        while ((c = getchar()) != '\n' && c != EOF);
        printf("\n");

    } while (opcao == 'S' || opcao == 's');

    return 0;
}