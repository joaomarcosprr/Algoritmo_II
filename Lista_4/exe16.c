#include <stdio.h>

int main() {
    FILE *arq;
    char linha[1024];
    char palavras[60][65];
    char palavra_atual[65];
    int qtd_palavras = 0;
    int soma_letras = 0;
    int indent = 0;
    int sem_formatacao = 0;
    int linhas_pagina = 0;
    int pagina = 1;
    int i, j, k, len;

    arq = fopen("texto.txt", "r");
    if (arq == NULL) {
        printf("Erro ao abrir o arquivo texto.txt\n");
        return 1;
    }

    while (fgets(linha, 1024, arq) != NULL) {
        len = 0;
        while (linha[len] != '\0') {
            if (linha[len] == '\n' || linha[len] == '\r') {
                linha[len] = '\0';
                break;
            }
            len++;
        }

        if (sem_formatacao == 1) {
            if (linha[0] == '.' && linha[1] == 'd' && linha[2] == 'E' && (linha[3] == '\0' || linha[3] == ' ')) {
                sem_formatacao = 0;
            } else {
                printf("%s\n", linha);
                linhas_pagina++;
                if (linhas_pagina == 59) {
                    printf("Pagina %d\n", pagina);
                    pagina++;
                    linhas_pagina = 0;
                }
            }
        } else {
            if (linha[0] == '.' && linha[1] == 'p' && linha[2] == 'p' && (linha[3] == '\0' || linha[3] == ' ')) {
                if (qtd_palavras > 0) {
                    for (i = 0; i < indent; i++) {
                        printf(" ");
                    }
                    for (i = 0; i < qtd_palavras; i++) {
                        printf("%s", palavras[i]);
                        if (i < qtd_palavras - 1) {
                            printf(" ");
                        }
                    }
                    printf("\n");
                    linhas_pagina++;
                    if (linhas_pagina == 59) {
                        printf("Pagina %d\n", pagina);
                        pagina++;
                        linhas_pagina = 0;
                    }
                    qtd_palavras = 0;
                    soma_letras = 0;
                }
                indent = 5;
            } else if (linha[0] == '.' && linha[1] == 'd' && linha[2] == 'S' && (linha[3] == '\0' || linha[3] == ' ')) {
                if (qtd_palavras > 0) {
                    for (i = 0; i < indent; i++) {
                        printf(" ");
                    }
                    for (i = 0; i < qtd_palavras; i++) {
                        printf("%s", palavras[i]);
                        if (i < qtd_palavras - 1) {
                            printf(" ");
                        }
                    }
                    printf("\n");
                    linhas_pagina++;
                    if (linhas_pagina == 59) {
                        printf("Pagina %d\n", pagina);
                        pagina++;
                        linhas_pagina = 0;
                    }
                    qtd_palavras = 0;
                    soma_letras = 0;
                    indent = 0;
                }
                sem_formatacao = 1;
            } else {
                i = 0;
                while (linha[i] != '\0') {
                    while (linha[i] == ' ' || linha[i] == '\t') {
                        i++;
                    }
                    if (linha[i] == '\0') {
                        break;
                    }

                    j = 0;
                    while (linha[i] != '\0' && linha[i] != ' ' && linha[i] != '\t') {
                        if (j < 60) {
                            palavra_atual[j] = linha[i];
                            j++;
                        }
                        i++;
                    }
                    palavra_atual[j] = '\0';

                    if (qtd_palavras > 0 && (indent + soma_letras + j + qtd_palavras > 60)) {
                        for (k = 0; k < indent; k++) {
                            printf(" ");
                        }
                        if (qtd_palavras == 1) {
                            printf("%s\n", palavras[0]);
                        } else {
                            int espacos_totais = 60 - indent - soma_letras;
                            int lacunas = qtd_palavras - 1;
                            int espacos_base = espacos_totais / lacunas;
                            int espacos_extras = espacos_totais % lacunas;
                            int w, s;

                            for (w = 0; w < qtd_palavras; w++) {
                                printf("%s", palavras[w]);
                                if (w < lacunas) {
                                    for (s = 0; s < espacos_base; s++) {
                                        printf(" ");
                                    }
                                    if (w < espacos_extras) {
                                        printf(" ");
                                    }
                                }
                            }
                            printf("\n");
                        }

                        linhas_pagina++;
                        if (linhas_pagina == 59) {
                            printf("Pagina %d\n", pagina);
                            pagina++;
                            linhas_pagina = 0;
                        }

                        qtd_palavras = 0;
                        soma_letras = 0;
                        indent = 0;
                    }

                    for (k = 0; k <= j; k++) {
                        palavras[qtd_palavras][k] = palavra_atual[k];
                    }
                    soma_letras += j;
                    qtd_palavras++;
                }
            }
        }
    }

    if (qtd_palavras > 0) {
        for (i = 0; i < indent; i++) {
            printf(" ");
        }
        for (i = 0; i < qtd_palavras; i++) {
            printf("%s", palavras[i]);
            if (i < qtd_palavras - 1) {
                printf(" ");
            }
        }
        printf("\n");
        linhas_pagina++;
    }

    if (linhas_pagina > 0) {
        printf("Pagina %d\n", pagina);
    }

    fclose(arq);

    return 0;
}