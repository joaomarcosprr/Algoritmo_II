#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char nome[50];
    int idade;
    float nota;
} Aluno;


int main(){
    FILE *arqA = fopen("turmaA.bin", "rb");
    FILE *arqB = fopen("turmaB.bin", "rb");
    FILE *saida = fopen("turma_completa.bin", "wb");

    if(arqA == NULL || arqB == NULL  ||  saida == NULL){
        if(arqA) fclose(arqA);
        if(arqA) fclose(arqB);
        if(arqA) fclose(saida);
        return 1;
    }

    Aluno a;

    while (fread(&a, sizeof(Aluno), 1, arqA) == 1)
    {
        fwrite(&a, sizeof(Aluno), 1, saida);
    }

    while (fread(&a, sizeof(Aluno), 1, arqB) == 1)
    {
        fwrite(&a, sizeof(Aluno), 1, saida);
    }

    if (arqA)
        fclose(arqA);
    if (arqA)
        fclose(arqB);
    if (arqA)
        fclose(saida);

    return 0;
}