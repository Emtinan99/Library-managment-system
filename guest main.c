#include<stdio.h>


int readBooks(){
    FILE *bookFile = fopen("Books.txt","r");
    if(bookFile == NULL){
        printf("Error opening file\n");
        return 1;
    }
    else{
    fprintf(bookFile,"This is a new file for the library management system\n.");
    fclose(bookFile);
    return 0;
    }
}

int viewResourcs(){
    FILE *resourceFile = fopen("resources.txt","r");
    if(resourceFile == NULL){
        printf("Error opening file\n");
        return 1;
    }
    else{
    fprintf(resourceFile,"This is a new file for the library management system\n.");
    fclose(resourceFile);
    return 0;
    }
}

int summary(){
    FILE *summaryFile = fopen("summary.txt","r");
    if(summaryFile == NULL){
        printf("Error opening file\n");
        return 1;
    }
    else{
    fprintf(summaryFile,"This is a new file for the library management system\n.");
    fclose(summaryFile);
    return 0;}
    }

int events(){
    FILE *eventsFile = fopen("events.txt","r");
    if(eventsFile == NULL){
        printf("Error opening file\n");
        return 1;
    }
    else{
    fprintf(eventsFile,"This is a new file for the library management system\n.");
    fclose(eventsFile);
    return 0;
    }
}

int workshops(){
    FILE *workshopFile = fopen("workshop.txt","r");
    if(workshopFile == NULL){
        printf("Error opening file\n");
        return 1;
    }
    else{
    fprintf(workshopFile,"This is a new file for the library management system\n.");
    fclose(workshopFile);
    return 0;
    }
}

int community(){
    FILE *communityFile = fopen("community.txt","r");
    if(communityFile == NULL){
        printf("Error opening file\n");
        return 1;
    }
    else
    {fprintf(communityFile,"This is a new file for the library management system\n.");
    fclose(communityFile);
    return 0;
    }
}

int service(){
    FILE *ServiceFile = fopen("lib_service.txt","r");
    if(ServiceFile == NULL){
        printf("Error opening file\n");
        return 1;
    }
    else {
    fprintf(ServiceFile,"This is a new file for the library management system\n.");
    fclose(ServiceFile);
    return 0;
    }
}

int benefit(){
    FILE *benefitsFile = fopen("benefits.txt","r");
    if(benefitsFile == NULL){
        printf("Error opening file\n");
        return 1;
    }
    else{
    fprintf(benefitsFile,"This is a new file for the library management system\n.");
    fclose(benefitsFile);
    return 0;
    }
}

int joining(){
    FILE *joinFile = fopen("join.txt","w");
    if(joinFile == NULL){
        printf("Error opening file\n");
        return 1;
    }
    else{
    fprintf(joinFile,"This is a new file for the library management system\n.");
    fclose(joinFile);
    return 0;
    }
}


int main(){


int lib_explor, event_info, lib_ser_overview, service_num, sub_ser1, sub_ser2, sub_ser3;
char  name[] = "name";
char  mail[] = "mail";
char  passwrd[] = "passwrd";



printf("1.Library Exploration. \n2.Event information\n3.Library Services Overview\nEnter the services service number:");
scanf("%d", &service_num);

if(service_num == 1){

    printf("1.Browse catalog \n2. View available resources \n3. Read book summaries\n input the service number: ");
    scanf("%d",&sub_ser1);

    if(sub_ser1 == 1)
        {
        readBooks();
        }

    else if(sub_ser1 == 2)
        {
        viewResourcs();
        }


    else if(sub_ser1 == 3)
        {
        summary();
        }

    else
    {
    printf("restart and enter a valid number");
    }
}


else if (service_num == 2){
    {
    printf("1 Explore upcoming library events\n2 workshops\3 community programs\n enter the service number:" );
    scanf("%d",&sub_ser2);
    }

    if(sub_ser2 == 1)
        {
        events();
        }

    else if(sub_ser2 == 2)
        {
        workshops();
        }

    else if(sub_ser2 == 3)
        {
        community();
        }

    else
    {
    printf("restart and enter a valid number");
    }
}

else if(service_num == '3'){
    printf("1 Library services\n2 Membership benefits\n3 How to join the library\n enter the");
    scanf("%d",&sub_ser3);

    if(sub_ser3 == 1)
        {
            service();
        }

    else if(sub_ser3 == 2)
        {
            benefit();
        }

    else if(sub_ser3 == 3)
        {
            printf("enter your name");
            scanf("%s",&name);

            printf("enter your email");
            scanf("%s",&mail);

            printf("enter your numbers for password");
            scanf("%d",&passwrd);

            joining();
            printf("welcome %s to the library",name);

        }


    else
    {
    printf("restart and enter a valid number");
    }
}

else
{
     printf("please restart and enter a valid service numbers");
}

return 0;
}
