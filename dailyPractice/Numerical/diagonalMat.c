#include <stdio.h>
#include <math.h>

#define N 3 
double Ad[N][N];
 double D[N][N];
void diagonal( double A[N][N] ){
      for (int row = 0; row < N; row++)
    {
        for (int col = 0; col < N; col++)
        {
          
               if(row==col)
               {
                D[row][col]=A[row][col];
                Ad[row][col]=0;
               }
               else{
                 D[row][col]=0;
                Ad[row][col]=A[row][col];
               
               }
        }
    }

}
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
void getInverseofDiagonal(double D[N][N]){
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if(i==j)
            D[i][j]=1/D[i][j];
        }
       
    }
}

int main()
{
    double A[N][N] = {
        {4, 1, 1},
        {2, 5, 2},
        {1, 2, 4}};
  
        diagonal(A);

        printf("Ad mat: \n");
        print(Ad);
        printf("\nD mat: \n");
        print(D);
        printf("\nInverse of D mat: \n");
        getInverseofDiagonal(D);
        print(D);


    
}