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
            printf("Pivot is zero, cannot proceed.\n");
            return 1;  // Exit with an error code
        }
        for (int i = j + 1; i < NMAX; i++) {
            double factor = x[i][j] / x[j][j];
            for (int k = j; k < NMAX + 1; k++) {
                x[i][k] = x[i][k] - x[j][k] * factor;
            }
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
