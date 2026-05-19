#include "recursao.h"
#include <stdio.h>

void decToBin(int num) {
    if (num < 0) {
        printf("-");
        decToBin(-num);
        return;
    }
    if (num == 0) return;
    
    decToBin(num / 2);
    printf("%d", num % 2);
}

int potencia(int b, int e) {
    // caso base
    if (e == 0) return 1;
    return b * potencia(b, e - 1);
}

int somaDigitos(int n) {
    // se for negativo, transforma em positivo
    if (n < 0) n = -n;
    
    if (n < 10) return n;
    
    return (n % 10) + somaDigitos(n / 10);
}
