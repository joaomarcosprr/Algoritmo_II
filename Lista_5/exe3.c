#include <stdio.h>

int N(int x){
    if(x == 0){
        return 0;
    }else if(x%2 == 0){
        printf("%d ", x);
    }
    
    return N(x-1);
}

int main(){
    int x;
    scanf("%d", &x);
    N(x);
    return 0;
}