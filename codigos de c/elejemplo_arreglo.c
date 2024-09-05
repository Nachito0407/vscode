#include<stdio.h>
#include<conio.h>
#define MT 4 //constante simbolica

int main(int argc, char const *argv[])
{
    int i,A[MT],B[MT];
    printf("ingresa el vector A \n\n");
    for ( i = 0; i < MT; i++)
    {
        printf("ingrese el elemento %d \n",i);
        scanf("%d",&A[i]);
    }
    printf("ingrese el segundo vector B \n\n");
    for ( i = 0; i < MT; i++)
    {
        printf("ingrse el elemento %d \n" ,i);
        scanf("%d",&B[i]);
    }
    printf("\n");
    printf("El vector A es: \n");
    for ( i = 0; i < MT; i++)
    {
        printf("%5d",A[i]);
    }
    printf("\n");
    printf("El vector B es: \n");
    for ( i = 0; i < MT; i++)
    {
        printf("%5d",B[i]);
    }
    return 0;
}
