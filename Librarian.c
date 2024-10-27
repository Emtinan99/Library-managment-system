#include <stdio.h>

void librarian_login();

int librarian_menu()
{
    int menu;

    do{
        printf("\nWhat would you like to do?\n");
        printf("1. Manage Book Inventory\n");
        printf("2. Manage Memberships\n");
        printf("3. Check Borrowings and Returns\n");
        printf("4. Generate Report\n");
        printf("5. Logout\n");
        printf("\nEnter your choice: ");
        scanf("%d", &menu);

        switch (menu)
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
            return 0;
        default:
            printf("\nInvalid choice. Please try again.\n");
        }
    }while(menu != 5);

    return 1;
}
