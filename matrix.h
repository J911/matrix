typedef struct {
  int rows;
  int cols;
  double **array;
} matrix_struct;

double **matrixMemoryAllocation(double **matrix, int rows, int cols);
matrix_struct getTransposeMatrix(matrix_struct m);
matrix_struct addMatrix(matrix_struct m1, matrix_struct m2);
void printMatrix(matrix_struct m);
