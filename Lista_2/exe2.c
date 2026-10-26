#include <stdio.h>

struct Ponto {
    int x;
    int y;
};

int estaDentro(struct Ponto p, struct Ponto v1, struct Ponto v2) {
    if (p.x >= v1.x && p.x <= v2.x && p.y >= v1.y && p.y <= v2.y) {
        return 1;
    }
    return 0;
}

int main() {
    struct Ponto v1, v2, p;

    scanf("%d %d", &v1.x, &v1.y);
    scanf("%d %d", &v2.x, &v2.y);
    scanf("%d %d", &p.x, &p.y);

    if (estaDentro(p, v1, v2)) {
        printf("Dentro\n");
    } else {
        printf("Fora\n");
    }

    return 0;
}