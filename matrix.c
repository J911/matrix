#include <stdlib.h>
#include <stdio.h>
#include "matrix.h"

double **matrixMemoryAllocation(double **matrix, int rows, int cols) {
  matrix = malloc(sizeof(double *) * rows);
  for(int i=0; i<rows; i++) matrix[i] = malloc(sizeof(double) * cols);
  return matrix;
}

void printMatrix(matrix_struct m) {
  for (int i=0; i<m.rows; i++){
    for (int j=0; j<m.cols; j++) printf("%lf ", m.array[i][j]);
    printf("\n");
  }
}

matrix_struct getTransposeMatrix(matrix_struct m) {
  matrix_struct tm;

  tm.cols = m.rows;
  tm.rows = m.cols;
  tm.array = matrixMemoryAllocation(tm.array, tm.rows, tm.cols);

  for (int i=0; i<tm.rows; i++) {
    for (int j=0; j<tm.cols; j++) {
      tm.array[i][j] = m.array[j][i];
    }
  }
  
  return tm;
}
