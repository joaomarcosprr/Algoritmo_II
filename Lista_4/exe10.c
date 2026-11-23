#include <stdio.h>

int main() {
    FILE *origem, *destino;
    char nome_origem[100], nome_destino[100];
    int c, i;

    printf("Digite o nome do arquivo de origem: ");
    fgets(nome_origem, 100, stdin);
    i = 0;
    while (nome_origem[i] != '\0') {
        if (nome_origem[i] == '\n' || nome_origem[i] == '\r') {
            nome_origem[i] = '\0';
            break;
        }
        i++;
    }

    printf("Digite o nome do arquivo de destino: ");
    fgets(nome_destino, 100, stdin);
    i = 0;
    while (nome_destino[i] != '\0') {
        if (nome_destino[i] == '\n' || nome_destino[i] == '\r') {
            nome_destino[i] = '\0';
            break;
        }
        i++;
    }

    origem = fopen(nome_origem, "r");
    if (origem == NULL) {
        printf("Erro ao abrir o arquivo de origem\n");
        return 1;
    }

    destino = fopen(nome_destino, "w");
    if (destino == NULL) {
        printf("Erro ao criar o arquivo de destino\n");
        fclose(origem);
        return 1;
    }

    while ((c = fgetc(origem)) != EOF) {
        fputc(c, destino);
    }

    fclose(origem);
    fclose(destino);

    return 0;
}