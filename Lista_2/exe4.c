#include <stdio.h>

typedef struct{
    int numerador;
    int denominador;
} racional;

int mdc(int a, int b){
    if(a < 0)
        a = -a;
    if(b < 0)
        b = -b;
    while (b  != 0){
        int aux = b;
        b = a %b;
        a = aux;
    }
    return a;
}


racional simplificar(racional r){
    int div = mdc(r.numerador, r.denominador);

    if(div != 0){
        r.numerador /= div;
        r.denominador /= div;
    }

    if(r.denominador < 0){
        r.numerador = -r.numerador;
        r.denominador = -r.denominador;
    }
    return r;
}


racional ler(){
    racional r;
    scanf("%d %d", &r.numerador, &r.denominador);
    return r;
}


racional somar(racional r1, racional r2){
    racional res;
    res.numerador = r1.numerador * r2.denominador + r2.numerador * r1.denominador;
    res.denominador = r1.denominador * r2.denominador;
    return simplificar(res);
}


racional subtrair(racional r1, racional r2){
    racional res;
    res.numerador = r1.numerador * r2.denominador - r2.numerador * r1.denominador;
    res.denominador = r1.denominador * r2.denominador;
    return simplificar(res);
}


racional multiplicar(racional r1, racional r2){
    racional res;
    res.numerador = r1.numerador * r2.numerador;
    res.denominador = r1.denominador * r2.denominador;
    return simplificar(res);
}


racional dividir(racional r1, racional r2){
    racional res;
    res.numerador = r1.numerador * r2.denominador;
    res.denominador = r1.denominador * r2.numerador;
    return simplificar(res);
}

int main(){
    racional r1 = ler();
    racional r2 = ler();

    racional s = somar(r1, r2);
    racional sub = subtrair(r1, r2);
    racional mul = multiplicar(r1, r2);
    racional div = dividir(r1, r2);

    printf("%d/%d\n", s.numerador, s.denominador);
    printf("%d/%d\n", sub.numerador, sub.denominador);
    printf("%d/%d\n", mul.numerador, mul.denominador);
    printf("%d/%d\n", div.numerador, div.denominador);   

    return 0;
}