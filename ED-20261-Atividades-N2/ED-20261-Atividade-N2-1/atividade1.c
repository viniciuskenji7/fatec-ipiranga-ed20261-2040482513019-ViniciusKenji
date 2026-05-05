#include <stdio.h>
#include <stdlib.h>
#include "viniciuskenji.h"

// =======================
// Funções auxiliares BST
// =======================

No* inserir(No* raiz, int valor) {
    if (raiz == NULL) {
        No* novo = (No*) malloc(sizeof(No));
        novo->valor = valor;
        novo->esq = novo->dir = NULL;
        return novo;
    }

    if (valor < raiz->valor)
        raiz->esq = inserir(raiz->esq, valor);
    else
        raiz->dir = inserir(raiz->dir, valor);

    return raiz;
}

No* buscar(No* raiz, int valor) {
    if (raiz == NULL || raiz->valor == valor)
        return raiz;

    if (valor < raiz->valor)
        return buscar(raiz->esq, valor);

    return buscar(raiz->dir, valor);
}

// =======================
// Implementações exigidas
// =======================

void imprimir_nos_internos(No* raiz) {
    if (raiz == NULL) return;

    if (raiz->esq != NULL || raiz->dir != NULL)
        printf("%d ", raiz->valor);

    imprimir_nos_internos(raiz->esq);
    imprimir_nos_internos(raiz->dir);
}

void imprimir_folhas(No* raiz) {
    if (raiz == NULL) return;

    if (raiz->esq == NULL && raiz->dir == NULL)
        printf("%d ", raiz->valor);

    imprimir_folhas(raiz->esq);
    imprimir_folhas(raiz->dir);
}

int calcular_altura(No* no) {
    if (no == NULL) return -1;

    int esq = calcular_altura(no->esq);
    int dir = calcular_altura(no->dir);

    return (esq > dir ? esq : dir) + 1;
}

int calcular_profundidade(No* raiz, int valor, int profundidade_atual) {
    if (raiz == NULL) return -1;

    if (raiz->valor == valor)
        return profundidade_atual;

    if (valor < raiz->valor)
        return calcular_profundidade(raiz->esq, valor, profundidade_atual + 1);

    return calcular_profundidade(raiz->dir, valor, profundidade_atual + 1);
}

void imprimir_nivel(No* raiz, int nivel) {
    if (raiz == NULL) return;

    if (nivel == 0)
        printf("%d ", raiz->valor);
    else {
        imprimir_nivel(raiz->esq, nivel - 1);
        imprimir_nivel(raiz->dir, nivel - 1);
    }
}

void imprimir_niveis(No* raiz, int nivel_atual) {
    int h = calcular_altura(raiz);

    for (int i = 0; i <= h; i++) {
        printf("Nivel %d: ", i);
        imprimir_nivel(raiz, i);
        printf("\n");
    }
}

void imprimir_ancestrais(No* raiz, int valor) {
    if (raiz == NULL) return;

    if (raiz->valor == valor)
        return;

    if ((valor < raiz->valor && buscar(raiz->esq, valor)) ||
        (valor > raiz->valor && buscar(raiz->dir, valor))) {

        printf("%d ", raiz->valor);

        if (valor < raiz->valor)
            imprimir_ancestrais(raiz->esq, valor);
        else
            imprimir_ancestrais(raiz->dir, valor);
    }
}

void imprimir_descendentes(No* no) {
    if (no == NULL) return;

    if (no->esq) {
        printf("%d ", no->esq->valor);
        imprimir_descendentes(no->esq);
    }

    if (no->dir) {
        printf("%d ", no->dir->valor);
        imprimir_descendentes(no->dir);
    }
}

// =======================
// FUNÇÃO PRINCIPAL
// =======================

void analisar_arvore(No* raiz, int valorBusca) {

    printf("=== DIAGNOSTICO GERAL ===\n");

    printf("Raiz: %d\n", raiz->valor);

    printf("Nos internos: ");
    imprimir_nos_internos(raiz);
    printf("\n");

    printf("Folhas: ");
    imprimir_folhas(raiz);
    printf("\n");

    printf("\nEstrutura por niveis:\n");
    imprimir_niveis(raiz, 0);

    printf("\n=== DIAGNOSTICO DO NO %d ===\n", valorBusca);

    No* no = buscar(raiz, valorBusca);

    if (no == NULL) {
        printf("Valor nao encontrado.\n");
        return;
    }

    // Grau
    int grau = 0;
    if (no->esq) grau++;
    if (no->dir) grau++;
    printf("Grau: %d\n", grau);

    // Ancestrais
    printf("Ancestrais: ");
    imprimir_ancestrais(raiz, valorBusca);
    printf("\n");

    // Descendentes
    printf("Descendentes: ");
    imprimir_descendentes(no);
    printf("\n");

    // Altura
    printf("Altura: %d\n", calcular_altura(no));

    // Profundidade
    printf("Profundidade: %d\n",
        calcular_profundidade(raiz, valorBusca, 0));

    // Subárvore
    printf("\nSubarvore:\n");
    imprimir_niveis(no, 0);
}

// =======================
// MAIN PARA TESTE
// =======================

int main() {
    No* raiz = NULL;

    int valores[] = {50, 30, 70, 20, 40, 60, 80};

    for (int i = 0; i < 7; i++)
        raiz = inserir(raiz, valores[i]);

    analisar_arvore(raiz, 30);

    return 0;
}