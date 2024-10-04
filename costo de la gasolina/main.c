#include <stdio.h>

int main() {

    float consumo = 10.0; // Consumo en litros por cada 100 km
    float precio_galon = 290.0; // Precio del galón de gasolina
    int distancia_total_km = 300; // Distancia total en km (150 km ida y 150 km vuelta)
    float litros_por_galon = 3.785; // Litros por galón


    float litros_necesarios = (distancia_total_km / 100.0) * consumo;


    float galones_necesarios = litros_necesarios / litros_por_galon;


    float costo_total = galones_necesarios * precio_galon;

    printf("El costo total de la gasolina para recorrer %d km es: %.2f\n", distancia_total_km, costo_total);

    return 0;
}
