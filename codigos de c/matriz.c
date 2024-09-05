#include <stdio.h>
#include <conio.h>
#define NF 4
#define NC 4

void ingresar_matriz (float[][NC],int,int); //prototipo
void mostrar_matriz (float[][NC],int,int); //prototipo

int main(int argc, char const *argv[])
{
    float A[NF][NC];

    ingresar_matriz(A,NF,NC);
    
    mostrar_matriz (A,NF,NC);
    
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