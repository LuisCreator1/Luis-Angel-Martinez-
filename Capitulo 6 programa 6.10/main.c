#include <stdio.h>
/* Cuadrado m�gico.
El programa genera un cuadrado m�gico siguiendo los criterios enunciados
anteriormente. */

const int MAX = 50;

void Cuadrado(int [][MAX], int);
void Imprime(int [][MAX], int); /* Prototipos de funciones. */

void main(void)
{
    int CMA[MAX][MAX], TAM;

    do
    {
        printf("Ingrese el tama�o impar de la matriz: ");
        scanf("%d", &TAM);
    }
    while ((TAM > MAX || TAM < 1) || (TAM % 2 == 0));
    /* Se verifica el tama�o del arreglo y el orden (impar) del mismo. */

    Cuadrado(CMA, TAM);
    Imprime(CMA, TAM);
}

void Cuadrado(int A[][MAX], int N)
/* Esta funci�n se utiliza para formar el cuadrado m�gico. */
{
    int I = 1, FIL = 0, COL = N / 2; /* Empezamos con el n�mero 1 en la mitad de la primera fila */
    int NUM = N * N;  /* El �ltimo n�mero es N*N */

    while (I <= NUM)
    {
        A[FIL][COL] = I;  /* Colocamos el n�mero en la posici�n actual */

        if (I % N != 0)  /* Si el n�mero no es m�ltiplo de N */
        {
            FIL = (FIL - 1 + N) % N;  /* Subimos una fila, asegur�ndonos de no salir de los l�mites */
            COL = (COL + 1) % N;      /* Nos movemos a la siguiente columna */
        }
        else
        {
            FIL++;  /* Si es m�ltiplo de N, bajamos a la fila siguiente sin movernos a la derecha */
        }

        I++;  /* Incrementamos el n�mero */
    }
}

void Imprime(int A[][MAX], int N)
/* Esta funci�n se utiliza para escribir el cuadrado m�gico. */
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
