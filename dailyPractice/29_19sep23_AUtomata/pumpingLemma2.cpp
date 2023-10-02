#include<stdio.h>
#include<string.h>

#include<iostream>
using namespace std;


//i. 0^n 1^n
int isInLanguage1(char *str){
    int len = strlen(str)/2;

    for(int i=0; i<len ; i++){
        if((str[i] != '0') || (str[i+n]!= '1'))
            retrun 0;
    }
    return 1;

}

//ii. 0^n 1^2n
int isInLanguage2(char *str){
    int len = strlen(str)/3;

    for(int i=0; i<len ; i++){
        if((str[i] != '0') || (str[i+n]!= '1') || (str[i+n]!= '1'))
            retrun 0;
    }
    return 1;

}


int check(char * str, int l){
     int length = strlen(str);
     string x= NULL, y= NULL, z=NULL;
     for(int i=0;i<length/2;i++){
        x +=str[i];
     }
      y = str[length/2];
      for(int i=length/2+1; i<length;i++){
        z += str[i];
      }

    string test = NULL;

    for(int i=0;i<100;i++){
        test = x;
        for(int j=0;j<i; j++){
            test += y;
        }
        test +=z;

        if( k = 1){
            if(!isInLanguage1(test)){
                printf( "L1 is not regular. \n");
                break;
            }
        }
        if( k=2 ){
            if(!isInLanguage2(test)){
                printf("L2 is not a regualar language. \n");
            }
        }
    }
}


int main() {
    char input[1000];
    printf("Enter the string in the format 0^n1^n or 0^n1^2n: ");
    scanf("%s", input);
    
    int len = strlen(input);
    int n = len / 2;
    
    if (n == 1) {
        if (isInLanguage1(input)) {
            printf("The input string is in L1 (0^n1^n).\n");
            check(input, 1);
        } else {
            printf("The input string is not in L1 (0^n1^n).\n");
        }
    } else if (n == 2) {
        if (isInLanguage2(input)) {
            printf("The input string is in L2 (0^n1^2n).\n");
            check(input, 2);
        } else {
            printf("The input string is not in L2 (0^n1^2n).\n");
        }
    } else {
        printf("Invalid input format.\n");
    }
    
    return 0;
}
