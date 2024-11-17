#include <stdio.h>
#include <string.h>

struct Member {
    int id;
    char name[100];
    char email[100];
    char phone[15];
};

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

void add_member() {
    struct Member members[100];
    char name[100], email[100], password[100], phone[15], line[256];
    int highest_id = 0, member_count = 0;

    // Step 1: Display pending registrations from join.txt
    FILE *join_file = fopen("join.txt", "r");
    if (join_file == NULL) {
        printf("Error: Could not open join.txt file.\n");
        return;
    }

    printf("Pending Registrations:\n");
    while (fgets(line, sizeof(line), join_file)) {
        sscanf(line, "%99[^,], %99[^,], %99s", name, email, password);
        printf("Name: %s, Email: %s, Password: %s\n", name, email, password);
    }
    fclose(join_file);

    // Step 2: Prompt user for new member details
    printf("\nEnter member name: ");
    scanf(" %[^\n]", name);
    printf("Enter member email: ");
    scanf(" %[^\n]", email);
    printf("Enter the phone number of the new member: ");
    scanf(" %[^\n]", phone);

    // Step 3: Read existing members to determine the highest member ID
    FILE *members_file = fopen("members.txt", "r");
    if (members_file != NULL) {
        while (fgets(line, sizeof(line), members_file)) {
            sscanf(line, "%d, %99[^,], %99[^,], %14s", &members[member_count].id, members[member_count].name, members[member_count].email, members[member_count].phone);
            if (members[member_count].id > highest_id) {
                highest_id = members[member_count].id;
            }
            member_count++;
        }
        fclose(members_file);
    }

    // Step 4: Generate new member ID
    int new_member_id = highest_id + 1;

    // Step 5: Append the new member to members.txt
    members_file = fopen("members.txt", "a");
    if (members_file == NULL) {
        printf("Error: Could not open members.txt file.\n");
        return;
    }
    fprintf(members_file, "%d, %s, %s, %s\n", new_member_id, name, email, phone);
    fclose(members_file);

    // Step 6: Create username (name+id) and append username and password to accounts.txt
    char username[120];
    snprintf(username, sizeof(username), "%s%d", name, new_member_id);

    FILE *accounts_file = fopen("accounts.txt", "a");
    if (accounts_file == NULL) {
        printf("Error: Could not open accounts.txt file.\n");
        return;
    }
    fprintf(accounts_file, "%s, %s\n", username, password);
    fclose(accounts_file);

    printf("\nNew member added successfully!\n");
    printf("Member ID: %d, Username: %s\n", new_member_id, username);
}


void update_member() {
    struct Member members[100];
    char line[256];
    int id, choice, found = 0, idx = 0, findidx = 0;

    FILE *update = fopen("members.txt", "r");
    if (update == NULL) {
        printf("Error opening file.\n");
        return;
    }

    printf("\nEnter member ID: ");
    scanf("%d", &id);
    getchar();
    clear_screen(0);

    // Load members from the file
    while (fgets(line, sizeof(line), update)) {
        sscanf(line, "%d, %99[^,], %99[^,], %14s", &members[idx].id, members[idx].name, members[idx].email, members[idx].phone);
        idx++;
    }
    fclose(update);

    // Find the member by ID
    for (int i = 0; i < idx; i++) {
        if (members[i].id == id) {
            found = 1;
            findidx = i;
            break;
        }
    }

    if (found) {
        printf("ID: %d\nName: %s\nEmail: %s\nPhone Number: %d\nEbook: %s\n", members[findidx].id, members[findidx].name, members[findidx].email, members[findidx].phone);

        do {
            printf("\nChoose a field to update:\n");
            printf("1. Name\n");
            printf("2. Email\n");
            printf("3. Phone\n");
            printf("4. Save changes\n");
            printf("\nEnter your choice: ");

            if (scanf("%d", &choice) != 1) {
                printf("\nInvalid input. Please enter a number.\n");
                clear_screen(1);
                while (getchar() != '\n'); // Clear input buffer
                continue;
            }
            getchar(); // Clear buffer

            switch (choice) {
                case 1:
                    printf("\nEnter new name: ");
                    fgets(members[findidx].name, sizeof(members[findidx].name), stdin);
                    members[findidx].name[strcspn(members[findidx].name, "\n")] = '\0';
                    break;
                case 2:
                    printf("\nEnter new email: ");
                    fgets(members[findidx].email, sizeof(members[findidx].email), stdin);
                    members[findidx].email[strcspn(members[findidx].email, "\n")] = '\0';
                    break;
                case 3:
                    printf("\nEnter new phone number: ");
                    fgets(members[findidx].phone, sizeof(members[findidx].phone), stdin);
                    members[findidx].phone[strcspn(members[findidx].phone, "\n")] = '\0';
                    break;
                case 4:
                    printf("\nSaving changes...\n");

                    FILE *save = fopen("members.txt", "w");
                    if (save == NULL) {
                        printf("Error opening file.\n");
                        return;
                    }

                    for (int j = 0; j < idx; j++) {
                        fprintf(save, "%d, %s, %s, %s\n", members[j].id, members[j].name, members[j].email, members[j].phone);
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
        } while (choice != 4);
    } else {
        printf("\nMember ID was not found. Please try again.\n\n");
        clear_screen(1);
        return;
    }
}
