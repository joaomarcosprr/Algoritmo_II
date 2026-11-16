#include <stdio.h>
int chamada = 0;
int F(int n){
    chamada++;
    if(n == 0){
        return 1;
    }
    if(n == 1){
        return 2;
    }
    return 2*F(n-2) * F(n-1);
}

int main(){
    int n, res;
    scanf("%d", &n);
    res = F(n);

    printf("Valor: %d\n", res);
    printf("Chamadas: %d\n", chamada);
    return 0;
}