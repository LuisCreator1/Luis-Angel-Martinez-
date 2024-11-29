#include <stdio.h>
#include <stdlib.h>

/* Suma reales.
El programa lee cadenas de caracteres de un archivo, detecta aquellas que
comienzan con números, los suma y calcula el promedio de los mismos. */
void sumypro(FILE *); /* Prototipo de función. */

void main(void)
{
    FILE *ap;
    if ((ap = fopen("arc2.txt", "r")) != NULL)  /* Abre el archivo arc2.txt para lectura. */
    {
        sumypro(ap);  /* Se llama a la función sumypro. Se pasa el archivo ap como parámetro. */
        fclose(ap);   /* Cierra el archivo después de usarlo. */
    }
    else
    {
        printf("No se puede abrir el archivo.\n");
    }
}

void sumypro(FILE *ap1)
/* Esta función lee cadenas de caracteres de un archivo, detecta aquellas
que comienzan con números, y obtiene la suma y el promedio de dichos
números. */
{
    char cad[30];
    int i = 0;
    float sum = 0.0, r;

    while (fgets(cad, 30, ap1) != NULL)  /* Lee línea por línea del archivo. */
    {
        r = atof(cad);  /* Convierte la cadena de caracteres a número flotante (real). */

        /* Si la cadena comienza con un número, atof lo convierte en un valor mayor que 0. */
        if (r)
        {
            i++;  /* Incrementa el contador de números. */
            sum += r;  /* Suma el número a la variable sum. */
        }
    }

    printf("\nSuma: %.2f", sum);
    if (i)  /* Si el contador es mayor que 0, calcula el promedio. */
    {
        printf("\nPromedio: %.2f", sum / i);
    }
    else
    {
        printf("\nNo se encontraron números válidos en el archivo.\n");
    }
}
