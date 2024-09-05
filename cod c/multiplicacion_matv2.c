#include <stdio.h>
#include <conio.h> 
#define NC 3
#define NF 3 
void ingresarmatriz (float[][NC], int, int);
void mostrarmatriz (float [][NC], int, int);
float productopunto (float[], float[], float);
void multmatricesv2 (float[][NC], float[][NC], float[][NC], int, int);
void transpuesta (float [][NC], float [][NC], int, int);
int main ()

{
    float A[NF][NC], B[NF][NC], C[NF][NC];
    printf("\nIngrese la matriz A\n ");
    ingresarmatriz (A, NF, NC);
    printf("\n La matriz A es\n ");
    mostrarmatriz (A, NF, NC);
    printf("\nIngrese la matriz B\n");
    ingresarmatriz (B, NF, NC);
    printf("\n La matriz B es\n ");
    mostrarmatriz (B, NF, NC);
    multmatricesv2 (A, B, C, NF, NC);
    printf("\nLa matriz resultado de la multiplicacion matricial es\n");
    mostrarmatriz (C, NF, NC);
    return 0;
}

void ingresarmatriz (float X[][NC],int nf,int nc){
    int i,j;
    for ( i = 0; i < 3; i++) {
        for ( j = 0; j < nc; j++) {
            printf("ingrese elemento[%d][%d]\n",i,j);
            scanf("%f",&X[i][j]);
        }
        
    }
    
}

void mostrarmatriz (float X[][NC],int nf,int nc){
    int i,j;
    for ( i = 0; i < nf; i++) {
            for ( j = 0; j < nc; j++) {
                printf("%7.2f",X[i][j]);
    }
            printf("\n");
    }
}

void transpuesta (float A[][NC], float B[][NC], int f, int c)
{
    int i, j;
    for (i=0; i<f; i++){
        for (j=0; j<c; j++)
            B[i][j] = A[j][i];
    }
}

float productopunto (float A[], float B[], float t) {
    float resultado = 0.0;
    for (int i = 0; i < t; i++) 
        resultado += A[i] * B[i];
}

void multmatricesv2 (float A[][NC], float B[][NC], float C[][NC], int nf, int nc)
{
    int i, j, k;
    float aux [NF][NC];
    printf("\n La transpuesta es\n");
    transpuesta(B, aux, nf, nc);
    mostrarmatriz (aux, nf, nc);
    for (i = 0; i < 3; i++) {
        for (j = 0; j < nc; j++) {
            C[i][j] = 0.0; 
            for (k = 0; k < nc; k++) {
                C[i][j] += A[i][k]*B[k][j];
                //C[i][j] = productopunto(A[i],aux[j], nc); 
            }
        }
    }
}