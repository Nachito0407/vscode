#include <stdio.h>
#include <conio.h>

int main(int argc, char const *argv[])
{
    int dato,contador,suma;
    suma=0;
    contador=1;
    for( ;contador<=10;contador++ )
    {
        printf("ingrese un numero \n");
        scanf("%d",&dato);
        suma=suma+dato;
    }
    printf("la suma es %d \n", suma);
    getch();
    return 0;
}