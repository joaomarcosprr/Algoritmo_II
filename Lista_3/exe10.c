#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nome[50];
    int idade;
    float nota;
} Aluno;

int main() {
    FILE *arq = fopen("alunos.bin", "wb");
    if (arq == NULL) {
        return 1;
    }

    Aluno a;
    for (int i = 0; i < 5; i++) {
        printf("Digite o nome do aluno %d: ", i + 1);
        scanf(" %49[^\n]", a.nome);

        printf("Digite a idade do aluno %d: ", i + 1);
        scanf("%d", &a.idade);

        printf("Digite a nota do aluno %d: ", i + 1);
        scanf("%f", &a.nota);

        fwrite(&a, sizeof(Aluno), 1, arq);
    }

    fclose(arq);
    return 0;
}