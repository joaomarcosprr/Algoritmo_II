#include <stdio.h>
#include <string.h>

void trocar(char *a, char *b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

void gerarPermutacoes(char str[], int k, int n) {
    int i;

    if (k == n - 1) {
        printf("%s\n", str);
        return;
    }

    for (i = k; i < n; i++) {
        trocar(&str[k], &str[i]);
        gerarPermutacoes(str, k + 1, n);
        trocar(&str[k], &str[i]);
    }
}

int main() {
    char str[100];
    int n;

    printf("Digite o conjunto de simbolos (ex: ABC): ");
    scanf("%s", str);

    n = strlen(str);
    if (n > 0) {
        gerarPermutacoes(str, 0, n);
    }

    return 0;
}