#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[100];
    char rua[100];
    int numero;
    char telefone[20];
    char cidade[50];
    char estado[10];
} Contato;

void adicionar() {
    FILE *arq = fopen("agenda.bin", "ab");
    if (arq == NULL) {
        return;
    }

    Contato c;
    printf("Nome: ");
    scanf(" %99[^\n]", c.nome);
    printf("Rua: ");
    scanf(" %99[^\n]", c.rua);
    printf("Numero: ");
    scanf("%d", &c.numero);
    printf("Telefone: ");
    scanf(" %19s", c.telefone);
    printf("Cidade: ");
    scanf(" %49[^\n]", c.cidade);
    printf("Estado: ");
    scanf(" %9s", c.estado);

    fwrite(&c, sizeof(Contato), 1, arq);
    fclose(arq);
}

void listar() {
    FILE *arq = fopen("agenda.bin", "rb");
    if (arq == NULL) {
        printf("Nenhum registro encontrado.\n");
        return;
    }

    Contato c;
    printf("\n--- AGENDA ---\n");
    while (fread(&c, sizeof(Contato), 1, arq) == 1) {
        printf("Nome: %s\n", c.nome);
        printf("Rua: %s, %d\n", c.rua, c.numero);
        printf("Telefone: %s\n", c.telefone);
        printf("Cidade/Estado: %s - %s\n", c.cidade, c.estado);
        printf("---------------------\n");
    }

    fclose(arq);
}

void remover() {
    FILE *arq = fopen("agenda.bin", "rb");
    if (arq == NULL) {
        printf("Nenhum registro para remover.\n");
        return;
    }

    Contato contatos[100];
    int total = 0;

    while (fread(&contatos[total], sizeof(Contato), 1, arq) == 1) {
        total++;
    }
    fclose(arq);

    if (total == 0) {
        printf("Agenda vazia.\n");
        return;
    }

    char nomeRemover[100];
    printf("Digite o nome a ser removido: ");
    scanf(" %99[^\n]", nomeRemover);

    arq = fopen("agenda.bin", "wb");
    if (arq == NULL) {
        return;
    }

    int removido = 0;
    for (int i = 0; i < total; i++) {
        if (strcmp(contatos[i].nome, nomeRemover) == 0 && !removido) {
            removido = 1;
            continue;
        }
        fwrite(&contatos[i], sizeof(Contato), 1, arq);
    }

    fclose(arq);

    if (removido) {
        printf("Registro removido com sucesso.\n");
    } else {
        printf("Nome nao encontrado.\n");
    }
}

int main() {
    int opcao;

    do {
        printf("\n1. Adicionar Contato\n");
        printf("2. Listar Contatos\n");
        printf("3. Remover Contato\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                adicionar();
                break;
            case 2:
                listar();
                break;
            case 3:
                remover();
                break;
            case 0:
                break;
            default:
                printf("Opcao invalida.\n");
        }
    } while (opcao != 0);

    return 0;
}