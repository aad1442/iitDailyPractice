#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_STATES 10
#define MAX_ALPHABET 10

void enqueue(int *queue, int *rear, int value) {
    queue[(*rear)++] = value;
}

int dequeue(int *queue, int *front) {
    return queue[(*front)++];
}

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

    printf("Enter the number of alphabet: ");
    scanf("%d", &m);
    int alphabet[m];
    for (i = 0; i < m; i++) {
        scanf("%d", &alphabet[i]);
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

    int strlength;
    printf("Enter the string length: ");
    scanf("%d", &strlength);
    char str[strlength];
    for (i = 0; i < strlength; i++) {
        scanf(" %c", &str[i]);
    }

    int *next_states_queue = malloc(MAX_STATES * sizeof(int));
    int f1, r1;
    
    bool isAccepted = false;
    for (i = 0; i < strlength; i++) {
        f1 = r1 = 0;
        enqueue(next_states_queue, &r1, ps);

        while (f1 != r1) {
            int current_state = dequeue(next_states_queue, &f1);

            for (k = 0; k < MAX_STATES; k++) {
                if (mat[current_state][str[i]][k] != -1) {
                    enqueue(next_states_queue, &r1, mat[current_state][str[i]][k]);
                } else {
                    break;
                }
            }
        }

        while (f1 != r1) {
            if (dequeue(next_states_queue, &f1) == fs) {
                isAccepted = true;
                break;
            }
        }
    }

    if (isAccepted) {
        printf("Rejected\n");
    } else {
        printf("Accepted\n");
    }

    free(next_states_queue);

    return 0;
}
