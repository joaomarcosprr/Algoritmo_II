
#include <stdio.h>
#include <string.h>

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

    while (n < 0 || n > 100 - cad.quant) {
        printf("Quantidade invalida. Digite novamente: ");
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

        printf("Sexo (F/M): ");
        scanf(" %c", (char *)&cad.func[cad.quant].sexo);

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

void ListaAniversarioSexo(TipoCadastro cad, int dia, int mes, int ano, char sexo) {
    int achou = 0;

    for (int i = 0; i < cad.quant; i++) {
        if (cad.func[i].dia == dia &&
            cad.func[i].mes == mes &&
            cad.func[i].ano == ano &&
            cad.func[i].sexo == sexo) {
            printf("%s\n", cad.func[i].nome);
            achou = 1;
        }
    }

    if (achou == 0) {
        printf("Nenhum funcionario encontrado.\n");
    }
}

int main() {
    TipoCadastro cad = {0};
    int dia, mes, ano;
    char sexo;

    cad = LeFuncionarios(cad);

    printf("\nDigite o dia: ");
    scanf("%d", &dia);

    printf("Digite o mes: ");
    scanf("%d", &mes);

    printf("Digite o ano: ");
    scanf("%d", &ano);

    printf("Digite o sexo (F/M): ");
    scanf(" %c", &sexo);

    printf("\nFuncionarios encontrados:\n");
    ListaAniversarioSexo(cad, dia, mes, ano, sexo);

    return 0;
}
