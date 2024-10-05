#include<stdio.h>
#include<conio.h>

int esprimo(int); //funcio que esta abajo
int main(int argc, char const *argv[])
{
    int numero;
    for (numero = 1; numero <= 100; numero++)
    {
        if (esprimo(numero))
        {
            printf("%d es primo \n", numero);
        }
    }
    return 0;
}
// inicio de la funcion
int esprimo(int num)
{
    int i, cont; // variable local
    cont = 0;
    for (i = 1; i <= num; i++)
        if (num % i == 0)
            cont++;
    
    if (cont <= 2)
        return 1;
    else
        return 0;
}
