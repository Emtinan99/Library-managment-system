#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_BOOKS 100
#define TITLE_LEN 100

typedef struct {
    char title[TITLE_LEN];
    int available_copies;
} Book;

void search_books(Book library[], int book_count);
int load_books_from_file(const char *filename, Book library[]);

void book_search_main() {
    Book library[MAX_BOOKS];
    int book_count = load_books_from_file("books.txt", library);

    if (book_count < 0) {
        printf("Failed to load books from file.\n");
        return; // Exit if loading fails
    }

    search_books(library, book_count); // Now call search_books after loading the library
}

int load_books_from_file(const char *filename, Book library[]) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Could not open file %s.\n", filename);
        return -1;
    }

    int count = 0;
    // Updated format to read title and available copies
    while (count < MAX_BOOKS && fscanf(file, "%99[^,],%d\n", library[count].title, &library[count].available_copies) == 2) {
        count++;
    }

    fclose(file);
    return count;
}

void search_books(Book library[], int book_count) {
    char search_title[TITLE_LEN];

    // Prompt the user for input
    getchar();
    printf("Enter the title of the book you want to search for: ");
    fgets(search_title, TITLE_LEN, stdin);

    // Remove newline character from the input
    search_title[strcspn(search_title, "\n")] = 0;

    // Trim whitespace from the search title
    char *start = search_title;
    while (*start == ' ') start++; // Trim leading spaces
    char *end = start + strlen(start) - 1;
    while (end > start && *end == ' ') end--; // Trim trailing spaces
    *(end + 1) = '\0'; // Null-terminate the trimmed string

    // Validate input
    if (strlen(start) == 0) {
        printf("Invalid input. Please enter a valid book title.\n");
        return;
    }

    int found = 0;

    for (int i = 0; i < book_count; i++) {
        // Convert both titles to lowercase for case-insensitive comparison
        char title_lower[TITLE_LEN];
        char search_lower[TITLE_LEN];

        // Convert library title to lowercase
        for (int j = 0; library[i].title[j]; j++) {
            title_lower[j] = tolower(library[i].title[j]);
        }
        title_lower[strlen(library[i].title)] = '\0'; // Null-terminate

        // Convert search title to lowercase
        for (int j = 0; start[j]; j++) {
            search_lower[j] = tolower(start[j]);
        }
        search_lower[strlen(start)] = '\0'; // Null-terminate

        if (strcmp(title_lower, search_lower) == 0) { // Compare with trimmed title
            found = 1;
            printf("Book Title: %s\n", library[i].title);
            printf("Available Copies: %d\n", library[i].available_copies);

            if (library[i].available_copies > 0) {
                char reserve_choice;
                printf("Would you like to reserve this book? (y/n): ");
                scanf(" %c", &reserve_choice); // Note the space before %c to consume any leftover newline

                // Validate reserve choice
                while (reserve_choice != 'y' && reserve_choice != 'Y' && reserve_choice != 'n' && reserve_choice != 'N') {
                    printf("Invalid choice. Please enter 'y' for yes or 'n' for no: ");
                    scanf(" %c", &reserve_choice);
                }

                if (reserve_choice == 'y' || reserve_choice == 'Y') {
                    library[i].available_copies--; // Deduct available copies
                    printf("You have successfully reserved the book: %s\n", library[i].title);
                    printf("Remaining Copies: %d\n", library[i].available_copies); // Show remaining copies
                } else {
                    printf("Reservation canceled.\n");
                }
            } else {
                printf("Sorry, this book is currently not available for borrowing.\n");
            }
            break;
        }
    }
    if (!found) {
        printf("Sorry, the book titled '%s' was not found in the catalog.\n", search_title);
    }
}
