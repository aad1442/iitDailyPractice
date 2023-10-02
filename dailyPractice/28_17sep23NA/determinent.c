#include <stdio.h>
#include <math.h>

#define SIZE 10

float determinant(float matrix[SIZE][SIZE], int n);

int main() {
    float a[SIZE][SIZE];
    int i, j, n;

    /* Inputs */
    /* 1. Reading order of matrix */
    printf("Enter order of matrix: ");
    scanf("%d", &n);
    /* 2. Reading Matrix */
    printf("Enter elements of matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("a[%d][%d] = ", i, j);
            scanf("%f", &a[i][j]);
        }
    }

    /* Calculate and display the determinant */
    float det = determinant(a, n);
    printf("Determinant = %0.3f\n", det);

    return 0;
}

float determinant(float matrix[SIZE][SIZE], int n) {
    int i, j, k;
    float det = 0;
    float submatrix[SIZE][SIZE];

    if (n == 2) {
        return (matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0]);
    } else {
        for (i = 0; i < n; i++) {
            int subi = 0; // Submatrix's row index
            for (j = 1; j < n; j++) {
                int subj = 0; // Submatrix's column index
                for (k = 0; k < n; k++) {
                    if (k == i) {
                        continue;
                    }
                    submatrix[subi][subj] = matrix[j][k];
                    subj++;
                }
                subi++;
            }
            det = det + (pow(-1, i) * matrix[0][i] * determinant(submatrix, n - 1));
        }
    }
    return det;
}

