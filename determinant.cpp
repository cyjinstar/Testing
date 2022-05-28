#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Determinant.h"

using namespace std;

 float** DetClass::submatrix(float **matrix, int n, int x, int y){
     float **submatrix = new float *[n];
     int subi = 0;
     for (int i = 0; i < n; i++) {
         submatrix[subi] = new float[n];
         int subj = 0;
         if (i == y) {
             continue;
         }
         for (int j = 0; j < n; j++) {
             if (j == x) {
                 continue;
             }
             submatrix[subi][subj] = matrix[i][j];
             subj++;
         }
         subi++;
     }
     return submatrix;
 }

 float DetClass::determinant(float **matrix, int n) {
     float det = 0;
     if (n == 2) {
         return matrix[0][0] * matrix[1][1] - matrix[1][0] * matrix[0][1];
     }
     for (int x = 0; x < n; ++x) {
         det += ((x % 2 == 0 ? 1 : -1) * matrix[0][x] * determinant(submatrix(matrix, n, x, 0), n - 1));
     }
     return det;
 }

 float** DetClass::detInvese(float **matrix, int n){
    float** adjMatrix = (float**)malloc(sizeof(float*) * n);
    for (int i = 0; i < n; i++) {
        adjMatrix[i] = (float*)malloc(sizeof(float) * n);
            for (int j = 0; j < n; j++) {
                adjMatrix[i][j] = ((j+i) % 2 == 0 ? 1 : -1) * determinant(submatrix(matrix, n, j, i), n - 1);
            }
    }
     return adjMatrix;
 }