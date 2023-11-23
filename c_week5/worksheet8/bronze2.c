#include <stdio.h>

#define ARR_1_ROWS 2;
#define ARR_1_COLS 3;
#define ARR_2_ROWS 3;
#define ARR_2_COLS 2;

void multiplyMatrices(int arrA[ARR_1_ROWS][ARR_1_COLS], int arrB[ARR_2_ROWS][ARR_2_COLS], int arrC[ARR_1_ROWS][ARR_2_COLS])
{
    for (int cRow = 0; cRow < ARR_1_ROWS; cRow++)
    {
        for (int cCol = 0; cCol < ARR_2_COLS; cCol++)
        {
            int sum = 0;

            for (int i = 0; i < ARR_1_COLS; i++)
            {
                sum += arrA[cRow][i] * arrB[i][cCol];
            }

            arrC[cRow][cCol] = sum;
        }
    }
}

void printArray(int a[ARR_1_ROWS][ARR_2_COLS], int rows, int cols)
{
    for (size_t i = 0; i < rows; ++i)
    {
        for (size_t j = 0; j < cols; ++j)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n"); // start new line of output
    }
}

int main()
{
    int arrA[ARR_1_ROWS][ARR_1_COLS] = {{3,2,6}, {2,9,4}};
    // int arrA[2][3] = {{1, 1, 1}, {1, 1, 1}};
    int arrB[ARR_2_ROWS][ARR_2_COLS] = {{8,4}, {2,9}, {7,7}};
    // int arrB[3][2] = {{1, 1}, {1, 1}, {1, 1}};
    int arrC[ARR_1_ROWS][ARR_2_COLS];

    multiplyMatrices(arrA, arrB, arrC);
    printf("Result:\n\n");
    printArray(arrC, 2, 2);
}