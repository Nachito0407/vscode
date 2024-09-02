#include<stdio.h>
#include<conio.h>
#define CF 2
#define CC 2

void ingresarmatriz(float [][CC],int,int);
void mostarmatriz(float [][CC],int,int);
void multmat(float [][CC],float [][CC],float [][CC],int,int);
void transpuesta(float[][CC],float[][CC],int,int);
float prodesc(float[],float[],int);

int main(int argc, char const *argv[])
{
    int cc,cf;
    float A[CF][CC],B[CF][CC],C[CF][CC];

    ingresarmatriz(A,CF,CC);

    ingresarmatriz(B,CF,CC);

    multmat2(A,B,C,CF,CC);

    mostarmatriz(C,CF,CC);

    return 0;
}

void ingresar_matriz (float X[][CC],int nf,int nc){
    int i,j;
    for ( i = 0; i < nf; i++) {
        for ( j = 0; j < nc; j++) {
            printf("ingrese elemento[%d][%d]\n",i,j);
            scanf("%f",&X[i][j]);
        }
        
    }
    
}

void mostrar_matriz (float X[][CC],int nf,int nc){
    int i,j;
    for ( i = 0; i < nf; i++) {
            for ( j = 0; j < nc; j++) {
                printf("%7.2f",X[i][j]);
    }
            printf("\n");
    }
}

void multmat (float A[][CC],float Y[][CC],float Z[][CC],int cc ,int cf)
{
    int i,j;
    float AUX[cf][cc];
    transpuesta(AUX,Y,cf,cc);
    for ( i = 0; i < cf; i++)
    {
        for ( j = 0; i < cc; j++)
        {
        Z[i][j]=prodesc(A,AUX,cc);
        }  
    }
}