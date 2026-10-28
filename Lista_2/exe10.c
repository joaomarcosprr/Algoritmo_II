
#include <stdio.h>

typedef struct {
    char nome[100];
    char rg[20];
    float salario;
    int idade;
    int sexo;
    int dia, mes, ano;
} TipoReg;

typedef struct {
    TipoReg func[100];
    int quant;
} TipoCadastro;

TipoCadastro LeFuncionarios(TipoCadastro cad) {
    int n;

    printf("Quantos funcionarios deseja cadastrar? ");
    scanf("%d", &n);

    while (n > 100 - cad.quant) {
        printf("Quantidade excede o limite. Digite novamente: ");
        scanf("%d", &n);
    }

    for (int i = 0; i < n; i++) {
        printf("\nNome: ");
        scanf(" %99[^\n]", cad.func[cad.quant].nome);

        printf("RG: ");
        scanf(" %19s", cad.func[cad.quant].rg);

        printf("Salario: ");
        scanf("%f", &cad.func[cad.quant].salario);

        printf("Idade: ");
        scanf("%d", &cad.func[cad.quant].idade);

        printf("Sexo: ");
        scanf("%d", &cad.func[cad.quant].sexo);

        printf("Dia de nascimento: ");
        scanf("%d", &cad.func[cad.quant].dia);

        printf("Mes de nascimento: ");
        scanf("%d", &cad.func[cad.quant].mes);

        printf("Ano de nascimento: ");
        scanf("%d", &cad.func[cad.quant].ano);

        cad.quant++;
    }

    return cad;
}

int main() {
    TipoCadastro cad = {0};

    cad = LeFuncionarios(cad);

    return 0;
}
