#include <stdio.h>
#include <stdlib.h>

struct No {
    int valor;
    int altura;
    struct No *esq;
    struct No *dir;
};

int maior(int a, int b) {
    return (a > b) ? a : b;
}

int calcularAltura(struct No* n) {
    if (n == NULL) {
        return -1;
    }
    int alturaEsq = calcularAltura(n->esq);
    int alturaDir = calcularAltura(n->dir);

    n->altura = 1 + maior(alturaEsq, alturaDir);

    return n->altura;
}

int obterFB(struct No* n) {
    if (n == NULL) {
        return 0;
    }

    int alturaEsq = calcularAltura(n->esq);
    int alturaDir = calcularAltura(n->dir);

    return alturaEsq - alturaDir;
}

struct No* criarNo(int valor) {
    struct No* novo = (struct No*) malloc(sizeof(struct No));

    novo->valor = valor;
    novo->altura = 0;
    novo->esq = NULL;
    novo->dir = NULL;

    return novo;
}

int main() {

    struct No* raiz = criarNo(20);
    raiz->esq = criarNo(10);
    raiz->esq->esq = criarNo(5);
    raiz->esq->esq->esq = criarNo(2);

    int alturaRaiz = calcularAltura(raiz);
    int fbRaiz = obterFB(raiz);

    printf("Altura da raiz (%d): %d\n", raiz->valor, alturaRaiz);
    printf("Fator de Balanceamento da raiz (%d): %d\n", raiz->valor, fbRaiz);

    return 0;
}