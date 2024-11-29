#include <stdio.h>
#include <string.h>

/* Declaración de la estructura domicilio */
typedef struct {
    char cal[20];     /* Calle */
    int num;          /* Número */
    char col[20];     /* Colonia */
    char cp[5];       /* Código Postal */
    char ciu[20];     /* Ciudad */
} domicilio;

/* Declaración de la estructura paciente */
typedef struct {
    char nom[50];     /* Nombre y apellido */
    int edad;         /* Edad */
    char sexo;        /* Sexo ('F' para femenino, 'M' para masculino) */
    int con;          /* Condición (1..5) */
    domicilio dom;    /* Estructura domicilio */
    char tel[15];     /* Teléfono */
} paciente;

void Lectura(paciente *, int);
void F1(paciente *, int);
void F2(paciente *, int);
void F3(paciente *, int);

int main(void) {
    paciente HOSPITAL[100]; /* Arreglo para almacenar los pacientes */
    int TAM;

    do {
        printf("Ingrese el número de pacientes (1 a 50): ");
        scanf("%d", &TAM);
    } while (TAM > 50 || TAM < 1); /* Verifica que el tamaño del arreglo sea válido */

    Lectura(HOSPITAL, TAM);
    F1(HOSPITAL, TAM);
    F2(HOSPITAL, TAM);
    F3(HOSPITAL, TAM);

    return 0;
}

/* Función para leer la información de los pacientes */
void Lectura(paciente A[], int T) {
    int I;

    for (I = 0; I < T; I++) {
        printf("\n\t\tPaciente %d\n", I + 1);
        getchar();  /* Limpiar el buffer de entrada de scanf */

        printf("Nombre: ");
        fgets(A[I].nom, 50, stdin);
        A[I].nom[strcspn(A[I].nom, "\n")] = 0;  /* Eliminar el salto de línea */

        printf("Edad: ");
        scanf("%d", &A[I].edad);

        getchar();  /* Limpiar el buffer de entrada de scanf */
        printf("Sexo (F-M): ");
        scanf("%c", &A[I].sexo);

        printf("Condición (1..5): ");
        scanf("%d", &A[I].con);

        getchar();  /* Limpiar el buffer de entrada de scanf */
        printf("\tCalle: ");
        fgets(A[I].dom.cal, 20, stdin);
        A[I].dom.cal[strcspn(A[I].dom.cal, "\n")] = 0;

        printf("\tNúmero: ");
        scanf("%d", &A[I].dom.num);

        getchar();  /* Limpiar el buffer de entrada de scanf */
        printf("\tColonia: ");
        fgets(A[I].dom.col, 20, stdin);
        A[I].dom.col[strcspn(A[I].dom.col, "\n")] = 0;

        printf("\tCódigo Postal: ");
        fgets(A[I].dom.cp, 5, stdin);
        A[I].dom.cp[strcspn(A[I].dom.cp, "\n")] = 0;

        printf("\tCiudad: ");
        fgets(A[I].dom.ciu, 20, stdin);
        A[I].dom.ciu[strcspn(A[I].dom.ciu, "\n")] = 0;

        printf("\tTeléfono: ");
        fgets(A[I].tel, 15, stdin);
        A[I].tel[strcspn(A[I].tel, "\n")] = 0;
    }
}

/* Función para calcular el porcentaje de hombres y mujeres */
void F1(paciente A[], int T) {
    int I, FEM = 0, MAS = 0, TOT;

    for (I = 0; I < T; I++) {
        if (A[I].sexo == 'F') FEM++;
        else if (A[I].sexo == 'M') MAS++;
    }

    TOT = FEM + MAS;

    printf("\nPorcentaje de Hombres: %.2f%%", (float)MAS / TOT * 100);
    printf("\nPorcentaje de Mujeres: %.2f%%\n", (float)FEM / TOT * 100);
}

/* Función para contar los pacientes por condición */
void F2(paciente A[], int T) {
    int I, C1 = 0, C2 = 0, C3 = 0, C4 = 0, C5 = 0;

    for (I = 0; I < T; I++) {
        switch (A[I].con) {
            case 1: C1++; break;
            case 2: C2++; break;
            case 3: C3++; break;
            case 4: C4++; break;
            case 5: C5++; break;
        }
    }

    printf("\nNúmero de pacientes en condición 1: %d", C1);
    printf("\nNúmero de pacientes en condición 2: %d", C2);
    printf("\nNúmero de pacientes en condición 3: %d", C3);
    printf("\nNúmero de pacientes en condición 4: %d", C4);
    printf("\nNúmero de pacientes en condición 5: %d\n", C5);
}

/* Función para mostrar pacientes con condición máxima de gravedad */
void F3(paciente A[], int T) {
    int I;
    printf("\nPacientes ingresados en estado de gravedad (Condición 5):\n");

    for (I = 0; I < T; I++) {
        if (A[I].con == 5) {
            printf("Nombre: %s\tTeléfono: %s\n", A[I].nom, A[I].tel);
        }
    }
}
