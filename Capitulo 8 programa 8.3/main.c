#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Estructuras-3.
El programa muestra la manera en que se declara una estructura anidada, así
como la forma de acceso a los campos de las variables o apuntadores de tipo
estructura, tanto para lectura como para escritura. Se utiliza además una
función que recibe como parámetro un apuntador de tipo estructura. */

typedef struct { /* Declaración de la estructura domicilio utilizando
                  un typedef. */
    char calle[20];
    int numero;
    int cp;
    char localidad[20];
} domicilio;

struct empleado { /* Declaración de la estructura anidada empleado. */
    char nombre[20];
    char departamento[20];
    float sueldo;
    domicilio direccion; /* direccion es un campo de tipo estructura
                           domicilio de la estructura empleado. */
};

void Lectura(struct empleado *a) { /* Función que permite leer los campos de un apuntador de tipo estructura empleado. */
    printf("\nIngrese el nombre del empleado: ");
    fgets(a->nombre, sizeof(a->nombre), stdin);
    a->nombre[strcspn(a->nombre, "\n")] = '\0';  // Eliminar salto de línea de fgets

    printf("Ingrese el departamento de la empresa: ");
    fgets(a->departamento, sizeof(a->departamento), stdin);
    a->departamento[strcspn(a->departamento, "\n")] = '\0';  // Eliminar salto de línea de fgets

    printf("Ingrese el sueldo del empleado: ");
    scanf("%f", &a->sueldo);
    getchar(); // Limpiar el buffer de entrada

    printf("----- Ingrese la dirección del empleado -----\n");
    printf("\tCalle: ");
    fgets(a->direccion.calle, sizeof(a->direccion.calle), stdin);
    a->direccion.calle[strcspn(a->direccion.calle, "\n")] = '\0';  // Eliminar salto de línea de fgets

    printf("\tNúmero: ");
    scanf("%d", &a->direccion.numero);

    printf("\tCódigo Postal: ");
    scanf("%d", &a->direccion.cp);
    getchar(); // Limpiar el buffer de entrada

    printf("\tLocalidad: ");
    fgets(a->direccion.localidad, sizeof(a->direccion.localidad), stdin);
    a->direccion.localidad[strcspn(a->direccion.localidad, "\n")] = '\0';  // Eliminar salto de línea de fgets
}

void main(void) {
    struct empleado e0 = {"Arturo", "Compras", 15500.75, "San Jerónimo", 120, 3490, "Toluca"};
    struct empleado *e1, *e2, e3, e4;

    /* Asignación dinámica de memoria para e1 y e2 */
    e1 = (struct empleado *)malloc(sizeof(struct empleado));
    if (e1 == NULL) { /* Verificar que la memoria se haya asignado correctamente */
        printf("Error en la asignación de memoria.\n");
        return;
    }

    e2 = (struct empleado *)malloc(sizeof(struct empleado));
    if (e2 == NULL) { /* Verificar que la memoria se haya asignado correctamente */
        printf("Error en la asignación de memoria.\n");
        free(e1);
        return;
    }

    /* Lectura de datos para e1 */
    printf("\nIngrese el nombre del empleado 1: ");
    fgets(e1->nombre, sizeof(e1->nombre), stdin);
    e1->nombre[strcspn(e1->nombre, "\n")] = '\0';  // Eliminar salto de línea de fgets

    printf("Ingrese el departamento de la empresa: ");
    fgets(e1->departamento, sizeof(e1->departamento), stdin);
    e1->departamento[strcspn(e1->departamento, "\n")] = '\0';  // Eliminar salto de línea de fgets

    printf("Ingrese el sueldo del empleado: ");
    scanf("%f", &e1->sueldo);
    getchar(); // Limpiar el buffer de entrada

    printf("----- Ingrese la dirección del empleado -----\n");
    printf("\tCalle: ");
    fgets(e1->direccion.calle, sizeof(e1->direccion.calle), stdin);
    e1->direccion.calle[strcspn(e1->direccion.calle, "\n")] = '\0';  // Eliminar salto de línea de fgets

    printf("\tNúmero: ");
    scanf("%d", &e1->direccion.numero);

    printf("\tCódigo Postal: ");
    scanf("%d", &e1->direccion.cp);
    getchar(); // Limpiar el buffer de entrada

    printf("\tLocalidad: ");
    fgets(e1->direccion.localidad, sizeof(e1->direccion.localidad), stdin);
    e1->direccion.localidad[strcspn(e1->direccion.localidad, "\n")] = '\0';  // Eliminar salto de línea de fgets

    /* Lectura de datos para e3 */
    printf("\nIngrese el nombre del empleado 3: ");
    fgets(e3.nombre, sizeof(e3.nombre), stdin);
    e3.nombre[strcspn(e3.nombre, "\n")] = '\0';  // Eliminar salto de línea de fgets

    printf("Ingrese el departamento de la empresa: ");
    fgets(e3.departamento, sizeof(e3.departamento), stdin);
    e3.departamento[strcspn(e3.departamento, "\n")] = '\0';  // Eliminar salto de línea de fgets

    printf("Ingrese el sueldo del empleado: ");
    scanf("%f", &e3.sueldo);
    getchar(); // Limpiar el buffer de entrada

    printf("----- Ingrese la dirección del empleado -----\n");
    printf("\tCalle: ");
    fgets(e3.direccion.calle, sizeof(e3.direccion.calle), stdin);
    e3.direccion.calle[strcspn(e3.direccion.calle, "\n")] = '\0';  // Eliminar salto de línea de fgets

    printf("\tNúmero: ");
    scanf("%d", &e3.direccion.numero);

    printf("\tCódigo Postal: ");
    scanf("%d", &e3.direccion.cp);
    getchar(); // Limpiar el buffer de entrada

    printf("\tLocalidad: ");
    fgets(e3.direccion.localidad, sizeof(e3.direccion.localidad), stdin);
    e3.direccion.localidad[strcspn(e3.direccion.localidad, "\n")] = '\0';  // Eliminar salto de línea de fgets

    /* Llamada a la función Lectura para e2 y e4 */
    Lectura(e2);
    Lectura(&e4);

    /* Mostrar datos de los empleados */
    printf("\nDatos del empleado 1:\n");
    printf("%s\t%s\t%.2f\t%s\t%d\t%d\t%s\n", e1->nombre, e1->departamento, e1->sueldo,
           e1->direccion.calle, e1->direccion.numero, e1->direccion.cp, e1->direccion.localidad);

    printf("\nDatos del empleado 3:\n");
    printf("%s\t%s\t%.2f\t%s\t%d\t%d\t%s\n", e3.nombre, e3.departamento, e3.sueldo,
           e3.direccion.calle, e3.direccion.numero, e3.direccion.cp, e3.direccion.localidad);

    /* Liberar memoria dinámica */
    free(e1);
    free(e2);
}
