#include <stdio.h>
#include <math.h>
#define NMAX 4
double x[NMAX][NMAX + 1] = {{1, -1, 2, -1, -8}, {2, -2, 3, -3, -20}, {1, 1, 1, 0, -2}, {1, -1, 4, 3, 4}};
void col(double mat[NMAX][NMAX + 1])
{
    printf("\n");
    for (int i = 0; i < 1; i++)
    {
        for (int j = 0; j < NMAX + 1; j++)
        {
            mat[1][j] = mat[1][j] - (mat[0][j] * 2);
        }
    }
    for (int i = 2; i <= 3; i++)
    {
        for (int j = 0; j < NMAX + 1; j++)
        {
            mat[i][j] = mat[i][j] - (mat[0][j]);
        }
    }
   printMat(mat);
   printf("\n");
    for (int j = 0; j < NMAX + 1; j++)
    {
        double temp = mat[1][j];
        mat[1][j] = mat[2][j];
        mat[2][j] = temp;
    }

    for (int j = 0; j < NMAX + 1; j++)
    {
        mat[3][j] = mat[3][j] + (2 * mat[2][j]);
    }

    printMat(mat);
}
void printMat(double mat[NMAX][NMAX + 1])
{
    for (int i = 0; i < NMAX; i++)
    {
        for (int j = 0; j < NMAX + 1; j++)
        {
            printf("%7.2lf ", mat[i][j]);
        }
        printf("\n");
    }
}
int main()
{
    int i, j, k;

    printMat(x);
    col(x);
    printf("\n");
   
}