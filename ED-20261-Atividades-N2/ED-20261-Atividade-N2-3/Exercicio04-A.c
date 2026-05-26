// RA: 2040482513019 - Vinicius Kenji dos Santos Enoki

#include <stdio.h>

int num_chamadas = 0;

// caso base: inicio > fim => nao achou; inicio==fim e igual => achou
int buscaBinaria(int *arr, int ini, int fim, int alvo) {
    int meio;
    num_chamadas++;
    if (ini > fim) return -1;
    meio = (ini + fim) / 2;
    if (*(arr + meio) == alvo) return meio;
    if (*(arr + meio) < alvo) return buscaBinaria(arr, meio + 1, fim, alvo);
    return buscaBinaria(arr, ini, meio - 1, alvo);
}

int main() {
    int dados[] = {2, 5, 8, 12, 16, 23, 38, 45, 72, 91};
    int tam = 10;
    int resultado;

    // busca de valor presente
    num_chamadas = 0;
    resultado = buscaBinaria(dados, 0, tam - 1, 23);
    printf("Busca por 23: indice=%d, chamadas=%d\n", resultado, num_chamadas);

    // busca de valor ausente
    num_chamadas = 0;
    resultado = buscaBinaria(dados, 0, tam - 1, 99);
    printf("Busca por 99: indice=%d, chamadas=%d\n", resultado, num_chamadas);

    // busca do primeiro elemento
    num_chamadas = 0;
    resultado = buscaBinaria(dados, 0, tam - 1, 2);
    printf("Busca por 2:  indice=%d, chamadas=%d\n", resultado, num_chamadas);

    return 0;
}
