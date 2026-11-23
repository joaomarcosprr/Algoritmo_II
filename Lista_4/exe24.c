#include <stdio.h>

int main() {
    FILE *arq;
    char nome_arq[100];
    int c, i;
    int caracteres = 0;
    int linhas = 0;
    int palavras = 0;
    int em_palavra = 0;
    int letras[26];

    for (i = 0; i < 26; i++) {
        letras[i] = 0;
    }

    printf("Digite o nome do arquivo: ");
    fgets(nome_arq, 100, stdin);
    i = 0;
    while (nome_arq[i] != '\0') {
        if (nome_arq[i] == '\n' || nome_arq[i] == '\r') {
            nome_arq[i] = '\0';
            break;
        }
        i++;
    }

    arq = fopen(nome_arq, "r");
    if (arq == NULL) {
        printf("Erro ao abrir o arquivo\n");
        return 1;
    }

    while ((c = fgetc(arq)) != EOF) {
        if (caracteres == 0) {
            linhas = 1;
        }
        caracteres++;

        if (c == '\n') {
            linhas++;
        }

        if (c == ' ' || c == '\t' || c == '\n' || c == '\r') {
            em_palavra = 0;
        } else {
            if (em_palavra == 0) {
                em_palavra = 1;
                palavras++;
            }
        }

        if (c >= 'a' && c <= 'z') {
            letras[c - 'a']++;
        } else if (c >= 'A' && c <= 'Z') {
            letras[c - 'A']++;
        }
    }

    fclose(arq);

    printf("Numero de caracteres: %d\n", caracteres);
    printf("Numero de linhas: %d\n", linhas);
    printf("Numero de palavras: %d\n", palavras);
    printf("Ocorrencia de cada letra:\n");
    for (i = 0; i < 26; i++) {
        printf("%c: %d\n", 'A' + i, letras[i]);
    }

    return 0;
}
