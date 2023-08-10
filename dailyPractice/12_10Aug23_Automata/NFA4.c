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
    int *next_states_queue = malloc(MAX_STATES * MAX_STATES * sizeof(int));
int array[MAX_STATES*MAX_STATES];
int jj=0;
array[jj]=ps;
int kk=1;
int jj2=1,kk2=1;
for (int i = 0; i < strlength; i++) {
    while (jj<kk) {
        int current_state = array[jj];
        jj++;
        printf("Current state is: %d", current_state);
        for (k = 0; k < MAX_STATES; k++) {
            if (mat[current_state][str[i]][k] != -1) {
                printf("KK1 - %d, KK2- %d",kk,kk2);
                array[kk2]=mat[current_state][str[i]][k];
                kk2++;
            } else {
                break;
            }
        }
    }
    kk=kk2+1;
}

bool isAccepted = false;
for(int i=kk;i<kk2;i++){
    if(array[i]==fs){
        isAccepted = true;
    }
}

if (isAccepted) {
    printf("Accepted\n");
} else {
    printf("Rejected\n");
}


}
