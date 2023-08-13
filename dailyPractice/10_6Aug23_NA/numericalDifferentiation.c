#include<stdio.h>

#define f(x) ((x)*(x)+1)

void numericalDifferentiation(double a, double b, int n){
    double h = (b-a)/n;
    double x[n+1];
    x[0]=a;
    x[n]=b;
    for(int i=1;i<n;i++){
        x[i]=x[i-1]+h;
    }
    double y[n+1];
    for(int i=0;i<=n;i++){
        y[i]= f(x[i]);
    }

    double fp[n+1];

    for(int i=0;i<=n;i++){
        if()
    }
}

int main(){
    int n;
    double a,b;
    sacnf("%lf %lf %d",&a,&b,&n);
}