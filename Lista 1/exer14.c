#include <stdio.h>
#include <string.h>

#define TAM 200

void mostrar_palavras(const char *frase) {
    char copia[TAM];
    
    strncpy(copia, frase, TAM - 1);
    copia[TAM - 1] = '\0';

    char *palavra = strtok(copia, " \t\n");

    printf("\nPalavras encontradas:\n");
    int cont = 1;
    while (palavra != NULL) {
        printf("%d: %s\n", cont, palavra);
        palavra = strtok(NULL, " \t\n");
        cont++;
    }
}

int main() {
    char frase[TAM];
    char opcao;

    do {
        printf("Digite uma frase: ");
        fgets(frase, sizeof(frase), stdin);
        frase[strcspn(frase, "\n")] = '\0';

        mostrar_palavras(frase);

        printf("\nDeseja testar outra frase? (S/N): ");
        scanf(" %c", &opcao);

        int c;
        while ((c = getchar()) != '\n' && c != EOF);
        printf("\n");

    } while (opcao == 'S' || opcao == 's');

    return 0;
}