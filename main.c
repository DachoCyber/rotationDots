#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif
#include "rotation.h"

#define N 30
#define PI 3.14159265358979323846

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void sleepMilliseconds(int milliseconds) {
#ifdef _WIN32
    Sleep(milliseconds);
#else
    usleep(milliseconds * 1000);
#endif
}

int main() {
    char dots[N][N];
    char rotatedDots[N][N];

    generateMatrix(dots);

    for(double fi = 0; fi <= 2 * PI; fi += 0.1) {
        rotateMatrixByFi(dots, rotatedDots, fi);
        clearScreen();
        printMatrix(rotatedDots);
        sleepMilliseconds(100);  // Adjust the delay as needed
    }

    return 0;
}
