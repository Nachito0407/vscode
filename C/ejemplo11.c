#include<stdio.h>
#include<conio.h>
main()
{
int contador, sumap, sumai, dato;
sumap=0; sumai=0;contador=1;

while(contador<=10)
{
    printf("Ingrese un entero\n");
    scanf("%d", &dato);
        if((dato%2)==0)
            {
            sumap+=dato;
            }
        else
            {
            sumai+=dato;
            }
    contador++;
}
printf("la suma de los pares es %d\n",sumap);
printf("la suma de los impares es %d\n",sumai);
}