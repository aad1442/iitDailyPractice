#include<stdio.h>
#define max 100
long int fib[max];
long int fibonacchi(int n){
    //prinf("%d\n",n);
    if(n<=1){
        fib[n]=n;
    }else if(fib[n]<0){
        fib[n]=fibonacchi(n-1)+fibonacchi(n-2);
    }
    return fib[n];
}

int main(){
    for(int i=0;i<max;i++){
        fib[i]=-1;
    }
    int n;
    printf("Enter the number: ");
    scanf("%d",&n);
    printf("Fibonacci of the number: %ld\n",fibonacchi(n));
    return 0;
}