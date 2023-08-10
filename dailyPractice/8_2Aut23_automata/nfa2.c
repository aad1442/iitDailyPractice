#include <stdio.h>
#include <stdbool.h>

#define Q0 0
#define Q1 1
#define Q2 2
// NFA transition function
int transition(int state, char input) {
    switch (state) {
        case Q0:
            return (input == '0') ? Q0 : ((input == '1') ? Q1 : Q0);
        case Q1:
            return (input == '1') ? Q2 : ((input == '0') ? Q0 : Q0);
        case Q2:
            return Q2;
    }
    return Q0;
}

// NFA simulation function
bool simulateNFA(const char* input) {
    int currentState = Q0;

    while (*input != '\0') {
        currentState = transition(currentState, *input);
        input++;
    }

    return currentState == Q2;
}

int main() {
    char input[100];
    printf("Enter a string: ");
    scanf("%s", input);

    if (simulateNFA(input)) {
        printf("String ends with '01'.\n");
    } else {
        printf("String does not end with '01'.\n");
    }

    return 0;
}
