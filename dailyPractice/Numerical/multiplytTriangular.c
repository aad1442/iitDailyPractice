#include <stdio.h>
#include <math.h>

#define N 3 // Define the number of equations

int i, j, k;
double result[N][N];
void print(double A[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("%0.2lf   ", A[i][j]);
        }
        printf("\n");
    }
}

void upperTriangular(double A[N][N], double L[N][N])
{

    for (i = 0; i < N; i++)
    {

        int p = i;
        while (A[p][i] == 0)
        {
            p++;
            if (p == N)
            {
                printf("No unique solution exists\n");
                return;
            }
        }

        if (p != i)
        {
            for (j = 0; j < N; j++)
            {
                double temp = A[p][j];
                A[p][j] = A[i][j];
                A[i][j] = temp;
            }
        }

        for (j = i + 1; j < N; j++)
        {
            double m = A[j][i] / A[i][i];
            L[j][i] = m;
            for (k = i; k < N; k++)
            {
                A[j][k] -= m * A[i][k];
            }
        }
    }
}
void multiplication(double matA[N][N], double matB[N][N])
{
    int row1 = N;
    int row2 = N;
    int col2 = N;

    for (int i = 0; i < row1; i++)
    {
        for (int j = 0; j < col2; j++)
        {
            result[i][j] = 0;
            for (int k = 0; k < row2; k++)
            {
                result[i][j] += matA[i][k] * matB[k][j];
            }
        }
    }
    printf("multiplication result: \n");
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("%0.2lf\t", result[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    double A[N][N] = {
        {4, 1, 1},
        {2, 5, 2},
        {1, 2, 4}};
    double L[N][N];

    // Initialize operationalMat with the original matrix A augmented with the identity matrix
    for (int row = 0; row < N; row++)
    {
        for (int col = 0; col < N; col++)
        {
            if (row == col)
                L[row][col] = 1;
            else
                L[row][col] = 0;
        }
    }
    
    upperTriangular(A, L);
    printf("Upper triangular: \n");
    print(A);
    printf("Lower triangular: \n");
    print(L);
    printf("\n");
    multiplication(L, A);

    return 0;
}
