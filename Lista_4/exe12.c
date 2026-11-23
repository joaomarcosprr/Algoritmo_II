#include <stdio.h>

int main() {
    FILE *entrada, *saida;
    int c;
    int em_palavra = 0;
    int comeca_vogal = 0;
    int total_palavras = 0;

    entrada = fopen("texto.txt", "r");
    if (entrada == NULL) {
        printf("Erro ao abrir o arquivo texto.txt\n");
        return 1;
    }

    saida = fopen("vogais.txt", "w");
    if (saida == NULL) {
        printf("Erro ao criar o arquivo vogais.txt\n");
        fclose(entrada);
        return 1;
    }

    while ((c = fgetc(entrada)) != EOF) {
        printf("%c", c);

        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
            if (em_palavra == 0) {
                em_palavra = 1;
                if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
                    c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
                    comeca_vogal = 1;
                    total_palavras++;
                    fputc(c, saida);
                } else {
                    comeca_vogal = 0;
                }
            } else {
                if (comeca_vogal == 1) {
                    fputc(c, saida);
                }
            }
        } else {
            if (em_palavra == 1) {
                if (comeca_vogal == 1) {
                    fputc('\n', saida);
                }
                em_palavra = 0;
                comeca_vogal = 0;
            }
        }
    }

    if (em_palavra == 1 && comeca_vogal == 1) {
        fputc('\n', saida);
    }

    fclose(entrada);
    fclose(saida);

    printf("\n\nNumero de palavras gravadas em vogais.txt: %d\n", total_palavras);

    return 0;
}