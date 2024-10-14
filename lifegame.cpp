#include <windows.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>

#include <new>
#include <conio.h>

#define XLIM 50
#define YLIM 50
#define PROB 3

#define CELDA 219 
#define FRAMERATE 32

//RECUERDA ESTABLECER LA RELACIÓN DE ASPECTO DE PIXEL EN LA CONSOLA.
//Propiedades > Fuente > Fuentes de Mapa de Bits > 8x8

using namespace std;

int **mat1, **mat2;

HANDLE hCon;

void ocultarCursor(){
	CONSOLE_CURSOR_INFO cci;
	
	cci.dwSize = 100;
	cci.bVisible = FALSE;
	
	SetConsoleCursorInfo(hCon, &cci);
}

void gotoxy(int x, int y){
	COORD dwPos;
	
	dwPos.X = x;
	dwPos.Y = y;
	
	SetConsoleCursorPosition(hCon, dwPos);
}

void drawMatrix1(){
	//VERSIÓN NO OPTIMIZADA.
	//Eliminarla si se desea.
	int i, j;
	gotoxy(0,0);
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

void drawMatrix2(){
	//VERSIÓN OPTIMIZADA DE LA FUNCIÓN DRAW.
	int i, j;
	for(i=0; i<XLIM; ++i){
		for(j=0; j<YLIM; ++j){
			if(mat1[i][j]!=mat2[i][j]){
				gotoxy(i, j);
				if(mat1[i][j]){
					printf("%c", CELDA);
				}
				else{
					printf(" ");
				}
			}
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
		//Si está viva, sobrevive si tiene 2 o 3 vecinos.
		//Si está muerta, nace si tiene 3 vecinos.
		nVecinos = (mat1[x][y])?((nVecinos == 2)||(nVecinos == 3)):(nVecinos == 3);
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
	
	//Creacion de la ventana.
	hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	
	//Coordenadas del Buffer
	_COORD Coordenada;	
	Coordenada.X = XLIM;
	Coordenada.Y = YLIM;
	
	//Tamaño de ventana
	_SMALL_RECT Rect;
	Rect.Top = 0;
	Rect.Left = 0;
	Rect.Right = XLIM - 1;
	Rect.Bottom = YLIM - 1;
	
	SetConsoleScreenBufferSize(hCon, Coordenada);
	SetConsoleWindowInfo(hCon, TRUE, &Rect);

	system("cls");
	ocultarCursor();
	
	//Inicialización de matrices:
	mat1 = new int*[XLIM];
	mat2 = new int*[XLIM];
	for(i=0; i<XLIM; ++i){
		mat1[i] = new int[YLIM];
		mat2[i] = new int[YLIM];
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
		//drawMatrix1();	//Versión NO optimizada.		
		drawMatrix2();		//Versión SÍ optimizada.
		myLogic();
		swap();
		Sleep(FRAMERATE);
	}
	
	return 0;
}