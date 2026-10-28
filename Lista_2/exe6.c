
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int data, mes, ano;
} dma;

int bissexto(int ano) {
    return ano % 400 == 0 ||
           (ano % 4 == 0 && ano % 100 != 0);
}

int verificador(int dd, int mm, int yyyy) {
    if (yyyy < 1 || mm < 1 || mm > 12 || dd < 1)
        return 0;

    int diasMes[] = {
        31, 28, 31, 30, 31, 30,
        31, 31, 30, 31, 30, 31
    };

    if (bissexto(yyyy))
        diasMes[1] = 29;

    return dd <= diasMes[mm - 1];
}

long long Dias(dma d) {
    long long ano = d.ano;
    ano--;

    long long total = ano * 365
                    + ano / 4
                    - ano / 100
                    + ano / 400;

    int diasMes[] = {
        31, 28, 31, 30, 31, 30,
        31, 31, 30, 31, 30, 31
    };

    if (bissexto(d.ano))
        diasMes[1] = 29;

    for (int i = 0; i < d.mes - 1; i++)
        total += diasMes[i];

    total += d.data;

    return total;
}

dma lerData(void) {
    dma d;

    do {
        printf("Informe uma data (dd mm aaaa): ");

        if (scanf("%d %d %d",
                  &d.data, &d.mes, &d.ano) != 3) {
            printf("Entrada invalida.\n");
            exit(1);
        }

        if (!verificador(d.data, d.mes, d.ano))
            printf("Data invalida. Tente novamente.\n");

    } while (!verificador(d.data, d.mes, d.ano));

    return d;
}

int main(void) {
    dma Pessoa1, Pessoa2;

    Pessoa1 = lerData();
    Pessoa2 = lerData();

    long long diferenca = Dias(Pessoa1) - Dias(Pessoa2);

    if (diferenca < 0)
        diferenca = -diferenca;

    printf("Diferenca em dias: %lld\n", diferenca);

    return 0;
}
