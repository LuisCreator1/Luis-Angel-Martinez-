#include <stdio.h>

/* Archivos y caracteres.
El programa lee caracteres de un archivo y los despliega en la pantalla. */

int main(void) {
    char p1;
    FILE *ar;

    // Abrir el archivo para lectura
    if ((ar = fopen("arc.txt", "r")) != NULL) {
        // Leer caracteres del archivo hasta el final
        while ((p1 = fgetc(ar)) != EOF) {
            putchar(p1); // Mostrar el carácter en la pantalla
        }
        fclose(ar); // Cerrar el archivo
    } else {
        // Error al intentar abrir el archivo
        printf("No se puede abrir el archivo\n");
    }

    return 0; // Finalizar el programa correctamente
}
