#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int horas;
    int minutos;
}hm;

int conversao(int *minutos, int *horas){
    *horas = *minutos/60;
    *minutos = *minutos%60;
    return 0;

}

int main(){

    hm tempo;
    scanf("%d", &tempo.minutos);
    conversao(&tempo.minutos, &tempo.horas);
    printf("%d horas e %d minutos\n", tempo.horas, tempo.minutos);

    return 0;
}