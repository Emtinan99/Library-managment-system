#include <stdio.h>
#include "Library Management System.h"

void clear_screen(int seconds)
{
    sleep(seconds);
    system("cls");
}
int main()
{
    int choice;

    do{
        printf("\nLog in as:\n");
        printf("1. Librarian\n");
        printf("2. Library Staff\n");
        printf("3. Library Member\n");
        printf("4. Guest\n");
        printf("5. Exit Program\n");
        printf("\nEnter your choice: ");

        if (scanf("%d", &choice) != 1)
        {
            printf("\nInvalid input. Please enter a number.\n");
            while (getchar() != '\n');
            continue;
        }

        switch (choice) {
            case 1:
                books_menu();
                break;
            case 2:
                staff_menu();
                break;
            case 3:
                member_login();
                break;
            case 4:
                guest_menu();
                break;
            case 5:
                printf("\nThank you for using our Library Management system!\nExiting now....\n");
                return 0;
            default:
                printf("\nInvalid choice. Please try again.\n");
                continue;
        }

    }while(choice != 5);
}
