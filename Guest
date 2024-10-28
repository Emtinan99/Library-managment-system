#include<stdio.h>
#include<string.h>

int readBooks() {
    FILE *bookFile = fopen("Books.txt", "r");  // Open for reading
    if (bookFile == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    char book[256];  // Buffer to store each line of the file
    while (fgets(book, sizeof(book), bookFile) != NULL) {
        printf("%s", book);  // Print the content of the file to the console
    }

    fclose(bookFile);  // Close the file
    return 0;
}


int viewResourcs(){
    FILE *resourceFile = fopen("resources.txt","r");
    if(resourceFile == NULL){
        printf("Error opening file\n");
        return 1;
    }
    char resource[200];
    while(fgets(resource, sizeof(resource), resourceFile) !=NULL)
    {
        printf("%s", resource);
    }
    fclose(resourceFile);
    return 0;
}


int summary(){
    FILE *summaryFile = fopen("summary.txt","r");
    if(summaryFile == NULL){
        printf("Error opening file\n");
        return 1;
    }
    char summary[100];
    while(fgets(summary, sizeof(summary),summaryFile) !=NULL)
    {
        printf("%s",summary);
    }
}

int events(){
    FILE *eventsFile = fopen("events.txt","r");
    if(eventsFile == NULL){
        printf("Error opening file\n");
        return 1;
    }
    char events[100];
    while(fgets(events, sizeof(events), eventsFile) != NULL)
        {
            printf("%s",events);
        }
    fclose(eventsFile);
    return 0;
    }

int workshops(){
    FILE *workshopFile = fopen("workshop.txt","r");
    if(workshopFile == NULL){
        printf("Error opening file\n");
        return 1;
    }
    char workshop[100];
    while(fgets(workshop,sizeof(workshop), workshopFile) !=NULL)
    {
        printf("%s",workshop);
    }
    fclose(workshopFile);
    return 0;
    }


int community(){
    FILE *communityFile = fopen("community.txt","r");
    if(communityFile == NULL){
        printf("Error opening file\n");
        return 1;
    }
    char communities[100];
   while(fgets(communities, sizeof(communities), communityFile) != NULL)
        {
            printf("%s",communities);
        }
   fclose(communityFile);
    return 0;
    }

int service(){
    FILE *ServiceFile = fopen("lib_service.txt","r");
    if(ServiceFile == NULL){
        printf("Error opening file\n");
        return 1;
    }
    char services[100];
    while(fgets(services, sizeof(services), ServiceFile) !=NULL)
        {
            printf("%s",services);
        }
    fclose(ServiceFile);
    return 0;
    }


int benefit(){
    FILE *benefitsFile = fopen("benefits.txt","r");
    if(benefitsFile == NULL){
        printf("Error opening file\n");
        return 1;
    }
    char benefites[100];
    while(fgets(benefites, sizeof(benefites), benefitsFile) !=NULL)
        {
            printf("%s",benefites);
        }
    fclose(benefitsFile);
    return 0;
    }

int joining(){
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
        printf("Error opening file\n");
        return 1;
        }
    else{
        name[strcspn(name, "\n")] = 0;    //
        mail[strcspn(mail, "\n")] = 0;    // Remove newline from email
        password[strcspn(password, "\n")] = 0;
        fprintf(joinFile, "%s-%s-%s \n", name, mail, password);
    fclose(joinFile);
    return 0;
    }
}

int menu()
{
    int service_num, sub_ser1, sub_ser2, sub_ser3;



printf("\n1.Library Exploration. \n2.Event information\n3.Library Services Overview \nEnter the services service number:");
    while(scanf("%d",&service_num)!= 1)
    { printf("Invalid input. Please enter a number: ");
        while (getchar() != '\n');
    }
if(service_num == 1){
    printf("\n1.Browse book catalog \n2.View available resources \n3.Read book summaries\n4.return to main menu \ninput the service number: ");
    while(scanf("%d",&sub_ser1)!= 1)
    { printf("Invalid input. Please enter a number: ");
        while (getchar() != '\n');
    }

    if(sub_ser1 == 1)
        {
            printf("\n");
            readBooks();
            printf("\n");
            menu();

        }

    else if(sub_ser1 == 2)
        {
            printf("\n");
            viewResourcs();
            printf("\n");
            menu();

        }


    else if(sub_ser1 == 3)
        {
            printf("\n");
            summary();
            printf("\n");
            menu();

        }

    else if(sub_ser1 == 4)
        {
            printf("\n");
            printf("\n");
            menu();
        }

    else
    {
        printf("\n");
        printf("\nEnter a valid number");
        printf("\n");
        menu();
    }

}

else if(service_num == 2){

    printf("\n1.Explore upcoming library events\n2.workshops\n3.community programs \n4.return to main menu \nEnter the service number: " );
    while(scanf("%d",&sub_ser2)!= 1)
    { printf("Invalid input. Please enter a number: ");
        while (getchar() != '\n');
    }


    if(sub_ser2 == 1)
        {
            printf("\n");
            events();
            printf("\n");
            menu();

        }

    else if(sub_ser2 == 2)
        {
            printf("\n");
            workshops();
            printf("\n");
            menu();
        }

    else if(sub_ser2 == 3)
        {
            printf("\n");
            community();
            printf("\n");
            menu();
        }

    else if(sub_ser1 == 4)
        {
            menu();
        }

    else
        {
            printf("please enter a valid number");
            printf("\n");
            menu();

        }
    }

else if(service_num == 3){

    printf("\n1.Library services\n2.Membership benefits\n3.How to join the library\n4.return to main menu \nEnter the service number: ");
    while(scanf("%d",&sub_ser3)!= 1)
    { printf("Invalid input. Please enter a number: ");
        while (getchar() != '\n');
    }

        if(sub_ser3 == 1)
            {
                printf("\n");
                service();
                printf("\n");
                menu();

            }

        else if(sub_ser3 == 2)
            {
                printf("\n");
                benefit();
                printf("\n");
                menu();

            }

        else if(sub_ser3 == 3)
            {
                printf("\n");
                joining();
                printf("\n");
                menu();
            }

    else if(sub_ser1 == 4)
        {
            printf("\n");
            menu();
            printf("\n");
        }

        else
        {
            printf("\nEnter a valid number");
            printf("\n");
            menu();
        }
}

else
{
    printf("\nEnter a valid service numbers");
    printf("\n");
    menu();
}

return 0;
}



int main(){

menu();
}

