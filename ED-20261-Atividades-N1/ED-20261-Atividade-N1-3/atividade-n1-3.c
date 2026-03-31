



/*----------------------------------------------------------------------------------*/
/* FATEC-Ipiranga                                    */        
/* ADS - Estrutura de Dados                          */
/* Id da Atividade: N1-3                             */
/* Objetivo: Simular HP12C com RPN usando pilha X,Y,Z,T */
/* Autor: Vinicius Kenji dos Santos Enoki            */
/* Data: 25/03/2026                                  */
/*----------------------------------------------------------------------------------*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct {
    double X, Y, Z, T;
    int topo;
} PilhaHP;

// Inicializa registradores
void inicializar(PilhaHP *p) {
    p->X = p->Y = p->Z = p->T = 0.0;
    p->topo = 0;
}

// Exibe estado da pilha
void mostrar(PilhaHP *p) {
    printf("\n--- ESTADO DA PILHA ---\n");
    printf("T: %.2lf\n", p->T);
    printf("Z: %.2lf\n", p->Z);
    printf("Y: %.2lf\n", p->Y);
    printf("X: %.2lf   <-- DISPLAY\n", p->X);
    printf("-----------------------\n");
}

// Push no modelo HP12c
void pushNumero(PilhaHP *p, double num) {
    if (p->topo == 3) {
        printf("\n-------------------O NUMERO EXCEDEU! DIGITE UMA OPERACAO-----------------------\n");
        return;
    }
    p->T = p->Z;
    p->Z = p->Y;
    p->Y = p->X;
    p->X = num;

    p->topo++;
}

// Verifica se há operandos suficientes
int temOperandos(PilhaHP *p) {
    // precisa pelo menos X e Y válidos
    return !(p->X == 0 && p->Y == 0 && p->Z == 0 && p->T == 0);
}

// Executa operação
int operar(PilhaHP *p, char op) {

    if (!temOperandos(p)) {
        printf("Erro: operandos insuficientes\n");
        return 0;
    }

    double resultado;

    switch (op) {
        case '+':
            resultado = p->Y + p->X;
            break;
        case '-':
            resultado = p->Y - p->X;
            break;
        case '*':
            resultado = p->Y * p->X;
            break;
        case '/':
            if (p->X == 0) {
                printf("Erro: divisao por zero\n");
                return 0;
            }
            resultado = p->Y / p->X;
            break;
        default:
            printf("Erro: operador invalido (%c)\n", op);
            return 0;
    }

    p->X = resultado;
    p->Y = p->Z;
    p->Z = p->T;

    p->topo--;

    return 1;
}

// Valida se token é número
int ehNumero(char *token) {
    if (isdigit(token[0]) || 
       (token[0] == '-' && isdigit(token[1]))) {
        return 1;
    }
    return 0;
}

int main() {

    PilhaHP p;
    char input[200];
    inicializar(&p);

    while (1) {


        printf("\nDigite expressao RPN (ou 'sair'): ");
        fgets(input, sizeof(input), stdin);

        // Removendo \n
        input[strcspn(input, "\n")] = 0;

        //  Para sair da calculadora
        if (strcmp(input, "sair") == 0) {
            printf("Encerrando calculadora...\n");
            break;
        }

        char *token = strtok(input, " ");

        while (token != NULL) {

            // Verificacap do numero
            if (ehNumero(token)) {
                double num = atof(token);
                printf("\nEntrada: %s\n", token);
                pushNumero(&p, num);
                mostrar(&p);
            }

            // Verificacao do operador
            else if (strlen(token) == 1 && strchr("+-*/", token[0])) {
                printf("\nOperador: %c\n", token[0]);

                if (!operar(&p, token[0])) {
                    break;
                }

                mostrar(&p);
            }

            // Caso seja invalido
            else {
                printf("Erro: token invalido -> %s\n", token);
                break;
            }

            token = strtok(NULL, " ");
        }

        printf("\n=================================\n");
        printf("Resultado final: %.2lf\n", p.X);
        printf("=================================\n");
    }

    return 0;
}