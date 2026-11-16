#include <stdio.h>
#include <time.h>

long long fibo_iterativo(int n, int *adicoes) {
    long long a = 0, b = 1, c;
    int i;

    *adicoes = 0;

    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }

    for (i = 2; i <= n; i++) {
        c = a + b;
        (*adicoes)++;
        a = b;
        b = c;
    }

    return b;
}

long long fibo_recursivo(int n, int *adicoes) {
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }

    (*adicoes)++;
    return fibo_recursivo(n - 1, adicoes) + fibo_recursivo(n - 2, adicoes);
}

int main() {
    int n, adicoes_iter, adicoes_rec;
    int testes_tempo[] = {10, 20, 30, 35, 40, 42};
    int i;
    clock_t inicio, fim;
    double tempo_iter, tempo_rec;

    printf("--- ITEM A: TEMPO DE EXECUCAO ---\n");
    for (i = 0; i < 6; i++) {
        n = testes_tempo[i];

        inicio = clock();
        fibo_iterativo(n, &adicoes_iter);
        fim = clock();
        tempo_iter = (double)(fim - inicio) / CLOCKS_PER_SEC;

        inicio = clock();
        fibo_recursivo(n, &adicoes_rec);
        fim = clock();
        tempo_rec = (double)(fim - inicio) / CLOCKS_PER_SEC;

        printf("n = %2d | Iterativo: %.6f s | Recursivo: %.6f s\n", n, tempo_iter, tempo_rec);
    }

    printf("\n--- ITEM B: NUMERO DE ADICOES (0 <= n <= 10) ---\n");
    for (n = 0; n <= 10; n++) {
        adicoes_rec = 0;
        fibo_iterativo(n, &adicoes_iter);
        fibo_recursivo(n, &adicoes_rec);

        printf("n = %2d | Iterativo: %2d adicoes | Recursivo: %2d adicoes\n", n, adicoes_iter, adicoes_rec);
    }

    return 0;
}