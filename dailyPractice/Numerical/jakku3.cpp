#include<iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

using namespace std;

#define N 3 // Number of variables
double A[N][N] = {
    {4, 1, 1},
    {2, 5, 2},
    {1, 2, 4},

};
double b[N] = {8, 3, 11};
double x[N] = {0};
double x_n[N];
int max_iterations = 100;
double tolerance = 1e-6;
int iteration, i, j, k;

double determinant3x3(double matrix[3][3])
{
    double det = 0.0;
    for (int i = 0; i < 3; i++)
    {
        det += matrix[0][i] * (matrix[1][(i + 1) % 3] * matrix[2][(i + 2) % 3] - matrix[1][(i + 2) % 3] * matrix[2][(i + 1) % 3]);
    }
    return det;
}

bool inverse3x3Matrix(double matrix[3][3], double result[3][3])
{
    double det = determinant3x3(matrix);

    if (std::abs(det) < 1e-10)
    {
        return false;
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            result[i][j] = (matrix[(j + 1) % 3][(i + 1) % 3] * matrix[(j + 2) % 3][(i + 2) % 3] - matrix[(j + 1) % 3][(i + 2) % 3] * matrix[(j + 2) % 3][(i + 1) % 3]) / det;
        }
    }

    return true;
}

void jacob()
{
    for (iteration = 0; iteration < max_iterations; iteration++)
    {
        double c[N];
        for (int i = 0; i < N; i++)
        {
            c[i] = 0;
            for (int j = 0; j < N; j++)
            {
                c[i] += A[i][j] + x[j];
            }
        }

        double d[N] = {0, 0, 0};
        for (int i = 0; i < N; i++)
        {
            d[i] = b[i] - c[i];
        }
        double e[N] = {0, 0, 0};
        for (int i = 0; i < N; i++)
        {
            e[N] = d[i] / A[i][i];
        }

        for (int i = 0; i < N; i++)
        {
            x_n[i] = x[i] + e[i];
        }

        double max_diff = 0;
        for (i = 0; i < N; i++)
        {
            double diff = fabs(x_n[i] - x[i]);
            if (diff > max_diff)
            {
                max_diff = diff;
            }
        }

        for (i = 0; i < N; i++)
        {
            x[i] = x_n[i];
            // printf("%lf\n", x[i]);
        }

        if (max_diff < tolerance)
        {
            break;
        }
    }

    printf("Total iteration: %d\n", iteration);

    printf("Solution:\n");
    for (i = 0; i < N; i++)
    {
        printf("x%d = %.6f\n", i + 1, x[i]);
    }
}

int main()
{
    int flag = 0;
    double sum = 0;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            if (i != j)
            {
                sum = sum + abs(A[i][j]);
            }
        }

        if (abs(A[i][i]) <= sum)
        {
            flag = 1;
        }
        sum = 0;
    }
    if (flag == 1)
    {
        printf("It is not diagonally dominated.\n");
        return 0;
    }
    else
    {
        jacob();
    }
    double result[N][N];

    if (inverse3x3Matrix(A, result))
    {
        cout<< "Original: "<<endl;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }

        cout << "Inverse Matrix:" << endl;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                cout << result[i][j] << " ";
            }
            cout << endl;
        }
    }
    else
    {
        cout << "The matrix is not invertible (determinant is zero or nearly zero)." << endl;
    }

    return 0;
}