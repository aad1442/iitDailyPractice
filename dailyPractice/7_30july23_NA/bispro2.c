#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define epsilon 10.0e-6
#define f(x) ((x) * (x) * (x) + 4 * (x) * (x) - 10)

int main()
{
    int n = 100, i;
    double a = 1.25, b = 1.5, c;
    int count = 0;
    double k = (b - a) / 20;
    a = a - k;
    b = a; 

    for (int i = 0; i < 20; i++)
    {
        printf("Count : %d ", ++count);
        a = a + k;
        b = b + k + k;
        printf("a=%lf, b=%lf\n", a, b);

        if (f(a) * f(b) > 0)
        {
            printf("No root in interval [%lf, %lf]\n", a, b);
            continue;
        }

        printf("i     a     b     c     f(a)     f(b)     f(c)\n");
        for (i = 0; i < n; i++)
        {
            c = (a + b) / 2;

            if (fabs(f(c)) < epsilon)
            {
                printf("Root : %lf\n", c);
                break;  // Exit the inner loop when a root is found
            }

            printf("%d %0.5lf %0.5lf %.5lf %.5lf %.5lf %.5lf\n", i, a, b, c, f(a), f(b), f(c));
            if (f(a) * f(c) < 0)
                b = c;
            else
                a = c;
        }continue;
    }

   
}

