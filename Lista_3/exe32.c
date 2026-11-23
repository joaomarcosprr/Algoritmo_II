#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int matricula;
    char nome[100];
    char curso[50];
} Aluno;

int e_curso_valido(const char *curso) {
    if (strcmp(curso, "Ciência da Computação") == 0 || strcmp(curso, "Ciencia da Computacao") == 0 ||
        strcmp(curso, "Sistemas de Informação") == 0 || strcmp(curso, "Sistemas de Informacao") == 0) {
        return 1;
    }
    return 0;
}

void pesquisar_por_nome() {
    FILE *arq = fopen("alunos.bin", "rb");
    if (arq == NULL) {
        printf("Erro ao abrir o arquivo alunos.bin\n");
        return;
    }

    Aluno alunos[500];
    int total = 0;
    Aluno temp;

    while (fread(&temp, sizeof(Aluno), 1, arq) == 1) {
        if (e_curso_valido(temp.curso)) {
            alunos[total++] = temp;
        }
    }
    fclose(arq);

    char nome_busca[100];
    while (1) {
        printf("\nDigite o nome para pesquisa (ou FIM para voltar): ");
        scanf(" %99[^\n]", nome_busca);

        if (strcmp(nome_busca, "FIM") == 0 || strcmp(nome_busca, "fim") == 0) {
            break;
        }

        int encontrado = 0;
        for (int i = 0; i < total; i++) {
            if (strcmp(alunos[i].nome, nome_busca) == 0) {
                printf("\nMatricula: %d\n", alunos[i].matricula);
                printf("Nome: %s\n", alunos[i].nome);
                printf("Curso: %s\n", alunos[i].curso);
                encontrado = 1;
                break;
            }
        }

        if (!encontrado) {
            printf("Aluno nao encontrado ou nao pertence aos cursos pesquisados.\n");
        }
    }
}

void pesquisar_por_matricula() {
    FILE *arq = fopen("alunos.bin", "rb");
    if (arq == NULL) {
        printf("Erro ao abrir o arquivo alunos.bin\n");
        return;
    }

    Aluno alunos[500];
    int total = 0;
    Aluno temp;

    while (fread(&temp, sizeof(Aluno), 1, arq) == 1) {
        if (e_curso_valido(temp.curso)) {
            alunos[total++] = temp;
        }
    }
    fclose(arq);

    int mat_busca;
    while (1) {
        printf("\nDigite a matricula para pesquisa (ou numero negativo para voltar): ");
        if (scanf("%d", &mat_busca) != 1) {
            break;
        }

        if (mat_busca < 0) {
            break;
        }

        int encontrado = 0;
        for (int i = 0; i < total; i++) {
            if (alunos[i].matricula == mat_busca) {
                printf("\nMatricula: %d\n", alunos[i].matricula);
                printf("Nome: %s\n", alunos[i].nome);
                printf("Curso: %s\n", alunos[i].curso);
                encontrado = 1;
                break;
            }
        }

        if (!encontrado) {
            printf("Aluno nao encontrado ou nao pertence aos cursos pesquisados.\n");
        }
    }
}

int main() {
    int opcao;

    do {
        printf("\n--- MENU PRINCIPAL ---\n");
        printf("1. Pesquisar por Nome\n");
        printf("2. Pesquisar por Matricula\n");
        printf("0. Fim\n");
        printf("Escolha uma opcao: ");
        if (scanf("%d", &opcao) != 1) {
            break;
        }

        switch (opcao) {
            case 1:
                pesquisar_por_nome();
                break;
            case 2:
                pesquisar_por_matricula();
                break;
            case 0:
                printf("Programa encerrado.\n");
                break;
            default:
                printf("Opcao invalida.\n");
        }
    } while (opcao != 0);

    return 0;
}