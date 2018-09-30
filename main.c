#include <stdio.h>
#include "matrix.h"

#define ROW_SIZE 2
#define COLUMN_SIZE 3

int main() {

  double raw[ROW_SIZE][COLUMN_SIZE] = {
    {1, 2, 3},
    {1, 2, 3}
  };

  matrix_struct m1, t1;
  m1.array = NULL;
  m1.cols = COLUMN_SIZE;
  m1.rows = ROW_SIZE;

  m1.array = matrixMemoryAllocation(m1.array, m1.rows, m1.cols);

  for (int i=0; i<ROW_SIZE ;i++) {
    for (int j=0; j<COLUMN_SIZE; j++) {
      m1.array[i][j] = raw[i][j];
    }
  }

  t1 = getTransposeMatrix(m1);

  printf("Raw Matrix: \n");
  printMatrix(m1);

  printf("Convert Transposed Matrix: \n");
  printMatrix(t1);
  
  return 0;
}
