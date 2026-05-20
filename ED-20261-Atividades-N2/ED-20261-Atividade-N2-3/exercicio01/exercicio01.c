
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


    printf("Antes: x = %d, y = %d\n", x, y);
    trocar(&x, &y);
    printf("Depois: x = %d, y = %d\n", x, y);

    return 0;
}