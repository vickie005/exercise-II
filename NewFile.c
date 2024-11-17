// C function
#include <stdio.h>
#include <stdlib.h>

void writeSentenceToFile() {
    char sentence[101]; // Buffer for user input (100 characters + null terminator)
    FILE *file;

    // Prompt the user to enter a sentence
    printf("Enter a sentence (up to 100 characters): ");
    if (fgets(sentence, sizeof(sentence), stdin) == NULL) {
        fprintf(stderr, "Error reading input.\n");
        return;
    }

    // Open the file in write mode
    file = fopen("data.txt", "w");
    if (file == NULL) {
        perror("Error opening file for writing");
        return;
    }

    // Write the sentence to the file
    if (fprintf(file, "%s", sentence) < 0) {
        fprintf(stderr, "Error writing to file.\n");
        fclose(file);
        return;
    }

    // Close the file
    if (fclose(file) != 0) {
        fprintf(stderr, "Error closing the file.\n");
        return;
    }

    printf("Sentence written to data.txt successfully.\n");
}

int main() {
    writeSentenceToFile();
    return 0;
}
