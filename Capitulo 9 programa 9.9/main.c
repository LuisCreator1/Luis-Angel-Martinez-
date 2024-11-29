#include <stdio.h>
/* Alumnos.
El programa lee bloques �variables de tipo estructura alumno� de un archivo
de acceso directo. */

typedef struct { /* Declaraci�n de la estructura alumno. */
    int matricula;
    char nombre[20];
    int carrera;
    float promedio;
} alumno;

void lee(FILE *); /* Prototipo de funci�n. */

void main(void)
{
    FILE *ar;
    if ((ar = fopen("ad1.dat", "r")) != NULL) /* Corrige las comillas y usa modo de apertura correcto */
    {
        lee(ar);
        fclose(ar);
    }
    else
    {
        printf("\nEl archivo no se puede abrir");
    }
}

void lee(FILE *ap)
/* Esta funci�n se utiliza para leer bloques de un archivo de acceso directo. */
{
    alumno alu;

    fread(&alu, sizeof(alumno), 1, ap); /* Primera lectura */

    while (!feof(ap)) /* Mantiene la l�gica del ciclo mientras no sea fin de archivo */
    {
        printf("\nMatr�cula: %d", alu.matricula);
        printf("\tCarrera: %d", alu.carrera);
        printf("\tPromedio: %.2f", alu.promedio);
        printf("\tNombre: %s", alu.nombre);
        fread(&alu, sizeof(alumno), 1, ap); /* Lee el siguiente registro */
    }
}
