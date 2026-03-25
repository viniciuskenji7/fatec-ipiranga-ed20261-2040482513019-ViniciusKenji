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

#define MAX_LENGTH 4

// Tipo pilha
typedef struct {
    int data[MAX_LENGTH];
    int topo;
} Pilha;

// Iniciando pilha
void inicializarPilha(Pilha pilha) {
    pilha.topo = -1;
    printf("Pilha inicializada com sucesso");
}

// Listando pilha
void listarPilha(Pilha pilha) {
    if (pilhaVazia == 1) return pritnf("A pilha esta vazia");
    printf("Estes são os elementos da pilha: %d", pilha.data);
}

// Verificação de pilha
int pilhaVazia(Pilha pilha) {
    if (pilha.topo == -1) {
        return 1;
    } else {
        return 0;
    }
}

// Inserindo pilha
void inserirPilha(Pilha pilha, int x) {
    if (pilha.topo == MAX_LENGTH) return printf("A pilha esta cheia");
    pilha.topo++;
    pilha.data[pilha.topo] = x;
}

// Removendo pilha
void removerPilha(Pilha *pilha) {
    int aux;
    if (pilhaVazia == 1) {
        return;
    } else {
        aux = *pilha.data[*pilha.topo];
        *pilha.topo--;
    }
}




int main() {

    printf("Ola mundo");

    return 0;
}

