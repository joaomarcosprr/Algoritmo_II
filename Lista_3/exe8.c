#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nome[50];
    int idade;
    float altura;
} Pessoa;

int main() {
    FILE *arq = fopen("pessoas.bin", "rb");
    if (arq == NULL) {
        return 1;
    }

    Pessoa pessoas[100];
    int total = 0;

    while (fread(&pessoas[total], sizeof(Pessoa), 1, arq) == 1) {
        total++;
    }
    fclose(arq);

    arq = fopen("pessoas.bin", "wb");
    if (arq == NULL) {
        return 1;
    }

    for (int i = 0; i < total; i++) {
        if (i != 1) {
            fwrite(&pessoas[i], sizeof(Pessoa), 1, arq);
        }
    }

    fclose(arq);
    return 0;
}