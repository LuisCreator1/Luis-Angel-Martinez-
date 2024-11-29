#include <stdio.h>
/* Incrementa salarios.
El programa incrementa el salario de los empleados de una empresa
—actualiza el archivo correspondiente— si sus ventas son superiores
al millón de pesos anuales. */

typedef struct /* Declaración de la estructura empleado. */
{
    int clave;
    int departamento;
    float salario;
    float ventas[12];
} empleado;

void incrementa(FILE *); /* Prototipo de función. */

void main(void)
{
    FILE *ar;
    if ((ar = fopen("ad5.dat", "r+")) != NULL)
    {
        /* El archivo se abre en la modalidad para leer y escribir. */
        incrementa(ar);
        fclose(ar);
    }
    else
    {
        printf("\nEl archivo no se puede abrir");
    }
}

void incrementa(FILE *ap)
/* Esta función se utiliza para incrementar el salario de todos aquellos
empleados que hayan tenido ventas anuales por más de $1,000,000.
Actualiza además el archivo correspondiente. */
{
    int i, j, t;
    float sum;
    empleado emple;
    t = sizeof(empleado);
    /* La función sizeof se utiliza para conocer el tamaño de la estructura empleado. */

    fread(&emple, sizeof(empleado), 1, ap);
    /* Se lee el primer registro del archivo. */

    while (!feof(ap))
    {
        i = ftell(ap) / t;
        /* La función ftell se utiliza para conocer la posición de nuestro
        apuntador en el archivo. La variable i nos proporciona el índice
        del bloque que estamos procesando. */

        sum = 0;
        for (j = 0; j < 12; j++)
        {
            sum += emple.ventas[j]; /* Se calculan las ventas anuales de cada empleado. */
        }

        if (sum > 1000000)
        {
            emple.salario = emple.salario * 1.10; /* Se incrementa el salario en 10%. */
            fseek(ap, (i - 1) * sizeof(empleado), SEEK_SET);
            /* Posiciona el apuntador al inicio del registro actual. */
            fwrite(&emple, sizeof(empleado), 1, ap);
            /* Escribe el registro actualizado. */
            fseek(ap, i * sizeof(empleado), SEEK_SET);
            /* Reposiciona el apuntador para leer el siguiente registro. */
        }

        fread(&emple, sizeof(empleado), 1, ap);
    }
}
