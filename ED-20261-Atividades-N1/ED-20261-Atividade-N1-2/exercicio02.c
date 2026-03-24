/*--------------------------------------------------*/
/* FATEC-Ipiranga */
/* ADS - Estrutura de Dados */
/* Id da Atividade: N2-2 */
/* Objetivo: Estado de memória */
/* */
/* Autor: Vinicius Kenji dos Santos Enoki */
/* Data: 24/03/2026 */
/*--------------------------------------------------*/
#include <stdio.h>
// Versão iterativa que imprime os dígitos na ordem inversa
void inverterNumero(int n) {
    if (n == 0) {
        printf("0");
        return;
    }
    while (n > 0) {
        printf("%d", n % 10);
        n = n / 10;
    }
}

int main() {
    int valor = 12345;
    printf("Invertendo o numero %d: ", valor);
    inverterNumero(valor);
    printf("\n");
    return 0;
}
