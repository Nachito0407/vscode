/*PROMEDIO CON NUMEROS ENTEROS*/

#include <stdio.h>
#include <conio.h>

int main(int argc, char const *argv[])
{
    float promedio,a,b,c,d,e;

    printf("ingrese 5 numeros reales \n");
    scanf("%f%f%f%f%f",&a, &b, &c, &d, &e);

    promedio=(a+b+c+d+e) / 5.0; //la division tiene que ser con un numero del tipo 1.0

    printf("El promedio de los numeros %.4f, %.4f, %.4f, %.4f, %.4f es %.4f \n ",a,b,c,d,e,promedio);
    
    return 0;
}
