#include <stdio.h>
#include <string.h>

/* Declaración de la estructura ubicación */
typedef struct {
    char zona[20];
    char calle[20];
    char colo[20];  /* Colonia */
} ubicacion;

/* Declaración de la estructura propiedades */
typedef struct {
    char clave[5];
    float scu;   /* Superficie cubierta */
    float ste;   /* Superficie terreno */
    char car[50]; /* Características */
    ubicacion ubi;  /* Ubicación */
    float precio;
    char dispo;  /* Disponibilidad (V-Renta, V-Venta) */
} propiedades;

void Lectura(propiedades *, int);
void F1(propiedades *, int);
void F2(propiedades *, int);

int main(void) {
    propiedades PROPIE[100];
    int TAM;

    do {
        printf("Ingrese el número de propiedades: ");
        scanf("%d", &TAM);
    } while (TAM > 100 || TAM < 1);  /* Verifica que el tamaño del arreglo sea válido */

    Lectura(PROPIE, TAM);
    F1(PROPIE, TAM);
    F2(PROPIE, TAM);

    return 0;
}

/* Función para leer los datos de las propiedades */
void Lectura(propiedades A[], int T) {
    int I;
    for (I = 0; I < T; I++) {
        printf("\n\tIngrese datos de la propiedad %d\n", I + 1);

        printf("Clave: ");
        getchar();  /* Limpiar el buffer */
        fgets(A[I].clave, 5, stdin);
        A[I].clave[strcspn(A[I].clave, "\n")] = 0;  /* Eliminar el salto de línea */

        printf("Superficie cubierta: ");
        scanf("%f", &A[I].scu);
        printf("Superficie terreno: ");
        scanf("%f", &A[I].ste);

        getchar();  /* Limpiar el buffer */
        printf("Características: ");
        fgets(A[I].car, 50, stdin);
        A[I].car[strcspn(A[I].car, "\n")] = 0;  /* Eliminar el salto de línea */

        printf("\tZona: ");
        fgets(A[I].ubi.zona, 20, stdin);
        A[I].ubi.zona[strcspn(A[I].ubi.zona, "\n")] = 0;  /* Eliminar el salto de línea */

        printf("\tCalle: ");
        fgets(A[I].ubi.calle, 20, stdin);
        A[I].ubi.calle[strcspn(A[I].ubi.calle, "\n")] = 0;

        printf("\tColonia: ");
        fgets(A[I].ubi.colo, 20, stdin);
        A[I].ubi.colo[strcspn(A[I].ubi.colo, "\n")] = 0;

        printf("Precio: ");
        scanf("%f", &A[I].precio);

        getchar();  /* Limpiar el buffer */
        printf("Disponibilidad (Venta-V Renta-R): ");
        scanf("%c", &A[I].dispo);
    }
}

/* Función para listar propiedades en venta en Miraflores con precio entre 450,000 y 650,000 */
void F1(propiedades A[], int T) {
    int I;
    printf("\n\t\tListado de Propiedades para Venta en Miraflores\n");

    for (I = 0; I < T; I++) {
        if ((A[I].dispo == 'V') && (strcmp(A[I].ubi.zona, "Miraflores") == 0)) {
            if (A[I].precio >= 450000 && A[I].precio <= 650000) {
                printf("\nClave de la propiedad: %s", A[I].clave);
                printf("\nSuperficie cubierta: %.2f", A[I].scu);
                printf("\nSuperficie terreno: %.2f", A[I].ste);
                printf("\nCaracterísticas: %s", A[I].car);
                printf("\nCalle: %s", A[I].ubi.calle);
                printf("\nColonia: %s", A[I].ubi.colo);
                printf("\nPrecio: %.2f\n", A[I].precio);
            }
        }
    }
}

/* Función para listar propiedades en renta dentro de un rango de precio */
void F2(propiedades A[], int T) {
    int I;
    float li, ls;
    char zon[20];

    printf("\n\t\tListado de Propiedades para Renta\n");
    printf("Ingrese zona geográfica: ");
    getchar();  /* Limpiar el buffer */
    fgets(zon, 20, stdin);
    zon[strcspn(zon, "\n")] = 0;  /* Eliminar el salto de línea */

    printf("Ingrese el límite inferior del precio: ");
    scanf("%f", &li);

    printf("Ingrese el límite superior del precio: ");
    scanf("%f", &ls);

    for (I = 0; I < T; I++) {
        if ((A[I].dispo == 'R') && (strcmp(A[I].ubi.zona, zon) == 0)) {
            if (A[I].precio >= li && A[I].precio <= ls) {
                printf("\nClave de la propiedad: %s", A[I].clave);
                printf("\nSuperficie cubierta: %.2f", A[I].scu);
                printf("\nSuperficie terreno: %.2f", A[I].ste);
                printf("\nCaracterísticas: %s", A[I].car);
                printf("\nCalle: %s", A[I].ubi.calle);
                printf("\nColonia: %s", A[I].ubi.colo);
                printf("\nPrecio: %.2f\n", A[I].precio);
            }
        }
    }
}
