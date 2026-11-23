#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int codigo;
    char nome[50];
    int semestre;
    int prereq;
} Disciplina;

typedef struct {
    int matricula;
    char nome[100];
    char curso[50];
} Aluno;

typedef struct {
    int matricula;
    int codigo_disc;
} DisciplinaCursada;

int aluno_cursou(int matricula, int codigo_disc) {
    FILE *arq = fopen("cursadas.bin", "rb");
    if (arq == NULL) {
        return 0;
    }

    DisciplinaCursada c;
    while (fread(&c, sizeof(DisciplinaCursada), 1, arq) == 1) {
        if (c.matricula == matricula && c.codigo_disc == codigo_disc) {
            fclose(arq);
            return 1;
        }
    }

    fclose(arq);
    return 0;
}

int main() {
    int semestre_alvo;
    printf("Digite o numero do semestre: ");
    if (scanf("%d", &semestre_alvo) != 1) {
        return 1;
    }

    FILE *arq_alunos = fopen("alunos.bin", "rb");
    if (arq_alunos == NULL) {
        return 1;
    }

    Aluno al;
    while (fread(&al, sizeof(Aluno), 1, arq_alunos) == 1) {
        printf("\nCurso: %s\n", al.curso);
        printf("Matricula: %d\n", al.matricula);
        printf("Nome: %s\n", al.nome);
        printf("Disciplinas liberadas para pre-matricula:\n");

        FILE *arq_disc = fopen("disciplinas.bin", "rb");
        if (arq_disc != NULL) {
            Disciplina d;
            int contador = 0;

            while (fread(&d, sizeof(Disciplina), 1, arq_disc) == 1) {
                if (d.semestre == semestre_alvo) {
                    int pode_cursar = 1;

                    if (d.prereq != 0) {
                        if (!aluno_cursou(al.matricula, d.prereq)) {
                            pode_cursar = 0;
                        }
                    }

                    if (pode_cursar) {
                        printf("- %s (Codigo: %d)\n", d.nome, d.codigo);
                        contador++;
                    }
                }
            }
            fclose(arq_disc);

            if (contador == 0) {
                printf("Nenhuma disciplina disponivel para este semestre.\n");
            }
        }
        printf("----------------------------------------\n");
    }

    fclose(arq_alunos);
    return 0;
}