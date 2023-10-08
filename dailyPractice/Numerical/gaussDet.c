#include <stdio.h>
#include <math.h>
#define NMAX 3
double x[NMAX+1][NMAX +1] = {{4, 1, 1}, {2, 5, 2}, {1, 2, 4}};
void col(double mat[NMAX+1][NMAX +1])
{
    printf("\n");
    for (int i = 0; i < 1; i++)
    {
        for (int j = 0; j <=NMAX ; j++)
        {
            mat[1][j] = (mat[1][j]*2) - (mat[0][j]);
        }
    }
    for (int i = 2; i < 3; i++)
    {
        for (int j = 0; j <= NMAX ; j++)
        {
            mat[i][j] = (4*mat[i][j]) - (mat[0][j]);
        }
    }
    for (int i = 2; i < 3; i++)
    {
        for (int j = 0; j <= NMAX ; j++)
        {
            mat[2][j] = (mat[2][j]*(9/7)) - (mat[1][j]);
        }
    }
   printMat(mat);
   double det=1;
   for(int i=0;i<NMAX;i++){
    for(int j=0;j<NMAX;j++){
        if(i==j){
           
            det*=mat[i][j];
        }
    }
   }
   printf("determinent: %lf ",det);
   printf("\n");
   /*
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

    printMat(mat);*/
}
void printMat(double mat[NMAX+1][NMAX + 1])
{
    for (int i = 0; i < NMAX; i++)
    {
        for (int j = 0; j < NMAX; j++)
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