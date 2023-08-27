#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

// Function to identify and print comments in a C file
void identify_comments(const char *filename) {
    // Open the file for reading
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file"); // Print error message if the file can't be opened
        exit(EXIT_FAILURE); // Exit the program with an error code
    }

    char line[MAX_LINE_LENGTH];
    bool in_multi_line_comment = false; // Tracks if we're inside a multi-line comment
    int line_number = 1; // Tracks the current line number

    // Read each line from the file
    while (fgets(line, sizeof(line), file)) {
        // Check if we're inside a multi-line comment
        if (in_multi_line_comment) {
            // Check if the current line contains the end of a multi-line comment
            char *end_comment = strstr(line, "*/");
            if (end_comment) {
                in_multi_line_comment = false; // Mark that we've exited the multi-line comment
                // Print the multi-line comment content along with the line number
                printf("%d: Multi-line comment: %.*s\n", line_number, (int)(end_comment - line), line);
            }
        } else {
            // Check for single-line comment and multi-line comment indicators
            char *single_line_comment = strstr(line, "//");
            char *start_multi_line_comment = strstr(line, "/*");
            char *end_multi_line_comment = strstr(line, "*/");

            // Handle single-line comments
            if (single_line_comment) {
                // Print the single-line comment along with the line number
                printf("%d: Single-line comment: %s\n", line_number, single_line_comment);
            }

            // Handle multi-line comments
            if (start_multi_line_comment) {
                if (end_multi_line_comment) {
                    // Print the multi-line comment along with the line number
                    printf("%d: Multi-line comment: %.*s\n", line_number, (int)(end_multi_line_comment - start_multi_line_comment + 2), start_multi_line_comment);
                } else {
                    in_multi_line_comment = true; // Mark that we're inside a multi-line comment
                    // Print the multi-line comment start along with the line number
                    printf("%d: Multi-line comment: %s\n", line_number, start_multi_line_comment);
                }
            }
        }

        line_number++; // Move to the next line
    }

    fclose(file); // Close the file
}

int main() {
    const char *filename = "test_code.c"; // Replace with your file name
    identify_comments(filename); // Call the function to identify comments
    return 0; // Exit the program
}
