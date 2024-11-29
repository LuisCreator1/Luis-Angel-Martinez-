#include <stdio.h>
/* Alumnos.
El programa almacena variables de tipo estructura alumno en un archivo. */

typedef struct /* Declaración de la estructura alumno. */
{
    int matricula;
    char nombre[20];
    int carrera;
    float promedio;
} alumno;

void escribe(FILE *); /* Prototipo de función. */

void main(void)
{
    FILE *ar;
    if ((ar = fopen("ad1.dat", "wb")) != NULL) /* Apertura del archivo en modo binario de escritura. */
    {
        escribe(ar); /* Llama a la función para escribir en el archivo. */
        fclose(ar);  /* Cierra el archivo después de escribir. */
    }
    else
    {
        printf("\nEl archivo no se puede abrir\n");
    }
}

void escribe(FILE *ap)
/* Esta función sirve para leer los datos de los alumnos utilizando una
estructura tipo alumno, que se almacenará posteriormente en un archivo. */
{
    alumno alu;
    int i = 0, r;

    printf("\n¿Desea ingresar información sobre alumnos? (Sí-1 No-0): ");
    scanf("%d", &r);

    while (r)
    {
        i++;
        printf("Matrícula del alumno %d: ", i);
        scanf("%d", &alu.matricula);

        printf("Nombre del alumno %d: ", i);
        fflush(stdin); /* Limpia el buffer de entrada. */
        gets(alu.nombre); /* Lee el nombre del alumno. */

        printf("Carrera del alumno %d: ", i);
        scanf("%d", &alu.carrera);

        printf("Promedio del alumno %d: ", i);
        scanf("%f", &alu.promedio);

        fwrite(&alu, sizeof(alumno), 1, ap);
        /* Observa que la función fwrite tiene cuatro argumentos:
           - La variable tipo estructura que se desea almacenar.
           - El tamaño de esa variable en términos de bytes.
           - El número de variables que se escribirán en el archivo.
           - El apuntador al inicio del archivo. */

        printf("\n¿Desea ingresar información sobre más alumnos? (Sí-1 No-0): ");
        scanf("%d", &r);
    }
}
