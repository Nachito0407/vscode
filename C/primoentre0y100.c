#include<stdio.h>
#include<conio.h>

int main(int argc, char const *argv[])
{
    int numero,cont,i;

    for (numero=1;numero<=100; numero++)
    {
        cont=0;
        for ( i = 1; i<=numero; i++)
        {
            if ((numero%i)==0)
            {
                cont++;
            }
        }
        if (cont==2)
        printf("%d es primo \n",numero);
    }
    
    return 0;
    getch();
}
