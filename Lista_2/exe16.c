
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

void AtualizaSalario(TipoCadastro *cad) {
    char rg[20];
    float salario;
    int achou = 0;

    printf("Digite o RG do funcionario: ");
    scanf(" %19s", rg);

    for (int i = 0; i < cad->quant; i++) {
        if (strcmp(cad->func[i].rg, rg) == 0) {
            printf("Digite o novo salario: ");
            scanf("%f", &salario);

            cad->func[i].salario = salario;
            achou = 1;

            printf("Salario atualizado com sucesso!\n");
            break;
        }
    }

    if (achou == 0) {
        printf("Funcionario nao encontrado.\n");
    }
}

void MostraFuncionarios(TipoCadastro cad) {
    for (int i = 0; i < cad.quant; i++) {
        printf("\nNome: %s\n", cad.func[i].nome);
        printf("RG: %s\n", cad.func[i].rg);
        printf("Salario: %.2f\n", cad.func[i].salario);
        printf("Idade: %d\n", cad.func[i].idade);
        printf("Sexo: %d\n", cad.func[i].sexo);
        printf("Nascimento: %02d/%02d/%d\n",
               cad.func[i].dia,
               cad.func[i].mes,
               cad.func[i].ano);
    }
}

int main() {
    TipoCadastro cad = {0};

    cad = LeFuncionarios(cad);

    AtualizaSalario(&cad);

    printf("\nCadastro atualizado:\n");
    MostraFuncionarios(cad);

    return 0;
}
