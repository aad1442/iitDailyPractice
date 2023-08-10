#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 256

int main() {
    time_t t;
    srand((unsigned) time(&t));

    const char* digits = "0123456789ABCDEF";

    unsigned char str_len = rand() % MAX_SIZE;


    char* str = malloc((str_len + 1) * sizeof(char));
    if (str == NULL) {
        fprintf(stderr, "malloc failed\n");
        return -1;
    }

    char* init_ptr = str;
    char tmp_char;

    for (int i = 0; i < str_len; i++) {
        if (i == 0) {
            do {
                tmp_char = *(digits + (rand() % 16));
            } while (tmp_char == '0');
        }
        *str = tmp_char;
        tmp_char = *(digits + (rand() % 16));
        str++;
    }

    *str = '\0';

    printf("%s", init_ptr);
    free(init_ptr);

    return 0;
}
