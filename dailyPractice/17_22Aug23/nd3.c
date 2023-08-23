#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_STATES 10
#define MAX_ALPHABETS 10
#define MAX_TRANSITIONS 10

int stringIndexThrow(char states[MAX_STATES][MAX_STATES], const char *str, int stateCount) {
    for (int i = 0; i < stateCount; i++) {
        if (!strcmp(states[i], str)) {
            return i;
        }
    }
    strcpy(states[stateCount], str);
    return stateCount;
}

int main() {
    int nState, nAlphabets, nFinishStates;
    char startState;
    char states[MAX_STATES][MAX_STATES];
    char alphabets[MAX_ALPHABETS];
    char table[MAX_STATES][MAX_ALPHABETS][MAX_TRANSITIONS];
    char finishingStates[MAX_STATES];

    //--------------------------------------INPUT---------------------------------------
    printf("Enter number of states: ");
    scanf("%d", &nState);

    for (int i = 0; i < nState; i++) {
        printf("State %d: ", i + 1);
        scanf(" %s", states[i]);
    }

    printf("Enter number of alphabets: ");
    scanf("%d", &nAlphabets);

    for (int i = 0; i < nAlphabets; i++) {
        printf("Alphabet %d: ", i + 1);
        scanf(" %c", &alphabets[i]);
    }

    printf("Enter the state Transition Table:\n");
    for (int i = 0; i < nState; i++) {
        printf("State %s transitions:\n", states[i]);
        for (int j = 0; j < nAlphabets; j++) {
            printf("For Alphabet %c\n", alphabets[j]);
            scanf(" %s", table[i][j]);
        }
    }

    printf("Enter the start state: ");
    scanf(" %c", &startState);

    printf("How many finishing states do you have: ");
    scanf("%d", &nFinishStates);

    for (int i = 0; i < nFinishStates; i++) {
        printf("Finishing state %d: ", i + 1);
        scanf(" %c", &finishingStates[i]);
    }

    //--------------------------------------CONVERT TO DFA---------------------------------------
    char dfaStates[MAX_STATES][MAX_STATES]; // DFA states
    int dfaTransition[MAX_STATES][MAX_ALPHABETS]; // DFA transition table
    int dfaStateCount = 0;

    // Initialize the DFA state set with the epsilon closure of the NFA start state
    dfaStates[dfaStateCount][0] = startState;
    dfaStates[dfaStateCount][1] = '\0';
    dfaStateCount++;

    for (int i = 0; i < dfaStateCount; i++) {
        for (int j = 0; j < nAlphabets; j++) {
            int newStateCount = 0;
            char newStateSet[MAX_STATES][MAX_STATES];

            // Calculate the set of NFA states reachable through current alphabet symbol
            for (int k = 0; k < strlen(dfaStates[i]); k++) {
                int nfaStateIndex = stringIndexThrow(states, dfaStates[i] + k, nState); // Get index of NFA state
                char *transitions = table[nfaStateIndex][j];

                for (int l = 0; l < strlen(transitions); l++) {
                    char newState = transitions[l];
                    if (newState != '\0' && !strstr(dfaStates[i], newStateSet[newStateCount])) {
                        strcpy(newStateSet[newStateCount], newState);
                        newStateCount++;
                    }
                }
            }

            newStateSet[newStateCount][0] = '\0';

            if (newStateCount > 0) {
                strcpy(dfaStates[dfaStateCount], newStateSet);
                dfaTransition[i][j] = dfaStateCount;
                dfaStateCount++;
            } else {
                dfaTransition[i][j] = -1; // -1 represents a trap state (no transitions)
            }
        }
    }

    //--------------------------------------OUTPUT 2---------------------------------------

    printf("\nTransition Table for DFA\n");
    // header of the table
    printf("\t\t");
    for (int i = 0; i < nAlphabets; i++) {
        printf("%c\t\t", alphabets[i]);
    }
    printf("\n-----------------------------------------\n");

    // table info
    for (int i = 0; i < dfaStateCount; i++) {
        bool isStartState = (dfaStates[i][0] == startState);
        bool isFinishState = false;
        for (int j = 0; j < nFinishStates; j++) {
            if (strstr(dfaStates[i], finishingStates[j])) {
                isFinishState = true;
                break;
            }
        }

        if (isStartState)
            printf("->%s\t\t", dfaStates[i]);
        else {
            if (isFinishState)
                printf(" *%s\t\t", dfaStates[i]);
            else
                printf("  %s\t\t", dfaStates[i]);
        }

        for (int j = 0; j < nAlphabets; j++) {
            if (dfaTransition[i][j] != -1) {
                printf("%s\t\t", dfaStates[dfaTransition[i][j]]);
            } else {
                printf("-\t\t");
            }
        }

        printf("\n");
    }

    printf("\n");

    return 0;
}
