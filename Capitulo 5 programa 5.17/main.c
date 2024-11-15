#include <stdio.h>
/* Apuntadores y arreglos */
void main(void)
{
    int V1[4] = {1, 3, 5, 7}, V2[4] = {2, 4, 0, 0}; // Inicializamos adecuadamente V2
    int *AX, *AY;

    AX = &V1[2];  // AX apunta a V1[2]
    AY = &V2[0];  // AY apunta a V2[0]

    // Modificamos los elementos de V2 usando punteros
    V2[2] = *(AX + 1);  // V2[2] toma el valor de V1[3], es decir, 7
    V2[3] = *AX;        // V2[3] toma el valor de V1[2], es decir, 5

    AX = AX + 1;        // AX ahora apunta a V1[3]
    V1[0] = *AX;        // V1[0] toma el valor de V1[3], es decir, 7

    // Imprime los valores de V1 y V2
    printf("\nV1[0]=%d V1[1]=%d V1[2]=%d V1[3]=%d \tV2[0]=%d V2[1]=%d V2[2]=%d V2[3]=%d",
           V1[0], V1[1], V1[2], V1[3], V2[0], V2[1], V2[2], V2[3]);

    // Manipulamos más los arreglos
    V1[2] = *AY;        // V1[2] toma el valor de V2[0], es decir, 2
    V1[1] = --*AY;      // Decrementa AY (que apunta a V2[0]) y asigna a V1[1], por lo que V1[1] será 1
    AX = AX + 1;        // AX apunta a V1[4] (fuera de los límites del arreglo, puede causar error)
    V1[3] = *AX;        // Aquí hay un problema, ya que AX apunta fuera del arreglo V1

    // Imprime los valores finales de V1 y V2
    printf("\nV1[0]=%d V1[1]=%d V1[2]=%d V1[3]=%d \tV2[0]=%d V2[1]=%d V2[2]=%d V2[3]=%d",
           V1[0], V1[1], V1[2], V1[3], V2[0], V2[1], V2[2], V2[3]);
}
