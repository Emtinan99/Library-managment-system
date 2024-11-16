#include <stdio.h>
#include <string.h>
#include "clear_screen.h"

void add_book();
void view_books();
void update_book();

struct Book
{
    int book_id;
    int copies;
    char title[100];
    char author[100];
    char ebook[4];

};

void books_menu()
{
    int choice;

     do{
        printf("\nManage Book Inventory:\n");
        printf("1. Add new book\n");
        printf("2. View all books\n");
        printf("3. Update book information\n");
        printf("4. Delete a book\n");
        printf("5. Back\n");
        printf("\nEnter your choice: ");

        if (scanf("%d", &choice) != 1)
        {
            printf("\nInvalid input. Please enter a number.\n");
            while (getchar() != '\n');
            continue;
        }

        switch (choice)
        {
        case 1:
            printf("\nthis has not been implemented yet\n");
            break;
        case 2:
            printf("\nthis has not been implemented yet\n");
            break;
        case 3:
            printf("\nthis has not been implemented yet\n");
            break;
        case 4:
            printf("\nthis has not been implemented yet\n");
            break;
        case 5:
            return;
        default:
            printf("\nInvalid choice. Please try again.\n");
        }
    }while(choice != 5);
}

void add_books()
{
    struct Book newbook;
    int id, highest_id = 0;
    char line[256];

    FILE *file;
    file = fopen("books.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    while (fgets(line, sizeof(line), file))
    {
        if (sscanf(line, "%d", &id) == 1 && id > highest_id)
        {
            highest_id = id;
        }
    }
    fclose(file);

    newbook.book_id = highest_id + 1;

    printf("\nEnter book title: ");
    fgets(newbook.title, sizeof(newbook.title), stdin);
    newbook.title[strcspn(newbook.title, "\n")] = '\0';

    printf("\nEnter author name: ");
    fgets(newbook.author, sizeof(newbook.author), stdin);
    newbook.author[strcspn(newbook.author, "\n")] = '\0';

    printf("\nEnter number of available copies: ");
    scanf("%d", &newbook.copies);
    getchar();

    printf("\nIs E-book version available (Yes/No)? ");
    fgets(newbook.ebook, sizeof(newbook.ebook), stdin);
    newbook.ebook[strcspn(newbook.ebook, "\n")] = '\0';

    file = fopen("books.txt", "a");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    fprintf(file, "%d, %s, %s, %d, %s\n", newbook.book_id, newbook.title, newbook.author, newbook.copies, newbook.ebook);
    fclose(file);

    printf("\nBook successfully added!\n");
    clear_screen(1);
}

void view_books()
{
    struct Book books[100];
    char line[256];
    int count = 0;

    FILE *file = fopen("books.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    printf("\nLoading...");
    clear_screen(1);

    printf("%-4s | %-35s | %-25s | %-16s | %-15s\n", "ID", "Title", "Author", "Available Copies", "E-book Available");
    printf("------------------------------------------------------------------------------------------------------------\n");

    while (fgets(line, sizeof(line), file))
    {
        sscanf(line, "%d, %99[^,], %99[^,], %d, %3s", &books[count].book_id, books[count].title, books[count].author, &books[count].copies, books[count].ebook);
        printf("%04d | %-35s | %-25s | %-16d | %-15s\n", books[count].book_id, books[count].title, books[count].author, books[count].copies, books[count].ebook);
        count++;

    }

    fclose(file);

    printf("\nPress 'Enter' to go back...");
    getchar();

    printf("\nLoading previous menu...");
    clear_screen(1);
}

void update_book()
{
    struct Book books[100];
    char line[256];
    int id, choice, found = 0, idx = 0, findidx = 0;
    FILE *update = fopen("books.txt", "r");
    if (update == NULL) {
        printf("Error opening file.\n");
        return;
    }

    printf("\nEnter book ID: ");
    scanf("%d", &id);
    getchar();
    clear_screen(0);

    while(fgets(line, sizeof(line), update))
    {
        sscanf(line, "%d, %99[^,], %99[^,], %d, %3s", &books[idx].book_id, books[idx].title, books[idx].author, &books[idx].copies, books[idx].ebook);
        idx++;
    }
    fclose(update);

    for(int i = 0; i < idx; i++)
    {
        if(books[i].book_id == id)
        {
            found = 1;
            findidx = i;
            break;
        }
    }

    char updated_title[100], updated_author[100], updated_ebook[4];
    int updated_copies;

    if(found)
    {
        printf("%-4s | %-30s | %-20s | %-16s | %-15s\n", "ID", "Title", "Author", "Available Copies", "E-book Available");
        printf("-----------------------------------------------------------------------------------------------------\n");
        printf("%04d | %-30s | %-20s | %-16d | %-15s\n", books[findidx].book_id, books[findidx].title, books[findidx].author, books[findidx].copies, books[findidx].ebook);

        do{
            printf("\nChoose a field to update:\n");
            printf("1. Book title\n");
            printf("2. Author\n");
            printf("3. Number of copies\n");
            printf("4. E-book availability\n");
            printf("5. Save chages\n");
            printf("\nEnter your choice: ");

            if (scanf("%d", &choice) != 1)
            {
                printf("\nInvalid input. Please enter a number.\n");
                clear_screen(1);
                while (getchar() != '\n');
                continue;
            }
            getchar();

            switch (choice) {
                case 1:
                    printf("\nEnter book title: ");
                    fgets(books[findidx].title, sizeof(books[findidx].title), stdin);
                    books[findidx].title[strcspn(books[findidx].title, "\n")] = '\0';
                    break;
                case 2:
                    printf("\nEnter author name: ");
                    fgets(books[findidx].author, sizeof(books[findidx].author), stdin);
                    books[findidx].author[strcspn(books[findidx].author, "\n")] = '\0';
                    break;
                case 3:
                    printf("\nEnter number of copies: ");
                    scanf("%d", &books[findidx].copies);
                    getchar(); // Clear buffer
                    break;
                case 4:
                    printf("\nIs E-book available? (Yes/No)? ");
                    fgets(books[findidx].ebook, sizeof(books[findidx].ebook), stdin);
                    books[findidx].ebook[strcspn(books[findidx].ebook, "\n")] = '\0';
                    break;
                case 5:
                    printf("\nSaving changes...\n");

                    FILE *save = fopen("books.txt", "w");
                    if (save == NULL) {
                        printf("Error opening file.\n");
                        return;
                    }

                    for (int j = 0; j < idx; j++)
                    {
                        fprintf(save, "%d, %s, %s, %d, %s\n", books[j].book_id, books[j].title, books[j].author, books[j].copies, books[j].ebook);
                    }
                    fclose(save);

                    printf("\nChanges saved successfully!\n");
                    clear_screen(1);
                    return;
                default:
                    printf("\nInvalid choice. Please try again.\n");
                    clear_screen(1);
                    continue;
            }

        }while(choice != 5);
    }

    else
    {
        printf("\nBook ID was not found. Please try again.\n\n");
        clear_screen(1);
        return;
    }
}
