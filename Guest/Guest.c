#include<stdio.h>
#include<string.h>

void readBooks() {
    FILE *bookFile = fopen("books.txt", "r");  // Open for reading/ and make a pointer for file operations
    if (bookFile == NULL) { //if file is null or not found or any error encountered 
        printf("Error opening file."); //then print error message
        return; //return control to the previous function
    }

    char book[256];  // character array to store lines of the file
    while (fgets(book, sizeof(book), bookFile) != NULL) { //fgets to copy lines from the file, sizeof to prevent overflow, bookFile to indicate the file
        printf("%s", book);  // Print the content of the file to the console
    }

    fclose(bookFile);  // Close the file
    return; //return the control to the previous function
}


void viewResourcs(){ //repetition of previous steps
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
    char  name[100] = "name"; //array declared
    char  mail[200] = "mail";
    char  password[100] = "password";

        getchar(); //read through all characters in the stated buffer/storage to clear them from any old leftover input to prevent loops from running infinitely 

        printf("Enter your name: ");
        fgets(name, sizeof(name), stdin); //get input from keyboard 'stdin' and store it in the array 'name','sizeof' to prevent overflow

        printf("\nEnter your email: ");
        fgets(mail, sizeof(mail), stdin);

        printf("\nEnter your password: ");
        fgets(password, sizeof(password), stdin);


        printf("\nWelcome to the library, %s",name); //greet user after they input their details


    FILE *joinFile = fopen("join.txt","a"); //open file with append to add to it without erasing previous data
    if(joinFile == NULL)
        {
        printf("Error opening file\n");
        return 1;
        }
    else{
        name[strcspn(name, "\n")] = 0;    //read through the array until finding '\n' and replace it with 0 aka null 
        mail[strcspn(mail, "\n")] = 0;    //same process^
        password[strcspn(password, "\n")] = 0; 
        fprintf(joinFile, "%s-%s-%s \n", name, mail, password); //print the user input into the txt file in this format 
    fclose(joinFile); //close file
    return ; //and return 0 for successful process
    }
}

void fee(){
    char ans;

    printf("All members will have to pay an annual RM25 registration fee, the fee will be sent to your email.\nYou can pay at the library front desk or through the link in the email, membership entitles you to attend events for free and avoid late books return fee (RM10)");

    while (1){  //infinite loop to only accept valid input

    printf("\nwant to be a library member? (y/n): ");
    while (getchar() != '\n'); //read through input until u get to '\n' to clear buffer
    scanf("%c",&ans);

    if(ans == 'y'){
        joining(); //jump to joining function
        break; // breaks after joining  is completed
    }
    else if(ans == 'n'){
        guest_menu(); //jump back to guest menu

    }
    else{
        printf("invalid input. Please enter 'y' or 'n'.\n");

    }

}
return;
}

void guest_menu()
{
    int service_num, sub_ser1, sub_ser2, sub_ser3;

    printf("\nWelcome, Guest.\n1.Library Exploration. \n2.Event Information\n3.Library Services Overview\n4.Return to login page\n\nEnter the service number: ");
        while(scanf("%d",&service_num)!= 1) //1 for successful process aka valid input
        { printf("Invalid input. Please enter a number: ");
            while (getchar() != '\n'); //clean buffer so loop doesn't run infinitely
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
                    fee();
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
