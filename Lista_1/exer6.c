#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define TAM 100

int main(){
    int a;
    char frase[TAM];
    printf("Digite uma palavra: ");
    fgets(frase, sizeof(frase), stdin);
    a = strlen(frase);

    for(int j = a - 1; j >= 0; j--){
        printf("%c", frase[j]);
    }
    return 0;
}