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

    Pessoa p;
    printf("--- LISTA DE PESSOAS ---\n");

    // Lê uma estrutura Pessoa por vez até o fim do arquivo
    while (fread(&p, sizeof(Pessoa), 1, arq) == 1) {
        printf("Nome: %s | Idade: %d | Altura: %.2fm\n", p.nome, p.idade, p.altura);
    }

    fclose(arq);
    return 0;
}