#include <stdio.h>
/* Mezcla.
El programa mezcla, respetando el orden, dos archivos que se encuentran
ordenados en forma ascendente considerando la matrícula de los alumnos. */

void mezcla(FILE *, FILE *, FILE *); /* Prototipo de función. */

void main(void)
{
    FILE *ar, *ar1, *ar2;
    ar = fopen("arc9.dat", "r");    /* Se abre el archivo arc9.dat para lectura. */
    ar1 = fopen("arc10.dat", "r");  /* Se abre el archivo arc10.dat para lectura. */
    ar2 = fopen("arc11.dat", "w");  /* Se abre el archivo arc11.dat para escritura. */

    if ((ar != NULL) && (ar1 != NULL) && (ar2 != NULL))
    {
        mezcla(ar, ar1, ar2);  /* Llama a la función de mezcla. */
        fclose(ar);
        fclose(ar1);
        fclose(ar2);
    }
    else
    {
        printf("No se pueden abrir los archivos.\n");
    }
}

void mezcla(FILE *ar, FILE *ar1, FILE *ar2)
{
    /* Esta función mezcla, respetando el orden, dos archivos que se encuentran
    ordenados en función de la matrícula. */
    int mat, mat1;
    float ca[3], ca1[3];
    int b = 1, b1 = 1;

    // Lee de ambos archivos y mezcla en el archivo de salida
    while (((!feof(ar)) || !b) && ((!feof(ar1)) || !b1))
    {
        if (b) /* Si la bandera b está encendida, se lee del archivo ar. */
        {
            if (fscanf(ar, "%d", &mat) == 1)  // Lectura de matrícula
            {
                for (int i = 0; i < 3; i++)
                    fscanf(ar, "%f", &ca[i]);  // Lectura de calificaciones
                b = 0;
            }
        }

        if (b1) /* Si la bandera b1 está encendida, se lee del archivo ar1. */
        {
            if (fscanf(ar1, "%d", &mat1) == 1)  // Lectura de matrícula
            {
                for (int i = 0; i < 3; i++)
                    fscanf(ar1, "%f", &ca1[i]);  // Lectura de calificaciones
                b1 = 0;
            }
        }

        // Comparación y mezcla
        if (mat < mat1)
        {
            fprintf(ar2, "%d\t", mat);  // Escribe matrícula en el archivo de salida
            for (int i = 0; i < 3; i++)
                fprintf(ar2, "%f\t", ca[i]);  // Escribe las calificaciones
            fputs("\n", ar2);  // Escribe salto de línea
            b = 1;  // Se indica que se debe leer la siguiente línea de ar
        }
        else
        {
            fprintf(ar2, "%d\t", mat1);  // Escribe matrícula en el archivo de salida
            for (int i = 0; i < 3; i++)
                fprintf(ar2, "%f\t", ca1[i]);  // Escribe las calificaciones
            fputs("\n", ar2);  // Escribe salto de línea
            b1 = 1;  // Se indica que se debe leer la siguiente línea de ar1
        }
    }

    // Escribir el resto de los registros que queden
    if (!b)
    {
        fprintf(ar2, "%d\t", mat);
        for (int i = 0; i < 3; i++)
            fprintf(ar2, "%f\t", ca[i]);
        fputs("\n", ar2);

        while (fscanf(ar, "%d", &mat) == 1)
        {
            for (int i = 0; i < 3; i++)
                fscanf(ar, "%f", &ca[i]);
            fprintf(ar2, "%d\t", mat);
            for (int i = 0; i < 3; i++)
                fprintf(ar2, "%f\t", ca[i]);
            fputs("\n", ar2);
        }
    }

    if (!b1)
    {
        fprintf(ar2, "%d\t", mat1);
        for (int i = 0; i < 3; i++)
            fprintf(ar2, "%f\t", ca1[i]);
        fputs("\n", ar2);

        while (fscanf(ar1, "%d", &mat1) == 1)
        {
            for (int i = 0; i < 3; i++)
                fscanf(ar1, "%f", &ca1[i]);
            fprintf(ar2, "%d\t", mat1);
            for (int i = 0; i < 3; i++)
                fprintf(ar2, "%f\t", ca1[i]);
            fputs("\n", ar2);
        }
    }
}
