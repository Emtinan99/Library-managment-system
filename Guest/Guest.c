#include<stdio.h>
#include<string.h>

void readBooks() {
    FILE *bookFile = fopen("books.txt", "r");  // Open for reading
    if (bookFile == NULL) {
        printf("Error opening file.");
        return;
    }

    char book[256];  // Buffer to store each line of the file
    while (fgets(book, sizeof(book), bookFile) != NULL) {
        printf("%s", book);  // Print the content of the file to the console
    }

    fclose(bookFile);  // Close the file
    return;
}


void viewResourcs(){
    FILE *resourceFile = fopen("resources.txt","r");
    if(resourceFile == NULL){
        printf("Error opening file.");
        return;
    }
    char resource[200];
    while(fgets(resource, sizeof(resource), resourceFile) !=NULL)
    {
        printf("%s", resource);
    }
    fclose(resourceFile);
    return;
}


void summary(){
    FILE *summaryFile = fopen("summary.txt","r");
    if(summaryFile == NULL){
        printf("Error opening file.");
        return;
    }
    char summary[100];
    while(fgets(summary, sizeof(summary),summaryFile) !=NULL)
    {
        printf("%s",summary);
    }
    return;
}

void events(){
    FILE *eventsFile = fopen("events.txt","r");
    if(eventsFile == NULL){
        printf("Error opening file.");
        return;
    }
    char events[100];
    while(fgets(events, sizeof(events), eventsFile) != NULL)
        {
            printf("%s",events);
        }
    fclose(eventsFile);
    return;
    }

void workshops(){
    FILE *workshopFile = fopen("workshop.txt","r");
    if(workshopFile == NULL){
        printf("Error opening file.");
        return;
    }
    char workshop[100];
    while(fgets(workshop,sizeof(workshop), workshopFile) !=NULL)
    {
        printf("%s",workshop);
    }
    fclose(workshopFile);
    return;
    }


void community(){
    FILE *communityFile = fopen("community.txt","r");
    if(communityFile == NULL){
        printf("Error opening file.");
        return;
    }
    char communities[100];
   while(fgets(communities, sizeof(communities), communityFile) != NULL)
        {
            printf("%s",communities);
        }
   fclose(communityFile);
    return;
    }

void service(){
    FILE *ServiceFile = fopen("lib_service.txt","r");
    if(ServiceFile == NULL){
        printf("Error opening file.");
        return;
    }
    char services[100];
    while(fgets(services, sizeof(services), ServiceFile) !=NULL)
        {
            printf("%s",services);
        }
    fclose(ServiceFile);
    return;
    }


void benefit(){
    FILE *benefitsFile = fopen("benefits.txt","r");
    if(benefitsFile == NULL){
        printf("Error opening file.");
        return;
    }
    char benefites[100];
    while(fgets(benefites, sizeof(benefites), benefitsFile) !=NULL)
        {
            printf("%s",benefites);
        }
    fclose(benefitsFile);
    return;
    }

void joining(){
    char  name[100] = "name";
    char  mail[200] = "mail";
    char  password[100] = "password";

        getchar();

        printf("Enter your name: ");
        fgets(name, sizeof(name), stdin);

        printf("Enter your email: ");
        fgets(mail, sizeof(mail), stdin);

        printf("Enter your numbers for password: ");
        fgets(password, sizeof(password), stdin);


        printf("\nWelcome to the library, %s",name);


    FILE *joinFile = fopen("join.txt","a");
    if(joinFile == NULL)
        {
        printf("Error opening file.");
        return;
        }
    else{
        name[strcspn(name, "\n")] = 0;    //
        mail[strcspn(mail, "\n")] = 0;    // Remove newline from email
        password[strcspn(password, "\n")] = 0;
        fprintf(joinFile, "%s-%s-%s \n", name, mail, password);
    fclose(joinFile);
    return;
    }
}

void guest_menu()
{
    int service_num, sub_ser1, sub_ser2, sub_ser3;

    printf("\nWelcome, Guest.\n1.Library Exploration. \n2.Event Information\n3.Library Services Overview\n4.Return to login page\n\nEnter the service number: ");
        while(scanf("%d",&service_num)!= 1)
        { printf("Invalid input. Please enter a number: ");
            while (getchar() != '\n');
        }
    if(service_num == 1){
        printf("\nLibrary Exploration:\n1.Browse book catalog\n2.View available resources\n3.Read book summaries\n4.return to Main Menu\n\nEnter the service number: ");
        while(scanf("%d",&sub_ser1)!= 1)
        { printf("Invalid input. Please enter a number: ");
            while (getchar() != '\n');
        }

        if(sub_ser1 == 1)
            {
                printf("\n");
                readBooks();
                printf("\n");
                guest_menu();
            }

        else if(sub_ser1 == 2)
            {
                printf("\n");
                viewResourcs();
                printf("\n");
                guest_menu();
            }


        else if(sub_ser1 == 3)
            {
                printf("\n");
                summary();
                printf("\n");
                guest_menu();
            }

        else if(sub_ser1 == 4)
            {
                printf("\n\n");
                guest_menu();
            }

        else
        {
            printf("\n\nEnter a valid number.\n");
            guest_menu();
        }
    }

    else if(service_num == 2){

        printf("\nEvent Information:\n1.Explore upcoming library events\n2.Workshops\n3.Community Programs\n4.Return to Main Menu\n\nEnter the service number: " );
        while(scanf("%d",&sub_ser2)!= 1)
        { printf("Invalid input. Please enter a number: ");
            while (getchar() != '\n');
        }


        if(sub_ser2 == 1)
            {
                printf("\n");
                events();
                printf("\n");
                guest_menu();
            }

        else if(sub_ser2 == 2)
            {
                printf("\n");
                workshops();
                printf("\n");
                guest_menu();
            }

        else if(sub_ser2 == 3)
            {
                printf("\n");
                community();
                printf("\n");
                guest_menu();
            }

        else if(sub_ser1 == 4)
            {
                guest_menu();
            }

        else
            {
                printf("Please enter a valid number.\n");
                guest_menu();
            }
        }

    else if(service_num == 3){

        printf("\nOverview of Library Services:\n1.Library Services\n2.Membership Benefits\n3.How to join the library\n4.Return to Main Menu\n\nEnter the service number: ");
        while(scanf("%d",&sub_ser3)!= 1)
        { printf("Invalid input. Please enter a number: ");
            while (getchar() != '\n');
        }

            if(sub_ser3 == 1)
                {
                    printf("\n");
                    service();
                    printf("\n");
                    guest_menu();
                }

            else if(sub_ser3 == 2)
                {
                    printf("\n");
                    benefit();
                    printf("\n");
                    guest_menu();
                }

            else if(sub_ser3 == 3)
                {
                    printf("\n");
                    joining();
                    printf("\n");
                    guest_menu();
                }

        else if(sub_ser1 == 4)
            {
                printf("\n");
                guest_menu();
                printf("\n");
            }

            else
            {
                printf("\nEnter a valid number.\n");
                guest_menu();
            }
    }

    else if(service_num == 4){
        printf("\nReturning to login page...\n");
        return;
    }

    else
    {
        printf("\nEnter a valid service number.\n");
        guest_menu();
    }
    return;
}
