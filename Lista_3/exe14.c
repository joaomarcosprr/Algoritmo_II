#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char telefone[20];
    char cidade[50];
    float tempo_ligacao;
} Registro;

int main() {
    FILE *arq1 = fopen("arquivo1.bin", "wb");
    FILE *arq2 = fopen("arquivo2.bin", "wb");

    if (arq1 == NULL || arq2 == NULL) {
        if (arq1) fclose(arq1);
        if (arq2) fclose(arq2);
        return 1;
    }

    int n1, n2;
    Registro r;

    printf("Quantos registros cadastrar no Arquivo 1? ");
    scanf("%d", &n1);
    for (int i = 0; i < n1; i++) {
        printf("\nRegistro %d (Arquivo 1):\n", i + 1);
        printf("Telefone: ");
        scanf(" %19s", r.telefone);
        printf("Cidade: ");
        scanf(" %49[^\n]", r.cidade);
        printf("Tempo de ligacao: ");
        scanf("%f", &r.tempo_ligacao);
        fwrite(&r, sizeof(Registro), 1, arq1);
    }
    fclose(arq1);

    printf("\nQuantos registros cadastrar no Arquivo 2? ");
    scanf("%d", &n2);
    for (int i = 0; i < n2; i++) {
        printf("\nRegistro %d (Arquivo 2):\n", i + 1);
        printf("Telefone: ");
        scanf(" %19s", r.telefone);
        printf("Cidade: ");
        scanf(" %49[^\n]", r.cidade);
        printf("Tempo de ligacao: ");
        scanf("%f", &r.tempo_ligacao);
        fwrite(&r, sizeof(Registro), 1, arq2);
    }
    fclose(arq2);

    arq1 = fopen("arquivo1.bin", "rb");
    arq2 = fopen("arquivo2.bin", "rb");

    if (arq1 == NULL || arq2 == NULL) {
        if (arq1) fclose(arq1);
        if (arq2) fclose(arq2);
        return 1;
    }

    Registro lista1[100], lista2[100];
    int q1 = 0, q2 = 0;

    while (fread(&lista1[q1], sizeof(Registro), 1, arq1) == 1) {
        q1++;
    }
    while (fread(&lista2[q2], sizeof(Registro), 1, arq2) == 1) {
        q2++;
    }

    fclose(arq1);
    fclose(arq2);

    printf("\nTelefones de cidades em comum:\n");
    for (int i = 0; i < q1; i++) {
        for (int j = 0; j < q2; j++) {
            if (strcmp(lista1[i].cidade, lista2[j].cidade) == 0) {
                printf("Cidade: %s -> Tel (Arquivo 1): %s | Tel (Arquivo 2): %s\n", 
                       lista1[i].cidade, lista1[i].telefone, lista2[j].telefone);
            }
        }
    }

    return 0;
}