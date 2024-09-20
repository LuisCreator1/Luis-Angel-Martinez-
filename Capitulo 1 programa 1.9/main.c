#include <stdio.h>

/* Estancia
El proograma, al recibir como dato la superficie de una estancia expresada
en acres, la convierte a hectareas.

ECA: variable de tipo real. */

void main (void)
{
 float ECA;
 printf("Ingrese la extension de la estancia: ");
 scanf("%f" , &ECA);
 ECA = ECA * 4047 / 10000;
 printf("\nExtension de la distancia en hectareas: %5.2f" , ECA);
}
