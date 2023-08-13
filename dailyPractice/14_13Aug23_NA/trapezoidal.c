#include<stdio.h>

#define f(x) (((x)*(x))+1)



double trapezoidal(double a,double b ,int n){
    double h=(b-a)/n;
    double x[n+1],y[n+1];
    double sumX=0.0,sumI=0.0;
    for(int i=0;i<n;i++){
        x[i]=a+h*i;
    }
    x[n]=b;
    for(int i=0;i<=n;i++){
        y[i]=f(x[i]);
    }
    for(int i=1;i<n;i++){
        sumI +=y[i];
    }
    for(int i=0;i<=n;i++){
        printf("%lf %lf\n",x[i],y[i]);
    }
    sumX = y[0]+y[n];
    printf("%lf, %lf",sumX,sumI);
    double I = h*(2*sumI+sumX)/2;
    return I;

}

int main(){
    double a,b;
    int n;
    scanf("%lf%lf%d",&a,&b,&n);
    printf("%lf ,%lf, %d\n",a,b,n);
    printf("\nIntegral Value: %lf\n",trapezoidal(a,b,n));
}