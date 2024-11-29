#include <stdio.h>
#include <ctype.h>
#include <string.h>

/* Reemplaza palabras.
El programa lee cadenas de caracteres de un archivo y cada vez que
encuentra la palabra México escrita en forma incorrecta —la primera con
minúscula— la reemplaza por su forma correcta y escribe la cadena en otro
archivo. */
void cambia(FILE *, FILE *);
/* Prototipo de función. Se pasan dos archivos como parámetros. */

void main(void)
{
    FILE *ar;
    FILE *ap;
    ar = fopen("arc.txt", "r"); /* Se abre el archivo arc.txt para lectura. */
    ap = fopen("arc1.txt", "w"); /* Se abre el archivo arc1.txt para escritura. */

    if ((ar != NULL) && (ap != NULL))
    {
        cambia(ar, ap);
        fclose(ar);
        fclose(ap);
    }
    else
    {
        printf("No se pueden abrir los archivos.\n");
    }
}

void cambia(FILE *ap1, FILE *ap2)
{
    /* Esta función reemplaza en la cadena de caracteres la palabra "méxico" escrita
    con minúsculas —la primera letra— por su forma correcta y escribe la cadena
    de caracteres en un nuevo archivo. */
    int i, j, k;
    char cad[100];  // Tamaño mayor para manejar cadenas más largas
    char cad1[100], aux[100];
    char *cad2;

    // Lee línea por línea del archivo
    while (fgets(cad, 100, ap1) != NULL)
    {
        strcpy(cad1, cad);  // Copia la cadena leída a cad1
        cad2 = strstr(cad1, "méxico");  // Busca "méxico" en cad1

        // Mientras encuentre "méxico" en minúsculas
        while (cad2 != NULL)
        {
            cad2[0] = 'M';  // Reemplaza la 'm' por 'M'

            i = strlen(cad1);   // Longitud total de cad1
            j = strlen(cad2);   // Longitud de la subcadena "méxico"
            k = i - j;          // Calcula la posición para insertar "México"

            if (k > 0)
            {
                strncpy(aux, cad1, k);  // Copia la parte antes de "méxico"
                aux[k] = '\0';          // Finaliza la cadena
                strcat(aux, cad2);      // Agrega el "México" corregido
                strcpy(cad1, aux);      // Actualiza cad1
            }
            else
            {
                strcpy(cad1, cad2);  // Si "méxico" es la primera palabra, solo copia
            }

            cad2 = strstr(cad1, "méxico");  // Busca la siguiente ocurrencia
        }

        fputs(cad1, ap2);  // Escribe la cadena corregida en el archivo de salida
    }
}
