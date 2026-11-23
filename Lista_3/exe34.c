#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int codigo;
    char descricao[100];
    int quantidade;
} Produto;

void entrada_produto() {
    FILE *arq = fopen("despensa.bin", "rb");
    Produto produtos[500];
    int total = 0;

    if (arq != NULL) {
        while (fread(&produtos[total], sizeof(Produto), 1, arq) == 1) {
            total++;
        }
        fclose(arq);
    }

    int codigo, qtd;
    printf("Codigo do produto: ");
    if (scanf("%d", &codigo) != 1) return;

    int achou = -1;
    for (int i = 0; i < total; i++) {
        if (produtos[i].codigo == codigo) {
            achou = i;
            break;
        }
    }

    if (achou != -1) {
        printf("Quantidade a adicionar: ");
        scanf("%d", &qtd);
        produtos[achou].quantidade += qtd;
    } else {
        Produto p;
        p.codigo = codigo;
        printf("Descricao do produto: ");
        scanf(" %99[^\n]", p.descricao);
        printf("Quantidade inicial: ");
        scanf("%d", &p.quantidade);
        produtos[total++] = p;
    }

    arq = fopen("despensa.bin", "wb");
    if (arq == NULL) return;

    for (int i = 0; i < total; i++) {
        fwrite(&produtos[i], sizeof(Produto), 1, arq);
    }
    fclose(arq);
}

void retirada_produto() {
    FILE *arq = fopen("despensa.bin", "rb");
    if (arq == NULL) {
        printf("Nenhum produto cadastrado.\n");
        return;
    }

    Produto produtos[500];
    int total = 0;
    while (fread(&produtos[total], sizeof(Produto), 1, arq) == 1) {
        total++;
    }
    fclose(arq);

    int codigo, qtd;
    printf("Codigo do produto para retirada: ");
    scanf("%d", &codigo);

    int achou = -1;
    for (int i = 0; i < total; i++) {
        if (produtos[i].codigo == codigo) {
            achou = i;
            break;
        }
    }

    if (achou == -1) {
        printf("Produto nao encontrado.\n");
        return;
    }

    printf("Quantidade a retirar: ");
    scanf("%d", &qtd);

    if (qtd > produtos[achou].quantidade) {
        printf("Quantidade insuficiente em estoque.\n");
        return;
    }

    produtos[achou].quantidade -= qtd;

    arq = fopen("despensa.bin", "wb");
    if (arq == NULL) return;

    for (int i = 0; i < total; i++) {
        fwrite(&produtos[i], sizeof(Produto), 1, arq);
    }
    fclose(arq);

    printf("Retirada realizada com sucesso.\n");
}

void relatorio_geral() {
    FILE *arq = fopen("despensa.bin", "rb");
    if (arq == NULL) {
        printf("Nenhum produto cadastrado.\n");
        return;
    }

    Produto p;
    printf("\n--- RELATORIO GERAL ---\n");
    while (fread(&p, sizeof(Produto), 1, arq) == 1) {
        printf("Codigo: %d | Descricao: %s | Quantidade: %d\n", p.codigo, p.descricao, p.quantidade);
    }

    fclose(arq);
}

void relatorio_indisponiveis() {
    FILE *arq = fopen("despensa.bin", "rb");
    if (arq == NULL) {
        printf("Nenhum produto cadastrado.\n");
        return;
    }

    Produto p;
    int cont = 0;
    printf("\n--- PRODUTOS NAO DISPONIVEIS ---\n");
    while (fread(&p, sizeof(Produto), 1, arq) == 1) {
        if (p.quantidade <= 0) {
            printf("Codigo: %d | Descricao: %s | Quantidade: %d\n", p.codigo, p.descricao, p.quantidade);
            cont++;
        }
    }

    if (cont == 0) {
        printf("Todos os produtos estao disponiveis em estoque.\n");
    }

    fclose(arq);
}

int main() {
    int opcao;

    do {
        printf("\n--- CONTROLE DE DESPENSA ---\n");
        printf("1. Entrada de Produto\n");
        printf("2. Retirada de Produto\n");
        printf("3. Relatorio Geral\n");
        printf("4. Relatorio de Produtos Nao Disponiveis\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        if (scanf("%d", &opcao) != 1) break;

        switch (opcao) {
            case 1:
                entrada_produto();
                break;
            case 2:
                retirada_produto();
                break;
            case 3:
                relatorio_geral();
                break;
            case 4:
                relatorio_indisponiveis();
                break;
            case 0:
                break;
            default:
                printf("Opcao invalida.\n");
        }
    } while (opcao != 0);

    return 0;
}