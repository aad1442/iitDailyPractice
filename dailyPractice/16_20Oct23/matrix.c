#include<stdio.h>

int mat1[3][3], mat2[3][3];

void multiplictation(int mat1[3][3],int mat2[3][3]){
    int row1 =3;
    int col2 =3;
    int row2 =3;
    int result[3][3];
    for(int i=0;i<row1;i++){
        for(int j=0;j<col2;j++){
             result[i][j]=0;
             for(int k=0;k<row2;k++){
                result[i][j] += mat1[i][k]* mat2[k][j];
             }
        }
    }
    printf("Matrix multiplication Result: \n");
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            printf("%d\t",result[i][j]);
        }
    }

}

int main(){
    //mat1={1,2,3,4,5,6,7,8,9};
    //mat2 = {1,2,3,4,5,6,7,8,9};
}