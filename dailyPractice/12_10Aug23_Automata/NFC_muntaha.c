#include <stdio.h>
#include <stdlib.h>

int main() {
    int num_of_stage, num_of_input, present_state, final_state, input[10], len = 0;
    printf("Enter stage number & number of input ");
    scanf("%d %d", &num_of_stage, &num_of_input);
    char stage[num_of_stage];
    for (int i = 0; i < num_of_stage; i++) {
        printf("Enter stages: ");
        scanf(" %c", &stage[i]);
    }
    int input_alpha[num_of_input];
    for (int j = 0; j < num_of_input; j++) {
        printf("Enter input alphabet ");
        scanf("%d", &input_alpha[j]);
    }

    printf("Enter input string (-1 to stop): ");
    for (int i = 0; i < 10; i++) {
        scanf("%d", &input[i]);
        len++;
        if (input[i] == -1) break;
    }
    char p_state, f_state;
    printf("Enter present & final state: ");
    scanf(" %c %c", &p_state, &f_state);
    
    int present_state_index = -1;
    int final_state_index = -1;
    
    // Find the indices of present and final states in the stage array
    for (int i = 0; i < num_of_stage; i++) {
        if (p_state == stage[i]) present_state_index = i;
        if (f_state == stage[i]) final_state_index = i;
    }
    
    if (present_state_index == -1 || final_state_index == -1) {
        printf("Invalid present or final state.\n");
        return 1;
    }
    
    // Initialize transition matrix
    int arr[2][num_of_stage][num_of_stage];
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < num_of_stage; j++) {
            printf("For input %d stage %c goes to num of stages: ", i, stage[j]);
            int stage_goes;
            scanf("%d", &stage_goes);
            for (int k = 0; k < stage_goes; k++) {
                printf("\nStage: ");
                scanf("%d", &arr[i][j][k]);
                if (arr[i][j][k] == 0) arr[i][j][k] = -1;
            }
        }
    }

    // NFA simulation
    int current_state = present_state_index;
    for (int x = 0; x < len - 1; x++) {
        int check = input[x];
        int next_state = -1;

        // Find the next state based on current state and input
        for (int i = 0; i < num_of_stage; i++) {
            if (arr[check][current_state][i] != -1) {
                next_state = arr[check][current_state][i];
                break;
            }
        }

        if (next_state == -1) {
            printf("No transition found for input %d in state %c\n", input_alpha[check], stage[current_state]);
            return 1;
        }

        current_state = next_state;
        printf("Updated state: %c\n", stage[current_state]);

        if (current_state == final_state_index) {
            printf("Accepted\n");
            break;
        }
    }

    if (current_state != final_state_index) {
        printf("Rejected\n");
    }

    return 0;
}