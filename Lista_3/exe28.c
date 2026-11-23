#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[100];
    int numero;
    char curso[50];
    float p1;
    float p2;
    float mt;
    float frequencia;
} Aluno;

void cadastrar() {
    FILE *arq = fopen("alunos.dat", "ab");
    if (arq == NULL) {
        return;
    }

    Aluno a;
    printf("Numero: ");
    scanf("%d", &a.numero);
    printf("Nome: ");
    scanf(" %99[^\n]", a.nome);
    printf("Curso: ");
    scanf(" %49[^\n]", a.curso);
    printf("Nota P1: ");
    scanf("%f", &a.p1);
    printf("Nota P2: ");
    scanf("%f", &a.p2);
    printf("Nota MT: ");
    scanf("%f", &a.mt);
    printf("Frequencia (%%): ");
    scanf("%f", &a.frequencia);

    fwrite(&a, sizeof(Aluno), 1, arq);
    fclose(arq);
}

void consultar() {
    FILE *arq = fopen("alunos.dat", "rb");
    if (arq == NULL) {
        printf("Nenhum registro encontrado.\n");
        return;
    }

    int num;
    printf("Digite o numero do aluno para consultar: ");
    scanf("%d", &num);

    Aluno a;
    int achou = 0;
    while (fread(&a, sizeof(Aluno), 1, arq) == 1) {
        if (a.numero == num) {
            float mp = (a.p1 + a.p2) / 2.0;
            float mf = 0.8 * mp + 0.2 * a.mt;

            printf("\nNumero: %d\n", a.numero);
            printf("Nome: %s\n", a.nome);
            printf("Curso: %s\n", a.curso);
            printf("P1: %.2f | P2: %.2f | MT: %.2f\n", a.p1, a.p2, a.mt);
            printf("Media Final: %.2f\n", mf);
            printf("Frequencia: %.2f%%\n", a.frequencia);
            if (mf >= 4.95 && a.frequencia >= 70.0) {
                printf("Condicao: Aprovado\n");
            } else {
                printf("Condicao: Reprovado\n");
            }
            achou = 1;
            break;
        }
    }

    if (!achou) {
        printf("Aluno nao encontrado.\n");
    }

    fclose(arq);
}

void alterar() {
    FILE *arq = fopen("alunos.dat", "rb");
    if (arq == NULL) {
        printf("Nenhum registro encontrado.\n");
        return;
    }

    Aluno alunos[100];
    int total = 0;
    while (fread(&alunos[total], sizeof(Aluno), 1, arq) == 1) {
        total++;
    }
    fclose(arq);

    int num;
    printf("Digite o numero do aluno a alterar: ");
    scanf("%d", &num);

    int achou = 0;
    for (int i = 0; i < total; i++) {
        if (alunos[i].numero == num) {
            printf("Novo Nome: ");
            scanf(" %99[^\n]", alunos[i].nome);
            printf("Novo Curso: ");
            scanf(" %49[^\n]", alunos[i].curso);
            printf("Nova P1: ");
            scanf("%f", &alunos[i].p1);
            printf("Nova P2: ");
            scanf("%f", &alunos[i].p2);
            printf("Nova MT: ");
            scanf("%f", &alunos[i].mt);
            printf("Nova Frequencia (%%): ");
            scanf("%f", &alunos[i].frequencia);
            achou = 1;
            break;
        }
    }

    if (!achou) {
        printf("Aluno nao encontrado.\n");
        return;
    }

    arq = fopen("alunos.dat", "wb");
    if (arq == NULL) {
        return;
    }

    for (int i = 0; i < total; i++) {
        fwrite(&alunos[i], sizeof(Aluno), 1, arq);
    }
    fclose(arq);
    printf("Dados alterados com sucesso.\n");
}

void excluir() {
    FILE *arq = fopen("alunos.dat", "rb");
    if (arq == NULL) {
        printf("Nenhum registro encontrado.\n");
        return;
    }

    Aluno alunos[100];
    int total = 0;
    while (fread(&alunos[total], sizeof(Aluno), 1, arq) == 1) {
        total++;
    }
    fclose(arq);

    int num;
    printf("Digite o numero do aluno a excluir: ");
    scanf("%d", &num);

    arq = fopen("alunos.dat", "wb");
    if (arq == NULL) {
        return;
    }

    int removido = 0;
    for (int i = 0; i < total; i++) {
        if (alunos[i].numero == num && !removido) {
            removido = 1;
            continue;
        }
        fwrite(&alunos[i], sizeof(Aluno), 1, arq);
    }
    fclose(arq);

    if (removido) {
        printf("Aluno excluido com sucesso.\n");
    } else {
        printf("Aluno nao encontrado.\n");
    }
}

void listar() {
    FILE *arq = fopen("alunos.dat", "rb");
    if (arq == NULL) {
        printf("Nenhum registro encontrado.\n");
        return;
    }

    Aluno a;
    printf("\n--- RELATORIO DE ALUNOS ---\n");
    while (fread(&a, sizeof(Aluno), 1, arq) == 1) {
        float mp = (a.p1 + a.p2) / 2.0;
        float mf = 0.8 * mp + 0.2 * a.mt;

        printf("Numero: %d | Nome: %s\n", a.numero, a.nome);
        printf("Media Final: %.2f | Frequencia: %.2f%%\n", mf, a.frequencia);
        if (mf >= 4.95 && a.frequencia >= 70.0) {
            printf("Condicao: Aprovado\n");
        } else {
            printf("Condicao: Reprovado\n");
        }
        printf("----------------------------------------\n");
    }

    fclose(arq);
}

int main() {
    int opcao;
    do {
        printf("\n1. Cadastrar Aluno\n");
        printf("2. Consultar Aluno\n");
        printf("3. Alterar Aluno\n");
        printf("4. Excluir Aluno\n");
        printf("5. Listar Alunos\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrar();
                break;
            case 2:
                consultar();
                break;
            case 3:
                alterar();
                break;
            case 4:
                excluir();
                break;
            case 5:
                listar();
                break;
            case 0:
                break;
            default:
                printf("Opcao invalida.\n");
        }
    } while (opcao != 0);

    return 0;
}