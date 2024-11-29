#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
    int numero1;
    int numero2;
    int numero3;
} NumerosLoteria;

void grabarRegistro(FILE *archivo) {
    NumerosLoteria registro;
    printf("Ingrese el Numero 1: ");
    scanf("%d", &registro.numero1);
    printf("Ingrese el Numero 2: ");
    scanf("%d", &registro.numero2);
    printf("Ingrese el Numero 3: ");
    scanf("%d", &registro.numero3);

    fwrite(&registro, sizeof(NumerosLoteria), 1, archivo);
    printf("Registro grabado exitosamente.\n");
}

void leerRegistros(FILE *archivo) {
    NumerosLoteria registro;
    rewind(archivo);
    printf("Registros en el archivo:\n");
    while (fread(&registro, sizeof(NumerosLoteria), 1, archivo)) {
        printf("Numero1: %d, Numero2: %d, Numero3: %d\n", registro.numero1, registro.numero2, registro.numero3);
    }
}


void agregarRegistros(FILE *archivo) {
    fseek(archivo, 0, SEEK_END);
    grabarRegistro(archivo);
}

void buscarNumero(FILE *archivo, int numeroBuscado) {
    NumerosLoteria registro;
    int contador = 0;

    rewind(archivo);
    while (fread(&registro, sizeof(NumerosLoteria), 1, archivo)) {
        if (registro.numero1 == numeroBuscado || registro.numero2 == numeroBuscado || registro.numero3 == numeroBuscado) {
            contador++;
        }
    }

    printf("El número %d aparece %d veces en el archivo.\n", numeroBuscado, contador);
}

int main() {
    FILE *archivo;
    int opcion, numeroBuscado;


    archivo = fopen("loteria.dat", "rb+");
    if (archivo == NULL) {

        archivo = fopen("loteria.dat", "wb+");
        if (archivo == NULL) {
            printf("Error al abrir el archivo.\n");
            return 1;
        }
    }

    do {
        printf("\n--- Menú ---\n");
        printf("1. Grabar un registro\n");
        printf("2. Leer registros\n");
        printf("3. Agregar un registro\n");
        printf("4. Buscar un número\n");
        printf("5. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                grabarRegistro(archivo);
                break;
            case 2:
                leerRegistros(archivo);
                break;
            case 3:
                agregarRegistros(archivo);
                break;
            case 4:
                printf("Ingrese el número a buscar: ");
                scanf("%d", &numeroBuscado);
                buscarNumero(archivo, numeroBuscado);
                break;
            case 5:
                printf("Saliendo del programa.\n");
                break;
            default:
                printf("Opción inválida. Inténtelo de nuevo.\n");
        }
    } while (opcion != 5);

    fclose(archivo);
    return 0;
}
