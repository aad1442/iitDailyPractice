#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define epsilon 10.0e-6
#define h(x) ((x)*(x))
#define g(x) (pow(x,.5))
#define f(x) g(x)-h(x)

double bisection(double a, double b)
{
    int n = 100, i;
    // printf("a");
    double c;
    if (f(a) * f(b) > 0)
    {
        printf("no root");
        return -1;
        exit(0);
    }
    printf("i     a     b     c     f(a)     f(b)     f(c)\n");
    for (i = 0; i < n; i++)
    {
        c = (a + b) / 2;

        if (fabs(f(c)) < epsilon)
        {
            printf("Root : %lf\n", c);
            return c;
            break;
        }
        printf("%d %0.5lf %0.5lf %.5lf %.5lf %.5lf %.5lf\n ", i, a, b, c, f(a), f(b), f(c));
        if (f(a) * f(c) < 0)
            b = c;
        else
            a = c;
    }
}


double simpson(double a, double b, int n)
{
    if (n % 2)
        n = n + 1;

    double h = (b - a) / n;
    double x[n + 1], y[n + 1];
    double sumX = 0.0, sumO = 0.0, sumE = 0.0;
    for (int i = 0; i < n; i++)
    {
        x[i] = a + h * i;
    }
    x[n] = b;
    for (int i = 0; i <= n; i++)
    {
        y[i] = f(x[i]);
    }
    for (int i = 1; i < n; i++)
    {
        if (i % 2)
            sumO += y[i];
        else
            sumE += y[i];
    }
    sumX = y[0] + y[n];
    printf("sumX: %lf, sumE:%lf, sumO:%lf", sumX, sumE, sumO);
    double I = h * (4 * sumO + 2 * sumE + sumX) / 3;
    return I;
}

int main()
{
     int n;
     double a, b;
    scanf("%lf%lf%d",&a,&b,&n);
    printf("%lf ,%lf, %d\n",a,b,n);
    double root = bisection(a,b);
    printf("Root is %lf\n",root);
    if(root>0){
        printf("Integral value:T; %lf",simpson(a,root,10));
    }
}