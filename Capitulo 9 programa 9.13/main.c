#include <stdio.h>
/* Cuenta caracteres.
El programa, al recibir como dato un archivo de texto y un carácter, cuenta
el número de veces que se encuentra el carácter en el archivo. */

int cuenta(char car); /* Prototipo de función. */

void main(void)
{
    int res;
    char car;

    printf("\nIngrese el carácter que se va a buscar en el archivo: ");
    car = getchar(); /* Obtiene el carácter ingresado por el usuario. */

    res = cuenta(car);

    if (res != -1)
        printf("\n\nEl carácter '%c' se encuentra en el archivo %d veces.\n", car, res);
    else
        printf("\nNo se pudo abrir el archivo.\n");
}

int cuenta(char car)
/* Esta función determina cuántas veces se encuentra el carácter en el archivo. */
{
    int res, con = 0;
    char p;
    FILE *ar;

    ar = fopen("arc.txt", "r"); /* Abre el archivo en modo lectura. */


    if (ar != NULL)
    {
        while ((p = getc(ar)) != EOF)
        {
            if (p == car)
                con++;
        }
        fclose(ar);
        res = con;
    }
    else
    {
        res = -1;
    }

    return res;
}
