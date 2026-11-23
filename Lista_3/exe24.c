#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[100];
    int sexo;
    char cor_olhos[30];
    float altura;
    float peso;
    char data_nascimento[11];
} PessoaEntrada;

typedef struct {
    char nome[100];
    char cor_olhos[30];
    float peso;
    char data_nascimento[11];
} PessoaSaida;

int main() {
    FILE *arq = fopen("cadastro.dat", "rb");
    FILE *arq_homens = fopen("homens.dat", "wb");
    FILE *arq_mulheres = fopen("mulheres.dat", "wb");

    if (arq == NULL || arq_homens == NULL || arq_mulheres == NULL) {
        if (arq) fclose(arq);
        if (arq_homens) fclose(arq_homens);
        if (arq_mulheres) fclose(arq_mulheres);
        return 1;
    }

    PessoaEntrada p_in;
    PessoaSaida p_out;

    while (fread(&p_in, sizeof(PessoaEntrada), 1, arq) == 1) {
        strcpy(p_out.nome, p_in.nome);
        strcpy(p_out.cor_olhos, p_in.cor_olhos);
        p_out.peso = p_in.peso;
        strcpy(p_out.data_nascimento, p_in.data_nascimento);

        if (p_in.sexo == 1) {
            fwrite(&p_out, sizeof(PessoaSaida), 1, arq_homens);
        } else if (p_in.sexo == 2) {
            fwrite(&p_out, sizeof(PessoaSaida), 1, arq_mulheres);
        }
    }

    fclose(arq);
    fclose(arq_homens);
    fclose(arq_mulheres);

    remove("cadastro.dat");

    return 0;
}