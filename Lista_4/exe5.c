#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void limpar_palavra(char *dest, const char *src) {
    int j = 0;
    for (int i = 0; src[i] != '\0'; i++) {
        if (isalnum((unsigned char)src[i])) {
            dest[j++] = tolower((unsigned char)src[i]);
        }
    }
    dest[j] = '\0';
}

int main() {
    char nome_arquivo[100];
    char palavra_alvo[100];
    char palavra_alvo_limpa[100];
    char buffer[100];
    char buffer_limpo[100];

    printf("Digite o nome do arquivo: ");
    if (scanf("%99s", nome_arquivo) != 1) {
        return 1;
    }

    printf("Digite a palavra a ser pesquisada: ");
    if (scanf("%99s", palavra_alvo) != 1) {
        return 1;
    }

    FILE *arq = fopen(nome_arquivo, "r");
    if (arq == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    limpar_palavra(palavra_alvo_limpa, palavra_alvo);

    int contagem = 0;
    while (fscanf(arq, "%99s", buffer) == 1) {
        limpar_palavra(buffer_limpo, buffer);
        if (strlen(buffer_limpo) > 0 && strcmp(buffer_limpo, palavra_alvo_limpa) == 0) {
            contagem++;
        }
    }

    fclose(arq);

    printf("A palavra '%s' aparece %d vez(es) no arquivo.\n", palavra_alvo, contagem);

    return 0;
}