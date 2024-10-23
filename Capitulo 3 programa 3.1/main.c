#include <stdio.h>

/* Nómina.
El programa, al recibir los salarios de 15 profesores, obtiene el total de la
nómina de la universidad.

I: variable de tipo entero.
SAL y NOM: variables de tipo real. */

void main (void)
{
int I;
float SAL, NOM;
NOM = 0;
for (I=1; I<=15; I++)
{

  printf("\Ingrese el salario del profesor%d:\t", I);
  scanf("%f", &SAL);
  NOM = NOM + SAL;

}
 printf("\nEl total de la nomina es: %.2f" , NOM);
}


