// RA: 2040482513019 - Vinicius Kenji dos Santos Enoki

#include <stdio.h>

int ch_rapida = 0;
int ch_ingenua = 0;

// caso base: exp == 0 => retorna 1
// caso recursivo par:  base^exp = (base^(exp/2))^2   => O(log n)
// caso recursivo impar: base^exp = base * base^(exp-1)
long long potenciaRapida(long long b, int e) {
    long long metade;
    ch_rapida++;
    if (e == 0) return 1;
    if (e % 2 == 0) {
        metade = potenciaRapida(b, e / 2);
        return metade * metade;
    }
    return b * potenciaRapida(b, e - 1);
}

// abordagem ingenua: base^n = base * base^(n-1) => O(n)
long long potenciaIngenua(long long b, int e) {
    ch_ingenua++;
    if (e == 0) return 1;
    return b * potenciaIngenua(b, e - 1);
}

int main() {
    long long r1, r2;

    // 2^10
    ch_rapida = 0; ch_ingenua = 0;
    r1 = potenciaRapida(2, 10);
    r2 = potenciaIngenua(2, 10);
    printf("2^10 = %lld | chamadas rapida=%d, ingenua=%d\n", r1, ch_rapida, ch_ingenua);

    // 3^7
    ch_rapida = 0; ch_ingenua = 0;
    r1 = potenciaRapida(3, 7);
    r2 = potenciaIngenua(3, 7);
    printf("3^7  = %lld | chamadas rapida=%d, ingenua=%d\n", r1, ch_rapida, ch_ingenua);

    // 5^0
    ch_rapida = 0; ch_ingenua = 0;
    r1 = potenciaRapida(5, 0);
    r2 = potenciaIngenua(5, 0);
    printf("5^0  = %lld | chamadas rapida=%d, ingenua=%d\n", r1, ch_rapida, ch_ingenua);

    // 7^12
    ch_rapida = 0; ch_ingenua = 0;
    r1 = potenciaRapida(7, 12);
    r2 = potenciaIngenua(7, 12);
    printf("7^12 = %lld | chamadas rapida=%d, ingenua=%d\n", r1, ch_rapida, ch_ingenua);

    (void)r2; // evita warning de variavel nao usada
    return 0;
}
