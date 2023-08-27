#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int mat1[3][3], mat2[3][3];

void multiplication(int mat1[3][3], int mat2[3][3])
{
    int row1 = 3;
    int col2 = 3;
    int row2 = 3;
    int result[3][3];

    for (int i = 0; i < row1; i++)
    {
        for (int j = 0; j < col2; j++)
        {
            result[i][j] = 0;
            for (int k = 0; k < row2; k++)
            {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }

    printf("Matrix multiplication Result: \n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d\t", result[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    // nt mat1[3][3] = {{1, 1, 1}, {1, 1, 1}, {1, 1, 1}};
    // int mat2[3][3] = {{1, 1, 1}, {1, 1, 1}, {1, 1, 1}};
    srand(time(NULL));
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            mat1[i][j] = rand() % 10;
        }
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            mat2[i][j] = rand() % 10;
        }
    }

        printf("Matrix 1  Result: \n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d\t", mat1[i][j]);
        }
        printf("\n");
    }

        printf("Matrix 2  Result: \n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d\t", mat2[i][j]);
        }
        printf("\n");
    }
    clock_t start_time = clock();
    multiplication(mat1, mat2);
    clock_t end_time = clock();
    double time = (double)(end_time- start_time)/CLOCKS_PER_SEC;
    printf("Time calcultation for the code is : %lf",time);

    return 0;
}
