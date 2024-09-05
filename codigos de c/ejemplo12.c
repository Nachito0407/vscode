#include<stdio.h>
#include<conio.h>
main()
{
int contador, suma2, suma3,suma5, sumar, dato;
suma2=0; suma3=0; suma5=0; sumar=0; contador=1;

while(contador<=10)
{
    printf("Ingrese un entero\n");
    scanf("%d", &dato);
    if((dato%2)==0)
        {
        suma2+=dato;
        }
    else if (dato%3==0)
        {
        suma3+=dato;
        }
    else if (dato%5==0)
            {
            suma5+=dato;
            }
    else
            {
            sumar+=dato;
            contador++;
    }
printf("la suma de los multipos de dos es %d\n",suma2);
printf("la suma de los multipos de tres es %d\n",suma3);
printf("la suma de los multipos de cinco es %d\n",suma5);
printf("la suma del resto es %d\n",sumar);
}
}