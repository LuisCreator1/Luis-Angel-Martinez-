#include <stdio.h>
#include <ctype.h>

/* Verifica.
El programa, al recibir como datos una cadena de caracteres y una posición específica en la cadena, determina si el caracter correspondiente es una letra minúscula. */

void main(void)
{
    char p, cad[50];
    int n;

    printf("\nIngrese la cadena de caracteres (máximo 50): ");
    fgets(cad, sizeof(cad), stdin);

    // Eliminar el salto de línea al final de la cadena (si existe)
    cad[strcspn(cad, "\n")] = 0;

    printf("\nIngrese la posición en la cadena que desea verificar: ");
    scanf("%d", &n);

    if ((n >= 1) && (n <= strlen(cad)))  // Verificación correcta de la posición
    {
        p = cad[n - 1];  // Recordar que las posiciones en C son base 0
        if (islower(p))  // Verifica si es una letra minúscula
            printf("\n%c es una letra minúscula", p);
        else
            printf("\n%c no es una letra minúscula", p);
    }
    else
        printf("\nEl valor ingresado de n es incorrecto");
}
