#include <stdio.h>

int main() {
    FILE *arq1, *arq2;
    char nome1[100], nome2[100];
    int c1, c2;
    int posicao = 1;
    int i;

    printf("Digite o nome do primeiro arquivo: ");
    fgets(nome1, 100, stdin);
    i = 0;
    while (nome1[i] != '\0') {
        if (nome1[i] == '\n' || nome1[i] == '\r') {
            nome1[i] = '\0';
            break;
        }
        i++;
    }

    printf("Digite o nome do segundo arquivo: ");
    fgets(nome2, 100, stdin);
    i = 0;
    while (nome2[i] != '\0') {
        if (nome2[i] == '\n' || nome2[i] == '\r') {
            nome2[i] = '\0';
            break;
        }
        i++;
    }

    arq1 = fopen(nome1, "r");
    if (arq1 == NULL) {
        printf("Erro ao abrir o primeiro arquivo\n");
        return 1;
    }

    arq2 = fopen(nome2, "r");
    if (arq2 == NULL) {
        printf("Erro ao abrir o segundo arquivo\n");
        fclose(arq1);
        return 1;
    }

    while ((c1 = fgetc(arq1)) != EOF && (c2 = fgetc(arq2)) != EOF) {
        if (c1 == c2) {
            printf("%d - %c (%d)\n", posicao, c1, c1);
        }
        posicao++;
    }

    fclose(arq1);
    fclose(arq2);

    return 0;
}