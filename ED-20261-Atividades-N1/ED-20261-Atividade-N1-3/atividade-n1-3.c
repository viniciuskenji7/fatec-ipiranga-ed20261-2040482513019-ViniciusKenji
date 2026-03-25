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

void inicializarPilha(Pilha pilha) {
    pilha.topo = -1;
    printf("Pilha inicializada com sucesso");
}

// Listando pilha
void listarPilha(Pilha pilha) {
    if (pilha.topo == -1) {
        printf("A pilha está vazia");
    }
    printf("Estes são os elementos da pilha: %d", pilha.data);
}


int calculadora(Pilha numeros, char op) {
    
}


int main() {

    printf("Ola mundo");

    return 0;
}

