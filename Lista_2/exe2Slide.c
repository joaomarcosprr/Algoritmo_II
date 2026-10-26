#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int dia, mes, ano;
}DATA;

typedef struct{
    char primeiro_nome[10], segundo_nome[10], RG[10];
    float salario;
    DATA dataAniversario, dataAdmissao;
}Empregados;



int main(){

    Empregados Empresa[2];
    for(int i = 0; i < 2; i++){
        system("cls");
        printf("\nInforme seu primeiro nome:");
        fgets(Empresa[i].primeiro_nome, 10, stdin);
        Empresa[i].primeiro_nome[strcspn(Empresa[i].primeiro_nome, "\n")] = '\0';
        printf("\nInforme seu segundo nome:");
        fgets(Empresa[i].segundo_nome, 10, stdin);
        Empresa[i].segundo_nome[strcspn(Empresa[i].segundo_nome, "\n")] = '\0';
        printf("\nInforme seu RG: ");
        fgets(Empresa[i].RG, 10, stdin);
        Empresa[i].RG[strcspn(Empresa[i].RG, "\n")] = '\0';
        printf("\nInforme o salario:");
        scanf("%f", &Empresa[i].salario);
        getchar();
        printf("\nInforme a sua data de nascimento: (dd mm yyyy)");
        scanf("%d %d %d", &Empresa[i].dataAniversario.dia, &Empresa[i].dataAniversario.mes, &Empresa[i].dataAniversario.ano);
        getchar();
        printf("\nInforme a sua data de admissao: (dd mm yyyy)");
        scanf("%d %d %d", &Empresa[i].dataAdmissao.dia, &Empresa[i].dataAdmissao.mes, &Empresa[i].dataAdmissao.ano);
        getchar();
        
    }

    for(int i = 0; i < 2; i++){
        printf("Nome: %s %s\n", Empresa[i].primeiro_nome, Empresa[i].segundo_nome);
        printf("Nascimento: %d/%d/%d\n", Empresa[i].dataAniversario.dia, Empresa[i].dataAniversario.mes, Empresa[i].dataAniversario.ano);
        printf("RG: %s\n", Empresa[i].RG);
        printf("Salario: %.2f\n", Empresa[i].salario);
        printf("Nascimento: %d/%d/%d\n", Empresa[i].dataAdmissao.dia, Empresa[i].dataAdmissao.mes, Empresa[i].dataAdmissao.ano);
        printf("\n");


    }
    printf("\nSalario do casal: %.2f", Empresa[0].salario+Empresa[1].salario);

    return 0;
}