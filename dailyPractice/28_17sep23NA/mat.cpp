#include<stdio.h>

void printMat(int mat[3][3]){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            printf("%d ",mat[i][j]);
        }printf("\n");
    }
}

int main(){
     int mat[3][3]={
        4 ,1 ,1,
        2 ,5 ,2,
        1 ,2 ,4
     };
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(i==1){
                mat[i][j]=mat[i-1][j]- (mat[i-1][j]/mat[i][j])*mat[i][j]; 
            }
            if(i==2){
                mat[i][j]= mat[i-2][j]- (mat[i-2][j]/mat[i][j])*mat[i][j];
            }
            if(i==2){
               //mat[i][j]= mat[i-2][j]- (mat[i-2][j]/mat[i][j])*mat[i][j];
            }
            
        }
    }
     printMat(mat);
}