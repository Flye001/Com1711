#include <stdio.h>

void printArray(int a[][3], int rows, int cols){
  for (size_t i = 0; i < rows; ++i) {
     for (size_t j = 0; j < cols; ++j) {
        printf("%d ", a[i][j]);
     }
     printf("\n"); // start new line of output 
     }
}
void printTransposedArray(int a[][2], int rows, int cols){
  for (size_t i = 0; i < rows; ++i) {
     for (size_t j = 0; j < cols; ++j) {
        printf("%d ", a[i][j]);
     }
     printf("\n"); // start new line of output 
     }
}

void transposeMatrix(int A[2][3], int T[3][2]) {
    for (int r = 0; r < 2; r++) {
        for (int c = 0; c < 3; c++) {
            T[c][r] = A[r][c];
        }
    }
}

int main() {
    int myArr[2][3] = { {1,2,3},
                        {4,5,6} };

    int transposed[3][2] = {};
    transposeMatrix(myArr, transposed);

    printf("Original Matrix:\n\n");
    printArray(myArr, 2, 3);
    printf("\nTransposed Matrix:\n\n");
    printTransposedArray(transposed, 3, 2);
}