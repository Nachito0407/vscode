/*PROMEDIO CON NUMEROS ENTEROS*/

#include <stdio.h>
#include <conio.h>

int main(int argc, char const *argv[])
{
    int a,b,c,d,e;
    float promedio;
    printf("ingrese 5 numeros enteros \n");
    scanf("%d%d%d%d%d",&a, &b, &c, &d, &e);
    promedio=(a+b+c+d+e) / 5.0; //la division tiene que ser con un numero del tipo 1.0
    printf("El promedio de los numeros %d, %d, %d, %d, %d es %.2f \n ",a,b,c,d,e,promedio);
    return 0;
}
