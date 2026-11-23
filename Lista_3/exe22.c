#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int chave;
    char informacao[100];
    char data[11];
} Registro;

int main() {
    FILE *fonte = fopen("FONTE", "rb");
    if (fonte == NULL) {
        return 1;
    }

    FILE *fontenova = fopen("FONTENOVA", "wb");
    if (fontenova == NULL) {
        fclose(fonte);
        return 1;
    }

    Registro r;
    while (fread(&r, sizeof(Registro), 1, fonte) == 1) {
        fwrite(&r, sizeof(Registro), 1, fontenova);
    }

    fclose(fonte);
    fclose(fontenova);

    return 0;
}