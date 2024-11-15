#include <stdio.h>
/* Fábrica de lácteos.
El programa, al recibir como datos las ventas mensuales de diferentes
productos, obtiene información estadística valiosa para la empresa. */

void Lectura1(int [15][12]);
void Lectura2(float[], int);
void Funcion1(int [][12], int, int, float [], float []); /* Prototipos de funciones. */
void Funcion2(float [], int);
void Funcion3(float [], int);

void main(void)
{
    int FAB[15][12] = {0}; /* Inicialización en 0 del arreglo FAB. */
    float COS[15], VEN[15];

    Lectura1(FAB);
    Lectura2(COS, 15);
    Funcion1(FAB, 15, 12, COS, VEN);
    Funcion2(VEN, 15);
    Funcion3(VEN, 15);
}

void Lectura1(int A[][12])
/* Esta función se utiliza para almacenar en el arreglo bidimensional las
diferentes transacciones que representan las ventas de los diferentes
productos. El fin de datos está dado por –1. */
{
    int MES, PRO, CAN;
    printf("\nIngrese mes, tipo de producto y cantidad vendida: ");
    scanf("%d %d %d", &MES, &PRO, &CAN);

    while (MES != -1 && PRO != -1 && CAN != -1)
    {
        A[MES - 1][PRO - 1] += CAN;
        printf("\nIngrese mes, tipo de producto y cantidad vendida: ");
        scanf("%d %d %d", &MES, &PRO, &CAN);
    }
}

void Lectura2(float A[], int N)
/* Esta función se utiliza para leer los precios de venta de los diferentes
productos. */
{
    int I;
    for (I = 0; I < N; I++)
    {
        printf("Ingrese costo del producto %d: ", I + 1);
        scanf("%f", &A[I]);
    }
}

void Funcion1(int A[][12], int F, int C, float V1[], float V2[])
/* Esta función se utiliza para calcular el monto de venta anual de cada uno
de los productos. El resultado se almacena en un arreglo unidimensional que
se utilizará posteriormente. */
{
    int I, J;
    float SUM;
    printf("\n");
    for (I = 0; I < F; I++)
    {
        SUM = 0;
        for (J = 0; J < C; J++)
            SUM += A[I][J];

        V2[I] = V1[I] * SUM;
        printf("\nTotal de ventas del producto %d: %8.2f", I + 1, V2[I]);
    }
}

void Funcion2(float A[], int C)
/* Esta función se utiliza para calcular el monto total de ventas de la fábrica. */
{
    int I;
    float totalVentas = 0;
    for (I = 0; I < C; I++)
    {
        totalVentas += A[I];
    }
    printf("\n\nMonto total de ventas de la fábrica: %8.2f", totalVentas);
}

void Funcion3(float A[], int C)
/* Esta función se utiliza para calcular el producto con la mayor venta. */
{
    int I;
    float mayorVenta = 0;
    int productoMayor = 0;

    for (I = 0; I < C; I++)
    {
        if (A[I] > mayorVenta)
        {
            mayorVenta = A[I];
            productoMayor = I + 1; /* Producto con la mayor venta */
        }
    }
    printf("\nEl producto con la mayor venta es el producto %d con un total de ventas de: %8.2f", productoMayor, mayorVenta);
}
