// C function to read the content from "data.txt"
#include <stdio.h>
#include <stdlib.h>

void readAndDisplayFileContent() {
    char buffer[101]; // Buffer to hold lines from the file (100 characters + null terminator)
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

    // Check for reading errors
    if (ferror(file)) {
        fprintf(stderr, "Error reading from file.\n");
        fclose(file);
        return;
    }

    // Close the file
    if (fclose(file) != 0) {
        fprintf(stderr, "Error closing the file.\n");
        return;
    }
}

int main() {
    readAndDisplayFileContent();
    return 0;
}
