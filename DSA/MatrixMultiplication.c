#include <stdio.h>
#include <stdlib.h>

void matrixMultiply(int rowsA, int colsA, int colsB, int A[rowsA][colsA], int B[colsA][colsB], int C[rowsA][colsB]) {
    // Initialize result matrix C to zero
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            C[i][j] = 0;
        }
    }

    // Matrix multiplication
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            for (int k = 0; k < colsA; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void printMatrix(int rows, int cols, int matrix[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int rowsA, colsA, rowsB, colsB;

    // Input dimensions of matrix A
    printf("Enter the number of rows and columns of Matrix A: ");
    scanf("%d %d", &rowsA, &colsA);

    // Input dimensions of matrix B
    printf("Enter the number of rows and columns of Matrix B: ");
    scanf("%d %d", &rowsB, &colsB);

    // Ensure matrix multiplication is possible
    if (colsA != rowsB) {
        printf("Matrix multiplication not possible. Number of columns in A must equal number of rows in B.\n");
        return 1;
    }

    int A[rowsA][colsA], B[rowsB][colsB], C[rowsA][colsB];

    // Input elements of matrix A
    printf("Enter elements of Matrix A (%d x %d):\n", rowsA, colsA);
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsA; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    // Input elements of matrix B
    printf("Enter elements of Matrix B (%d x %d):\n", rowsB, colsB);
    for (int i = 0; i < rowsB; i++) {
        for (int j = 0; j < colsB; j++) {
            scanf("%d", &B[i][j]);
        }
    }

    // Perform matrix multiplication
    matrixMultiply(rowsA, colsA, colsB, A, B, C);

    // Print the matrices
    printf("Matrix A:\n");
    printMatrix(rowsA, colsA, A);

    printf("Matrix B:\n");
    printMatrix(rowsB, colsB, B);

    printf("Resultant Matrix C (A x B):\n");
    printMatrix(rowsA, colsB, C);

    return 0;
}
