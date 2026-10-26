#include <stdio.h>

int main() {
    FILE *arquivo = fopen("dados.bin", "rb");

    if (arquivo != NULL) {
        printf("O arquivo existe!\n");
        fclose(arquivo);
    } else {
        printf("Arquivo nao encontrado!\n");
    }

    return 0;
}