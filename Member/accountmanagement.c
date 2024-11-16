#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 10
#define MAX_LINE_LENGTH 256
#define MAX_USERS 100

typedef struct {
    char title[100];
    char dueDate[11];
    float fee;
} Book;

typedef struct {
    char username[100];
    Book borrowedBooks[MAX_BOOKS];
    int bookCount;
    float totalFees;
} User;

void account_management(const char *username) {
    FILE *file = fopen("accounthistory.txt", "r");
    if (file == NULL) {
        printf("Error opening user accounts file.\n");
        return;
    }

    User user;
    int found = 0;

    while (fgets(user.username, sizeof(user.username), file) != NULL) {
        user.username[strcspn(user.username, "\n")] = 0;

        fscanf(file, "%f", &user.totalFees);
        user.bookCount = 0;

        while (user.bookCount < MAX_BOOKS && fscanf(file, "%s %s %f",
            user.borrowedBooks[user.bookCount].title,
            user.borrowedBooks[user.bookCount].dueDate,
            &user.borrowedBooks[user.bookCount].fee) == 3) {
            user.bookCount++;
        }
        if (strcmp(user.username, username) == 0) {
            found = 1;
            break;
        }
    }
    fclose(file);

    if (!found) {
        printf("User  not found.\n");
        return;
    }
    printf("Borrowed Books for %s:\n", user.username);
    for (int i = 0; i < user.bookCount; i++) {
        printf("Title: %s, Due Date: %s, Fee: %.2f\n",
            user.borrowedBooks[i].title,
            user.borrowedBooks[i].dueDate,
            user.borrowedBooks[i].fee);
    }

    if (user.totalFees > 0) {
        char choice;
        printf("You have remaining fees of %.2f. Do you want to pay? (y/n): ", user.totalFees);
        scanf(" %c", &choice);

        if (choice == 'y' || choice == 'Y') {
            float paymentAmount;
            printf("Enter the amount you want to pay: ");
            scanf("%f", &paymentAmount);

            if (paymentAmount > user.totalFees) {
                printf("You cannot pay more than the total fees. Payment not processed.\n");
            } else {
                user.totalFees -= paymentAmount;
                printf("Fees paid successfully. Remaining fees: %.2f\n", user.totalFees);
            }
        } else {
            printf("Fees remain unpaid.\n");
        }
    } else {
        printf("No remaining fees.\n");
    }

    file = fopen("accounthistory.txt", "w");
    if (file == NULL) {
        printf("Error opening user accounts file for writing.\n");
        return;
    }

    rewind(file);
    fprintf(file, "%s\n%.2f\n", user.username, user.totalFees);
    for (int i = 0; i < user.bookCount; i++) {
        fprintf(file, "%s %s %.2f\n",
            user.borrowedBooks[i].title,
            user.borrowedBooks[i].dueDate,
            user.borrowedBooks[i].fee);
    }

    fclose(file);
}

