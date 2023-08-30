#include <iostream>
#include <string.h>
using namespace std;
char arrow[100][100];
int dp[100][100];
string LCS;
int max(int a, int b)
{
    if (a >= b)
        return a;
    else
        return b;
}
int LCSmemoized(char X[], char Y[], int m, int n)
{

 
    // char arrow[m+1][n+1];
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            dp[i][j] = -1;
        }
    }
    if (m == 0 || n == 0)
    {

        return  0;
    }
    if(dp[m][n]!=-1) return dp[m][n];
    else if (X[m - 1] == Y[n - 1])
    {
        arrow[m][n] = 'd';
        return dp[m][n] = 1 + LCSmemoized(X, Y, m - 1, n - 1);
    }
    else
    {
        int store = max(LCSmemoized(X, Y, m - 1, n), LCSmemoized(X, Y, m, n - 1));
        if (store == LCSmemoized(X, Y, m - 1, n))
            arrow[m][n] = 'u';
        else
            arrow[m][n] = 'l';

        return dp[m][n] = max(LCSmemoized(X, Y, m - 1, n), LCSmemoized(X, Y, m, n - 1));
    }
    
}

/*for(int i=1;i<=m;i++){
    for(int j=1;j<=n;j++){
        if(X[i-1]==Y[j-1]){
            dp[i][j]=dp[i-1][j-1]+1;
        }
        else{
            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
}*/
void printLCS(char X[], int m, int n){
    if (m == 0 || n == 0)
    {

        return  ;
    }
    if(dp[m][n]=='d'){
        printLCS(X,m-1,n-1);
        cout<<X[m-1];
    }
    else if(dp[m][n]=='u'){
        printLCS(X,m-1,n);

    }
    else printLCS(X,m,n-1);
}
int main()
{
    char X[] = "abcbdab";
    char Y[] = "bdcaba";
    int m = strlen(X);
    int n = strlen(Y);
     //char arrow[m+1][n+1];
   
    cout << endl;

    cout << "LCS length: " << LCSmemoized(X, Y, m, n) << endl;
     for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            cout << arrow[i][j]<<"  ";
            
        } cout<<endl;
    }
    cout<<endl;
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            cout << dp[i][j]<<"  ";
            
        } cout<<endl;
    }
    printLCS(X,m,n);
     
}