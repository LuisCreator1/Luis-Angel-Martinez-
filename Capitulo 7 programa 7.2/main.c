#include <stdio.h>
#include <ctype.h> // Biblioteca para el manejo de caracteres

int main(void)
{
    char p1;

    // Análisis para verificar si el carácter ingresado es un dígito
    printf("\nIngrese un carácter para analizar si este es un dígito: ");
    p1 = getchar();
    if (isdigit(p1)) // Verifica si p1 es un dígito
        printf("%c es un dígito\n", p1);
    else
        printf("%c no es un dígito\n", p1);

    // Limpieza del búfer de entrada
    while (getchar() != '\n');

    // Análisis para verificar si el carácter ingresado es una letra
    printf("\nIngrese un carácter para examinar si este es una letra: ");
    p1 = getchar();
    if (isalpha(p1)) // Verifica si p1 es una letra
        printf("%c es una letra\n", p1);
    else
        printf("%c no es una letra\n", p1);

    // Limpieza del búfer de entrada
    while (getchar() != '\n');

    // Análisis para verificar si el carácter ingresado es una letra minúscula
    printf("\nIngrese un carácter para examinar si este es una letra minúscula: ");
    p1 = getchar();
    if (isalpha(p1)) {
        if (islower(p1)) // Verifica si p1 es una letra minúscula
            printf("%c es una letra minúscula\n", p1);
        else
            printf("%c no es una letra minúscula\n", p1);
    } else {
        printf("%c no es una letra\n", p1);
    }

    // Limpieza del búfer de entrada
    while (getchar() != '\n');

    // Conversión de una letra mayúscula a minúscula
    printf("\nIngrese una letra para convertirla de mayúscula a minúscula: ");
    p1 = getchar();
    if (isalpha(p1)) {
        if (isupper(p1)) // Verifica si p1 es una letra mayúscula
            printf("%c fue convertida de mayúscula a minúscula\n", tolower(p1));
        else
            printf("%c es una letra minúscula\n", p1);
    } else {
        printf("%c no es una letra\n", p1);
    }

    return 0; // Retorna 0 para indicar que el programa terminó correctamente
}
