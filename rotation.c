#include <stdio.h>
#include <math.h>
#include "rotation.h"

#define N 30

void printMatrix(char dots[][N]) {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            printf("%c", dots[i][j]);
        }
        printf("\n");
    }
}

void rotateMatrixByFi(char dots[][N], char rotatedDots[][N], double fi) {
    int centerX = N / 2;
    int centerY = N / 2;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            rotatedDots[i][j] = ' ';
        }
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            int x = j - centerX;
            int y = i - centerY;
            int rotatedX = (int)(x * cos(fi) - y * sin(fi)) + centerX;
            int rotatedY = (int)(x * sin(fi) + y * cos(fi)) + centerY;

            if (rotatedX >= 0 && rotatedX < N && rotatedY >= 0 && rotatedY < N) {
                rotatedDots[rotatedY][rotatedX] = dots[i][j];
            }
        }
    }
}

void generateMatrix(char dots[][N]) {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            dots[i][j] = '.';
        }
    }
}
