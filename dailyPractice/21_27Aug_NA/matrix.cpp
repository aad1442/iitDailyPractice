#include <stdio.h>
#include <math.h>
#define NMAX 4


void swap(double x[NMAX][NMAX + 1],int a, int b){
    for(int i=0;i<NMAX+1;i++){
        printf("swapping:%lf,%lf \n",x[a][i],x[b][i]);
        double temp= x[a][i];
        x[a][i]=x[b][i];
        x[b][i]=temp;
    }
}

void printMatrix(double x[NMAX][NMAX + 1])
{
    for (int i = 0; i < NMAX; i++) // Use NMAX for rows
    {
        for (int j = 0; j < NMAX + 1; j++)
        {
            printf("%7.2f", x[i][j]);
        }
        printf("\n");
    }
}

int main(void) {
    // Your initial matrix declaration
    double x[NMAX][NMAX + 1] = {{1, -1, 2, -1, -8},
                                {2, -2, 3, -3, -20},
                                {1, 1, 1, 0, -2},
                                {1, -1, 4, 3, 4}};

    // Last three element of first row
    for (int i = 0; i < NMAX + 1; i++) {
        x[1][i] = x[1][i] - 2 * x[0][i];
    }
    for (int i = 0; i < NMAX + 1; i++) {
        x[2][i] = x[2][i] - x[0][i];
    }
    for (int i = 0; i < NMAX + 1; i++) {
        x[3][i] = x[3][i] - x[0][i];
    }

    printf("Before swap: \n");
    printMatrix(x);
    swap(x,1, 2);
    
    printf("After swap: \n");
    printMatrix(x);


    printf("Final\n");
    for(int i=2;i<NMAX+1;i++){
        x[3][i]=x[3][i]+2*x[2][i];
    }
    printMatrix(x);
}