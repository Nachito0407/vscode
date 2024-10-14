#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define XLIM 50
#define YLIM 50
#define PROB 3

#define CELDA 219 
#define FRAMERATE 16

//RECUERDA ESTABLECER LA RELACIÓN DE ASPECTO DE PIXEL EN LA CONSOLA.
//Propiedades > Fuente > Fuentes de Mapa de Bits > 8x8

int **mat1, **mat2;

void drawMatrix(){
	int i, j;
	system("cls");
	for(j=0; j<YLIM; ++j){
		for(i=0; i<XLIM; ++i){
			if(mat1[i][j]){
				printf("%c", CELDA);
			}
			else{
				printf(" ");
			}
		}
		if(j!=YLIM-1){
			printf("\n");
		}
	}
}

void swap(){
	int **tmp;
	tmp = mat1;
	mat1 = mat2;
	mat2 = tmp;	
}

int isBorder(int i, int j){
	return (!i || !j || (i == XLIM-1) || (j == YLIM-1));
}

int sobrevive(int x, int y){
	int i, j, nVecinos = 0;
	//Se excluyen los bordes.
	if (isBorder(x, y)){
		return 0;
	}
	else{
		for(i=x-1; i<=x+1; ++i){
			for(j=y-1; j<=y+1; ++j){
				nVecinos += mat1[i][j];
			}
		}
		nVecinos -= mat1[x][y];
		//Si está viva:
		if(mat1[x][y]){
			nVecinos = ((nVecinos == 2)||(nVecinos == 3));
		}
		//Si está muerta:
		else{
			nVecinos = (nVecinos == 3);
		}
		return nVecinos;
	}
}

void myLogic(){
	int i, j;
	for(i=0; i<XLIM; ++i){
		for(j=0; j<YLIM; ++j){
			mat2[i][j] = sobrevive(i, j);
		}
	}
}

void inicio(){
	int i, j;
	srand(time(NULL));
	
	mat1 = (int **)malloc(sizeof(int*)*XLIM);
	mat2 = (int **)malloc(sizeof(int*)*XLIM);
	for(i=0; i<XLIM; ++i){
		mat1[i] = (int *)malloc(sizeof(int)*YLIM);
		mat2[i] = (int *)malloc(sizeof(int)*YLIM);
	}
	
	for(i=0; i<XLIM; ++i){
		for(j=0; j<YLIM; ++j){
			mat1[i][j] = (PROB > (rand()%10))*(!isBorder(i, j));
			mat2[i][j] = 0;
		}
	}
}

int main(){
	inicio();
	while(1){		
		drawMatrix();
		myLogic();
		swap();
		Sleep(FRAMERATE);
	}
	
	return 0;
}