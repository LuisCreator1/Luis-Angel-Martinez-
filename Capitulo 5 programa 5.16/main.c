#include <stdio.h>
/* Apuntadores y arreglos */

void main(void)
{
    int V1[4] = {2, 3, 4, 7}, V2[4] = {6, 0, 0, 0};  // Inicializando adecuadamente V2
    int *AX, *AY;

    AX = &V1[3];  // AX apunta a V1[3]
    AY = &V2[0];  // AY debe apuntar a un índice válido de V2

    V1[V2[0] - V1[2]] = *AY;  // V2[0] - V1[2] = 6 - 4 = 2, V1[2] se cambia a *AY
    *AY = *AX - V1[0];  // *AY toma el valor de *AX - V1[0], es decir, 7 - 2 = 5

    printf("\nV1[0]=%d V1[1]=%d V1[2]=%d V1[3]=%d \tV2[0]=%d V2[1]=%d V2[2]=%d V2[3]=%d",
           V1[0], V1[1], V1[2], V1[3], V2[0], V2[1], V2[2], V2[3]);

    V2[1] = ++*AX;  // Se incrementa *AX (que es V1[3]) y se asigna a V2[1]
    V2[3] = (*AY)++;  // Se asigna a V2[3] el valor de *AY y luego se incrementa AY

    *AX += 2;  // Se incrementa el valor de V1[3] por 2

    printf("\nV1[0]=%d V1[1]=%d V1[2]=%d V1[3]=%d \tV2[0]=%d V2[1]=%d V2[2]=%d V2[3]=%d",
           V1[0], V1[1], V1[2], V1[3], V2[0], V2[1], V2[2], V2[3]);
}
