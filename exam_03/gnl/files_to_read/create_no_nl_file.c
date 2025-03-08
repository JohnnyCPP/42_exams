#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TEXT_LENGTH 20

void generate_random_text(char *text, size_t length) {
    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    for (size_t i = 0; i < length; i++) {
        text[i] = charset[rand() % (sizeof(charset) - 1)];
    }
    text[length] = '\0'; // Null-terminate the string
}

int main() {
    FILE *file;
    char random_text[TEXT_LENGTH + 1];

    // Seed the random number generator
    srand(time(NULL));

    // Generate random text
    generate_random_text(random_text, TEXT_LENGTH);

    // Create and open the file for writing
    file = fopen("./file_with_no_nl.txt", "w");
    if (!file) {
        perror("Error opening file");
        return 1;
    }

    // Write the random text to the file without a newline character at the end
    fwrite(random_text, sizeof(char), TEXT_LENGTH, file);

    // Close the file
    fclose(file);

    printf("File 'file_with_no_nl.txt' created with random text without a newline at the end.\n");

    return 0;
}
