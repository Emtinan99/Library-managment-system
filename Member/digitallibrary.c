#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256

void display_file_contents(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file: %s\n", filename);
        return;
    }

    char line[MAX_LINE_LENGTH];
    printf("Contents of %s:\n", filename);
    while (fgets(line, sizeof(line), file) != NULL) {
        char title[MAX_LINE_LENGTH];
        int stock;
        float price;

        sscanf(line, "%[^,],%d,%f", title, &stock, &price);

        printf("Title: %s, In Stock: %d, Price: %.2f\n", title, stock, price);
    }
    printf("\n");

    fclose(file);
}

void deduct_item_from_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file: %s\n", filename);
        return;
    }

    // Temporary file to store updated data
    FILE *tempFile = fopen("temp.txt", "w");
    if (tempFile == NULL) {
        printf("Error creating temporary file.\n");
        fclose(file);
        return;
    }

    char line[MAX_LINE_LENGTH];
    char title[MAX_LINE_LENGTH];
    int stock;
    float price;
    char itemToDeduct[MAX_LINE_LENGTH];

    printf("Enter the title of the item to deduct: ");
    fgets(itemToDeduct, sizeof(itemToDeduct), stdin);
    itemToDeduct[strcspn(itemToDeduct, "\n")] = 0; // Remove newline character

    int found = 0;

    while (fgets(line, sizeof(line), file) != NULL) {
        sscanf(line, "%[^,],%d,%f", title, &stock, &price);

        if (strcmp(title, itemToDeduct) == 0) {
            if (stock > 0) {
                stock--;
                found = 1;
                printf("Deducted 1 from %s. New stock: %d\n", title, stock);
            } else {
                printf("Sorry, %s is out of stock.\n", title);
            }
        }

        fprintf(tempFile, "%s,%d,%.2f\n", title, stock, price);
    }

    if (!found) {
        printf("Item not found: %s\n", itemToDeduct);
    }

    fclose(file);
    fclose(tempFile);

    remove(filename);
    rename("temp.txt", filename);
}

void deduct_item() {
    char deductChoice;
    printf("Do you want to deduct an item from stock? (y/n): ");
    scanf(" %c", &deductChoice);
    getchar(); // Consume the newline character

    if (deductChoice == 'y' || deductChoice == 'Y') {
        int category;
        printf("Choose the category:\n");
        printf("1. Online Journals\n");
        printf("2. eBooks\n");
        printf("3. Audiobooks\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &category);
        getchar(); // Consume the newline character

        switch (category) {
            case 1:
                deduct_item_from_file("online_journals.txt");
                break;
            case 2:
                deduct_item_from_file("ebooks.txt");
                break;
            case 3:
                deduct_item_from_file("audiobooks.txt");
                break;
            case 4:
                // Assuming member_login() is defined elsewhere
                // member_login();
                return; // Exit the function
            default:
                printf("Invalid category selected.\n");
                break;
        }
    } else {
        // If the user chooses 'n', return to digital_library_access
        printf("Returning to Digital Library Access...\n");
    }
}

void digital_library_access() {
    printf("Welcome to the Digital Library Access!\n\n");

    int choice;
    printf("Please choose a category to display:\n");
    printf("1. Online Journals\n");
    printf("2. eBooks\n");
    printf("3. Audiobooks\n");
    printf("0. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    getchar(); // Consume the newline character

    switch (choice) {
        case 1:
            display_file_contents("online_journals.txt");
            break;
        case 2:
            display_file_contents("ebooks.txt");
            break;
        case 3:
            display_file_contents("audiobooks.txt");
            break;
        case 0:
            printf("Exiting the program. Goodbye!\n");
            return; // Exit the function
        default:
            printf("Invalid choice. Please try again.\n");
            break;
    }
    deduct_item(); // Call deduct_item after displaying the contents
}

