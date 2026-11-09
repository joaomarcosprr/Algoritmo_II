#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char sexo;
    int idade;
    float salario;
    char estado_civil[20];
    int num_dependentes;
    float valor_patrimonio;
    int calorias_dia;
    char grau_instrucao[50];
} Amostra;

int main() {
    FILE *f1 = fopen("regiao1.bin", "rb");
    FILE *f2 = fopen("regiao2.bin", "rb");
    FILE *f3 = fopen("regiao3.bin", "rb");
    FILE *fout = fopen("regiao_intercalada.bin", "wb");

    if (f1 == NULL || f2 == NULL || f3 == NULL || fout == NULL) {
        if (f1) fclose(f1);
        if (f2) fclose(f2);
        if (f3) fclose(f3);
        if (fout) fclose(fout);
        return 1;
    }

    Amostra a1, a2, a3;
    int tem1 = (fread(&a1, sizeof(Amostra), 1, f1) == 1);
    int tem2 = (fread(&a2, sizeof(Amostra), 1, f2) == 1);
    int tem3 = (fread(&a3, sizeof(Amostra), 1, f3) == 1);

    while (tem1 || tem2 || tem3) {
        int menor = 0;

        if (tem1) {
            menor = 1;
        }
        if (tem2 && (menor == 0 || a2.idade < a1.idade)) {
            menor = 2;
        }
        if (tem3 && (menor == 0 || (menor == 1 && a3.idade < a1.idade) || (menor == 2 && a3.idade < a2.idade))) {
            menor = 3;
        }

        if (menor == 1) {
            fwrite(&a1, sizeof(Amostra), 1, fout);
            tem1 = (fread(&a1, sizeof(Amostra), 1, f1) == 1);
        } else if (menor == 2) {
            fwrite(&a2, sizeof(Amostra), 1, fout);
            tem2 = (fread(&a2, sizeof(Amostra), 1, f2) == 1);
        } else if (menor == 3) {
            fwrite(&a3, sizeof(Amostra), 1, fout);
            tem3 = (fread(&a3, sizeof(Amostra), 1, f3) == 1);
        }
    }

    fclose(f1);
    fclose(f2);
    fclose(f3);
    fclose(fout);

    return 0;
}