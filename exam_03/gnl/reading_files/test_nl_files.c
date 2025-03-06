#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

void replace_newline_with_br(const char *input_file) {
    FILE *file = fopen(input_file, "r");
    if (!file) {
        perror("Error opening file");
        return;
    }

    char buffer[BUFFER_SIZE];
    while (fgets(buffer, BUFFER_SIZE, file)) {
        // Replacing newline characters with "<br>"
        for (int i = 0; buffer[i] != '\0'; i++) {
            if (buffer[i] == '\n') {
                printf("<br>");
            } else {
                putchar(buffer[i]);
            }
        }
    }

    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    replace_newline_with_br(argv[1]);
    return 0;
}
