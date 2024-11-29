#include <stdio.h>
#include <string.h>

typedef struct {
    int clave;
    char nombre[15];
    float precio;
    int existencia;
} producto;

void Lectura(producto *, int);
void Ventas(producto *, int);
void Reabastecimiento(producto *, int);
void Nuevos_Productos(producto *, int *);
void Inventario(producto *, int);

void main(void) {
    producto INV[100];
    int TAM, OPE;

    do {
        printf("Ingrese el número de productos: ");
        scanf("%d", &TAM);
    } while (TAM > 100 || TAM < 1);  // Corrected logical OR

    Lectura(INV, TAM);
    printf("\nIngrese operación a realizar. \n\t\t1 – Ventas \n\t\t 2 – Reabastecimiento \n\t\t 3 - Nuevos Productos \n\t\t 4 – Inventario \n\t\t 0 - Salir: ");
    scanf("%d", &OPE);

    while (OPE) {
        switch (OPE) {
            case 1: Ventas(INV, TAM); break;
            case 2: Reabastecimiento(INV, TAM); break;
            case 3: Nuevos_Productos(INV, &TAM); break;
            case 4: Inventario(INV, TAM); break;
        }
        printf("\nIngrese operación a realizar. \n\t\t1 – Ventas \n\t\t 2 – Reabastecimiento \n\t\t 3 - Nuevos Productos \n\t\t 4 – Inventario \n\t\t 0 - Salir: ");
        scanf("%d", &OPE);
    }
}

void Lectura(producto A[], int T) {
    int I;
    for (I = 0; I < T; I++) {
        printf("\nIngrese información del producto %d", I + 1);
        printf("\n\tClave: ");
        scanf("%d", &A[I].clave);
        fflush(stdin);

        printf("\tNombre: ");
        fgets(A[I].nombre, sizeof(A[I].nombre), stdin);
        A[I].nombre[strcspn(A[I].nombre, "\n")] = 0;  // Remove newline

        printf("\tPrecio: ");
        scanf("%f", &A[I].precio);

        printf("\tExistencia: ");
        scanf("%d", &A[I].existencia);
    }
}

void Ventas(producto A[], int T) {
    int CLA, CAN, I, RES;
    float TOT = 0.0, PAR;

    printf("\nIngrese clave del producto -0 para salir-: ");
    scanf("%d", &CLA);

    while (CLA) {
        printf("\tCantidad: ");
        scanf("%d", &CAN);

        I = 0;
        while (I < T && A[I].clave < CLA) I++;  // Search for the product

        if (I == T || A[I].clave > CLA) {
            printf("\nLa clave del producto es incorrecta");
        } else if (A[I].existencia >= CAN) {
            A[I].existencia -= CAN;  // Update inventory
            PAR = A[I].precio * CAN;
            TOT += PAR;
        } else {
            printf("\nNo existe en inventario la cantidad solicitada. Solo hay %d", A[I].existencia);
            printf("\nLos lleva 1 - Si 0 – No?: ");
            scanf("%d", &RES);
            if (RES) {
                PAR = A[I].precio * A[I].existencia;
                A[I].existencia = 0;  // Update inventory to zero
                TOT += PAR;
            }
        }

        printf("\nIngrese la siguiente clave del producto -0 para salir-: ");
        scanf("%d", &CLA);
    }
    printf("\nTotal de la venta: %.2f", TOT);
}

void Reabastecimiento(producto A[], int T) {
    int CLA, CAN, I;

    printf("\nIngrese clave del producto -0 para salir-: ");
    scanf("%d", &CLA);

    while (CLA) {
        I = 0;
        while (I < T && A[I].clave < CLA) I++;  // Search for the product

        if (I == T || A[I].clave > CLA) {
            printf("\nLa clave del producto ingresada es incorrecta");
        } else {
            printf("\tCantidad: ");
            scanf("%d", &CAN);
            A[I].existencia += CAN;  // Update inventory
        }

        printf("\nIngrese otra clave del producto -0 para salir-: ");
        scanf("%d", &CLA);
    }
}

void Nuevos_Productos(producto A[], int *T) {
    int CLA, I, J;

    printf("\nIngrese clave del producto -0 para salir-: ");
    scanf("%d", &CLA);

    while (*T < 30 && CLA) {
        I = 0;
        while (I < *T && A[I].clave < CLA) I++;  // Search for the right position

        if (I == *T) {  // Insert at the last position
            A[I].clave = CLA;
            printf("\tNombre: ");
            fflush(stdin);
            fgets(A[I].nombre, sizeof(A[I].nombre), stdin);
            A[I].nombre[strcspn(A[I].nombre, "\n")] = 0;  // Remove newline

            printf("\tPrecio: ");
            scanf("%f", &A[I].precio);

            printf("\tCantidad: ");
            scanf("%d", &A[I].existencia);

            (*T)++;  // Increment product count
        } else if (A[I].clave == CLA) {
            printf("\nEl producto ya se encuentra en el inventario");
        } else {
            for (J = *T; J > I; J--) {
                A[J] = A[J - 1];  // Shift elements right
            }
            A[I].clave = CLA;
            printf("\tNombre: ");
            fflush(stdin);
            fgets(A[I].nombre, sizeof(A[I].nombre), stdin);
            A[I].nombre[strcspn(A[I].nombre, "\n")] = 0;  // Remove newline

            printf("\tPrecio: ");
            scanf("%f", &A[I].precio);

            printf("\tCantidad: ");
            scanf("%d", &A[I].existencia);

            (*T)++;  // Increment product count
        }

        printf("\nIngrese otra clave de producto -0 para salir-: ");
        scanf("%d", &CLA);
    }

    if (*T == 30) {
        printf("\nYa no hay espacio para incorporar nuevos productos");
    }
}

void Inventario(producto A[], int T) {
    int I;
    for (I = 0; I < T; I++) {
        printf("\nClave: %d", A[I].clave);
        printf("\tNombre: %s", A[I].nombre);
        printf("\tPrecio: %.2f", A[I].precio);
        printf("\tExistencia: %d \n", A[I].existencia);
}
}
