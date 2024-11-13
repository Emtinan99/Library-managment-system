#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERNAME_LENGTH 100
#define MAX_LINE_LENGTH 256

void book_recommendation_main(char *username) {
    FILE *file;
    char line[MAX_LINE_LENGTH];
    int found = 0;

    // Open the book recommendations file
    file = fopen("book_recomendation.txt", "r"); // Corrected filename
    if (file == NULL) {
        printf("Error opening book recommendation file.\n");
        return;
    }

    printf("Based on your borrowing preference and history, recommended books for %s are:\n", username);

    // Read the file line by line
    while (fgets(line, sizeof(line), file) != NULL) {
        // Remove newline character from the line
        line[strcspn(line, "\n")] = 0;

        // Check if the line matches the username
        if (strcmp(line, username) == 0) {
            found = 1; // User found
            printf("\nRecommendations:\n");

            // Read and print book recommendations until a blank line or end of file
            while (fgets(line, sizeof(line), file) != NULL) {
                // Remove newline character from the line
                line[strcspn(line, "\n")] = 0;

                // Break if a blank line is encountered
                if (line[0] == '\0') {
                    break;
                }

                // Print the book details directly
                printf("%s\n", line);
            }
            break; // Exit after reading recommendations for the user
        }
    }

    if (!found) {
        printf("No recommendations found for %s.\n", username);
    }

    fclose(file);
}
