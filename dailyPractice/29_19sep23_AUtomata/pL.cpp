#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;

// Function to check if a string is in L1 (0^n1^n)
// int isInLanguage1(char *str) {
//     int len = strlen(str) / 2;

//     for (int i = 0; i < len; i++) {
//         if (str[i] != '0' || str[i + len] != '1')
//             return 0;
//     }
//     return 1;
// }

// // Function to check if a string is in L2 (0^n1^2n)
// int isInLanguage2(char *str) {
//     int len = strlen(str) / 3;

//     for (int i = 0; i < len; i++) {
//         if (str[i] != '0' || str[i + 2 * len] != '1')
//             return 0;
//     }
//     return 1;
// }

int isLanguage(char *str, int p, int q){
    int l = strlen(str);
    int k=p+q;
    for(int i=0;i<(l/k)*p;i++){
        if(str[i]!='0'){
            return 0;
        }
    }
    for(int i=l/k*p +1 ;i<l;i++){
        if(str[i]!='1'){
            return 0;
        }
    }
    return 1;
}

void check(char *str, int n) {
    int len = strlen(str);
    string x = "", y = "", z = "";

    for (int i = 0; i < len / 2; i++) {
        x += str[i];
    }
    
    y = str[len / 2];

    for (int i = len / 2 + 1; i < len; i++) {
        z += str[i];
    }

    string test = "";

    for (int k = 0; k < 100; k++) {
        test = x;
        for (int j = 0; j < k; j++) {
            test += y;
        }
        test += z;

        if (n == 1) {
            if (!isInLanguage1((char *)test.c_str())) {
                printf("L1 is not regular.\n");
                break;
            }
        } else if (n == 2) {
            if (!isInLanguage2((char *)test.c_str())) {
                printf("L2 is not a regular language.\n");
                break;
            }
        }
    }
}

int main() {
    char input[1000];
    printf("Enter the string in the format 0^n1^n or 0^n1^2n: ");
    scanf("%s", input);
    int n;
    printf( "Check for language 1 or language 2: \n");
    scanf ("%d",&n);

    if (n == 1) {
        if (isInLanguage1(input)) {
            printf("The input string is in L1 (0^n1^n).\n");
            check(input, 1);
        } else {
            printf("The input string is not in L1 (0^n1^n).\n");
        }
    } else if (n == 2) {
        if (isInLanguage2(input)) {
            printf("The input string is in L2 (0^n1^2n).\n");
            check(input, 2);
        } else {
            printf("The input string is not in L2 (0^n1^2n).\n");
        }
    } else {
        printf("Invalid input format.\n");
    }

    return 0;
}
