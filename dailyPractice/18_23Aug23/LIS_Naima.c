#include<stdio.h>

void printLIS(int a[],  int prev[], int i){
    if(i == -1){
        return;
    }
    printLIS(a,prev,prev[i]);
    printf("%d ",a[i]);
}

int LISFDP(int a[], int n){
    int L[n], LP[n], prev[n];
    L[0] = -112998873;
    LP[0] = -1;
    prev[0] = -1;
    int length =1;
    for(int i=1; i<=n; i++){
        if(L[length-1] <a[i]){
            L[length] = a[i];
            LP[length] = i;
            prev[i] = LP[length-1];
            length++;
        }
        else{
            int s, h, m;
            s =0, h=length;
            while(s<h){
                m = (s+h)/2;
                if(L[m]<a[i]){
                    s = m+1;
                }
                else{
                    h = m;
                }
            }
            L[s] = a[i];
            LP[s] = i;
            prev[i] = LP[s-1];
        }
    }
    printf("Element of prev: ");
    for(int i=0; i<n; i++){
        printf("%d ",prev[i]);
    }
    printf("\n");
    /*int maxIndex=0;
    for (int i = 1; i < n; i++) {
        if (LP[i] > LP[maxIndex]) {
            maxIndex = i;
        }
    }*/
    //for(int i=0; i<10; i++){
        //printf("%d ", LP[i]);
    //}
    printf("Sequence:");
    printLIS(a,prev,9);
    int maxLength = 0;
    for (int i = 0; i < n; i++) {
        if (LP[i] >= 0 && LP[i]<=10) {
            maxLength++;
        }
    }
    return maxLength;
}
int main(void){
    int a[] = {0,2,5,3,6,1,2,10,7,9 };
    int n = sizeof(a) / sizeof(a[0]);
    int maxlen = printf("\nMax length:%d\n",LISFDP(a, n));
    return 0;
}