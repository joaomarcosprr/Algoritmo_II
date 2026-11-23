#include <stdio.h>

int Func(int n) {
    int soma = 0;
    int i;

    for (i = 1; i <= n; i++) {
        soma += i;
    }

    return soma;
}

int main() {
    int n;

    printf("Digite um numero inteiro nao negativo: ");
    scanf("%d", &n);

    if (n >= 0) {
        printf("Resultado: %d\n", Func(n));
    }

    return 0;
}