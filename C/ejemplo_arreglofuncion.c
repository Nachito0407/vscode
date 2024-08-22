#include<stdio.h>
#include<conio.h>
#define MT 5 //constante simbolica

void ingresarvector(int[], int);
void mostrarvector(int[], int);

int main(int argc, char const *argv[])
{

    int A[MT],B[MT];
    printf("ingresa el vector A \n\n");
    ingresarvector(A,MT);

    printf("ingrese el segundo vector B \n\n");
    ingresarvector(B,MT);

    printf("El vector A es: \n\n");
    mostrarvector(A,MT);

    printf("\n\n");

    printf("El vector B es: \n\n");
    mostrarvector(B,MT);

    return 0;

}

void ingresarvector(int X[],int t)
{
    int i;
    for ( i = 0; i < t; i++)
    {
        printf("ingrese elemento %d \n\n", i);
        scanf("%d" ,& X[i]);
    }
}

void mostrarvector(int X[], int t)
{
    int i;
    for ( i = 0; i < t ; i++)
    {
        printf("%5d", X[i]);
    }
    
}