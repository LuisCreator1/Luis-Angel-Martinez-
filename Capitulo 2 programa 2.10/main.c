#include <stdio.h>
#include <math.h>

/* Par, impar o nulo.

NUM: variable de tipo enter. */

void main (void)
{
 int NUM;
 printf("ingrese el numero: ");
 scanf("%d" , &NUM);
 if (NUM == 0)
        printf("\nNulo");
 else
    if (pow (-1, NUM) > 0)
    printf("\nPar");
 else
    printf("\nImpar");
}

