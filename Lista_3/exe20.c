#include <stdio.h>
#include <stdlib.h>

int main(){
FILE *origem = foden("numeros.bin", "rb");
if(origem == NULL){
    return 1;
}

FILE *destino = foden("pares.bin", "rb");
if(destino == NULL){
    return 1;
}

int numero;

while (fread(&numero, sizeof(int), 1, origem) == 1){
    if(numero % 2 == 0){
        fwrite(&numero, sizeof(int), 1, destino);
    }
}

fclose(origem);
fclose(destino);

    return 0;
}