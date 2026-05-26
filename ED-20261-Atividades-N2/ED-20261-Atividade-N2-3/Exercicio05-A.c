// RA: 2040482513019 - Vinicius Kenji dos Santos Enoki

#include <stdio.h>
#include <stdlib.h>

/*
 * ABB resultante apos inserir: 50,30,70,20,40,60,80,10,25,45,65
 *
 *              50
 *            /    \
 *          30      70
 *         /  \    /  \
 *        20  40  60  80
 *       / \    \   \
 *      10  25  45  65
 */

typedef struct Nozinho {
    int val;
    struct Nozinho *esq;
    struct Nozinho *dir;
} Nozinho;

Nozinho *inserir(Nozinho *raiz, int novo_val) {
    Nozinho *fresco;
    if (raiz == NULL) {
        fresco = (Nozinho *)malloc(sizeof(Nozinho));
        fresco->val = novo_val;
        fresco->esq = NULL;
        fresco->dir = NULL;
        return fresco;
    }
    if (novo_val < raiz->val)
        raiz->esq = inserir(raiz->esq, novo_val);
    else
        raiz->dir = inserir(raiz->dir, novo_val);
    return raiz;
}

// retorna -1 para nulo, 0 para folha, caso contrario max(esq,dir)+1
int alturaNo(Nozinho *nd) {
    int ae, ad;
    if (nd == NULL) return -1;
    ae = alturaNo(nd->esq);
    ad = alturaNo(nd->dir);
    return (ae > ad ? ae : ad) + 1;
}

// retorna -1 se nao achar
int profundidadeNo(Nozinho *raiz, int procurado, int prof_acum) {
    if (raiz == NULL) return -1;
    if (raiz->val == procurado) return prof_acum;
    if (procurado < raiz->val)
        return profundidadeNo(raiz->esq, procurado, prof_acum + 1);
    return profundidadeNo(raiz->dir, procurado, prof_acum + 1);
}

// numero de filhos diretos
int grauNo(Nozinho *nd) {
    int g = 0;
    if (nd == NULL) return 0;
    if (nd->esq != NULL) g++;
    if (nd->dir != NULL) g++;
    return g;
}

// percurso em-ordem para imprimir grau de cada no
void grauEmOrdem(Nozinho *nd) {
    if (nd == NULL) return;
    grauEmOrdem(nd->esq);
    printf("  no=%d  grau=%d\n", nd->val, grauNo(nd));
    grauEmOrdem(nd->dir);
}

void liberarArvore(Nozinho *nd) {
    if (nd == NULL) return;
    liberarArvore(nd->esq);
    liberarArvore(nd->dir);
    free(nd);
}

int main() {
    int seq[] = {50, 30, 70, 20, 40, 60, 80, 10, 25, 45, 65};
    int tam = 11, k;
    Nozinho *raizao = NULL;

    for (k = 0; k < tam; k++)
        raizao = inserir(raizao, seq[k]);

    // Parte B - a) alturas
    printf("=== Alturas ===\n");
    int alvos_alt[] = {50, 30, 70, 20, 10};
    for (k = 0; k < 5; k++) {
        // busca manual so pra pegar o ponteiro do no
        Nozinho *cur = raizao;
        while (cur && cur->val != alvos_alt[k])
            cur = (alvos_alt[k] < cur->val) ? cur->esq : cur->dir;
        printf("  altura(%d) = %d\n", alvos_alt[k], alturaNo(cur));
    }

    // Parte B - b) profundidades
    printf("\n=== Profundidades ===\n");
    int alvos_prof[] = {50, 30, 70, 45, 10};
    for (k = 0; k < 5; k++)
        printf("  prof(%d) = %d\n", alvos_prof[k], profundidadeNo(raizao, alvos_prof[k], 0));

    // Parte B - c) grau de cada no em-ordem
    printf("\n=== Grau de cada no (em-ordem) ===\n");
    grauEmOrdem(raizao);

    // Parte B - d) altura total
    printf("\n=== Altura total da arvore ===\n");
    printf("  altura = %d\n", alturaNo(raizao));

    liberarArvore(raizao);
    return 0;
}
