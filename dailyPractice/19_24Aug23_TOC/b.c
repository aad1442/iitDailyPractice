#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

void identify_comments(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    char line[MAX_LINE_LENGTH];
    bool in_multi_line_comment = false;
    int line_number = 1;

    while (fgets(line, sizeof(line), file)) {
        // Check for multi-line comments
        if (in_multi_line_comment) {
            char *end_comment = strstr(line, "*/");
            if (end_comment) {
                in_multi_line_comment = false;
                printf("%d: %.*s\n", line_number, (int)(end_comment - line), line);
            }
        } else {
            char *single_line_comment = strstr(line, "//");
            char *start_multi_line_comment = strstr(line, "/*");
            char *end_multi_line_comment = strstr(line, "*/");

            if (single_line_comment) {
                printf("%d: %s\n", line_number, single_line_comment);
            }

            if (start_multi_line_comment) {
                if (end_multi_line_comment) {
                    printf("%d: %.*s\n", line_number, (int)(end_multi_line_comment - start_multi_line_comment + 2), start_multi_line_comment);
                } else {
                    in_multi_line_comment = true;
                    printf("%d: %s\n", line_number, start_multi_line_comment);
                }
            }
        }
        
        line_number++;
    }

    fclose(file);
}

int main() {
    const char *filename = "test_code.c"; // Replace with your file name
    identify_comments(filename);
    return 0;
}
