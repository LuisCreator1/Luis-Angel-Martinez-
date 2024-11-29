#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Estructuras-2.
El programa muestra la manera en que se declara una estructura, así como la
forma en que se tiene acceso a los campos de los apuntadores de tipo estructura
tanto para lectura como para escritura. Se utiliza además una función que
recibe como parámetro un apuntador de tipo estructura. */

struct alumno /* Declaración de la estructura. */
{
    int matricula;
    char nombre[20];
    char carrera[20]; /* Campos de la estructura alumno. */
    float promedio;
    char direccion[20];
};

void Lectura(struct alumno *); /* Prototipo de función. */

void main(void)
{
    struct alumno a0 = {120, "María", "Contabilidad", 8.9, "Querétaro"};
    struct alumno *a3, *a4, *a5, a6;

    /* Apuntadores de tipo estructura */
    a3 = &a0; /* En este caso al apuntador de tipo estructura alumno a3
                se le asigna la dirección de la variable de tipo estructura alumno, a0. */

    /* Asignación dinámica de memoria */
    a4 = (struct alumno *)malloc(sizeof(struct alumno)); /* Asignación dinámica para a4 */
    if (a4 == NULL) { /* Verificar que la memoria se haya asignado correctamente */
        printf("Error en la asignación de memoria.\n");
        return;
    }

    /* Lectura de datos para a4 */
    printf("\nIngrese la matrícula del alumno 4: ");
    scanf("%d", &a4->matricula);
    getchar(); /* Limpiar el buffer de entrada */

    printf("Ingrese el nombre del alumno 4: ");
    fgets(a4->nombre, sizeof(a4->nombre), stdin);
    a4->nombre[strcspn(a4->nombre, "\n")] = '\0';  // Eliminar salto de línea de fgets

    printf("Ingrese la carrera del alumno 4: ");
    fgets(a4->carrera, sizeof(a4->carrera), stdin);
    a4->carrera[strcspn(a4->carrera, "\n")] = '\0';  // Eliminar salto de línea de fgets

    printf("Ingrese promedio del alumno 4: ");
    scanf("%f", &a4->promedio);
    getchar(); /* Limpiar el buffer de entrada */

    printf("Ingrese la dirección del alumno 4: ");
    fgets(a4->direccion, sizeof(a4->direccion), stdin);
    a4->direccion[strcspn(a4->direccion, "\n")] = '\0';  // Eliminar salto de línea de fgets

    /* Asignación dinámica de memoria para a5 */
    a5 = (struct alumno *)malloc(sizeof(struct alumno));
    if (a5 == NULL) { /* Verificar que la memoria se haya asignado correctamente */
        printf("Error en la asignación de memoria.\n");
        return;
    }

    /* Llamada a la función Lectura para a5 */
    Lectura(a5);

    /* Llamada a la función Lectura para a6 */
    Lectura(&a6);

    /* Imprimir los datos */
    printf("\nDatos del alumno 3\n");
    printf("%d\t%s\t%s\t%.2f\t%s\n", a3->matricula, a3->nombre, a3->carrera,
           a3->promedio, a3->direccion);

    printf("\nDatos del alumno 4\n");
    printf("%d\t%s\t%s\t%.2f\t%s\n", a4->matricula, a4->nombre, a4->carrera,
           a4->promedio, a4->direccion);

    printf("\nDatos del alumno 5\n");
    printf("%d\t%s\t%s\t%.2f\t%s\n", a5->matricula, a5->nombre, a5->carrera,
           a5->promedio, a5->direccion);

    printf("\nDatos del alumno 6\n");
    printf("%d\t%s\t%s\t%.2f\t%s\n", a6.matricula, a6.nombre, a6.carrera,
           a6.promedio, a6.direccion);

    /* Liberar memoria dinámica */
    free(a4);
    free(a5);
}

void Lectura(struct alumno *a)
{
    /* Esta función permite leer los campos de un apuntador de tipo estructura alumno. */
    printf("\nIngrese la matrícula del alumno: ");
    scanf("%d", &a->matricula);
    getchar(); /* Limpiar el buffer de entrada */

    printf("Ingrese el nombre del alumno: ");
    fgets(a->nombre, sizeof(a->nombre), stdin);
    a->nombre[strcspn(a->nombre, "\n")] = '\0';  // Eliminar salto de línea de fgets

    printf("Ingrese la carrera del alumno: ");
    fgets(a->carrera, sizeof(a->carrera), stdin);
    a->carrera[strcspn(a->carrera, "\n")] = '\0';  // Eliminar salto de línea de fgets

    printf("Ingrese el promedio del alumno: ");
    scanf("%f", &a->promedio);
    getchar(); /* Limpiar el buffer de entrada */

    printf("Ingrese la dirección del alumno: ");
    fgets(a->direccion, sizeof(a->direccion), stdin);
    a->direccion[strcspn(a->direccion, "\n")] = '\0';  // Eliminar salto de línea de fgets
}
