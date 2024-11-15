#include <stdio.h>
/* Simétrico.
El programa, al recibir como dato un arreglo bidimensional cuadrado, determina
si el mismo es simétrico. */

const int MAX = 100;

void Lectura(int [][MAX], int); /* Prototipos de funciones. */
int Simetrico(int [][MAX], int);

void main(void)
{
    int MAT[MAX][MAX], N, RES;
    do
    {
        printf("Ingrese el tamaño del arreglo: ");
        scanf("%d", &N);
    }
    while (N > MAX || N < 1); /* Se verifica que el tamaño del arreglo sea válido. */

    Lectura(MAT, N);  // Llamada a la función para leer la matriz
    RES = Simetrico(MAT, N); // Llamada a la función que determina si es simétrico

    if (RES)
        printf("\nEl arreglo bidimensional es simétrico");
    else
        printf("\nEl arreglo bidimensional no es simétrico");
}

void Lectura(int A[][MAX], int T)
/* La función Lectura se utiliza para leer un arreglo bidimensional cuadrado de
tipo entero de T filas y T columnas. */
{
    int I, J;
    for (I = 0; I < T; I++)
        for (J = 0; J < T; J++)
        {
            printf("Fila: %d\tColumna: %d: ", I + 1, J + 1);
            scanf("%d", &A[I][J]);
        }
}

int Simetrico(int A[][MAX], int T)
/* La función Simétrico se utiliza para determinar si el arreglo bidimensional
cuadrado es simétrico. Si es simétrico regresa 1, en caso contrario, 0. */
{
    int I, J, F = 1;
    for (I = 0; I < T && F; I++)
    {
        for (J = 0; J < I; J++) // Solo compara la parte triangular inferior
        {
            if (A[I][J] != A[J][I]) // Si algún valor no es igual, no es simétrica
            {
                F = 0;
                break;
            }
        }
    }
    return F;
}
