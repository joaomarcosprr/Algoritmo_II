#include <stdio.h>

int Digitos(int N) {
    if (N >= -9 && N <= 9) {
        return 1;
    }
    return 1 + Digitos(N / 10);
}

int main() {
    int n;

    printf("Digite um numero inteiro: ");
    scanf("%d", &n);

    printf("Quantidade de digitos: %d\n", Digitos(n));

    return 0;
}