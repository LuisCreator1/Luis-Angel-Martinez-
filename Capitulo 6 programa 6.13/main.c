#include <stdio.h>
/* Empresa textil.
El programa, al recibir un arreglo tridimensional que contiene información
sobre las ventas mensuales de tres departamentos en los últimos ocho años,
genera información estadística valiosa para la empresa. */

const int MES = 12;
const int DEP = 3;
const int AÑO = 8;

void Lectura(float [MES][DEP][AÑO], int, int, int);
void Funcion1(float [MES][DEP][AÑO], int, int, int);
void Funcion2(float [MES][DEP][AÑO], int, int, int); /* Prototipos de funciones. */
void Funcion3(float [MES][DEP][AÑO], int, int, int);

void main(void)
{
    float PRO[MES][DEP][AÑO];
    Lectura(PRO, MES, DEP, AÑO);
    Funcion1(PRO, MES, DEP, 2);
    Funcion2(PRO, MES, DEP, AÑO);
    Funcion3(PRO, MES, DEP, AÑO);
}

void Lectura(float A[][DEP][AÑO], int F, int C, int P)
/* La función Lectura se utiliza para leer un arreglo tridimensional de tipo
real de F filas, C columnas y P planos de profundidad. */
{
    int K, I, J;
    for (K = 0; K < P; K++)
        for (I = 0; I < F; I++)
            for (J = 0; J < C; J++)
            {
                printf("Año: %d\tMes: %d\tDepartamento: %d: ", K + 1, I + 1, J + 1);
                scanf("%f", &A[I][J][K]);
            }
}

void Funcion1(float A[][DEP][AÑO], int F, int C, int P)
/* Esta función se utiliza para obtener las ventas totales de la empresa
en el segundo año. */
{
    int I, J;
    float SUM = 0.0;
    for (I = 0; I < F; I++)
        for (J = 0; J < C; J++)
            SUM += A[I][J][P - 1];
    printf("\n\nVentas totales de la empresa en el segundo año: %.2f", SUM);
}

void Funcion2(float A[][DEP][AÑO], int F, int C, int P)
/* Esta función se utiliza para obtener el departamento que tuvo las mayores
ventas en el último año. Genera además el importe de las ventas. */
{
    int I, J;
    float SUM[DEP] = {0}; // Sumar las ventas por departamento
    for (I = 0; I < F; I++)
        for (J = 0; J < C; J++)
            SUM[J] += A[I][J][P - 1];

    // Comparar las ventas y determinar el departamento con mayores ventas
    int maxDep = 0;
    for (int k = 1; k < DEP; k++) {
        if (SUM[k] > SUM[maxDep]) {
            maxDep = k;
        }
    }

    // Imprimir el departamento con mayores ventas
    switch (maxDep) {
        case 0:
            printf("\n\nDepartamento con mayores ventas en el último año: Hilos");
            break;
        case 1:
            printf("\n\nDepartamento con mayores ventas en el último año: Lanas");
            break;
        case 2:
            printf("\n\nDepartamento con mayores ventas en el último año: Licra");
            break;
    }
    printf(" Ventas: %.2f", SUM[maxDep]);
}

void Funcion3(float A[][DEP][AÑO], int F, int C, int P)
/* Esta función se utiliza para obtener el departamento, mes y año con la mayor
venta. Escribe también el monto de las ventas. */
{
    int K, I, J, DE, ME, AN;
    float VEN = -1.0;
    for (K = 0; K < P; K++)
        for (I = 0; I < F; I++)
            for (J = 0; J < C; J++)
                if (A[I][J][K] > VEN)
                {
                    VEN = A[I][J][K];
                    DE = J;
                    ME = I;
                    AN = K;
                }

    // Imprimir el departamento, mes y año con la mayor venta
    printf("\n\nDepartamento: ");
    switch (DE) {
        case 0:
            printf("Hilos");
            break;
        case 1:
            printf("Lanas");
            break;
        case 2:
            printf("Licra");
            break;
    }
    printf("\tMes: %d\tAño: %d", ME + 1, AN + 1);
    printf("\tVentas: %.2f", VEN);
}
