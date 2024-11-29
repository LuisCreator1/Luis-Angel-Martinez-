#include <stdio.h>
/* Alumnos.
El programa pregunta al usuario el número de registro que desea
modificar, obtiene el nuevo promedio del alumno y modifica tanto el
registro como el archivo correspondiente. */

typedef struct /* Declaración de la estructura alumno. */
{
    int matricula;
    char nombre[20];
    int carrera;
    float promedio;
} alumno;

void modifica(FILE *); /* Prototipo de función. */

void main(void)
{
    FILE *ar;
    if ((ar = fopen("ad1.dat", "r+")) != NULL) /* Corrige las comillas y usa el modo correcto */
    {
        modifica(ar);
        fclose(ar);
    }
    else
    {
        printf("\nEl archivo no se puede abrir");
    }
}

void modifica(FILE *ap)
/* Esta función se utiliza para modificar el promedio de un alumno. */
{
    int d;
    alumno alu;
    printf("\nIngrese el número de registro que desea modificar: ");
    /* Observa que el lenguaje C almacena el primer registro en la
    posición cero. Por lo tanto, si desea modificar el registro n,
    debe buscarlo en la posición n-1. */
    scanf("%d", &d); /* Corrige las comillas */

    fseek(ap, (d - 1) * sizeof(alumno), SEEK_SET);
    /* Posiciona el puntero en el registro a modificar. */

    fread(&alu, sizeof(alumno), 1, ap);
    /* Lee el registro que se desea modificar. */

    printf("\nIngrese el promedio correcto del alumno: ");
    scanf("%f", &alu.promedio); /* Modifica el promedio del registro. */

    fseek(ap, (d - 1) * sizeof(alumno), SEEK_SET);
    /* Reposiciona el puntero en el lugar correcto para escribir el registro modificado. */

    fwrite(&alu, sizeof(alumno), 1, ap);
    /* Escribe el registro actualizado en el archivo. */
}
