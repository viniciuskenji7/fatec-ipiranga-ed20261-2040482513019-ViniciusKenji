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
#include <ctype.h>
#include <stdlib.h>

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

// Verificar se é número
int ehNumero(char *token) {
    // Precisa implementar:
    // - Verificar se o primeiro caractere é um dígito ou sinal de menos
    // - Retornar 1 se for número, 0 se não
    if (isdigit(token) == 0) {
        return 0;
    }
    return 1;
}

//Executar operação
int executarOperacao(Pilha *p, char operador) {
    // - Precisa implementar:
    // - Fazer pop de dois valores
    // - Aplicar a operação (+, -, *, /)
    // - Fazer push do resultado
    // - Retornar 1 se sucesso, 0 se erro
    
}



int main() {

    Pilha pilha;
    inicializarPilha(&pilha);

    char entrada[100];
    char *token;

    pritnf("Digite a expressão NPR: \n");
    fgets(entrada, 100, stdin);

    token = strtok(entrada, " ");

    while(token != NULL) {
        if (ehNumero(token) == 0) {
            switch(*token) {
                case "+":
                    pop()
            }
        }
    }


    return 0;
}

