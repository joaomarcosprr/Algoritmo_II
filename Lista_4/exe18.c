#include <stdio.h>

int main() {
    FILE *arq;
    int n, i, j, c;
    char nome[55];
    float nota1, nota2, media;

    arq = fopen("alunos.txt", "r");
    if (arq == NULL) {
        printf("Erro ao abrir o arquivo alunos.txt\n");
        return 1;
    }

    fscanf(arq, "%d", &n);
    while ((c = fgetc(arq)) != '\n' && c != EOF);

    for (i = 0; i < n; i++) {
        if (fgets(nome, 55, arq) != NULL) {
            j = 0;
            while (nome[j] != '\0') {
                if (nome[j] == '\n' || nome[j] == '\r') {
                    nome[j] = '\0';
                    break;
                }
                j++;
            }

            fscanf(arq, "%f", &nota1);
            fscanf(arq, "%f", &nota2);
            while ((c = fgetc(arq)) != '\n' && c != EOF);

            media = (nota1 + nota2) / 2.0;

            if (media < 5.0) {
                printf("%s\n", nome);
            }
        }
    }

    fclose(arq);

    return 0;
}