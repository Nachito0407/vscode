#include<stdio.h>
#include<conio.h>
#define MT 5 //constante simbolica

void ingresarvector(int[], int);
void mostrarvector(int[], int);
void sumavectores(int[], int[], int[], int);

int main(int argc, char const *argv[])
{
    int A[MT], B[MT], resultado[MT];

    printf("Ingresa el vector A \n\n");
    ingresarvector(A, MT);

    printf("Ingrese el segundo vector B \n\n");
    ingresarvector(B, MT);

    printf("El vector A es: \n\n");
    mostrarvector(A, MT);

    printf("\n\n");

    printf("El vector B es: \n\n");
    mostrarvector(B, MT);

    sumavectores(A, B, resultado, MT);

    printf("\n\nEl vector resultado (A + B) es: \n\n");
    mostrarvector(resultado, MT);

    return 0;
}

// Funciones con arrays
void ingresarvector(int X[], int t)
{
    int i;
    for (i = 0; i < t; i++)
    {
        printf("Ingrese elemento %d: ", i + 1);
        scanf("%d", &X[i]);
    }
}

void mostrarvector(int X[], int t)
{
    int i;
    for (i = 0; i < t; i++)
    {
        printf("%5d", X[i]);
    }
    printf("\n");
}

void sumavectores(int A[], int B[], int resultado[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        resultado[i] = A[i] + B[i];
    }
}