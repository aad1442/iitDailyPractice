#include <stdio.h>
#include <stdbool.h>

#define MAX_STATES 10
#define MAX_ALPHABET 10

int main() {
    int n, m;
    int i, j, k;
    char psc, fsc;
    int ps, fs;

    printf("Enter the number of states: ");
    scanf("%d", &n);
    char state[n];
    for (i = 0; i < n; i++) {
        scanf(" %c", &state[i]);
    }
    for (i = 0; i < n; i++) {
        printf("state %c\n", state[i]);
    }

    printf("Enter the number of alphabet: ");
    scanf("%d", &m);
    int alphabet[m];
    for (i = 0; i < m; i++) {
        scanf("%d", &alphabet[i]);
    }
    for (i = 0; i < m; i++) {
        printf("Alphabet:%d\n", alphabet[i]);
    }

    int mat[MAX_STATES][MAX_ALPHABET][MAX_STATES];
    

// Initialize mat array to -1
for (i = 0; i < MAX_STATES; i++) {
    for (j = 0; j < MAX_ALPHABET; j++) {
        for (k = 0; k < MAX_STATES; k++) {
            mat[i][j][k] = -1;
        }
    }
}

    printf("Enter the starting state: ");
    scanf(" %c", &psc);
    printf("Enter the final state: ");
    scanf(" %c", &fsc);
    for (i = 0; i < n; i++) {
        if (psc == state[i]) {
            ps = i;
        }
        if (fsc == state[i]) {
            fs = i;
        }
    }
    printf("present state = %d, final state = %d\n", ps, fs);

    printf("Enter the transition table:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            printf("For state %c and alphabet %d, Enter the number of states in the transition (0-10): ", state[i], alphabet[j]);
            int num_states;
            scanf("%d", &num_states);
            for (k = 0; k < num_states; k++) {
                printf("Enter the value of mat[%d][%d][%d]: ", i, j, k);
                scanf("%d", &mat[i][j][k]);
            }
        }
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            printf("For state %c and alphabet %d, Transition states: ", state[i], alphabet[j]);
            int num_states;
            for (k = 0; k < MAX_STATES; k++) {
                if (mat[i][j][k] != -1) {
                    printf("%d ", mat[i][j][k]);
                }
                else {
                    break;
                }
            }
            printf("\n");
        }
    }

    int strlength;
    printf("Enter the string length: ");
    scanf("%d", &strlength);
    int str[strlength];
    for (i = 0; i < strlength; i++) {
        scanf("%d", &str[i]);
    }

    for (i = 0; i < strlength; i++) {
        printf("\n%d\n", str[i]);
    }

    for (i = 0; i < strlength; i++) {
        int next_states[MAX_STATES];
        int num_next_states = 0;
        for (k = 0; k < MAX_STATES; k++) {
            if (mat[ps][str[i]][k] != -1) {
                next_states[num_next_states++] = mat[ps][str[i]][k];
            }
            else {
                break;
            }
        }

        // Follow all possible transitions and update the current state
        for (j = 0; j < num_next_states; j++) {
            ps = next_states[j];
            printf("Now present state is %d\n", ps);
        }
    }

    if (ps == fs) {
        printf("Accepted\n");
    }
    else {
        printf("Rejected\n");
    }

    return 0;
}