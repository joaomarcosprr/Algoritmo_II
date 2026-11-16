#include <stdio.h>

int N(int x){
    if(x == 0){
        printf("%d\n", x);
        return 0;
    }
    printf("%d ", x);
    return N(x-1);
}

int main(){
    int x;
    scanf("%d", &x);
    N(x);
    return 0;
}