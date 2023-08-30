#include <iostream>
#include <cstring>
using namespace std;

#define MAX_LENGTH 100

int memo[MAX_LENGTH + 1][MAX_LENGTH + 1];
char b[MAX_LENGTH + 1][MAX_LENGTH + 1];

void printMemo(int m,int n){
    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            std::cout<<memo[i][j]<<"-"<<b[i][j]<<"\t";
        } std::cout<<std::endl;
    }
}
void printLCS(const std::string &X,int m,int n){
    if(m==0 || n==0){
        return;
    }
    if(b[m][n]=='D'){
        printLCS(X,m-1,n-1);
        std::cout<<X[m-1];
    }else if(b[m][n]=='U'){
        printLCS(X,m-1,n);
    }else{
        printLCS(X,m,n-1);
    }
}
int LCS_LENGTH_MEMO(const std::string &X, const std::string &Y, int i, int j) {
    if (i == 0 || j == 0) {
        return 0;
    }

    if (memo[i][j] != -1) {
        return memo[i][j];
    }

    if (X[i - 1] == Y[j - 1]) {
        memo[i][j] = LCS_LENGTH_MEMO(X, Y, i - 1, j - 1) + 1;
        b[i][j]='D';
        return memo[i][j];
    } else {
        int up = LCS_LENGTH_MEMO(X, Y, i - 1, j);
        int left = LCS_LENGTH_MEMO(X, Y, i, j - 1);

        //memo[i][j] = (left >= up) ? left : up;
        if(up>=left){
            memo[i][j]=up;
            b[i][j]='U';
        }else{
            memo[i][j]=left;
            b[i][j]='L';
        }
        return memo[i][j];
    }
}

void MEMOIZED_LCS(const std::string &X, const std::string &Y) {
    int m = X.length();
    int n = Y.length();
    //printf("%d %d",m,n);

    memset(memo, -1, sizeof(memo));

    int lcsLength = LCS_LENGTH_MEMO(X, Y, m, n);

    char b[MAX_LENGTH + 1][MAX_LENGTH + 1];
    // for (int i = 0; i <= m; i++) {
    //     for (int j = 0; j <= n; j++) {
    //         if (i == 0 || j == 0) {
    //             b[i][j] = ' ';
    //         } else if (X[i - 1] == Y[j - 1]) {
    //             b[i][j] = 'D';
    //         } else if (memo[i - 1][j] >= memo[i][j - 1]) {
    //             b[i][j] = 'U';
    //         } else {
    //             b[i][j] = 'L';
    //         }
    //     }
    // }

    // Print LCS length and b table
    std::cout << "LCS Length: " << lcsLength << std::endl;
    std::cout << "b Table:" << std::endl;
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            std::cout << b[i][j] << ' ';
        }
        std::cout << std::endl;
    }

   std::cout<<"Printing LCS table: "<<std::endl;
   printMemo(m,n);

    // std::string lcs = printLCS(X, m, n);
    // cout << "LCS: " << lcs << std::endl;
    std::cout<<"Printing LCS:"<<endl;
    printLCS(X,m,n);
    cout<<endl;
}

int main() {
    const string X = "ABCBDAB";
    const string Y = "BDCABA";

    MEMOIZED_LCS(X, Y);
    //std::cout<<" "<<printLCS(X,m,n)<<std::endl;


    return 0;
}
