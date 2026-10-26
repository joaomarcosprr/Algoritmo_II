#include <stdio.h>
#define TAM 5

int main(){
    FILE *arquivo = fopen("dados.bin", "rb+");

    if(arquivo == NULL){
        return 1;
    }

    int NovoValor, posicao;
    printf("informe a posicao: \n");
    scanf("%d", &posicao);    

    printf("informe o novo valor: \n");
    scanf("%d", &NovoValor);

    fseek(arquivo, (posicao - 1) * sizeof(int), SEEK_SET);
    fwrite(&NovoValor, sizeof(int), 1, arquivo);

    printf("Arquivo Editado!\n");
    fclose(arquivo);
    return 0;
}