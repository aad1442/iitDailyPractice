#include<stdio.h>
#include<stdlib.h>
#define max 100

int main()
{
    char s[5][max];
    int s_size[5];

    for(int i=0;i<5;i++){
        int num = rand()%20;
        s_size[i]= num; 
        printf("%d\n",num);
        for(int j=0;j<num;j++)
        {
           s[i][j]= 48 + rand()%2;
        }
        s[i][num]=NULL;
    }

    for(int i=0;i<5;i++){
        printf("String %d:\n",i+1);
        printf("%s",s[i]);
        printf("\n");
    }
}
