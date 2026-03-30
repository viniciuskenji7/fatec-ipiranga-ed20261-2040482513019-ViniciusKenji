/*----------------------------------------------------------------------------------*/
/* FATEC-Ipiranga                                    */        
/* ADS - Estrutura de Dados                              */
/* Id da Atividade: N1-3                      */
/* Objetivo: Desenvolver uma aplicação que simule o funcionamento lógico da calculadora financeira HP12C, utilizando os conceitos de     /Estrutura de Dados de Pilha (Stack) para o processamento de expressões em Notação Polonesa Reversa. */
/*                                                                                  */
/*Autor: Vinicius Kenji dos Santos Enoki                     */
/*                                                                   Data:25/03/2026*/
/*----------------------------------------------------------------------------------*/



#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 4

// Tipo pilha
typedef struct {
    int data[MAX_LENGTH];
    int topo;
} Pilha;

// Iniciando pilha
void inicializarPilha(Pilha *p) {
    p->topo = -1;
    printf("Pilha inicializada com sucesso\n");
}

// Verificação de pilha
int pilhaVazia(Pilha *p) {
    if (p->topo == -1) {
        return 1;
    } else {
        return 0;
    }
}

// Listando pilha
void listarPilha(Pilha *p) {
    if (pilhaVazia(p)) {
        printf("A pilha esta vazia\n");
        return;
    }
    printf("Estes sao os elementos da pilha: \n");

    for (int i = 0; i <= p->topo; i++) {
        printf("%d\n", p->data[i]);
    }
}

// Inserindo pilha
int push(Pilha *p, int x) {
    if (p->topo == MAX_LENGTH - 1) {
        printf("A pilha esta cheia\n");
        return 0;
    }
    p->data[++p->topo] = x;
    return 1;
}

// Removendo pilha
int pop(Pilha *p, int *out) {
    if (p->topo == -1) {
        return 0;
    }
    *out = p->data[p->topo--];
    return 1;
}



int main() {

    Pilha calculadora;
    inicializarPilha(&calculadora);

    char entrada[100];

    printf("Digite a expressao RPN: \n");


    return 0;
}

