#include <stdio.h>
#include <conio.h>

#define CF 3
#define CC 3

void mostrarvector(float X[], int t);
void ingresar_matriz(float [][CC], int, int);
void mostrar_matriz(float [][CC], int, int);
void multiplicar_mat(float [][CC], float [][CC], float [][CC], int, int);
void transpuesta(float[][CC], float[][CC], int, int);
float prodesc(float[], float[], int);

int main(int argc, char const *argv[]) {
    float A[CF][CC], Y[CF][CC], Z[CF][CC],aux[CF][CC];

    ingresar_matriz(A, CF, CC);
    ingresar_matriz(Y, CF, CC);

    multiplicar_mat(A, Y, Z, CF, CC);

    mostrar_matriz(Z, CF, CC);

    return 0;
}

void ingresar_matriz(float X[][CC], int nf, int nc) {
    int i, j;
    for (i = 0; i < nf; i++) {
        for (j = 0; j < nc; j++) {
            printf("Ingrese elemento[%d][%d]: ", i, j);
            scanf("%f", &X[i][j]);
        }
    }
}

void mostrar_matriz(float X[][CC], int nf, int nc) {
    int i, j;
    for (i = 0; i < nf; i++) {
        for (j = 0; j < nc; j++) {
            printf("%7.2f ", X[i][j]);
        }
        printf("\n");
    }
}

void multiplicar_mat(float A[][CC], float Y[][CC], float Z[][CC], int cf, int cc) {
    int i, j, k;
    for (i = 0; i < cf; i++) {
        for (j = 0; j < cc; j++) {
            Z[i][j] = 0;
            for (k = 0; k < cc; k++) {
                Z[i][j] += A[i][k] * Y[k][j];
            }
        }
    }
}

float prodesc(float vec1[], float vec2[], int n) {
    float resultado = 0.0;
    int k;
    for (k = 0; k < n; k++) {
        resultado += vec1[k] * vec2[k];
    }
    return resultado;
}
void mostrarvector(float X[], int t)
{
    int i;
    for (i = 0; i < t; i++)
    {
        printf("%7.2f", X[i]);
    }
    printf("\n");
}