#include<stdio.h>
#include<conio.h>
int main() {
    int contador, suma2, suma3, suma5, suma, dato;
    suma2 = 0; suma3 = 0; suma5 = 0; suma = 0; contador = 1;

    while (contador <= 10) {
        printf("Ingrese un entero\n");
        scanf("%d", &dato);

        if (dato % 2 == 0) {
            suma2++;
        } else if (dato % 3 == 0) {
            suma3++;
        } else if (dato % 5 == 0) {
            suma5++;
        } else {
            suma++;
        }
        contador++;
    }

    printf("La cantidad de los múltiplos de dos es %d\n", suma2);
    printf("La cantidad de los múltiplos de tres es %d\n", suma3);
    printf("La cantidad de los múltiplos de cinco es %d\n", suma5);
    printf("La cantidad del resto es %d\n", suma);

    return 0;
}
