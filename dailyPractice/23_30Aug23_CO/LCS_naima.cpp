#include <stdio.h>
#include <string.h>

// Maximum length of strings
#define MAX_LENGTH 100

// Memoization table
int memo[MAX_LENGTH + 1][MAX_LENGTH + 1];

// Function to calculate LCS using memoization
int lcs_memo(char *X, char *Y, int m, int n) {
    if (memo[m][n] != -1)
        return memo[m][n];

    if (m == 0 || n == 0)
        return memo[m][n] = 0;

    if (X[m - 1] == Y[n - 1])
        return memo[m][n] = 1 + lcs_memo(X, Y, m - 1, n - 1);
    else
        return memo[m][n] = max(lcs_memo(X, Y, m - 1, n), lcs_memo(X, Y, m, n - 1));
}

// Utility function to find maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    char X[MAX_LENGTH], Y[MAX_LENGTH];

    printf("Enter the first string: ");
    scanf("%s", X);

    printf("Enter the second string: ");
    scanf("%s", Y);

    int m = strlen(X);
    int n = strlen(Y);

    // Initialize memoization table with -1
    memset(memo, -1, sizeof(memo));

    int length = lcs_memo(X, Y, m, n);
    printf("Length of LCS: %d\n", length);

    return 0;
}
