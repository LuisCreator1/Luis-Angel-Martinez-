#include <stdio.h>
#include <string.h>

/* Vendedores. El programa maneja información sobre las ventas que realizan los vendedores de artículos domésticos de una importante empresa de la Ciudad de México. */

typedef struct { /* Declaración de la estructura banco. */
    char noba[10]; /* Nombre del banco. */
    char nucu[10]; /* Número de cuenta. */
} banco;

typedef union { /* Declaración de la union fpago. */
    banco che; /* Cheque. Campo de tipo estructura banco. */
    banco nomi; /* Nómina. Campo de tipo estructura banco. */
    char venta; /* Ventanilla. */
} fpago;

typedef struct { /* Declaración de la estructura domicilio. */
    char cnu[20]; /* Calle y número. */
    char col[20]; /* Colonia. */
    char cp[5];  /* Código Postal. */
    char ciu[15]; /* Ciudad. */
} domicilio;

typedef struct { /* Declaración de la estructura vendedor. */
    int num; /* Número de vendedor. */
    char nom[20]; /* Nombre del vendedor. */
    float ven[12]; /* Ventas del año. Arreglo unidimensional de tipo real. */
    domicilio domi; /* domi es de tipo estructura domicilio. */
    float sal; /* Salario mensual. */
    fpago pago; /* pago es de tipo unión fpago. */
    int cla; /* Clave forma de pago. */
} vendedor;

void Lectura(vendedor *, int);
void F1(vendedor *, int);
void F2(vendedor *, int);
void F3(vendedor *, int);
void F4(vendedor *, int); /* Prototipos de funciones. */

void main(void) {
    vendedor VENDEDORES[100]; /* Declaración del arreglo unidimensional de tipo estructura vendedor. */
    int TAM;

    do {
        printf("Ingrese el número de vendedores: ");
        scanf("%d", &TAM);
    } while (TAM > 100 || TAM < 1); /* Se verifica que el número de elementos del arreglo sea correcto. */

    Lectura(VENDEDORES, TAM);
    F1(VENDEDORES, TAM);
    F2(VENDEDORES, TAM);
    F3(VENDEDORES, TAM);
    F4(VENDEDORES, TAM);

    printf("\n\tFIN DEL PROGRAMA");
}

void Lectura(vendedor A[], int T) {
    int I, J;
    for (I = 0; I < T; I++) {
        printf("\n\tIngrese datos del vendedor %d", I + 1);

        // Número de vendedor
        printf("\nNúmero de vendedor: ");
        scanf("%d", &A[I].num);

        // Nombre del vendedor
        printf("Nombre del vendedor: ");
        fflush(stdin);
        fgets(A[I].nom, 20, stdin);
        A[I].nom[strcspn(A[I].nom, "\n")] = '\0';  // Eliminar el salto de línea dejado por fgets

        // Ventas del año
        printf("Ventas del año: \n");
        for (J = 0; J < 12; J++) {
            printf("\tMes %d: ", J + 1);
            scanf("%f", &A[I].ven[J]);
        }

        // Domicilio del vendedor
        printf("Domicilio del vendedor: \n");
        printf("\tCalle y número: ");
        fflush(stdin);
        fgets(A[I].domi.cnu, 20, stdin);
        A[I].domi.cnu[strcspn(A[I].domi.cnu, "\n")] = '\0';  // Eliminar el salto de línea
        printf("\tColonia: ");
        fgets(A[I].domi.col, 20, stdin);
        A[I].domi.col[strcspn(A[I].domi.col, "\n")] = '\0';  // Eliminar el salto de línea
        printf("\tCódigo Postal: ");
        fgets(A[I].domi.cp, 5, stdin);
        A[I].domi.cp[strcspn(A[I].domi.cp, "\n")] = '\0';  // Eliminar el salto de línea
        printf("\tCiudad: ");
        fgets(A[I].domi.ciu, 15, stdin);
        A[I].domi.ciu[strcspn(A[I].domi.ciu, "\n")] = '\0';  // Eliminar el salto de línea

        // Salario
        printf("Salario del vendedor: ");
        scanf("%f", &A[I].sal);

        // Forma de Pago
        printf("Forma de Pago (Banco-1 Nómina-2 Ventanilla-3): ");
        scanf("%d", &A[I].cla);

        // Dependiendo de la clave, almacenamos la información correspondiente
        switch (A[I].cla) {
            case 1: {  // Pago mediante banco
                printf("\tNombre del banco: ");
                fflush(stdin);
                fgets(A[I].pago.che.noba, 10, stdin);
                A[I].pago.che.noba[strcspn(A[I].pago.che.noba, "\n")] = '\0';  // Eliminar el salto de línea
                printf("\tNúmero de cuenta: ");
                fgets(A[I].pago.che.nucu, 10, stdin);
                A[I].pago.che.nucu[strcspn(A[I].pago.che.nucu, "\n")] = '\0';  // Eliminar el salto de línea
                break;
            }
            case 2: {  // Pago mediante nómina
                printf("\tNombre del banco: ");
                fflush(stdin);
                fgets(A[I].pago.nomi.noba, 10, stdin);
                A[I].pago.nomi.noba[strcspn(A[I].pago.nomi.noba, "\n")] = '\0';  // Eliminar el salto de línea
                printf("\tNúmero de cuenta: ");
                fgets(A[I].pago.nomi.nucu, 10, stdin);
                A[I].pago.nomi.nucu[strcspn(A[I].pago.nomi.nucu, "\n")] = '\0';  // Eliminar el salto de línea
                break;
            }
            case 3:  // Pago mediante ventanilla
                A[I].pago.venta = 'S';
                break;
            default:
                printf("Forma de pago no válida.\n");
                break;
        }
    }
}

void F1(vendedor A[], int T) {
    int I, J;
    float SUM;
    printf("\n\t\tVentas Totales de los Vendedores");
    for (I = 0; I < T; I++) {
        printf("\nVendedor: %d", A[I].num);
        SUM = 0.0;
        for (J = 0; J < 12; J++) {
            SUM += A[I].ven[J];
        }
        printf("\nVentas: %.2f\n", SUM);
    }
}

void F2(vendedor A[], int T) {
    int I, J;
    float SUM;
    printf("\n\t\tIncremento a los Vendedores con Ventas > 1,500,000$");
    for (I = 0; I < T; I++) {
        SUM = 0.0;
        for (J = 0; J < 12; J++) {
            SUM += A[I].ven[J];
        }
        if (SUM > 1500000.00) {
            A[I].sal = A[I].sal * 1.05;
            printf("\nNúmero de empleado: %d\nVentas: %.2f\nNuevo salario: %.2f", A[I].num, SUM, A[I].sal);
        }
    }
}

void F3(vendedor A[], int T) {
    int I, J;
    float SUM;
    printf("\n\t\tVendedores con Ventas < 300,000");
    for (I = 0; I < T; I++) {
        SUM = 0.0;
        for (J = 0; J < 12; J++) {
            SUM += A[I].ven[J];
        }
        if (SUM < 300000.00) {
            printf("\nNúmero de empleado: %d\nNombre: %s\nVentas: %.2f", A[I].num, A[I].nom, SUM);
        }
    }
}

void F4(vendedor A[], int T) {
    int I;
    printf("\n\t\tVendedores con Cuenta en el Banco");
    for (I = 0; I < T; I++) {
        if (A[I].cla == 1) {
            printf("\nNúmero de vendedor: %d\n Banco: %s\nCuenta: %s", A[I].num, A[I].pago.che.noba, A[I].pago.che.nucu);
        }
    }
}
