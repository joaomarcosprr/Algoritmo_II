#include <stdio.h>

int buscaBinaria(int v[], int esq, int dir, int valor) {
    int meio;

    if (esq > dir) {
        return -1;
    }

    meio = (esq + dir) / 2;

    if (v[meio] == valor) {
        return meio;
    }

    if (valor < v[meio]) {
        return buscaBinaria(v, esq, meio - 1, valor);
    }

    return buscaBinaria(v, meio + 1, dir, valor);
}

int main() {
    int v[100], n, i, valor, pos;
    char resp;

    do {
        printf("Digite o tamanho do vetor (max 100): ");
        scanf("%d", &n);

        if (n <= 0 || n > 100) {
            printf("Tamanho invalido.\n");
        } else {
            printf("Digite os %d elementos em ordem crescente:\n", n);
            for (i = 0; i < n; i++) {
                printf("Elemento %d: ", i + 1);
                scanf("%d", &v[i]);
            }

            printf("Digite o valor a ser pesquisado: ");
            scanf("%d", &valor);

            pos = buscaBinaria(v, 0, n - 1, valor);

            if (pos != -1) {
                printf("Valor encontrado na posicao (indice) %d.\n", pos);
            } else {
                printf("Valor nao encontrado no vetor.\n");
            }
        }

        printf("Deseja realizar outra pesquisa (S/N)? ");
        scanf(" %c", &resp);
    } while (resp == 'S' || resp == 's');

    return 0;
}