#include <stdio.h>
/* Apuntadores y arreglos */
void main(void)
{
    int X = 5, Y = 8, V[5] = {1, 3, 5, 7, 9};
    int *AY, *AX;

    AY = &Y;
    X = *AY;
    *AY = V[3] + V[2];  // Suma V[3] y V[2], y asigna el resultado a Y

    printf("\nX=%d Y=%d V[0]=%d V[1]=%d V[2]=%d V[3]=%d V[4]=%d",
           X, Y, V[0], V[1], V[2], V[3], V[4]);

    AX = &V[V[0] * V[1]];  // V[0] * V[1] da el índice que usa AX
    X = *AX;
    Y = *AX * V[1];
    *AX = *AY - 3;  // Modifica el valor en la dirección de AX

    printf("\nX=%d Y=%d V[0]=%d V[1]=%d V[2]=%d V[3]=%d V[4]=%d",
           X, Y, V[0], V[1], V[2], V[3], V[4]);
}
