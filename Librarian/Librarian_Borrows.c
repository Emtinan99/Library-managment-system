#include <stdio.h>

void borrowings_menu()
{
    int choice;

     do{
        printf("\nManage Borrowings and Returns:\n");
        printf("1. Check overdue books\n");
        printf("2. View all borrowed books\n");
        printf("3. Update borrowing status\n");
        printf("4. Back\n");
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
            return;
        default:
            printf("\nInvalid choice. Please try again.\n");
        }
    }while(choice != 4);
}
