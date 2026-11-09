#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *origem = fopen("dados.bin", "rb");
    if (origem == NULL) {
        return 1;
    }

    FILE *destino = fopen("dados_sem_zeros.bin", "wb");
    if (destino == NULL) {
        fclose(origem);
        return 1;
    }

    int numero;
    while (fread(&numero, sizeof(int), 1, origem) == 1) {
        if (numero != 0) {
            fwrite(&numero, sizeof(int), 1, destino);
        }
    }

    fclose(origem);
    fclose(destino);
    return 0;
}