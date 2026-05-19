#include <stdio.h>
#include "recursao.h"
#include "interface.h"

int main(void) {
    int opt, num, base, exponent, res;

    do {
        exibirMenu();
        opt = lerOpcao();

        switch (opt) {
            case 1:
                // converte pra binario
                num = lerInteiro("Digite um numero inteiro: ");
                printf("Binario de %d: ", num);
                if (num == 0)
                    printf("0");
                else
                    decToBin(num);
                printf("\n");
                break;

            case 2:
                base = lerInteiro("Digite a base: ");
                exponent  = lerInteiroPositivo("Digite o expoente (>= 0): ");
                res = potencia(base, exponent);
                printf("Resultado: %d^%d = %d\n", base, exponent, res);
                break;

            case 3:
                num = lerInteiro("Digite um numero inteiro: ");
                res = somaDigitos(num);
                printf("Soma dos digitos de %d = %d\n", num, res);
                break;

            case 0:
                printf("Encerrando o CUCC. Ate logo!\n");
                break;

            default:
                printf("Opcao invalida. Tente novamente.\n");
        }

    } while (opt != 0);

    return 0;
}
