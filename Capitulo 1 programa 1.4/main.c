#include <stdio.h>

/* Superficie del triangulo.
Elprograma, al recibir como datos la base y la altura de un triangulo,
calcula su superfici.

BAS, ALT Y SUP: variable de tipo real. */

void main (void)
{
 float BAS, ALT, SUP;
 printf("ingrese la base y la altura del triangulo: ");
 scanf("%f %f", %BAS, %ALT);
 SUP = BAS * ALT / 2;
 primtf("\nLa superficie del triangulo es: %5.2f", SUP);
}
