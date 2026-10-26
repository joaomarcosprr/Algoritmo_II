#include <stdio.h>
#include <string.h>

#define TAM 4

struct Pessoa{
    char nome[50];
    int idade;
    float altura;

};

int main(){
    FILE *arquivo = fopen("pessoas.bin", "wb");

    if(arquivo == NULL){
        return 1;
    }

    struct Pessoa p;

    for (int i = 0; i < TAM; i++){
        printf("Pessoa %d\n: \n", i + 1);
        printf("Digite o nome: ");
        fgets(p.nome, 50, stdin);
        p.nome[strcspn(p.nome, "\n")] = '\0';
        printf("Digite a idade: ");
        scanf("%d", &p.idade);
        printf("Digite a altura: ");
        scanf("%f", &p.altura);
        getchar();
        
        fwrite(&p, sizeof(struct Pessoa), 1, arquivo);

        

    }
        printf("Pessoas cadastradas com sucesso!\n");

        fclose(arquivo);
        return 0;

}
