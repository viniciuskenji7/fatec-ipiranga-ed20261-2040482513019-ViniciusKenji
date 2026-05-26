// RA: 2040482513019 - Vinicius Kenji dos Santos Enoki

#include <stdio.h>

int qtd_mov = 0;

void hanoi(int qtd_discos, char pino_orig, char pino_dest, char pino_aux) {
    if (qtd_discos == 1) {
        printf("Mover disco 1 de %c para %c\n", pino_orig, pino_dest);
        qtd_mov++;
        return;
    }
    hanoi(qtd_discos - 1, pino_orig, pino_aux, pino_dest);
    printf("Mover disco %d de %c para %c\n", qtd_discos, pino_orig, pino_dest);
    qtd_mov++;
    hanoi(qtd_discos - 1, pino_aux, pino_dest, pino_orig);
}

int main() {
    int tamanhos[] = {1, 3, 4};
    int k;
    for (k = 0; k < 3; k++) {
        qtd_mov = 0;
        printf("\n=== n = %d ===\n", tamanhos[k]);
        hanoi(tamanhos[k], 'A', 'C', 'B');
        printf("Total de movimentos: %d\n", qtd_mov);
    }
    return 0;
}
