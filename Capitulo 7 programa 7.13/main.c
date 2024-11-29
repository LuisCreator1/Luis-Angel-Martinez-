#include <stdio.h>

/* Calcula longitud.
El programa calcula la longitud de la cadena sin utilizar la función strlen. */

int cuenta(char *); /* Prototipo de función. */

void main(void)
{
    int i;
    char cad[50];
    printf("\nIngrese la cadena de caracteres: ");
    gets(cad);  // Aunque gets() es inseguro, lo mantengo como en tu código.
    i = cuenta(cad);
    printf("\nLongitud de la cadena: %d", i);
}

int cuenta(char *cadena)
/* La función calcula la longitud de la cadena. */
{
    int c = 0;
    while (cadena[c] != '\0')  // Corregido el operador de comparación
        c++;
    return (c);
}
