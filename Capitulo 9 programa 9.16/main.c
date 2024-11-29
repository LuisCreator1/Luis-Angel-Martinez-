#include <stdio.h>
#include <stdlib.h>

/* Suma reales.
El programa lee cadenas de caracteres de un archivo, detecta aquellas que
comienzan con n�meros, los suma y calcula el promedio de los mismos. */
void sumypro(FILE *); /* Prototipo de funci�n. */

void main(void)
{
    FILE *ap;
    if ((ap = fopen("arc2.txt", "r")) != NULL)  /* Abre el archivo arc2.txt para lectura. */
    {
        sumypro(ap);  /* Se llama a la funci�n sumypro. Se pasa el archivo ap como par�metro. */
        fclose(ap);   /* Cierra el archivo despu�s de usarlo. */
    }
    else
    {
        printf("No se puede abrir el archivo.\n");
    }
}

void sumypro(FILE *ap1)
/* Esta funci�n lee cadenas de caracteres de un archivo, detecta aquellas
que comienzan con n�meros, y obtiene la suma y el promedio de dichos
n�meros. */
{
    char cad[30];
    int i = 0;
    float sum = 0.0, r;

    while (fgets(cad, 30, ap1) != NULL)  /* Lee l�nea por l�nea del archivo. */
    {
        r = atof(cad);  /* Convierte la cadena de caracteres a n�mero flotante (real). */

        /* Si la cadena comienza con un n�mero, atof lo convierte en un valor mayor que 0. */
        if (r)
        {
            i++;  /* Incrementa el contador de n�meros. */
            sum += r;  /* Suma el n�mero a la variable sum. */
        }
    }

    printf("\nSuma: %.2f", sum);
    if (i)  /* Si el contador es mayor que 0, calcula el promedio. */
    {
        printf("\nPromedio: %.2f", sum / i);
    }
    else
    {
        printf("\nNo se encontraron n�meros v�lidos en el archivo.\n");
    }
}
