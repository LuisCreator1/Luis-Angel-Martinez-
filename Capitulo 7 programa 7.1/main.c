#include <stdio.h> // Biblioteca para funciones de entrada y salida

int main(void)
{
    char p1, p2, p3 = '$'; // Declaración e inicialización de variables

    printf("\nIngrese un caracter: ");
    p1 = getchar(); // Se utiliza la función getchar para leer un carácter.
    putchar(p1);    // Se utiliza la función putchar para escribir el carácter.
    printf("\n");

    // Eliminar caracteres sobrantes en el búfer de entrada
    while (getchar() != '\n'); // Alternativa estándar para limpiar el búfer

    printf("\nEl caracter p3 es: ");
    putchar(p3); // Escribir el carácter almacenado en p3.
    printf("\n");

    printf("\nIngrese otro caracter: ");
    scanf(" %c", &p2); // Leer otro carácter con scanf
    printf("%c\n", p2); // Escribir el carácter leído

    return 0; // Retornar 0 al sistema operativo
}
