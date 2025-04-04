#include <stdio.h>

// Función para calcular el determinante de una matriz n x n
int determinante(int matriz[10][10], int n) {
    int det = 0;
    
    // Caso base: si la matriz es de 1x1
    if (n == 1) {
        return matriz[0][0];
    }
    
    // Matriz menor
    int menor[10][10];
    int signo = 1;
    
    for (int i = 0; i < n; i++) {
        int fila = 0, columna = 0;
        
        // Crear la submatriz eliminando la primera fila y la columna i
        for (int j = 1; j < n; j++) {
            columna = 0;
            for (int k = 0; k < n; k++) {
                if (k != i) {
                    menor[fila][columna] = matriz[j][k];
                    columna++;
                }
            }
            fila++;
        }
        
        // Recursión para calcular el determinante
        det += signo * matriz[0][i] * determinante(menor, n - 1);
        signo = -signo; // Alterna signo (+, -)
    }
    
    return det;
}

int main() {
    int n;
    printf("Ingrese el tamano de la matriz (max 10): ");
    scanf("%d", &n);

    int matriz[10][10];

    printf("Ingrese los elementos de la matriz:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }

    printf("El determinante de la matriz es: %d\n", determinante(matriz, n));

    return 0;
}