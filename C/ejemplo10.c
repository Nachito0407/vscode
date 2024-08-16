#include<stdio.h>
#include<conio.h>
main()
{
int contador, suma, dato;
suma=0; contador=1;
while(contador<=10)
{
    printf("Ingrese un entero\n");
    scanf("%d", &dato);
    if((dato%2)!=0)
        {
        suma+=dato;
        }
    contador++;
    }
printf("la suma de los impares es %d\n",suma);
}