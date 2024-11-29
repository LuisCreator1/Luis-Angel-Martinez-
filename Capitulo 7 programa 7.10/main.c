#include <stdio.h>
#include <stdlib.h>

/* Suma y promedio.
El programa, al recibir como datos varias cadenas de caracteres que
contienen reales, los suma y obtiene el promedio de los mismos. */

void main(void)
{
    char c, cad[10];
    int i = 0;
    float sum = 0.0;

    printf("\nDesea ingresar una cadena de caracteres (S/N)? ");
    c = getchar();
    getchar();  // Consumir el salto de línea dejado por getchar

    while (c == 'S' || c == 's')  // Aceptar tanto 'S' como 's'
    {
        printf("\nIngrese la cadena de caracteres: ");
        fgets(cad, sizeof(cad), stdin);

        // Eliminar el salto de línea que fgets agrega
        cad[strcspn(cad, "\n")] = 0;

        sum += atof(cad);  // Convertir la cadena a número flotante y sumar
        i++;  // Incrementar el contador de entradas

        printf("\nDesea ingresar otra cadena de caracteres (S/N)? ");
        c = getchar();
        getchar();  // Consumir el salto de línea
    }

    // Evitar división por cero si no se ingresaron números
    if (i > 0)
    {
        printf("\nSuma: %.2f", sum);
        printf("\nPromedio: %.2f", sum / i);
    }
    else
    {
        printf("\nNo se ingresaron datos válidos.");
    }
}
