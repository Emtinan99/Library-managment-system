#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 100
#define USERNAME_LEN 50
#define PASSWORD_LEN 50
#define MAX_GENRE_LENGTH 50

void account_management(char *username); // Corrected function declaration
void book_search_main();
void book_recommendation_main(username);
void digital_library_access();

void member_login() {
    char username[USERNAME_LEN];
    char password[PASSWORD_LEN];
    char stored_username[USERNAME_LEN];
    char stored_password[PASSWORD_LEN];

    FILE *file = fopen("account.txt", "r");

    if (file == NULL) {
        printf("Could not open account.txt file.\n");
        return; // Return instead of 0
    }

    printf("Welcome Library Member!\n");
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    int login_success = 0;

    while (fscanf(file, "%s %s", stored_username, stored_password) != EOF) {
        if (strcmp(username, stored_username) == 0 && strcmp(password, stored_password) == 0) {
            login_success = 1;
            break;
        }
    }

    fclose(file);

    if (!login_success) {
        printf("Invalid username or password. Please try again.\n");
        member_login(); // This can lead to stack overflow; consider a loop instead
        return; // Add return to avoid further execution
    }

    int choice;

    while (1) {
        printf("\nLibrary System Menu:\n");
        printf("1. Account Management\n");
        printf("2. Book Search\n");
        printf("3. Book Recommendation\n");
        printf("4. Digital Library Access\n");
        printf("5. Exit to Library Login\n");
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                account_management(username);
                break;
            case 2:
                book_search_main();
                break;
            case 3:
                book_recommendation_main(username);
                break;
            case 4:
                digital_library_access();
                break;
            case 5:
                printf("Exiting the program.\n");
                return;
            default:
                printf("Invalid choice. Please enter a number between 1 and 5.\n");
                break; // Add break to avoid fall-through
        }
    }
}

