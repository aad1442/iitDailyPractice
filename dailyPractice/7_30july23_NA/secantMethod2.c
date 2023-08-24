#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define epsilon 1.0e-6
#define f(x) ((x)*(x)*(x) + 4*(x)*(x) - 10)

int main() {
    int n = 100, i;
    double x0 = 1.25, x1 = 2, x2;

    if (f(x0) * f(x1) > 0) {
        printf("No root exists between x0 and x1.\n");
        exit(0);
    }

    printf("i     x0         x1         x2         f(x0)      f(x1)      f(x2)\n");

    for (i = 0; i < n; i++) {
        x2 = x1 - f(x1) * (x1 - x0) / (f(x1) - f(x0));

        if (fabs(f(x2)) < epsilon) {
            printf("Root: %lf\n", x2);
            break;
        }

        printf("%d   %lf   %lf   %lf   %lf   %lf   %lf\n", i, x0, x1, x2, f(x0), f(x1), f(x2));

        x0 = x1;
        x1 = x2;
    }

    if (i == n) {
        printf("Method did not converge within %d iterations.\n", n);
    }

    return 0;
}
