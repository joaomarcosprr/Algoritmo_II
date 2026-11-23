#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int numero_conta;
    char nome[100];
    float saldo;
} Conta;

typedef struct {
    int numero_conta;
    char tipo;
    float valor;
} Movimentacao;

int main() {
    FILE *f_anterior = fopen("contas_anterior.bin", "rb");
    FILE *f_mov = fopen("movimentacoes.bin", "rb");
    FILE *f_novas = fopen("contas_novas.bin", "rb");
    FILE *f_removidas = fopen("contas_removidas.bin", "rb");
    FILE *f_atual = fopen("contas_atualizadas.bin", "wb");

    if (f_atual == NULL) {
        if (f_anterior) fclose(f_anterior);
        if (f_mov) fclose(f_mov);
        if (f_novas) fclose(f_novas);
        if (f_removidas) fclose(f_removidas);
        return 1;
    }

    Conta *contas = NULL;
    int total_contas = 0;
    Conta c_temp;

    if (f_anterior != NULL) {
        while (fread(&c_temp, sizeof(Conta), 1, f_anterior) == 1) {
            contas = (Conta *)realloc(contas, (total_contas + 1) * sizeof(Conta));
            contas[total_contas] = c_temp;
            total_contas++;
        }
        fclose(f_anterior);
    }

    if (f_novas != NULL) {
        while (fread(&c_temp, sizeof(Conta), 1, f_novas) == 1) {
            contas = (Conta *)realloc(contas, (total_contas + 1) * sizeof(Conta));
            contas[total_contas] = c_temp;
            total_contas++;
        }
        fclose(f_novas);
    }

    int *removidas = NULL;
    int total_removidas = 0;
    int num_rem;

    if (f_removidas != NULL) {
        while (fread(&num_rem, sizeof(int), 1, f_removidas) == 1) {
            removidas = (int *)realloc(removidas, (total_removidas + 1) * sizeof(int));
            removidas[total_removidas] = num_rem;
            total_removidas++;
        }
        fclose(f_removidas);
    }

    Movimentacao *movs = NULL;
    int total_movs = 0;
    Movimentacao m_temp;

    if (f_mov != NULL) {
        while (fread(&m_temp, sizeof(Movimentacao), 1, f_mov) == 1) {
            movs = (Movimentacao *)realloc(movs, (total_movs + 1) * sizeof(Movimentacao));
            movs[total_movs] = m_temp;
            total_movs++;
        }
        fclose(f_mov);
    }

    for (int i = 0; i < total_contas; i++) {
        int foi_removida = 0;
        for (int j = 0; j < total_removidas; j++) {
            if (contas[i].numero_conta == removidas[j]) {
                foi_removida = 1;
                break;
            }
        }

        if (!foi_removida) {
            for (int k = 0; k < total_movs; k++) {
                if (movs[k].numero_conta == contas[i].numero_conta) {
                    if (movs[k].tipo == 'C' || movs[k].tipo == 'c') {
                        contas[i].saldo += movs[k].valor;
                    } else if (movs[k].tipo == 'D' || movs[k].tipo == 'd') {
                        contas[i].saldo -= movs[k].valor;
                    }
                }
            }
            fwrite(&contas[i], sizeof(Conta), 1, f_atual);
        }
    }

    fclose(f_atual);

    free(contas);
    free(removidas);
    free(movs);

    return 0;
}