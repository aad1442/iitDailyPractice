#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define epsilon 10e-6
#define f(x) (x*x*x +4*x*x -10)

int main(){
    double a=1.25,b=1.5,c;
    int n=100;
    
    if(f(a)*f(b)>0){
    	printf("No root");
        exit(0);
	}
    for(int i=0;i<n;i++){
        //c=(a*f(b) - b*f(a))-(f(b)-f(a));
        c= b-(f(b)*(b-a))/(f(b)-f(a));
        if(fabs(f(c))<epsilon){
            printf("Root = %lf\n",c);
            exit(0);
        }
        printf(" %d  %lf %lf %lf %lf %lf %lf\n",i, a,b,c,f(a),f(b),f(c));
        if(f(a)*f(c)<0)b=c;
        else a=c;
    }
}
