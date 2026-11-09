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
    int inicio_frase = 1;

    while ((ch = fgetc(arq)) != EOF) {
        if (isalpha(ch)) {
            if (inicio_frase) {
                putchar(toupper(ch));
                inicio_frase = 0;
            } else {
                putchar(tolower(ch));
            }
        } else {
            putchar(ch);
            if (ch == '.' || ch == '!' || ch == '?' || ch == "\0") {
                inicio_frase = 1;
            }
        }
    }

    fclose(arq);
    return 0;
}