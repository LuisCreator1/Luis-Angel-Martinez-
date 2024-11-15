#include <stdio.h>

/* B�squeda binaria. */
const int MAX = 100;

void Lectura(int[], int); /* Prototipos de funciones. */
int Binaria(int *, int, int);

int main(void) {
    int RES, ELE, TAM, VEC[MAX];

    do {
        printf("Ingrese el tama�o del arreglo: ");
        scanf("%d", &TAM);
    } while (TAM > MAX || TAM < 1); /* Verificaci�n del tama�o del arreglo. */

    Lectura(VEC, TAM);

    printf("\nIngrese el elemento a buscar: ");
    scanf("%d", &ELE);

    RES = Binaria(VEC, TAM, ELE); /* Llama a la funci�n que busca en el arreglo. */

    if (RES)
        printf("\nEl elemento se encuentra en la posici�n: %d", RES);
    else
        printf("\nEl elemento no se encuentra en el arreglo");

    return 0;
}

void Lectura(int A[], int T)
/* La funci�n Lectura se utiliza para leer un arreglo unidimensional de T elementos de tipo entero. */
{
    int I;
    for (I = 0; I < T; I++) {
        printf("Ingrese el elemento %d: ", I + 1);
        scanf("%d", &A[I]);
    }
}

int Binaria(int A[], int T, int E)
/* Esta funci�n realiza una b�squeda binaria del elemento E en el arreglo A de T elementos.
   Si se encuentra el elemento, devuelve la posici�n correspondiente (ajustada a 1). En caso contrario, devuelve 0. */
{
    int IZQ = 0, DER = T - 1, CEN;
    while (IZQ <= DER) {
        CEN = (IZQ + DER) / 2;
        if (E == A[CEN])
            return CEN + 1; /* Devuelve la posici�n ajustada a 1. */
        else if (E > A[CEN])
            IZQ = CEN + 1;
        else
            DER = CEN - 1;
    }
    return 0; /* Si no se encuentra, devuelve 0. */
}
