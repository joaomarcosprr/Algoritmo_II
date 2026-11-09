#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int e_vogal(char c) {
    c = tolower((unsigned char)c);
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

int main() {
    char nome_entrada[100];
    char nome_saida[100];

    printf("Digite o nome do arquivo de entrada: ");
    if (scanf("%99s", nome_entrada) != 1) {
        return 1;
    }

    printf("Digite o nome do arquivo de saida: ");
    if (scanf("%99s", nome_saida) != 1) {
        return 1;
    }

    FILE *fin = fopen(nome_entrada, "r");
    if (fin == NULL) {
        printf("Erro ao abrir o arquivo de entrada.\n");
        return 1;
    }

    FILE *fout = fopen(nome_saida, "w");
    if (fout == NULL) {
        printf("Erro ao criar o arquivo de saida.\n");
        fclose(fin);
        return 1;
    }

    int ch;
    while ((ch = fgetc(fin)) != EOF) {
        if (e_vogal(ch)) {
            fputc('*', fout);
        } else {
            fputc(ch, fout);
        }
    }

    fclose(fin);
    fclose(fout);

    printf("Arquivo processado com sucesso.\n");

    return 0;
}