#include <stdio.h>

int fatorial_iterativo(int n) {
    int res = 1;
    int i;
    for (i = 2; i <= n; i++) {
        res = res * i;
    }
    return res;
}

int fatorial_recursivo(int n) {
    if (n <= 1) {
        return 1;
    }
    return n * fatorial_recursivo(n - 1);
}

int produto_iterativo(int a, int b) {
    int res = 0;
    int i;
    for (i = 0; i < b; i++) {
        res = res + a;
    }
    return res;
}

int produto_recursivo(int a, int b) {
    if (b == 0) {
        return 0;
    }
    return a + produto_recursivo(a, b - 1);
}

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
    printf("a) 6! -> Iterativo: %d | Recursivo: %d\n", fatorial_iterativo(6), fatorial_recursivo(6));
    printf("b) 9! -> Iterativo: %d | Recursivo: %d\n", fatorial_iterativo(9), fatorial_recursivo(9));
    printf("c) 50*3 -> Iterativo: %d | Recursivo: %d\n", produto_iterativo(50, 3), produto_recursivo(50, 3));
    printf("d) 5*4 -> Iterativo: %d | Recursivo: %d\n", produto_iterativo(5, 4), produto_recursivo(5, 4));
    printf("e) F(10) -> Iterativo: %d | Recursivo: %d\n", fibonacci_iterativo(10), fibonacci_recursivo(10));
    printf("f) F(11) -> Iterativo: %d | Recursivo: %d\n", fibonacci_iterativo(11), fibonacci_recursivo(11));

    return 0;
}