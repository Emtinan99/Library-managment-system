#include <stdio.h>
#include "Library Management System.h"

int main()
{
    int choice, loggedIn;

    do{
        printf("\nLog in as:\n");
        printf("1. Librarian\n");
        printf("2. Library Staff\n");
        printf("3. Library Member\n");
        printf("4. Guest\n");
        printf("5. Exit Program\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                loggedIn = librarian_menu();

                if(loggedIn == 0)
                {
                    printf("\nLogging out...\n");
                }
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

    }while(choice != 5);
}
