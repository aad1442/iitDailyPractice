#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define epsilon 10.0e-6
#define f(x) ((x)*(x)*(x)+4*(x)*(x)-10)

int main(){
  int n=100,i;
  //printf("a");
  double x0=1.25,x1=2,x2;
  if(f(x0)*f(x1)>0){ 
    printf("no root");
  exit(0);
  }
  printf("i     a     b     c     f(a)     f(b)     f(c)\n");
  for(i=0;i<n;i++){
     x2 = x1 - f(x1 )*(x1 - x0 )/( f(x1 ) - f(x0 ) );
    
 
  if(fabs(f(x2)) < epsilon){
  printf("Root : %lf\n",x2                            );
  break;
  }
  printf("%d %0.5lf %0.5lf %.5lf %.5lf %.5lf %.5lf\n ",i,x0,x1,x2,f(x0),f(x1),f(x2));
  x0=x1,x1=x2;
  
}
}