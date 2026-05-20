

#include <stdio.h>


void imprimirVetor(float *vet, int n) {
    
    printf("Notas: \n");
    for (int i = 0; i < n; i++) {
        printf("%.2f\n", *vet);
        vet++;
    }
    printf("-----------------------\n");
}

float calcularMedia(float *vet, int n) {
    
    float soma;
    float media;
    printf("Media das Notas: \n");
    for(int i = 0; i < n; i++) {
        soma += *vet;
        vet++;
    }
    media = soma / n;
    printf("Media: %.2f\n", media);
    return media;
}

void encontrarExtremos(float *vet, int n, float *maior, float *menor) {
    // Valores bases para o maior e o menor
    *maior = *vet;
    *menor = *vet;

    printf("Encontrando extremos: \n");
    for(int i = 0; i < n; i++) {
        if(*vet > *maior) {
            *maior = *vet;
        } else if (*vet < *menor) {
            *menor = *vet;
        }
        vet++;
    }
    printf("O maior numero do vetor e: %.2f\n", *maior);
    printf("O menor numero do vetor e: %.2f\n", *menor);
}

void normalizar(float *vet, int n) {
    float normalizado;
    for (int i = 0; i < n; i++) {
        normalizado = *vet / n;
        *vet = normalizado;
        vet++;
    }
    printf("Vetor normalizado: \n");
    for(int i = 0; i < n; i++) {
        printf("%.2f\n", *vet);
        vet++;
    }
}


int main() {

    float notas[] = {
        7.5f,
        3.2f,
        9.8f,
        6.0f,
        5.5f,
        8.1f
    };
    float maior, menor;

    imprimirVetor(notas, 6);
    calcularMedia(notas, 6);
    encontrarExtremos(notas, 6, &maior, &menor);
    normalizar(notas, 6);

    return 0;
}