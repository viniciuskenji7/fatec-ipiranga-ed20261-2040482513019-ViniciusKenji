#include <stdio.h>
#include <stdlib.h>

struct Noh {
    int dado;
    int nivel;
    struct Noh *ladoEsq;
    struct Noh *ladoDir;
};

// Retorna o maior valor
int compararMaior(int num1, int num2) {
    return (num1 > num2) ? num1 : num2;
}

// Calcula a altura dos nós
int atualizarAltura(struct Noh* atual) {
    if (atual == NULL) {
        return -1;
    }

    int alturaLadoEsq = atualizarAltura(atual->ladoEsq);
    int alturaLadoDir = atualizarAltura(atual->ladoDir);

    atual->nivel = 1 + compararMaior(alturaLadoEsq, alturaLadoDir);

    return atual->nivel;
}

// Calcula o fator de balanceamento
int calcularFB(struct Noh* atual) {
    if (atual == NULL) {
        return 0;
    }

    int alturaLadoEsq = atualizarAltura(atual->ladoEsq);
    int alturaLadoDir = atualizarAltura(atual->ladoDir);

    return alturaLadoEsq - alturaLadoDir;
}

// Cria um novo nó
struct Noh* novoElemento(int numero) {
    struct Noh* elemento = (struct Noh*) malloc(sizeof(struct Noh));

    elemento->dado = numero;
    elemento->nivel = 0;
    elemento->ladoEsq = NULL;
    elemento->ladoDir = NULL;

    return elemento;
}

int main() {

    struct Noh* topo = novoElemento(20);
    topo->ladoEsq = novoElemento(10);
    topo->ladoEsq->ladoEsq = novoElemento(5);
    topo->ladoEsq->ladoEsq->ladoEsq = novoElemento(2);

    int alturaTopo = atualizarAltura(topo);
    int fbTopo = calcularFB(topo);

    printf("Altura da raiz (%d): %d\n", topo->dado, alturaTopo);
    printf("Fator de Balanceamento da raiz (%d): %d\n", topo->dado, fbTopo);

    return 0;
}