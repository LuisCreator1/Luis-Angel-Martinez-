#include <stdio.h>

/* Primos.
El programa almacena en un arreglo unidimensional los primeros 100 números
primos. */

const int TAM = 100;

void Imprime(int[], int); /* Prototipos de funciones. */
void Primo(int, int *);

int main(void) {
    int P[TAM] = {2, 3};  // Los dos primeros números primos
    int FLA, J = 2, PRI = 5;

    while (J < TAM) {
        FLA = 1;
        Primo(PRI, &FLA); /* Determina si PRI es primo. */
        if (FLA) {  /* Si FLA es 1, entonces PRI es primo. */
            P[J] = PRI;
            J++;
        }
        PRI += 2;  // Incrementamos en 2 para solo probar números impares.
    }

    Imprime(P, TAM);
    return 0;
}

void Primo(int A, int *B)
/* Esta función determina si A es primo. Si encuentra un divisor, establece *B en 0. */
{
    int DI = 3;
    while (*B && (DI * DI <= A)) {
        if (A % DI == 0) {
            *B = 0;  // No es primo si tiene divisores distintos de 1 y A.
        }
        DI += 2;  // Solo probamos divisores impares.
    }
}

void Imprime(int Primos[], int T)
/* Esta función imprime el arreglo unidimensional de números primos. */
{
    int I;
    for (I = 0; I < T; I++) {
        printf("\nPrimos[%d]: %d", I, Primos[I]);
    }
}
