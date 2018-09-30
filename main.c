#include <stdio.h>
#include "matrix.h"

#define ROW_SIZE 4
#define COLUMN_SIZE 4

int main() {

  double raw[ROW_SIZE][COLUMN_SIZE] = {
    {2, 1, 1, 3},
    {0, 3, 1, 7},
    {4, 3, 9, 9},
    {2, 3, 4, 1}
  };

  matrix_struct m1, t1;
  m1.array = NULL;
  m1.cols = COLUMN_SIZE;
  m1.rows = ROW_SIZE;

  m1.array = matrixMemoryAllocation(m1.array, m1.rows, m1.cols);

  double determinant;

  for (int i=0; i<ROW_SIZE ;i++) {
    for (int j=0; j<COLUMN_SIZE; j++) {
      m1.array[i][j] = raw[i][j];
    }
  }

  t1 = getTransposeMatrix(m1);

  determinant = getMatrixDeterminant(m1);

  printf("Raw Matrix: \n");
  printMatrix(m1);

  printf("Convert Transposed Matrix: \n");
  printMatrix(t1);

  printf("Matrix Determinant: %lf \n", determinant);

  return 0;
}
