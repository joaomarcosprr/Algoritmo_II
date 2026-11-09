#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nome[50];
    int idade;
    float altura;
} Pessoa;

int main() {
    FILE *arq = fopen("pessoas.bin", "rb");

    if (arq == NULL) {
        printf("Erro ao abrir o arquivo pessoas.bin\n");
        return 1;
    }

    // Move o ponteiro para o final do arquivo
    fseek(arq, 0, SEEK_END);

    // Obtém o tamanho total do arquivo em bytes
    long tamanho_bytes = ftell(arq);

    // Calcula a quantidade de registros dividindo pelo tamanho da estrutura
    int quantidade = tamanho_bytes / sizeof(Pessoa);

    printf("Quantidade de estruturas 'Pessoa' no arquivo: %d\n", quantidade);

    fclose(arq);
    return 0;
}