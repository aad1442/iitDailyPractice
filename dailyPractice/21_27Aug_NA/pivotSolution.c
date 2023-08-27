#include <stdio.h>
#include <math.h>
#define NMAX 4

void swap(double x[NMAX][NMAX + 1], int a, int b) {
    for (int i = 0; i < NMAX + 1; i++) {
        double temp = x[i][a];
        x[i][a] = x[i][b];
        x[i][b] = temp;
    }
}

void printMatrix(double x[NMAX][NMAX + 1]) {
    for (int i = 0; i < NMAX; i++) {
        for (int j = 0; j < NMAX + 1; j++) {
            printf("%7.2f", x[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main(void) {
    // Your initial matrix declaration
    double x[NMAX][NMAX + 1] = {{1, -1, 2, -1, -8},
                                {2, -2, 3, -3, -20},
                                {1, 1, 1, 0, -2},
                                {1, -1, 4, 3, 4}};

    printf("Initial Augmented Matrix:\n");
    printMatrix(x);

    // Applying column operations
    for (int j = 0; j < NMAX; j++) {
        if (x[j][j] == 0) {
            int pivotRow = -1;
            for (int i = j + 1; i < NMAX; i++) {
                if (x[i][j] != 0) {
                    pivotRow = i;
                    break;
                }
            }
            if (pivotRow == -1) {
                printf("No non-zero pivot found, unable to proceed.\n");
                return 1;  // Exit with an error code
            }
            printf("Swapping rows %d and %d\n", j, pivotRow);
            swap(x, j, pivotRow);
            printf("After swapping:\n");
            printMatrix(x);
        }
        for (int i = j + 1; i < NMAX; i++) {
            double factor = x[i][j] / x[j][j];
            printf("Scaling row %d by factor %.2f and subtracting from row %d\n", j, factor, i);
            for (int k = j; k < NMAX + 1; k++) {
                x[i][k] = x[i][k] - x[j][k] * factor;
            }
            printMatrix(x);
        }
    }

    printf("After column operations:\n");
    printMatrix(x);

    // Back substitution
    double solution[NMAX];
    for (int i = NMAX - 1; i >= 0; i--) {
        solution[i] = x[i][NMAX];
        for (int j = i + 1; j < NMAX; j++) {
            solution[i] -= x[i][j] * solution[j];
        }
        solution[i] /= x[i][i];
    }

    printf("Solution:\n");
    for (int i = 0; i < NMAX; i++) {
        printf("x[%d] = %lf\n", i, solution[i]);
    }

    return 0;
}
