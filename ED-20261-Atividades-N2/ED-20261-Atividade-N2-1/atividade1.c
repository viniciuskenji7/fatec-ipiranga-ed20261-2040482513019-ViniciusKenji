
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
    int grau;
    int profundidade;
    int length;
}Node;

Node *createNode(int value) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    if(newNode != NULL) {
        newNode->data = value;
        newNode->left = NULL;
        newNode->right = NULL;
        newNode->grau = 1;
        newNode->profundidade = 0;
    }
    
    return newNode;
}

Node *insertData(Node *root, int value) {

    if(root == NULL) {
        return createNode(value);
        printf("\nRoot Inicializado com sucesso!\n");
    }

    if (value < root->data) {
        root->left = insertData(root->left, value);
        root->left->grau += 1;
        root->profundidade += 1;
        printf("\nValor no esquerdo: %d", root->left->data);
    } else if (value > root->data) {
        root->right = insertData(root->right, value);
        root->right->grau += 1;
        root->profundidade += 1;
        printf("\nValor no direito: %d", root->right->data);
    }
    return root;
}

void printData(Node *root) {
    printf("Nó raiz: %d\n", root->data);
    for (int i = 0; i < root->profundidade; i++) {
        if(root->left)
    }
}

int main() {
    Node *root = NULL;
    root = insertData(root, 15);
    root = insertData(root, 50);
    root = insertData(root, 10);
    root = insertData
    return 0;
}


