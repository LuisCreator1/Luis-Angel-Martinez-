#include <stdio.h>

typedef struct /* Declaración de la estructura alumno. */
{
    int matricula;
    char nombre[20];
    int carrera;
    float promedio;
} alumno;

void ordena(FILE *, FILE *); /* Prototipo de función. */

void main(void)
{
    FILE *ar1, *ar2;
    ar1 = fopen("ad5.dat", "rb"); /* Se abre el archivo en modo binario de lectura. */
    ar2 = fopen("ad6.dat", "wb"); /* Se abre el archivo en modo binario de escritura. */

    if ((ar1 != NULL) && (ar2 != NULL)) {
        ordena(ar1, ar2); /* Ordena los registros y los escribe en el nuevo archivo. */
        fclose(ar1);
        fclose(ar2);
    } else {
        printf("\nEl o los archivos no se pudieron abrir\n");
    }
}

void ordena(FILE *ap1, FILE *ap2)
{
    alumno alu[100];  /* Suponemos que no hay más de 100 registros. */
    int n = 0;

    /* Leer todos los registros del archivo de entrada. */
    while (fread(&alu[n], sizeof(alumno), 1, ap1)) {
        n++;
    }

    /* Ordenar los alumnos por la matrícula de menor a mayor (algoritmo de burbuja). */
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (alu[i].matricula > alu[j].matricula) {
                alumno temp = alu[i];
                alu[i] = alu[j];
                alu[j] = temp;
            }
        }
    }

    /* Escribir los registros ordenados en el archivo de salida. */
    for (int i = 0; i < n; i++) {
        fwrite(&alu[i], sizeof(alumno), 1, ap2);
    }
}
