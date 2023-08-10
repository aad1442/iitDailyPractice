#include<stdio.h>

int max(int a,int b){
    if(a>b)
        return a;
    return b;
}

int cutRodTopDown(int p[],int n){
    if(n==0)
        return 0;
    int q= -1;
    for(int i =1;i<=n;i++){
        q = max(q,p[i]+cutRod(p,n-i));
    }
    return q;
}
int memerizedCutRod(int p[],int n){
    int r[n];
    for(int i=0;i<n;i++){
        r[i]=-1;
    }
    return memerizedCutRodAux(p,n,r);
}
int memerizedCutRodAux(int p[],int n, int r[]){
    if(r[n]>=0)
        return r[n];
    int q;
    if(n==0)
        q=0;
    else{
        q= -1;
        for(int i=1;i<=n;i++){
            q = max(q,p[i]+memerizedCutRodAux(p,n-i,r));
        }
    }
    r[n]=q;
    return q;
    
}


int main(){

    int n,p[n];
    freopen("rod.txt","r",stdin);
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&p[i]);
    }
    for(int i=0;i<n;i++){
        printf("%d",p[i]);
    }
    
    int r[11];
    printf("%d\n",cutRodTopDown(p,4));
}