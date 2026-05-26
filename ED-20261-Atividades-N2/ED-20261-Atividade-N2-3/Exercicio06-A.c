// RA: 2040482513019 - Vinicius Kenji dos Santos Enoki

#include <stdio.h>
#include <stdlib.h>

typedef struct Nozinho {
    int val;
    struct Nozinho *esq;
    struct Nozinho *dir;
} Nozinho;

Nozinho *inserir(Nozinho *raiz, int v) {
    Nozinho *novo;
    if (raiz == NULL) {
        novo = (Nozinho *)malloc(sizeof(Nozinho));
        novo->val = v; novo->esq = NULL; novo->dir = NULL;
        return novo;
    }
    if (v < raiz->val){
        raiz->esq = inserir(raiz->esq, v);    
    } else {
        raiz->dir = inserir(raiz->dir, v);
    }
    return raiz;
}

int alturaNo(Nozinho *nd) {
    int ae, ad;
    if (nd == NULL) return -1;
    ae = alturaNo(nd->esq);
    ad = alturaNo(nd->dir);
    return (ae > ad ? ae : ad) + 1;
}

int profundidadeNo(Nozinho *raiz, int alvo, int acum) {
    if (raiz == NULL) return -1;
    if (raiz->val == alvo) return acum;
    if (alvo < raiz->val) return profundidadeNo(raiz->esq, alvo, acum + 1);
    return profundidadeNo(raiz->dir, alvo, acum + 1);
}

int grauNo(Nozinho *nd) {
    int g = 0;
    if (nd == NULL) return 0;
    if (nd->esq) g++;
    if (nd->dir) g++;
    return g;
}

// imprime ancestrais do pai ate a raiz (recursivo)
// retorna 1 se achou o valor na subarvore, 0 caso contrario
int imprimirAncestral(Nozinho *raiz, int alvo) {
    int achou;
    if (raiz == NULL) return 0;
    if (raiz->val == alvo) return 1;
    achou = imprimirAncestral(raiz->esq, alvo);
    if (!achou) achou = imprimirAncestral(raiz->dir, alvo);
    if (achou) printf("%d ", raiz->val);
    return achou;
}

// percurso em-ordem imprimindo descendentes (exceto o proprio no raiz da subarvore)
void descEmOrdem(Nozinho *nd, int eh_raiz_chamada) {
    if (nd == NULL) return;
    descEmOrdem(nd->esq, 0);
    if (!eh_raiz_chamada) printf("%d ", nd->val);
    descEmOrdem(nd->dir, 0);
}

void imprimirDescendentes(Nozinho *raiz, int alvo) {
    Nozinho *cur = raiz;
    while (cur && cur->val != alvo){
        cur = (alvo < cur->val) ? cur->esq : cur->dir;
    }
    if (cur == NULL) printf("(nao encontrado)"); return;
    descEmOrdem(cur, 1);
}

int contarDescendentes(Nozinho *nd) {
    if (nd == NULL) return 0;
    return 1 + contarDescendentes(nd->esq) + contarDescendentes(nd->dir);
}

void relatorioNo(Nozinho *raiz, int alvo) {
    Nozinho *cur = raiz;
    while (cur && cur->val != alvo)
        cur = (alvo < cur->val) ? cur->esq : cur->dir;

    if (cur == NULL) {
        printf("Erro: no %d nao existe na arvore.\n", alvo);
        return;
    }

    printf("+----------------------------------+\n");
    printf("| RELATORIO DO NO: %-16d|\n", alvo);
    printf("+----------------------------------+\n");
    printf("| Profundidade : %-17d|\n", profundidadeNo(raiz, alvo, 0));
    printf("| Altura       : %-17d|\n", alturaNo(cur));
    printf("| Grau         : %-17d|\n", grauNo(cur));
    printf("| Ancestrais   : ");
    imprimirAncestral(raiz, alvo);
    printf("\n");
    printf("| Descendentes : ");
    imprimirDescendentes(raiz, alvo);
    printf("\n");
    printf("| Qtd Descend. : %-17d|\n", contarDescendentes(cur) - 1 + (cur->esq || cur->dir ? 0 : 0));
    // contarDescendentes conta a propria subarvore menos o no raiz
    // reescrevendo de forma clara:
    printf("+----------------------------------+\n\n");
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

    for (k = 0; k < tam; k++){
        raizao = inserir(raizao, seq[k]);
    }
    relatorioNo(raizao, 50);
    relatorioNo(raizao, 30);
    relatorioNo(raizao, 10);
    relatorioNo(raizao, 70);

    // teste com no inexistente
    relatorioNo(raizao, 99);

    liberarArvore(raizao);
    return 0;
}
