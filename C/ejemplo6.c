#include <stdio.h>
#include <conio.h>
int main(int argc, char const *argv[])
{
    int a1,a2,a3,a4;
    float b1,b2,b3,b4;
    printf("ingresame 3 reales \n");
    scanf("%f%f%f", &b1,&b2,&b3); // %d es para numeros enteros y %f es para numeros reales
  b4=b1+b2+b3;
  printf("la suma de %.2f con %.2f y %.2f es %5f \n" , b1,b2,b3,b4);
    return 0;
}
