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
        s[i][num]=0;
    }

    for(int i=0;i<5;i++){
        printf("String %d:\n",i+1);
        printf("%s",s[i]);
        printf("\n");
    }

    for(int i=0;i<5;i++){
        printf("Length of string %d :  ",i+1);
        int l=0;
        while(s[i][l])l++;
        printf("%d\n",s_size[i]=l);
    }

    char ss[]={'0','1','0','1'};
    int flag =0;
    int i=0;
    while(ss[i]!=NULL){

        if(ss[i]!='0' && ss[i]!='1'){
            flag =1;
        }i++;
    }
    if(!flag){
        printf("From the alphabet");
    }else{
        printf("Not From");
    }

    char str[s_size[0]+s_size[1]];
    int k=1;
    // for( k=0;k<s_size[0];k++){
    //     str[k]=s[0][k];
    // }i--;
    // for(int j=0;j<s_size[1];j++,i++){
    //     printf("a");
    //     str[k]=s[1][j];
    //     //printf("%c",str[i]);
    // }
    // printf("\n%s\n",str);
    // // for(int i=0;str[i]!=NULL;i++){
    // //     printf("%c",str[i]);
    // // }
    for(int i=0,j=s_size[0];i<s_size[0],j<s_size[1]+s_size[0];i++,j++){
        str[i]=s[0][i];
        str[j]=s[1][i];
    }
    printf("\n%s\n",str);


}