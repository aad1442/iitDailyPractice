#include<iostream>
#include<stdlib.h>

using namespace std;


bool isLanguage(string word, int p, int q) {
    int l0 = 0;
    while (l0 < word.length() && word[l0] == '0') {
        l0++;
    }
    
    int l1 = 0;
    while (l0 + l1 < word.length() && word[l0 + l1] == '1') {
        l1++;
    }
    
    int n = l0 / p;
    
    return (q * n == l1);
}


void LanguageCheck(int p, int q){
    int n = 3+rand()%7;
    string w,wx,wy,wz,wp,x,y,z;
    int xl,yl,zl;
    w=wx=wy=wz=wp=x=y=z="";
    for(int i=0;i<p;i++){
        w +="0";
    }
    for(int i=0;i<q;i++){
        w += "1";
    }
    //rand() % (ub - lb + 1)) + lb
    yl = (rand() % (n - 1 + 1)) + 1;
    xl = n - yl ;
    zl = w.size() -xl -yl;

    int i,j,k;
    i=j=k=0;
    for(i=0;i<xl;i++){
        wx[i] += w[i];
    }
    for(i,j;j<yl;i++,j++){
        wy[j] += w[i];
    }
    for(i,k;k<zl;i++,k++){
        wz[k] += w[i];
    }

    for(int i=0;i<100;i++){
        wp = wx;
        for(int j=0;j<i;j++){
            wp += wy;
        }
        wp += wz;
        
    }

    



}

int main(){
    string input;
    int p,q;
    cout<<"Enter a the string:(0^n 1^n or 0^n 1^2n) ";
    cin

    if(input =="0^n1^n"){
        p=q=1;
    }else{
        p=1;
        q=2;
    }

    LanguageCheck(p,q);
}