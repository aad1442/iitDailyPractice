#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_STATES 10
#define MAX_ALPHABETS 10
#define MAX_TRANSITIONS 10


    int nState, nAlphabets, nFinishStates;
    char startState;
    char states[MAX_STATES];
    char alphabets[MAX_ALPHABETS];
    char table[MAX_STATES][MAX_ALPHABETS][MAX_TRANSITIONS];
    char finishingStates[MAX_STATES];

int dtable[MAX_STATES][MAX_ALPHABETS];
char dstates[MAX_STATES][MAX_STATES];
int array[MAX_ALPHABETS];


void substates(char *str){
    for(int i=0;i<MAX_ALPHABETS;i++){
        array[i]=-1;
    }
    int k=0;
    for(int i=0;i<nState;i++){
        if(isSubstring(str,states[i])){
            array[k]=i;
            k++;
        }

    }
}



int stringIndexThrow(const char *str) {
    int i;
    for (i = 0; i < 10 && dstates[i][0] != '\0'; i++) {
        if (!strcmp(dstates[i], str)) {
            return i;
        }
    }
    strcpy(dstates[i], str);
    return i;
}


bool isSubstring(const char *bigString, const char *smallString) {
    int bigLen = strlen(bigString);
    int smallLen = strlen(smallString);

    for (int i = 0; i <= bigLen - smallLen; i++) {
        bool found = true;
        for (int j = 0; j < smallLen; j++) {
            if (bigString[i + j] != smallString[j]) {
                found = false;
                break;
            }
        }
        if (found) {
            return true;
        }
    }
    return false;
}

int main() {
    freopen("nd.txt","r",stdin);
    int nState, nAlphabets, nFinishStates;
    char startState;
    char states[MAX_STATES];
    char alphabets[MAX_ALPHABETS];
    char table[MAX_STATES][MAX_ALPHABETS][MAX_TRANSITIONS];
    char finishingStates[MAX_STATES];

    //--------------------------------------INPUT---------------------------------------
    printf("Enter number of states: ");
    scanf("%d", &nState);

    for (int i = 0; i < nState; i++) {
        printf("State %d: ", i + 1);
        scanf(" %c", &states[i]);
    }

    printf("Enter number of alphabets: ");
    scanf("%d", &nAlphabets);

    for (int i = 0; i < nAlphabets; i++) {
        printf("Alphabet %d: ", i + 1);
        scanf(" %c", &alphabets[i]);
    }

    printf("Enter the state Transition Table:\n");
    for (int i = 0; i < nState; i++) {
        printf("State %c transitions:\n", states[i]);
        for (int j = 0; j < nAlphabets; j++) {
            printf("For Alphabet %c\n", alphabets[j]);
            scanf(" %c", &table[i][j][0]); // First transition state
            if (table[i][j][0] == 'x') {
                table[i][j][0] = '\0'; // Empty transition
            } else {
                int k = 1;
                while (true) {
                    char next_state;
                    scanf(" %c", &next_state);
                    if (next_state == 'x') {
                        break;
                    }
                    table[i][j][k++] = next_state;
                }
                table[i][j][k] = '\0';
            }
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

    //--------------------------------------OUTPUT 1---------------------------------------

printf("\nTransition Table for NFA\n");
    // header of the table
    printf("\t\t");
    for (int i = 0; i < nAlphabets; i++)
    {
        printf("%c\t\t", alphabets[i]);
    }
    printf("\n-----------------------------------------\n");

    // table info
    for (int i = 0; i < nState; i++)
    {
        bool isStartState = (states[i] == startState);
        bool isFinishState = false;
        for (int j = 0; j < nFinishStates; j++)
        {
            if (states[i] == finishingStates[j])
            {
                isFinishState = true;
                break;
            }
        }

        if (isStartState)
            printf("->%c\t\t", states[i]);
        else
        {
            if (isFinishState)
                printf(" *%c\t\t", states[i]);
            else
                printf("  %c\t\t", states[i]);
        }

        for (int j = 0; j < nAlphabets; j++)
        {
            // Check if the transition has multiple states
            if (strlen(table[i][j]) > 0)
            {
                printf("{%s}\t\t", table[i][j]);
            }
            else
            {
                printf("-\t\t"); // No transition
            }
        }

        printf("\n");
    }

    printf("\n\n");


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
                    if (newState != '\0' && !isSubstring(dfaStates[i], newStateSet[newStateCount])) {
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
            if (isSubstring(dfaStates[i], finishingStates[j])) {
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