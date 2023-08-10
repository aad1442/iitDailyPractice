#include<stdio.h>

int fibonacci(int n){
    if(n==0){
        return 0;
    }
    if(n==1){
        return 1;
    }else{
        return fibonacci(n-1)+fibonacci(n-2);
    }

}

int main(n){
    printf("Enter the number: ");
    scanf("%d",&n);
    printf("Fibonacci of the number is %d",fibonacci(n));
}