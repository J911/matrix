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

matrix_struct addMatrix(matrix_struct m1, matrix_struct m2) {
  if (m1.rows != m2.rows || m1.cols != m2.cols) perror("MATRIX SIZE ERROR!");

  matrix_struct res;
  res.cols = m1.rows;
  res.rows = m1.cols;

  res.array = matrixMemoryAllocation(res.array, res.rows, res.cols);

  for (int i=0; i<res.rows; i++) {
    for (int j=0; j<res.cols; j++) {
      res.array[i][j] = m1.array[i][j] + m2.array[i][j];
    }
  }

  return res;
}

double getMatrixDeterminant(matrix_struct m) {
  double determinant = 0;
  if (m.rows != m.cols) perror("MATRIX SIZE ERROR!");
  if (m.rows == 0) return 1;
  if (m.rows == 1) return m.array[0][0];
  if (m.rows == 2) return m.array[0][0] * m.array[1][1] - m.array[0][1] * m.array[1][0];

  for (int i=0; i<m.rows; i++) {
    int t_row, t_col;
    int flag = i % 2 == 0 ? 1 : -1;
    matrix_struct t;
    t.rows = m.rows - 1;
    t.cols = m.cols - 1;
    t.array = matrixMemoryAllocation(t.array, t.rows, t.cols);

    t_row = 0;
    for (int j=1; j<m.rows; j++) {      
      t_col = 0;
      for (int k=0; k<m.cols; k++) {
        if (k == i) continue;
        t.array[t_row][t_col] = m.array[j][k];
        t_col++;
      }
      t_row++;
    }
    
    determinant += getMatrixDeterminant(t) * m.array[0][i] * flag;
  }
  return determinant;
}