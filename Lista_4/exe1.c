#include <stdio.h>
#include <stdlib.h>

int main() {
    char nome_arquivo[100];

    printf("Digite o nome do arquivo: ");
    if (scanf("%99s", nome_arquivo) != 1) {
        return 1;
    }

    FILE *arq = fopen(nome_arquivo, "r");
    if (arq == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    int ch;
    while ((ch = fgetc(arq)) != EOF) {
        putchar(ch);
    }

    fclose(arq);
    return 0;
}