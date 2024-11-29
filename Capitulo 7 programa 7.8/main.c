#include <stdio.h>
#include <string.h>
#include <ctype.h>

/* Minúsculas y mayúsculas.
El programa, al recibir como dato un arreglo unidimensional de tipo
cadena de caracteres, determina el número de minúsculas y mayúsculas
que hay en cada cadena. */

void minymay(char *cadena); /* Prototipo de función. */

void main(void)
{
    int i, n;
    char FRA[20][50];  /* Arreglo unidimensional de cadenas de caracteres. */

    printf("\nIngrese el número de filas del arreglo: ");
    scanf("%d", &n);

    // Se lee cada cadena de texto.
    for (i = 0; i < n; i++)
    {
        printf("Ingrese la línea %d de texto: ", i + 1);
        getchar();  // Limpiar el buffer de entrada antes de usar gets
        fgets(FRA[i], sizeof(FRA[i]), stdin);
        FRA[i][strcspn(FRA[i], "\n")] = 0;  // Eliminar el salto de línea que añade fgets
    }

    printf("\n\n");
    // Procesar cada cadena ingresada.
    for (i = 0; i < n; i++)
        minymay(FRA[i]);
}

void minymay(char *cadena)
{
    int i = 0, mi = 0, ma = 0;

    while (cadena[i] != '\0')
    {
        if (islower(cadena[i]))  // Verifica si es minúscula
            mi++;
        else if (isupper(cadena[i]))  // Verifica si es mayúscula
            ma++;
        i++;
    }

    // Muestra los resultados.
    printf("\nNúmero de letras minúsculas: %d", mi);
    printf("\nNúmero de letras mayúsculas: %d\n", ma);
}
