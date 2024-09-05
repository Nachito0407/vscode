#include <stdio.h>
#include <conio.h>

#define cf 3
#define cc 3

void ingresar_matriz(float [][cc], int, int);
void mostrar_matriz(float [][cc], int, int);
void multiplicar_mat(float [][], float [][], float [][], int, int);
void transpuesta(float[][cc], float[][cc], int, int);
float prodesc(float[], float[], int);

int main(int argc, char const *argv[]) {
    float A[cf][cc], Y[cf][cc], Z[cf][cc];

    ingresar_matriz(A, cf, cc);
    ingresar_matriz(Y, cf, cc);

    multmat2(A, Y, Z, cf, cc);

    mostrar_matriz(Z, cf, cc);

    return 0;
}

void ingresar_matriz(float X[][cc], int nf, int nc) {
    int i, j;
    for (i = 0; i < nf; i++) {
        for (j = 0; j < nc; j++) {
            printf("Ingrese elemento[%d][%d]: ", i, j);
            scanf("%f", &X[i][j]);
        }
    }
}

void mostrar_matriz(float X[][cc], int nf, int nc) {
    int i, j;
    for (i = 0; i < nf; i++) {
        for (j = 0; j < nc; j++) {
            printf("%7.2f ", X[i][j]);
        }
        printf("\n");
    }
}

void multiplicar_mat(float A[][cc], float Y[][cc], float Z[][cc], int cf, int cc) {
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
