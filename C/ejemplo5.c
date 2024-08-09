#include <stdio.h>
#include <conio.h>
int main(int argc, char const *argv[])
{
    int a1,a2,a3,a4;
    float b1,b2,b3,b4;
    printf("ingresame 3 enteros\n");
    scanf("%d%d%d", &a1,&a2,&a3); // %d es para numeros enteros y %f es para numeros reales
  a4=a1+a2+a3;
  printf("la suma de %d con %d y %d es %d \n" , a1,a2,a3,a4);
    return 0;
}
