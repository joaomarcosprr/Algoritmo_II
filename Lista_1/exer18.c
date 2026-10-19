#include <stdio.h>
#include <string.h>

int main(){
    int a;
    char frase[50];
    printf("Digite um texto: \n");
    fgets(frase, sizeof(frase), stdin);
    a = strlen(frase);

    printf("O texto com algoritmo de Cesar: \n");
    for(int i = 0; i < a - 1; i++){
        printf("%c", frase[i]+3);
    }
    return 0;
}