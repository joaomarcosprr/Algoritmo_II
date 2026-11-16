#include <stdio.h>

int F_a(int i) {
    int soma = 1;
    int k;

    for (k = 2; k <= i; k++) {
        soma = soma + k;
    }

    return soma;
}

int F_b(int i) {
    int a = 0, b = 1, c, k;

    if (i == 0) {
        return 0;
    }
    if (i == 1) {
        return 1;
    }

    for (k = 2; k <= i; k++) {
        c = a + b;
        a = b;
        b = c;
    }

    return b;
}

int main() {
    int n;

    printf("Digite um valor inteiro para i: ");
    scanf("%d", &n);

    printf("Resultado a): %d\n", F_a(n));
    if (n >= 0) {
        printf("Resultado b): %d\n", F_b(n));
    }

    return 0;
}