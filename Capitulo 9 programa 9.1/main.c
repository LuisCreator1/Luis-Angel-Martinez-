#include <stdio.h>

/* Archivos y caracteres.
El programa escribe caracteres en un archivo. */

int main(void)
{
    char p1;
    FILE *ar;
    ar = fopen("arc.txt", "w"); /* Se abre el archivo arc.txt para escritura. */

    if (ar != NULL)
    {
        printf("Introduce caracteres. Presiona Enter para terminar:\n");
        while ((p1 = getchar()) != '\n')
        {
            /* Se escriben caracteres en el archivo mientras no se detecte el
               caracter que indica el fin de la línea. */
            fputc(p1, ar);
        }
        fclose(ar); /* Se cierra el archivo. */
        printf("Archivo guardado exitosamente.\n");
    }
    else
    {
        printf("No se puede abrir el archivo\n");
    }

    return 0;
}
