#include <stdio.h>

struct pessoa {
    char nome[50];
    int idade;
    float altura;
    char telefone[10];
} amigos[20];

int main() {
    FILE *arq;
    int n, i, j, c;

    printf("Quantidade de pessoas (maximo 20): ");
    scanf("%d", &n);
    while ((c = getchar()) != '\n' && c != EOF);

    if (n < 1) {
        n = 1;
    }
    if (n > 20) {
        n = 20;
    }

    for (i = 0; i < n; i++) {
        printf("Nome: ");
        fgets(amigos[i].nome, 50, stdin);
        j = 0;
        while (amigos[i].nome[j] != '\0' && amigos[i].nome[j] != '\n' && amigos[i].nome[j] != '\r') {
            j++;
        }
        if (amigos[i].nome[j] == '\0') {
            while ((c = getchar()) != '\n' && c != EOF);
        } else {
            amigos[i].nome[j] = '\0';
        }

        printf("Idade: ");
        scanf("%d", &amigos[i].idade);

        printf("Altura: ");
        scanf("%f", &amigos[i].altura);
        while ((c = getchar()) != '\n' && c != EOF);

        printf("Telefone: ");
        fgets(amigos[i].telefone, 10, stdin);
        j = 0;
        while (amigos[i].telefone[j] != '\0' && amigos[i].telefone[j] != '\n' && amigos[i].telefone[j] != '\r') {
            j++;
        }
        if (amigos[i].telefone[j] == '\0') {
            while ((c = getchar()) != '\n' && c != EOF);
        } else {
            amigos[i].telefone[j] = '\0';
        }
    }

    arq = fopen("amigos.bin", "wb");
    if (arq == NULL) {
        printf("Erro ao criar o arquivo amigos.bin\n");
        return 1;
    }

    fwrite(amigos, sizeof(struct pessoa), n, arq);
    fclose(arq);

    return 0;
}