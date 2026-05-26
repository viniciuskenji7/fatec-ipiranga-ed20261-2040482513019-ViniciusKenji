// RA: 2040482513019 - Vinicius Kenji dos Santos Enoki
#include <stdio.h>



void trocar(int *a, int *b) {
    if (a == b) return;
    // O a recebe a soma entre ele e b = 30
    *a = *a + *b;
    // b recebe a subtração entre a (30) e b (20) = 10
    *b = *a - *b;
    // a recebe a subtração entre ele e b = 30 - 10 = 20
    *a = *a - *b;
}

int main() {
    int x = 10;
    int y = 20;

    // Utilizando esse (void *) para indicar que estou printando um endereço de memoria e nao um integer normal
    printf("Endereco x = %p, Endereco y = %p\n", (void *)&x, (void *)&y);
    printf("Antes: x = %d, y = %d\n", x, y);
    // Passando os endereços para a troca
    trocar(&x, &y);
    printf("Depois: x = %d, y = %d\n", x, y);
    printf("Endereco x = %p, Endereco y = %p\n", (void *)&x, (void *)&y);

    return 0;
}