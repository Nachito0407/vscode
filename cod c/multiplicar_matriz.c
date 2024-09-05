#include <stdio.h>
#include <conio.h>
#define NF 3
#define NC 3

void ingresar_matriz (float[][NC],int,int); //prototipo
void mostrar_matriz (float[][NC],int,int); //prototipo
void multiplicar_matriz (float [][NC],float[][NC],float[][NC],int,int); //prototipo

int main(int argc, char const *argv[])
{
    float A[NF][NC],B[NF][NC],C[NF][NC];

    printf("\n ingresar matriz A\n");

    ingresar_matriz(A,NF,NC);

    printf("\n ingresar matriz B\n");

    ingresar_matriz(B,NF,NC);

    multiplicar_matriz(A,B,C,NF,NC);
    printf("\n la matriz resultado es:\n");
    
    mostrar_matriz (C,NF,NC);
    
    return 0;
}

void ingresar_matriz (float X[][NC],int nf,int nc){
    int i,j;
    for ( i = 1; i < nf; i++) {
        for ( j = 1; j < nc; j++) {
            printf("ingrese elemento[%d][%d]\n",i,j);
            scanf("%f",&X[i][j]);
        }
        
    }
    
}

void mostrar_matriz (float X[][NC],int nf,int nc){
    int i,j;
    for ( i = 1; i < nf; i++) {
            for ( j = 1; j < nc; j++) {
                printf("%7.2f",X[i][j]);
    }
            printf("\n");
    }
}

void multiplicar_matriz (float X[][NC],float Y[][NC],float Z[][NC],int nc,int nf){
    int i,j,k;
            for ( i = 1; i < nf; i++)
            {
                for ( j = 1; j < nc; j++)
                {
                    Z[i][j]=0;
                        for ( k = 1; k < nc; k++)
                            {
                            Z[i][j]=X[i][j]*Y[i][j];
                            }
                }
            }    
} 
