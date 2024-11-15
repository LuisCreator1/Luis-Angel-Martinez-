#include <stdio.h>

/* Búsqueda binaria. */
const int MAX = 100;

void Lectura(int[], int); /* Prototipos de funciones. */
int Binaria(int *, int, int);

int main(void) {
    int RES, ELE, TAM, VEC[MAX];

    do {
        printf("Ingrese el tamaño del arreglo: ");
        scanf("%d", &TAM);
    } while (TAM > MAX || TAM < 1); /* Verificación del tamaño del arreglo. */

    Lectura(VEC, TAM);

    printf("\nIngrese el elemento a buscar: ");
    scanf("%d", &ELE);

    RES = Binaria(VEC, TAM, ELE); /* Llama a la función que busca en el arreglo. */

    if (RES)
        printf("\nEl elemento se encuentra en la posición: %d", RES);
    else
        printf("\nEl elemento no se encuentra en el arreglo");

    return 0;
}

void Lectura(int A[], int T)
/* La función Lectura se utiliza para leer un arreglo unidimensional de T elementos de tipo entero. */
{
    int I;
    for (I = 0; I < T; I++) {
        printf("Ingrese el elemento %d: ", I + 1);
        scanf("%d", &A[I]);
    }
}

int Binaria(int A[], int T, int E)
/* Esta función realiza una búsqueda binaria del elemento E en el arreglo A de T elementos.
   Si se encuentra el elemento, devuelve la posición correspondiente (ajustada a 1). En caso contrario, devuelve 0. */
{
    int IZQ = 0, DER = T - 1, CEN;
    while (IZQ <= DER) {
        CEN = (IZQ + DER) / 2;
        if (E == A[CEN])
            return CEN + 1; /* Devuelve la posición ajustada a 1. */
        else if (E > A[CEN])
            IZQ = CEN + 1;
        else
            DER = CEN - 1;
    }
    return 0; /* Si no se encuentra, devuelve 0. */
}
