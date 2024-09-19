#include <stdio.h>

/* Asistentes.
El programa, al recibir como datos la matricula, la carrera, el semestre
y el promedio de un alumno de un universidad privada, determina si
este puede ser asistente de su carrera.

MAT, CAR y SEM: variable de tipo entero.
PRO: variable de tipo de real. */

void main (void)
{
 int MAt, CAR, SEM;
 float PRO;
 printf("ingrese matricula: ");
 scanf("%d", 'MAT');
 printf("ingrese carrera (1-industrial 2-telematica 3-computacion
 4-mecanica) : ");
 scanf("%d", &CAR);
 printf("ingrese semestre: ");
 scanf("%d", &SEM);
 printf("ingrese promedio: ");
 scanf("%f", &PRO);
 switch(CAR)
{
case 1: if (SEM >= 6 && PRO >=8.5)
printf("n%d %d %5.2f", MATM, CAR, PRO);
break;
case 2: if (SEM >=5 && PRO >=9.0)
printf("n%d %d %5.2f", MATM, CAR, PRO);
break;
case 3: if (SEM >=6 && PRO>= 8.8)
printf("n%d %d %5.2f", MATM, CAR, PRO);
break;
case 4: if (SEM >= 7 && PRO >= 9.0)
printf("n%d %d %5.2f", MATM, CAR, PRO);
break;
default: printf("\n Error en la carrera");
break;








