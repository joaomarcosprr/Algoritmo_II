#include <stdio.h>
#include <string.h>

int main(){
    int a;
    char frase[50];
    printf("Digite um texto: \n");
    fgets(frase, sizeof(frase), stdin);
    a = strlen(frase);

    printf("O texto com um caracter a mais na tabela ASCII: \n");
    for(int i = 0; i < a - 1; i++){
        printf("%c", frase[i]+1);
    }
    return 0;
}