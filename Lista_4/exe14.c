#include <stdio.h>

int main() {
    FILE *entrada, *saida;
    int linhas, colunas, qtd_anuladas;
    int i, j, lin_anulada, col_anulada;

    entrada = fopen("matriz.txt", "r");
    if (entrada == NULL) {
        printf("Erro ao abrir o arquivo matriz.txt\n");
        return 1;
    }

    fscanf(entrada, "%d %d %d", &linhas, &colunas, &qtd_anuladas);

    int matriz[linhas][colunas];

    for (i = 0; i < linhas; i++) {
        for (j = 0; j < colunas; j++) {
            matriz[i][j] = 1;
        }
    }

    for (i = 0; i < qtd_anuladas; i++) {
        fscanf(entrada, "%d %d", &lin_anulada, &col_anulada);
        if (lin_anulada >= 0 && lin_anulada < linhas && col_anulada >= 0 && col_anulada < colunas) {
            matriz[lin_anulada][col_anulada] = 0;
        }
    }

    fclose(entrada);

    saida = fopen("matriz saida.txt", "w");
    if (saida == NULL) {
        printf("Erro ao criar o arquivo matriz saida.txt\n");
        return 1;
    }

    for (i = 0; i < linhas; i++) {
        for (j = 0; j < colunas; j++) {
            fprintf(saida, "%d", matriz[i][j]);
            if (j < colunas - 1) {
                fprintf(saida, " ");
            }
        }
        fprintf(saida, "\n");
    }

    fclose(saida);

    return 0;
}