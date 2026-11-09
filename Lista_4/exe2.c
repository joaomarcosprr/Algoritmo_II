#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int e_vogal(char c) {
    c = tolower(c);
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

int e_consoante(char c) {
    c = tolower(c);
    return (isalpha(c) && !e_vogal(c));
}

int main() {
    FILE *arq = fopen("texto.txt", "r");
    if (arq == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    int ch;
    int vogais = 0;
    int consoantes = 0;

    while ((ch = fgetc(arq)) != EOF) {
        if (e_vogal(ch)) {
            vogais++;
        } else if (e_consoante(ch)) {
            consoantes++;
        }
    }

    fclose(arq);

    printf("Vogais: %d\n", vogais);
    printf("Consoantes: %d\n", consoantes);

    return 0;
}