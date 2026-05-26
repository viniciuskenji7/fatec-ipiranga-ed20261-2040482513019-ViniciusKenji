// RA: 2040482513019 - Vinicius Kenji dos Santos Enoki

#include <stdio.h>

void hanoi_nivel(int qtd_discos, char pino_orig, char pino_dest, char pino_aux, int prof_atual) {
    int esp;
    if (qtd_discos == 1) {
        for (esp = 0; esp < prof_atual * 2; esp++) printf(" ");
        printf("[nivel %d] Mover disco 1 de %c para %c\n", prof_atual, pino_orig, pino_dest);
        return;
    }
    hanoi_nivel(qtd_discos - 1, pino_orig, pino_aux, pino_dest, prof_atual + 1);

    for (esp = 0; esp < prof_atual * 2; esp++) printf(" ");
    printf("[nivel %d] Mover disco %d de %c para %c\n", prof_atual, qtd_discos, pino_orig, pino_dest);

    hanoi_nivel(qtd_discos - 1, pino_aux, pino_dest, pino_orig, prof_atual + 1);
}

int main() {
    int tamanhos[] = {1, 3, 4};
    int k;
    for (k = 0; k < 3; k++) {
        printf("\n=== n = %d ===\n", tamanhos[k]);
        hanoi_nivel(tamanhos[k], 'A', 'C', 'B', 0);
    }
    return 0;
}
