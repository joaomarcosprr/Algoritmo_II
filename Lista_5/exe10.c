#include <stdio.h>

long int combinacao(int n, int p) {
    if (p > n || n < 0 || p < 0) {
        return 0;
    }
    if (p == 0 || p == n) {
        return 1;
    }
    return combinacao(n - 1, p) + combinacao(n - 1, p - 1);
}

int main() {
    int n, p;
    char resp;

    do {
        printf("Digite o valor de n: ");
        scanf("%d", &n);
        printf("Digite o valor de p: ");
        scanf("%d", &p);

        if (n < 0 || p < 0) {
            printf("Valores invalidos.\n");
        } else {
            printf("C(%d, %d) = %ld\n", n, p, combinacao(n, p));
        }

        printf("Deseja realizar outro calculo (S/N)? ");
        scanf(" %c", &resp);
    } while (resp == 'S' || resp == 's');

    return 0;
}