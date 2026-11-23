#include <stdio.h>

int somaVetor(int v[], int n) {
    if (n == 0) {
        return 0;
    }
    return v[n - 1] + somaVetor(v, n - 1);
}

int main() {
    int v[100], n, i;
    char resp;

    do {
        printf("Digite o tamanho do vetor (max 100): ");
        scanf("%d", &n);

        if (n < 0 || n > 100) {
            printf("Tamanho invalido.\n");
        } else {
            for (i = 0; i < n; i++) {
                printf("Digite o elemento %d: ", i + 1);
                scanf("%d", &v[i]);
            }
            printf("Soma dos elementos = %d\n", somaVetor(v, n));
        }

        printf("Deseja realizar outro calculo (S/N)? ");
        scanf(" %c", &resp);
    } while (resp == 'S' || resp == 's');

    return 0;
}