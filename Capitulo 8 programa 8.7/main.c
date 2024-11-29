#include <stdio.h>
#include <string.h>

typedef struct {
    char calle[30];
    int numero;
    char colonia[30];
    char cp[10];  // Código Postal
    char ciudad[30];
} Domicilio;

typedef struct {
    char nombre[50];
    int edad;
    char sexo;  // 'M' for male, 'F' for female
    int condicion;  // 1 to 5, where 5 is the most severe
    Domicilio domicilio;
    char telefono[15];
} PACIENTE;

void mostrar_porcentaje_hombres_mujeres(PACIENTE[], int);
void contar_condiciones(PACIENTE[], int);
void mostrar_maxima_gravedad(PACIENTE[], int);

int main() {
    int N, i;

    // Solicitar el número de pacientes
    printf("Ingrese el número de pacientes (1 a 100): ");
    scanf("%d", &N);

    // Verificar que el número de pacientes sea válido
    if (N < 1 || N > 100) {
        printf("Número de pacientes inválido.\n");
        return 1;
    }

    PACIENTE hospital[N];  // Arreglo para almacenar la información de los pacientes

    // Leer la información de los pacientes
    for (i = 0; i < N; i++) {
        printf("\nPaciente %d:\n", i + 1);
        printf("Nombre: ");
        fflush(stdin); // Limpiar buffer
        gets(hospital[i].nombre);
        printf("Edad: ");
        scanf("%d", &hospital[i].edad);
        printf("Sexo (M/F): ");
        fflush(stdin);
        scanf("%c", &hospital[i].sexo);
        printf("Condición (1 a 5): ");
        scanf("%d", &hospital[i].condicion);
        printf("Calle: ");
        fflush(stdin);
        gets(hospital[i].domicilio.calle);
        printf("Número: ");
        scanf("%d", &hospital[i].domicilio.numero);
        printf("Colonia: ");
        fflush(stdin);
        gets(hospital[i].domicilio.colonia);
        printf("Código Postal: ");
        gets(hospital[i].domicilio.cp);
        printf("Ciudad: ");
        gets(hospital[i].domicilio.ciudad);
        printf("Teléfono: ");
        gets(hospital[i].telefono);
    }

    // Mostrar los resultados
    mostrar_porcentaje_hombres_mujeres(hospital, N);
    contar_condiciones(hospital, N);
    mostrar_maxima_gravedad(hospital, N);

    return 0;
}

void mostrar_porcentaje_hombres_mujeres(PACIENTE hospital[], int N) {
    int hombres = 0, mujeres = 0;
    for (int i = 0; i < N; i++) {
        if (hospital[i].sexo == 'M') {
            hombres++;
        } else if (hospital[i].sexo == 'F') {
            mujeres++;
        }
    }
    printf("\nPorcentaje de hombres: %.2f%%", (float)hombres / N * 100);
    printf("\nPorcentaje de mujeres: %.2f%%\n", (float)mujeres / N * 100);
}

void contar_condiciones(PACIENTE hospital[], int N) {
    int condiciones[5] = {0};  // Array para contar las condiciones de 1 a 5
    for (int i = 0; i < N; i++) {
        if (hospital[i].condicion >= 1 && hospital[i].condicion <= 5) {
            condiciones[hospital[i].condicion - 1]++;
        }
    }

    printf("\nNúmero de pacientes por condición:\n");
    for (int i = 0; i < 5; i++) {
        printf("Condición %d: %d pacientes\n", i + 1, condiciones[i]);
    }
}

void mostrar_maxima_gravedad(PACIENTE hospital[], int N) {
    printf("\nPacientes con condición máxima de gravedad (5):\n");
    for (int i = 0; i < N; i++) {
        if (hospital[i].condicion == 5) {
            printf("Nombre: %s, Teléfono: %s\n", hospital[i].nombre, hospital[i].telefono);
        }
    }
}
