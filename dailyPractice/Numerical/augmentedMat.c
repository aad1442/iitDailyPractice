#include <stdio.h>

int main() {
    // Define the coefficients and constants of the system of equations
    double coefficients[][3] = {{2, 3, 8}, {4, -2, 2}, {3, 2, 6}};
    int numEquations = 3; // Number of equations

    // Print the augmented matrix
    for (int i = 0; i < numEquations; i++) {
        for (int j = 0; j < numEquations + 1; j++) {
            printf("%8.2f ", coefficients[i][j]);
        }
        printf("\n");
    }

    return 0;
}
