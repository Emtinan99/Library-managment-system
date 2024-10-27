#include <stdio.h>

int main()
{
    int login;

    do{
        printf("\nLog in as:\n");
        printf("1. Librarian\n");
        printf("2. Library Staff\n");
        printf("3. Library Member\n");
        printf("4. Guest\n");
        printf("5. Exit Program\n");
        printf("\nEnter your choice: ");
        scanf("%d", &login);

        switch (login) {
            case 1:
                printf("\nWill implement librarian stuff later teehee <3\n");
                break;
            case 2:
                printf("\npls call the login function from library staff after you finish implementing it\n");
                break;
            case 3:
                printf("\npls call the login function from library member\n");
                break;
            case 4:
                printf("\npls call the main menu function for guest\n");
                break;
            case 5:
                printf("\nThank you for using our Library Management system!\nExiting now....\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
        }

    }while(login != 5);
}
