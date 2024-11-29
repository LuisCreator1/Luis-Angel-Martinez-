#include <stdio.h>
#include <ctype.h>

/* Cuenta letras minúsculas y mayúsculas.
El programa, al recibir como dato una frase, determina el número de letras
minúsculas y mayúsculas que existen en la frase. */

void main(void)
{
    char cad[50];
    int i = 0, mi = 0, ma = 0;

    printf("\nIngrese la cadena de caracteres (máximo 50 caracteres): ");
    gets(cad);  // Aunque gets() es inseguro, lo mantengo como en tu código.

    while(cad[i] != '\0')
    {
        if (islower(cad[i]))
            mi++;  // Incrementar el contador de minúsculas
        else if (isupper(cad[i]))
            ma++;  // Incrementar el contador de mayúsculas
        i++;
    }

    printf("\n\nNúmero de letras minúsculas: %d", mi);
    printf("\nNúmero de letras mayúsculas: %d", ma);
}
