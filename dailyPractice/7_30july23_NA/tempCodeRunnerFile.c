#include<stdio.h>
#include<math.h>

#define epsilon 10e-6
#define f(x) ((x)*(x)*(x))+(4*(x)*(x))-10
#define g(x) ((10-(4*x*x))/(x*x))

int main(){
    int n= 100;
    double x0 = 1.5;
    double x1 = g(x0);

    for(int i=0;i<n;i++){
            if(fabs(x0)<epsilon){
        printf("%d");

    }else{
        x0=x1;
    }
    }


}