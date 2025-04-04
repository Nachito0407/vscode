#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#ifdef _WIN32
    #include <windows.h>
    void usleep(__int64 usec) {
        HANDLE timer;
        LARGE_INTEGER ft;
        ft.QuadPart = -(10 * usec);
        timer = CreateWaitableTimer(NULL, TRUE, NULL);
        SetWaitableTimer(timer, &ft, 0, NULL, NULL, 0);
        WaitForSingleObject(timer, INFINITE);
        CloseHandle(timer);
    }
    #define CLEAR_SCREEN "cls"
#else
    #include <unistd.h>
    #define CLEAR_SCREEN "clear"
#endif

double A = 0, B = 0, C = 0;
const int width = 160, height = 44;
double zBuffer[160 * 44];
char buffer[160 * 44];
const char backgroundASCIICode = ' ';
const int distanceFromCam = 100;
double K1 = 40;
double incrementSpeed = 0.6;

double calculateX(int i, int j, int k) {
    return j * sin(A) * sin(B) * cos(C) - k * cos(A) * sin(B) * cos(C) +
           j * cos(A) * sin(C) + k * sin(A) * sin(C) + i * cos(B) * cos(C);
}

double calculateY(int i, int j, int k) {
    return j * cos(A) * cos(C) + k * sin(A) * cos(C) -
           j * sin(A) * sin(B) * sin(C) + k * cos(A) * sin(B) * sin(C) -
           i * cos(B) * sin(C);
}

double calculateZ(int i, int j, int k) {
    return k * cos(A) * cos(B) - j * sin(A) * cos(B) + i * sin(B);
}

void calculateForSurface(double cubeX, double cubeY, double cubeZ, int ch, double horizontalOffset) {
    double x = calculateX(cubeX, cubeY, cubeZ);
    double y = calculateY(cubeX, cubeY, cubeZ);
    double z = calculateZ(cubeX, cubeY, cubeZ) + distanceFromCam;
    double ooz = 1 / z;
    int xp = (int)(width / 2 + horizontalOffset + K1 * ooz * x * 2);
    int yp = (int)(height / 2 - K1 * ooz * y);
    int idx = xp + yp * width;
    if (idx >= 0 && idx < width * height) {
        if (ooz > zBuffer[idx]) {
            zBuffer[idx] = ooz;
            buffer[idx] = ch;
        }
    }
}

void renderCube(double cubeWidth, double horizontalOffset) {
    for (double cubeX = -cubeWidth; cubeX < cubeWidth; cubeX += incrementSpeed) {
        for (double cubeY = -cubeWidth; cubeY < cubeWidth; cubeY += incrementSpeed) {
            calculateForSurface(cubeX, cubeY, -cubeWidth, '@', horizontalOffset);
            calculateForSurface(cubeWidth, cubeY, cubeX, '$', horizontalOffset);
            calculateForSurface(-cubeWidth, cubeY, -cubeX, '~', horizontalOffset);
            calculateForSurface(-cubeX, cubeY, cubeWidth, '#', horizontalOffset);
            calculateForSurface(cubeX, -cubeWidth, -cubeY, ';', horizontalOffset);
            calculateForSurface(cubeX, cubeWidth, cubeY, '+', horizontalOffset);
        }
    }
}

int main() {
    while (1) {
        memset(buffer, backgroundASCIICode, width * height);
        memset(zBuffer, 0, width * height * sizeof(double));
        
        renderCube(20, -40);
        renderCube(10, 10);
        renderCube(5, 40);
        
        system(CLEAR_SCREEN);
        for (int k = 0; k < width * height; k++) {
            putchar(k % width ? buffer[k] : '\n');
        }
        
        A += 0.05;
        B += 0.05;
        C += 0.01;
        usleep(8000);
    }
    return 0;
}
