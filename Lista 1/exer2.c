#include <stdio.h>
#include <string.h>

int main(){
    int a;
    char frase[50];
    printf("Digite um texto com letras em minuscula: ");
    fgets(frase, sizeof(frase), stdin);
    a = strlen(frase);

    for(int i = 0; i < a - 1; i++){
        printf("%c", frase[i]-32);
    }
    return 0;
}