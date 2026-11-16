#include <stdio.h>

int fibonacci_iterativo(int n) {
    int a = 0, b = 1, c, i;

    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }

    for (i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }

    return b;
}

int fibonacci_recursivo(int n) {
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }

    return fibonacci_recursivo(n - 1) + fibonacci_recursivo(n - 2);
}

int main() {
    int n;

    printf("Digite o valor de n: ");
    scanf("%d", &n);

    if (n < 0) {
        printf("Valor invalido\n");
        return 1;
    }

    printf("Iterativo: %d\n", fibonacci_iterativo(n));
    printf("Recursivo: %d\n", fibonacci_recursivo(n));

    return 0;
}