#include <stdio.h>
#include <string.h>

void librarian_menu();

void librarian_login()
{
    char correctUser[20] = "librarian", correctPass[20] = "librarianpass";
    char user[20], pass[20], exit[2];

    do{
        printf("\nUsername: ");
        scanf("%19s", user);

        if(strcmp(user, correctUser) != 0)
        {
            printf("\nIncorrect Username. Would you like to try again? (y/n): ");
            scanf("%1s", exit);

            while(strcmp(exit, "y") != 0)
            {
                if(strcmp(exit, "n") == 0)
                {
                    printf("\nReturning to Login Page....\n");
                    return;
                }
                else
                {
                    printf("\nInvalid entry. Please try again (y/n): ");
                    scanf("%1s", exit);
                }
            }
            continue;
        }

        printf("Password: ");
        scanf("%19s", pass);

        if (strcmp(pass, correctPass) == 0)
        {
            printf("\nLogin successful!\n");
            librarian_menu();
            return;
        }

        else
        {
            printf("\nIncorrect Password. Would you like to try again? (y/n): ");
            scanf("%1s", exit);

            while(strcmp(exit, "y") != 0)
            {
                if(strcmp(exit, "n") == 0)
                {
                    printf("\nReturning to Login Page....\n");
                    return;
                }
                else
                {
                    printf("\nInvalid entry. Please try again (y/n): ");
                    scanf("%1s", exit);
                }
            }
            continue;
        }
    }while(1);
}

void librarian_menu()
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
            printf("\nThank you for using the Library Management System! Logging out...\n");
            return;
        default:
            printf("\nInvalid choice. Please try again.\n");
        }
    }while(menu != 5);
}
