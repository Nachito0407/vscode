#include<stdio.h>
#include<conio.h>
int main(int argc, char const *argv[])
{
    int numero,cont,i,cnum;
    cnum=0; numero=1;
    while (cnum<=100)
    {
        cont=0;
        for ( i = 1; i <= numero; i++)
        {
            if ((numero%i)==0)
            {
                cont++;
            }
            
        }
        if (cont<=2)
        {
            printf("%d es primo \n",numero);
            cnum++;
        }
        numero++;
    }
    return 0;
}
