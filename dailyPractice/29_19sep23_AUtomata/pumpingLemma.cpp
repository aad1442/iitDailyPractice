#include <stdio.h>
#include <string.h>

// Function to check if a string is in L1 (0^n1^n)
// int isInLanguage1(char *str) {
//     int len = strlen(str);
//     int n = len / 2;
    
//     for (int i = 0; i < n; i++) {
//         if (str[i] != '0' || str[i + n] != '1') {
//             return 0;
//         }
//     }
    
//     return 1;
// }

// // Function to check if a string is in L2 (0^n1^2n)
// int isInLanguage2(char *str) {
//     int len = strlen(str);
//     int n = len / 3;
    
//     for (int i = 0; i < n; i++) {
//         if (str[i] != '0' || str[i + 2 * n] != '1') {
//             return 0;
//         }
//     }
    
//     return 1;
// }

int isInLanguage(char *str, int p, int q) {
    int len = strlen(str) / (p + q);

    for (int i = 0; i < len; i++) {
        for (int j = 0; j < p; j++) {
            if (str[i * (p + q) + j] != '0') {
                return 0;
            }
        }
        for (int j = 0; j < q; j++) {
            if (str[i * (p + q) + p + j] != '1') {
                return 0;
            }
        }
    }
    return 1;
}


// Function to generate xy^kz and check if it's in the language
int generateAndCheck(char *str, int n) {
    int len = strlen(str);
    char xykz[1000];
    int flag = 0;
    
    for (int k = 0; k <= n; k++) {
        int xyLen = len + k;
        
        for (int i = 0; i < len; i++) {
            xykz[i] = str[i];
        }
        
        for (int i = len; i < xyLen; i++) {
            xykz[i] = str[i - len];
        }
        
        xykz[xyLen] = '\0';
        
        if (n == 1) {
            if (isInLanguage1(xykz)) {
                flag = 1;
                break;
            }
        } else if (n == 2) {
            if (isInLanguage2(xykz)) {
                flag = 1;
                break;
            }
        }
    }
    
    return flag;
}

int main() {
    char input[1000];
    printf("Enter the string in the format 0^n1^n or 0^n1^2n: ");
    scanf("%s", input);
    
    int len = strlen(input);
    int n = len / 2;
    
    if (n == 1) {
        if (isInLanguage1(input)) {
            printf("The input string is in L1 (0^n1^n).\n");
        } else {
            printf("The input string is not in L1 (0^n1^n).\n");
        }
    } else if (n == 2) {
        if (isInLanguage2(input)) {
            printf("The input string is in L2 (0^n1^2n).\n");
        } else {
            printf("The input string is not in L2 (0^n1^2n).\n");
        }
    } else {
        printf("Invalid input format.\n");
    }
    
    return 0;
}
