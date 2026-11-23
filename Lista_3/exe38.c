#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char sexo;
    int idade;
    char fumante;
} Resposta;

int main() {
    FILE *arq = fopen("resposta.bin", "rb");
    if (arq == NULL) {
        printf("Erro ao abrir o arquivo resposta.bin\n");
        return 1;
    }

    Resposta r;
    int total_pessoas = 0;
    int total_fumantes = 0;
    int total_homens = 0;
    int homens_nao_fumantes_sub40 = 0;
    int total_mulheres = 0;
    int mulheres_fumantes_acima40 = 0;

    while (fread(&r, sizeof(Resposta), 1, arq) == 1) {
        total_pessoas++;

        if (r.fumante == 'S' || r.fumante == 's') {
            total_fumantes++;
        }

        if (r.sexo == 'M' || r.sexo == 'm') {
            total_homens++;
            if ((r.fumante == 'N' || r.fumante == 'n') && r.idade < 40) {
                homens_nao_fumantes_sub40++;
            }
        } else if (r.sexo == 'F' || r.sexo == 'f') {
            total_mulheres++;
            if ((r.fumante == 'S' || r.fumante == 's') && r.idade > 40) {
                mulheres_fumantes_acima40++;
            }
        }
    }

    fclose(arq);

    if (total_pessoas > 0) {
        printf("Percentual de fumantes: %.2f%%\n", ((float)total_fumantes / total_pessoas) * 100.0f);
    } else {
        printf("Nenhuma pessoa entrevistada.\n");
    }

    if (total_homens > 0) {
        printf("Percentual de homens nao fumantes abaixo de 40 anos: %.2f%%\n", ((float)homens_nao_fumantes_sub40 / total_homens) * 100.0f);
    } else {
        printf("Nenhum homem entrevistado.\n");
    }

    if (total_mulheres > 0) {
        printf("Percentual de mulheres fumantes acima de 40 anos: %.2f%%\n", ((float)mulheres_fumantes_acima40 / total_mulheres) * 100.0f);
    } else {
        printf("Nenhuma mulher entrevistada.\n");
    }

    return 0;
}