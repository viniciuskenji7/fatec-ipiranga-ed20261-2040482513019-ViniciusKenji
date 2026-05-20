// RA: 2040482513019 - Vinicius Kenji dos Santos Enoki
#include <stdio.h>


int main() {

    int v[] = {10, 20, 30, 40, 50};
    int *p = v;
    // Estou fazendo essa divisão pois o resultado que ela me retorna é o tamanho do array. 20 / 4 = 5;
    int size = sizeof(v) / sizeof(v[0]);
    int soma = 0;
    int *inicio = v;
    int *fim = v + size;

    // A) Imprima cada elemento e seu endereço
    printf("Elementos do Vetor e Enderecos:\n");
    for(int i = 0; p < v + size; i++) {
        printf("%d -> %p\n", *p, &p);
        soma += *p;
        p++;
    }
    printf("----------------------------------\n");
    printf("\n");
    printf("----------------------------------\n");
    printf("Soma de todos os elementos: %d\n", soma);
    printf("Invertendo vetor: \n");
    while(inicio < fim) {
        *inicio = *inicio + *fim;
        *fim = *inicio - *fim;
        *inicio = *inicio - *fim;

        inicio++;
        fim--;
    }
    p = v;
    for(int i = 0; p < v + (size + 1); i++) {
        printf("%d\n", *p);
        p++;
    }
    printf("--------------------------------\n");
    
    // B) Calcule e imprima a soma de todos os elementos.

    return 0;
}