#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
    FILE *arq = fopen("texto.txt", "r");
    if (arq == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    int ch;
    int linhas = 0;
    int caracteres = 0;
    int palavras = 0;
    int em_palavra = 0;
    int ultimo_ch = '\n';

    while ((ch = fgetc(arq)) != EOF) {
        caracteres++;

        if (ch == '\n') {
            linhas++;
        }

        if (!isspace(ch)) {
            if (!em_palavra) {
                palavras++;
                em_palavra = 1;
            }
        } else {
            em_palavra = 0;
        }

        ultimo_ch = ch;
    }

    if (caracteres > 0 && ultimo_ch != '\n') {
        linhas++;
    }

    fclose(arq);

    printf("Linhas: %d\n", linhas);
    printf("Caracteres: %d\n", caracteres);
    printf("Palavras: %d\n", palavras);

    return 0;
}