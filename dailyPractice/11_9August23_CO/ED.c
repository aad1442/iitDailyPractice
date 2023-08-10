#include<stdio.h>

int min(int a, int b, int c) {
    int min_value = a;

    if (b < min_value) {
        min_value = b;
    }

    if (c < min_value) {
        min_value = c;
    }

    return min_value;
}


int main(){
    freopen("Ed.txt","r",stdin);
    int s_x,s_y;
    scanf("%d",&s_x);
    scanf("%d",&s_y);
    char x[s_x],y[s_y];
    scanf("%s %s",x,y);
    printf("%d %d %s %s",s_x,s_y,x,y);
    printf("%d %d",s_x,s_y);
    int c[s_x][s_y];
    for(int i=0;i<s_x;i++){
        for(int j=0;j<s_y;j++){
            if(j==0){
                c[i][j]=i;
            }
            else if(i==0){
                c[i][j]=j;
            }else if(x[i]==y[j]){
                c[i][j]=c[i-1][j-1];
            }else{
                c[i][j]=min(c[i-1][j-1],c[i-1][j],c[i][j-1])+1;
            }
        }
    }

    printf("\n%d\n",c[s_x][s_y]);


}