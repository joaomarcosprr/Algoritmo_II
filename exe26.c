#include <stdio.h>

int termoSequenciaT(int n) {
    if (n == 1) {
        return 1;
    }
    return termoSequenciaT(n - 1) + 3;
}

int main() {
    int n, i;

    printf("Digite a quantidade de termos (n >= 1): ");
    scanf("%d", &n);

    if (n < 1) {
        printf("Valor invalido.\n");
    } else {
        printf("Sequencia T: ");
        for (i = 1; i <= n; i++) {
            printf("%d ", termoSequenciaT(i));
        }
        printf("\n");
    }

    return 0;
}