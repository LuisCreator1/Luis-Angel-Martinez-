#include <stdio.h>
/* Cuadrado mágico.
El programa genera un cuadrado mágico siguiendo los criterios enunciados
anteriormente. */

const int MAX = 50;

void Cuadrado(int [][MAX], int);
void Imprime(int [][MAX], int); /* Prototipos de funciones. */

void main(void)
{
    int CMA[MAX][MAX], TAM;

    do
    {
        printf("Ingrese el tamaño impar de la matriz: ");
        scanf("%d", &TAM);
    }
    while ((TAM > MAX || TAM < 1) || (TAM % 2 == 0));
    /* Se verifica el tamaño del arreglo y el orden (impar) del mismo. */

    Cuadrado(CMA, TAM);
    Imprime(CMA, TAM);
}

void Cuadrado(int A[][MAX], int N)
/* Esta función se utiliza para formar el cuadrado mágico. */
{
    int I = 1, FIL = 0, COL = N / 2; /* Empezamos con el número 1 en la mitad de la primera fila */
    int NUM = N * N;  /* El último número es N*N */

    while (I <= NUM)
    {
        A[FIL][COL] = I;  /* Colocamos el número en la posición actual */

        if (I % N != 0)  /* Si el número no es múltiplo de N */
        {
            FIL = (FIL - 1 + N) % N;  /* Subimos una fila, asegurándonos de no salir de los límites */
            COL = (COL + 1) % N;      /* Nos movemos a la siguiente columna */
        }
        else
        {
            FIL++;  /* Si es múltiplo de N, bajamos a la fila siguiente sin movernos a la derecha */
        }

        I++;  /* Incrementamos el número */
    }
}

void Imprime(int A[][MAX], int N)
/* Esta función se utiliza para escribir el cuadrado mágico. */
{
    int I, J;
    for (I = 0; I < N; I++)
    {
        for (J = 0; J < N; J++)
        {
            printf("\nElemento %d %d: %d", I + 1, J + 1, A[I][J]);
        }
    }
}
