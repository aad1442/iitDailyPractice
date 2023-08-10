#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_STATES 10
#define MAX_ALPHABET 10

void enqueue(int *queue, int *rear, int value) {
    queue[(*rear)++] = value;
}

// Function to dequeue an element from the queue
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
        int *next_states_queue = malloc(MAX_STATES * sizeof(int));
        int f1 = 0;
        int r1 = 0;
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

        free(next_states_queue);
    }

    // Enqueue the final states
    int *final_states_queue = malloc(MAX_STATES * sizeof(int));
    int f2 = 0;
    int r2 = 0;
    enqueue(final_states_queue, &r2, fs);

    // Collect all possible final states
    while (f2 != r2) {
        int current_state = dequeue(final_states_queue, &f2);

        for (k = 0; k < MAX_STATES; k++) {
            if (mat[current_state][0][k] != -1) {  // Assuming alphabet 0 represents epsilon transitions
                enqueue(final_states_queue, &r2, mat[current_state][0][k]);
            } else {
                break;
            }
        }
    }

    // Check if any of the final states match the accepting state
    bool isAccepted = false;
    for (i = 0; i < r2; i++) {
        if (final_states_queue[i] == fs) {
            isAccepted = true;
            break;
        }
    }

    if (isAccepted) {
        printf("Accepted\n");
    } else {
        printf("Rejected\n");
    }

    free(final_states_queue);

    return 0;
}
