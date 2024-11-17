#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256
#define ACCOUNT_HISTORY_FILE "accounthistory.txt"

// Function to search for a user's borrowing history
void account_management(const char *username) {
    FILE *file = fopen(ACCOUNT_HISTORY_FILE, "r+");
    if (file == NULL) {
        perror("Error opening account history file");
        return;
    }

    char line[MAX_LINE_LENGTH];
    int found = 0;
    float overdueFees = 0.0; // Variable to store overdue fees
    long position = 0; // To store the position of the line to update

    // Read each line from the account history file
    while (fgets(line, sizeof(line), file)) {
        // Check if the line contains the username
        if (strstr(line, username) != NULL) {
            found = 1;
            printf("Account History for %s:\n", username);

            // Replace commas with newlines for better formatting
            char *token = strtok(line, ",");
            while (token != NULL) {
                printf("%s\n", token);

                // Check if the token contains overdue fees
                if (strstr(token, "Overdue Fees:") != NULL) {
                    // Extract the overdue fees
                    sscanf(token, " Overdue Fees: %f", &overdueFees);
                }

                token = strtok(NULL, ",");
            }

            // Check if there are overdue fees
            if (overdueFees > 0.0) {
                char choice;
                printf("You have overdue fees of %.2f. Do you want to pay? (y/n): ", overdueFees);
                scanf(" %c", &choice); // Read user input

                if (choice == 'y' || choice == 'Y') {
                    printf("You have paid the overdue fees of %.2f.\n", overdueFees);
                    // Update the line to set overdue fees to 0.00
                    snprintf(line, sizeof(line), "%s, Overdue Fees: 0.00\n", username);
                    // Move the file pointer back to the position of the line to update
                    fseek(file, position, SEEK_SET);
                    // Write the updated line back to the file
                    fputs(line, file);
                } else {
                    printf("You chose not to pay the overdue fees.\n");
                }
            }
            break; // Exit after finding the first match
        }
        position = ftell(file); // Store the current position for potential update
    }

    if (!found) {
        printf("No account history found for username: %s\n", username);
    }

    fclose(file);
}
