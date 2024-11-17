// modified program to write a second sentence
#include <stdio.h>
#include <stdlib.h>

// Function to append a sentence to the file
void appendSentenceToFile() {
    char sentence[101]; // Buffer for the user input
    FILE *file;

    // Prompt the user to enter a sentence
    printf("Enter a sentence to append (up to 100 characters): ");
    if (fgets(sentence, sizeof(sentence), stdin) == NULL) {
        fprintf(stderr, "Error reading input.\n");
        return;
    }

    // Open the file in append mode
    file = fopen("data.txt", "a");
    if (file == NULL) {
        perror("Error opening file for appending");
        return;
    }

    // Write the new sentence to the file
    if (fprintf(file, "%s", sentence) < 0) {
        fprintf(stderr, "Error writing to file.\n");
        fclose(file); // Close the file before returning
        return;
    }

    // Close the file
    if (fclose(file) != 0) {
        fprintf(stderr, "Error closing file after appending.\n");
        return;
    }

    printf("Sentence appended to data.txt successfully.\n");
}

// Function to read and display the file content
void readAndDisplayFileContent() {
    char buffer[101]; // Buffer to hold lines from the file
    FILE *file;

    // Open the file for reading
    file = fopen("data.txt", "r");
    if (file == NULL) {
        perror("Error opening file for reading");
        return;
    }

    // Read and display the content of the file
    printf("Content of data.txt:\n");
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        printf("%s", buffer); // Print each line read from the file
    }

    // Check for errors during reading
    if (ferror(file)) {
        fprintf(stderr, "Error reading from file.\n");
        fclose(file); // Close the file before returning
        return;
    }

    // Close the file
    if (fclose(file) != 0) {
        fprintf(stderr, "Error closing file after reading.\n");
        return;
    }
}

// Main function
int main() {
    // Append a sentence to the file
    appendSentenceToFile();

    // Read and display the updated file content
    readAndDisplayFileContent();

    return 0;
}
