#include <stdio.h>
#include <ctype.h>
/* Letras minúsculas y mayúsculas.
El programa, al recibir como dato un archivo formado por cadenas de caracteres,
determina el número de letras minúsculas y mayúsculas que hay en el archivo. */

void minymay(FILE *); /* Prototipo de función. */
/* Observa que esta función va a recibir un archivo como parámetro. */

void main(void)
{
    FILE *ar;
    if ((ar = fopen("arc5.txt", "r")) != NULL) /* Cambié las comillas estilizadas por comillas estándar. */
    {
        minymay(ar);
        /* Se llama a la función minymay. Se pasa el archivo ar como parámetro. */
        fclose(ar);
    }
    else
    {
        printf("No se pudo abrir el archivo.\n");
    }
}

void minymay(FILE *arc)
/* Esta función cuenta el número de minúsculas y mayúsculas que hay en el archivo arc. */
{
    int min = 0, may = 0;
    char p;

    while ((p = fgetc(arc)) != EOF) /* Se utiliza la función fgetc() para leer caracteres del archivo. */
    {
        if (islower(p)) /* Verifica si el carácter es una letra minúscula. */
            min++;
        else if (isupper(p)) /* Verifica si el carácter es una letra mayúscula. */
            may++;
    }

    printf("\nNúmero de minúsculas: %d\n", min);
    printf("Número de mayúsculas: %d\n", may);
}
