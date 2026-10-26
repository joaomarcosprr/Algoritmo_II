#include <stdio.h>
#define TAM 5

int main(){
    FILE *arquivo = fopen("dados.bin", "wb");

    if(arquivo == NULL){
        return 1;
    }

    int num;
    for(int i = 0; i < TAM; i++){
        printf("Digite o valor %d: ", i + 1);
        scanf("%d", &num);
        fwrite(&num, sizeof(int), 1, arquivo);
    }

    printf("Arquivo cadastrado!\n");

    fclose(arquivo);
    return 0;
}