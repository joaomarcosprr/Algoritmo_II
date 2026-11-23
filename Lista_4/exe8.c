#include <stdio.h>

int main() {
    FILE *arq;
    int vet[10];
    int bits[32];
    int i, j, num;

    for (i = 0; i < 10; i++) {
        printf("Digite o %do numero: ", i + 1);
        scanf("%d", &vet[i]);
    }

    arq = fopen("binarios.txt", "w");
    if (arq == NULL) {
        printf("Erro ao criar o arquivo binarios.txt\n");
        return 1;
    }

    for (i = 0; i < 10; i++) {
        num = vet[i];
        if (num == 0) {
            fprintf(arq, "0");
        } else {
            if (num < 0) {
                fprintf(arq, "-");
                num = -num;
            }
            j = 0;
            while (num > 0) {
                bits[j] = num % 2;
                num = num / 2;
                j++;
            }
            while (j > 0) {
                j--;
                fprintf(arq, "%d", bits[j]);
            }
        }
        fprintf(arq, "\n");
    }

    fclose(arq);

    return 0;
}