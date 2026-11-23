#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *f_bruto = fopen("salbruto.bin", "rb");
    FILE *f_desc = fopen("desc.bin", "rb");
    FILE *f_liq = fopen("salliq.txt", "w");

    if (f_bruto == NULL || f_desc == NULL || f_liq == NULL) {
        if (f_bruto) fclose(f_bruto);
        if (f_desc) fclose(f_desc);
        if (f_liq) fclose(f_liq);
        return 1;
    }

    float sal_bruto, desconto, sal_liquido;

    while (fread(&sal_bruto, sizeof(float), 1, f_bruto) == 1 &&
           fread(&desconto, sizeof(float), 1, f_desc) == 1) {
        sal_liquido = sal_bruto - desconto;
        fprintf(f_liq, "%.2f\n", sal_liquido);
    }

    fclose(f_bruto);
    fclose(f_desc);
    fclose(f_liq);

    return 0;
}