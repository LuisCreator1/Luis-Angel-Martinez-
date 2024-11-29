#include <stdio.h>
#include <string.h> // Biblioteca para manejo de cadenas

int main(void) {
    // Declaración de cadenas y variables
    char *cad0 = "Buenos días";
    char cad1[20] = "Hola";
    char cad2[] = "México";
    char cad3[] = {'B', 'i', 'e', 'n', 'v', 'e', 'n', 'i', 'd', 'o', '\0'};
    char cad4[20], cad5[20], cad6[20];
    char p;
    int i = 0;

    // Imprimir cadenas predefinidas
    printf("\nLa cadena cad0 es: ");
    puts(cad0);

    printf("\nLa cadena cad1 es: ");
    printf("%s\n", cad1);

    printf("\nLa cadena cad2 es: ");
    puts(cad2);

    printf("\nLa cadena cad3 es: ");
    puts(cad3);

    // Leer una línea de texto con fgets
    printf("\nIngrese una línea de texto (se lee con fgets): \n");
    fgets(cad4, sizeof(cad4), stdin);
    cad4[strcspn(cad4, "\n")] = '\0'; // Eliminar el salto de línea al final
    printf("\nLa cadena cad4 es: ");
    puts(cad4);

    // Leer una palabra con scanf
    printf("\nIngrese una palabra (se lee con scanf): \n");
    scanf("%19s", cad5); // Limitar la entrada a 19 caracteres
    printf("\nLa cadena cad5 es: ");
    printf("%s\n", cad5);

    // Consumir el salto de línea residual en el búfer
    while (getchar() != '\n');

    // Leer una línea de texto carácter por carácter con getchar
    printf("\nIngrese una línea de texto (se lee con getchar): \n");
    while ((p = getchar()) != '\n') {
        cad6[i++] = p;
    }
    cad6[i] = '\0'; // Terminar la cadena con el carácter NULL
    printf("\nLa cadena cad6 es: ");
    puts(cad6);

    return 0;
}
