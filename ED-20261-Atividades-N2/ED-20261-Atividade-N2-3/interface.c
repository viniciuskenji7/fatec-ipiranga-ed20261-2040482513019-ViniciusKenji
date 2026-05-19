#include "interface.h"
#include <stdio.h>

void exibirMenu(void) {
    printf("\n------------------------------------------\n");
    printf("|      CUCC - Conversor e Calculadora      |\n");
    printf("|          Cientifica em C                 |\n");
    printf("|------------------------------------------|\n");
    printf("|  1. Converter Decimal para Binario       |\n");
    printf("|  2. Calcular Potencia (base^exp)         |\n");
    printf("|  3. Somar Digitos de um Numero           |\n");
    printf("|  0. Sair                                 |\n");
    printf("|------------------------------------------|\n");
    printf("Escolha uma opcao: ");
}

int lerOpcao(void) {
    int opt;
    if (scanf("%d", &opt) != 1) {
        while (getchar() != '\n');
        return -1;
    }
    return opt;
}

int lerInteiro(const char *msg) {
    int val;
    printf("%s", msg);
    while (scanf("%d", &val) != 1) {
        // limpa buffer se entrada errada
        while (getchar() != '\n');
        printf("Entrada invalida. %s", msg);
    }
    return val;
}

int lerInteiroPositivo(const char *msg) {
    int val;
    do {
        val = lerInteiro(msg);
        if (val < 0)
            printf("Por favor, informe um valor >= 0.\n");
    } while (val < 0);
    return val;
}
