#include<stdio.h>
#include<conio.h>
int main(int argc, char const *argv[])
{
    int i,contador=0,numero;
    printf("ingrese un numero");
    scanf( "%d",& numero);
    for (i = 1; i<=numero; i++)
        {
            if (numero%i==0)
                {
                contador++;
                }
        }
        if (contador>2)
        {
            printf("el numero no es primo \n");
        }
        else
        {
            printf("el numero es primo \n");
        }
    return 0;
}