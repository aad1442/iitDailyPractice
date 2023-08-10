#include<stdio.h>
#include<math.h>

#define epsilon 10e-6
#define f(x) ((x)*(x)*(x))+(4*(x)*(x))-10
#define g(x) pow(((10 - ((x)*(x)*(x)))/4),.5)

/// @brief 
/// @return 
int main(){
    int n= 10000;
    double x0 = 1.5;
    double x1 = g(x0);

    for(int i=0;;i++){
        //printf("Adnan");
            if(fabs(x0)<epsilon){
        printf("   aaaa- \n%lf\n   ",x1);
        break;

    }else{
        x0=x1;
    }
    }

    return 0 ;


}