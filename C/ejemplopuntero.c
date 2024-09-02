#include<stdio.h>
#include<conio.h>

int main(int argc, char const *argv[])
{
    char x , *punt , A[4][4];
    x='a';

    printf("la direccion de x es %p y su contenido es %c \n", &x ,x);

    punt= &x;

    printf("la direccion de x es %p y su contenido es %c \n", punt,*punt);

    punt=A[0]; //punt=&A[0];

    printf("la direccion de la matriz A es %p \n", punt);

    return 0;
}
