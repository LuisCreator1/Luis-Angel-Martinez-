#include <stdio.h>

/* Frecuencia de calificaciones.
El programa, al recibir como datos las calificaciones de un grupo de 50
alumnos, obtiene la frecuencia de cada una de las calificaciones y adem�s
escribe cu�l es la frecuencia m�s alta. */

const int TAM = 50;

void Lectura(int *, int);
void Frecuencia(int *, int, int *, int); /* Prototipos de funciones. */
void Impresion(int *, int);
void Mayor(int *, int);

int main(void) {
    int CAL[TAM], FRE[6] = {0}; /* Declaraci�n de los arreglos. */
    Lectura(CAL, TAM); /* Se llama a la funci�n Lectura. */
    Frecuencia(CAL, TAM, FRE, 6);
    /* Se llama a la funci�n Frecuencia, se pasan ambos arreglos. */
    printf("\nFrecuencia de Calificaciones\n");
    Impresion(FRE, 6);
    Mayor(FRE, 6);
    return 0;
}

void Lectura(int VEC[], int T)
/* La funci�n Lectura se utiliza para leer el arreglo de calificaciones. */
{
    int I;
    for (I = 0; I < T; I++) {
        printf("Ingrese la calificaci�n (0-5) del alumno %d: ", I + 1);
        scanf("%d", &VEC[I]);
        /* Validaci�n para asegurar que la calificaci�n est� en el rango 0-5 */
        while (VEC[I] < 0 || VEC[I] > 5) {
            printf("Calificaci�n inv�lida. Ingrese nuevamente (0-5): ");
            scanf("%d", &VEC[I]);
        }
    }
}

void Frecuencia(int CAL[], int T, int FRE[], int numCalificaciones)
/* La funci�n Frecuencia calcula la frecuencia de cada calificaci�n */
{
    int I;
    for (I = 0; I < T; I++) {
        FRE[CAL[I]]++;
    }
}

void Impresion(int FRE[], int numCalificaciones)
/* La funci�n Impresion imprime el arreglo de frecuencias. */
{
    int I;
    for (I = 0; I < numCalificaciones; I++) {
        printf("Frecuencia de %d: %d\n", I, FRE[I]);
    }
}

void Mayor(int FRE[], int numCalificaciones)
/* La funci�n Mayor encuentra y muestra la frecuencia m�s alta */
{
    int I, maxFrecuencia = FRE[0], calificacion = 0;
    for (I = 1; I < numCalificaciones; I++) {
        if (FRE[I] > maxFrecuencia) {
            maxFrecuencia = FRE[I];
            calificacion = I;
        }
    }
    printf("La calificaci�n con la frecuencia m�s alta es %d con una frecuencia de %d.\n", calificacion, maxFrecuencia);
}











































