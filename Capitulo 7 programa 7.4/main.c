#include <stdio.h>
#include <string.h> // Para usar funciones como strcpy

void main(void) {
    char *cad0;
    cad0 = "Argentina"; /* La declaración y la asignación son correctas. */
    puts(cad0);          // Imprime "Argentina"
    cad0 = "Brasil";     /* Correcto. Modifica el puntero a otra cadena literal. */
    puts(cad0);          // Imprime "Brasil"

    char cad1[20];       // Arreglo con espacio reservado
    printf("\nIngrese una cadena de caracteres (máx. 19 caracteres): ");
    fgets(cad1, sizeof(cad1), stdin); // Uso seguro para leer una cadena
    cad1[strcspn(cad1, "\n")] = '\0'; // Elimina el salto de línea
    puts(cad1);          // Imprime la cadena ingresada

    char cad2[20] = "México"; /* Correcto. Se inicializa con una cadena. */
    puts(cad2);          // Imprime "México"

    printf("\nIngrese otra cadena (máx. 19 caracteres): ");
    fgets(cad2, sizeof(cad2), stdin); // Lee una nueva cadena
    cad2[strcspn(cad2, "\n")] = '\0'; // Elimina el salto de línea
    puts(cad2);          // Imprime la nueva cadena ingresada

    // Esta línea tenía un error: ahora usa strcpy para copiar la cadena completa.
    strcpy(cad2, "Guatemala"); /* Correcto. Copia la cadena en el arreglo. */
    puts(cad2);          // Imprime "Guatemala"
}
