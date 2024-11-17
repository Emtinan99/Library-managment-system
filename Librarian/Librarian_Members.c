#include <stdio.h>

void members_menu()
{
    int choice;

     do{
        printf("\nManage Memberships:\n");
        printf("1. Add new member\n");
        printf("2. View all members\n");
        printf("3. Update member information\n");
        printf("4. Delete a member\n");
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

void add_member()
{

}
