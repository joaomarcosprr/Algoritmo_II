#include <stdio.h>
#define TAM 5

int main() {
    FILE *arquivo = fopen("dados.bin", "rb");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return 1;
    }

    int num;
    int i = 1;

    printf("Lendo valores do arquivo:\n");
    while (fread(&num, sizeof(int), 1, arquivo) == 1) {
        printf("Valor %d: %d\n", i, num);
        i++;
    }

    fclose(arquivo);
    return 0;
}