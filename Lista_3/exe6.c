/**
#include <stdio.h>
#define TAM 5

int main() {
    FILE *arquivo = fopen("pessoas.bin", "rb");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return 1;
    }

    struct Pessoa p;
    int i = 1;

    printf("Lendo pessoas do arquivo:\n");
    while (fread(&p, sizeof(int), 1, arquivo) == 1) {
        printf("Nome: %s", p[i])
        i++;
    }

    fclose(arquivo);
    return 0;
}