#include <stdio.h>

int somaNaturais(int n) {
    if (n == 0) {
        return 0;
    }
    return n + somaNaturais(n - 1);
}

int main() {
    int n;
    char resp;

    do {
        printf("Introduza o valor de N: ");
        scanf("%d", &n);

        if (n < 0) {
            printf("Valor invalido.\n");
        } else {
            printf("Soma = %d\n", somaNaturais(n));
        }

        printf("Deseja efetuar outro calculo (S/N)? ");
        scanf(" %c", &resp);
    } while (resp == 'S' || resp == 's');

    return 0;
}