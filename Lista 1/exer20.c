#include <stdio.h>
#include <string.h>

#define TAM 200

char *remover_espacos(char *str) {
    int i = 0, j = 0;

    while (str[i] != '\0') {
        if (str[i] != ' ') {
            str[j] = str[i];
            j++;
        }
        i++;
    }
    str[j] = '\0';

    return str;
}

int main() {
    char frase[TAM];

    printf("Digite uma frase: ");
    fgets(frase, sizeof(frase), stdin);
    frase[strcspn(frase, "\n")] = '\0';

    remover_espacos(frase);

    printf("String sem espacos: %s\n", frase);

    return 0;
}