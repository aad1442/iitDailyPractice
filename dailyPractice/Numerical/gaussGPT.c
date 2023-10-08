#include <stdio.h>
#include <stdlib.h>

#define NMAX 100

int main() {
    int n; // Number of equations and variables
    printf("Enter the number of equations: ");
    scanf("%d", &n);

    double matrix[NMAX][NMAX + 1]; // Augmented matrix (with an extra column for constants)
    double solutions[NMAX];       // Array to store the solutions

    // Input the augmented matrix
    printf("Enter the coefficients and constants:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n; j++) {
            scanf("%lf", &matrix[i][j]);
        }
    }

    // Perform Gaussian elimination
    for (int k = 0; k < n - 1; k++) {
        for (int i = k + 1; i < n; i++) {
            double factor = matrix[i][k] / matrix[k][k];
            for (int j = k; j <= n; j++) {
                matrix[i][j] -= factor * matrix[k][j];
            }
        }
    }

    // Back-substitution to find the solutions
    for (int i = n - 1; i >= 0; i--) {
        solutions[i] = matrix[i][n];
        for (int j = i + 1; j < n; j++) {
            solutions[i] -= matrix[i][j] * solutions[j];
        }
        solutions[i] /= matrix[i][i];
    }

    // Print the solutions
    printf("Solutions:\n");
    for (int i = 0; i < n; i++) {
        printf("x[%d] = %.2lf\n", i, solutions[i]);
    }

    return 0;
}
