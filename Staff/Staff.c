#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define BOOKS_CAPACITY_LIMIT 1000

typedef struct {
    char id[5];
    char title[100];
    char author[50];
    int copies;
    char ebook_available[4];
    int shelf;
} Book;


typedef struct {
    int id;
    char name[50];
    char email[50];
    char phone[15];
} Member;


typedef struct {
    int reservationId;
    int memberId;
    char bookId[5];
    char date[20];
} Reservation;


Book books[BOOKS_CAPACITY_LIMIT];
int numBooks = 0;
Member libraryMembers[100];
int numMembers = 0;
Reservation bookings[1000];
int numOfReservations = 0;


void retrieveBookInfo();
void saveBookData();
void memberAssistance();
void shelfManagement();
void digitalAssistance();
void retrieveMembersDetails();
void storeReservationDetails();
void retrieveReservationInfo();

void toLowerCase(char *str) {
    for(int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

void retrieveBookInfo() {
    FILE *fp = fopen("books.txt", "r");
    if (fp == NULL) {
        printf("No existing book data.\n");
        return;
    }

    char line[200];
    numBooks = 0;

    while (fgets(line, sizeof(line), fp)) {

        line[strcspn(line, "\n")] = 0;

        int result = sscanf(line, "%4[^,],%99[^,],%49[^,],%d,%[^,],%d",
               books[numBooks].id,
               books[numBooks].title,
               books[numBooks].author,
               &books[numBooks].copies,
               books[numBooks].ebook_available,
               &books[numBooks].shelf);

        if (result == 6) {

            numBooks++;
        } else {

            result = sscanf(line, "%4[^,],%99[^,],%49[^,],%d,%[^,\n]",
                   books[numBooks].id,
                   books[numBooks].title,
                   books[numBooks].author,
                   &books[numBooks].copies,
                   books[numBooks].ebook_available);

            if (result == 5) {
                books[numBooks].shelf = 0;
                numBooks++;
            }
        }
    }

    fclose(fp);
    printf("Loaded %d books from file.\n", numBooks);
}



void saveBookData() {
    FILE *fp = fopen("books.txt", "r+");
    if (fp == NULL) {
        printf("Error saving book data!\n");
        return;
    }


    fseek(fp, 0, SEEK_SET);
    for (int i = 0; i < numBooks; i++) {
        fprintf(fp, "%s,%s,%s,%d,%s,%d\n",
                books[i].id,
                books[i].title,
                books[i].author,
                books[i].copies,
                books[i].ebook_available,
                books[i].shelf);
    }
    fclose(fp);
}

void saveCopiesField(const char* bookId, int newCopies) {
    FILE *fp = fopen("books.txt", "r+");
    if (fp == NULL) {
        printf("Error opening book data file!\n");
        return;
    }

    char line[200];
    long int position = 0;
    int found = 0;

    while (fgets(line, sizeof(line), fp)) {
        char currentId[5];
        char title[100];
        char author[50];
        int copies;
        char ebook[4];
        int shelf;

        sscanf(line, "%4[^,],%99[^,],%49[^,],%d,%3[^,],%d",
               currentId, title, author, &copies, ebook, &shelf);

        if (strcmp(currentId, bookId) == 0) {
            char *copiesStart = strstr(line, ",") + 1;
            copiesStart = strstr(copiesStart, ",") + 1;
            copiesStart = strstr(copiesStart, ",") + 1;

            fseek(fp, position + (copiesStart - line), SEEK_SET);

            fprintf(fp, "%d", newCopies);
            found = 1;
            break;
        }
        position = ftell(fp);
    }

    fclose(fp);

    if (!found) {
        printf("Book with ID %s not found!\n", bookId);
    }
}


void retrieveMembersDetails() {
    FILE *fp = fopen("members.txt", "r");
    if(fp == NULL) {
        printf("Error: Cannot open members.txt\n");
        return;
    }
    numMembers = 0;

    while(fscanf(fp, "%d,%[^,],%[^,],%[^\n]\n",
          &libraryMembers[numMembers].id,
          libraryMembers[numMembers].name,
          libraryMembers[numMembers].email,
          libraryMembers[numMembers].phone) == 4) {
        numMembers++;
    }
    fclose(fp);
}

void retrieveReservationInfo() {
    FILE *fp = fopen("reservations.txt", "r");
    if(fp == NULL) {
        printf("No existing reservation data.\n");
        return;
    }

    while(fscanf(fp, "%d,%d,%d,%[^\n]\n",
          &bookings[numOfReservations].reservationId,
          &bookings[numOfReservations].memberId,
          &bookings[numOfReservations].bookId,
          bookings[numOfReservations].date) == 4) {
        numOfReservations++;
    }
    fclose(fp);
}

void storeReservationDetails() {
    FILE *fp = fopen("reservations.txt", "w");
    if(fp == NULL) {
        printf("Error saving reservation data!\n");
        return;
    }

    for(int i = 0; i < numOfReservations; i++) {
        fprintf(fp, "%d,%d,%s,%s\n",
               bookings[i].reservationId,
               bookings[i].memberId,
               bookings[i].bookId,
               bookings[i].date);
    }
    fclose(fp);
}

void memberAssistance() {
    int selectedOption;
    char searchTitle[100];
    int isPresent;

    while(1) {
        printf("\n=== Member Assistance ===\n");
        printf("1. Search for books\n");
        printf("2. Reserve books\n");
        printf("3. Library services information\n");
        printf("4. Back to main menu\n");
        printf("Enter choice (1-4): ");
        scanf("%d", &selectedOption);
        getchar();

        switch(selectedOption) {
            case 1: {
			    printf("Enter book title to search: ");
			    fgets(searchTitle, sizeof(searchTitle), stdin);
			    searchTitle[strcspn(searchTitle, "\n")] = 0;

			    toLowerCase(searchTitle);

			    printf("\nSearch Results:\n");
			    printf("----------------------------------------\n");
			    isPresent = 0;


			    for (int i = 0; i < numBooks; i++) {
			        char tempTitle[100];
			        strcpy(tempTitle, books[i].title);
			        toLowerCase(tempTitle);

			        if (strstr(tempTitle, searchTitle) != NULL) {

			            char clean_ebook[5];
			            strncpy(clean_ebook, books[i].ebook_available, 4);
			            clean_ebook[4] = '\0';

			            if(strncmp(clean_ebook, "Ye", 2) == 0) {
			                strcpy(clean_ebook, "Yes");
			            } else if(strncmp(clean_ebook, "No", 2) == 0) {
			                strcpy(clean_ebook, "No");
			            }

			            printf("ID: %s\n", books[i].id);
			            printf("Title: %s\n", books[i].title);
			            printf("Author: %s\n", books[i].author);
			            printf("Copies: %d\n", books[i].copies);
			            printf("eBook Available: %s\n", clean_ebook);

			            if (books[i].shelf == 0) {
			                printf("Shelf Number: Not assigned (0)\n");
			            } else {
			                printf("Shelf Number: %d\n", books[i].shelf);
			            }

			            printf("Status: %s\n", books[i].copies > 0 ? "Available" : "Not Available");
			            printf("----------------------------------------\n");
			            isPresent = 1;
			        }
			    }

			    if(!isPresent) {
			        printf("No books found matching '%s'\n", searchTitle);
			        printf("----------------------------------------\n");
			    }
			    break;
			}


        	case 2: {
			    int memberId;
			    char bookIdInput[5];
			    time_t t = time(NULL);
			    struct tm *tm = localtime(&t);
			    char date[20];
			    strftime(date, sizeof(date), "%Y-%m-%d", tm);

			    if (numMembers == 0) {
			        printf("Error: No member data available. Please contact administrator.\n");
			        break;
			    }

			    printf("\nAvailable Members:\n");
			    printf("----------------------------------------\n");
			    for (int i = 0; i < numMembers; i++) {
			        printf("Member ID: %d, Name: %s\n", libraryMembers[i].id, libraryMembers[i].name);
			    }
			    printf("----------------------------------------\n");

			    printf("\nAvailable Books for Reservation:\n");
			    printf("----------------------------------------\n");
			    int isPresent = 0;
			    for (int i = 0; i < numBooks; i++) {
			        if (books[i].copies > 0) {
			            char clean_ebook[5];
			            strncpy(clean_ebook, books[i].ebook_available, 4);
			            clean_ebook[4] = '\0';
						if(strncmp(clean_ebook, "Ye", 2) == 0) {
						    strcpy(clean_ebook, "Yes");
						} else if(strncmp(clean_ebook, "No", 2) == 0) {
						    strcpy(clean_ebook, "No");
						}

			            printf("ID: %s\n", books[i].id);
			            printf("Title: %s\n", books[i].title);
			            printf("Author: %s\n", books[i].author);
			            printf("Copies: %d\n", books[i].copies);
			            printf("eBook Available: %s\n", clean_ebook);
			            printf("----------------------------------------\n");
			            isPresent = 1;
			        }
			    }

			    if (!isPresent) {
			        printf("No books are currently available for reservation\n");
			        printf("----------------------------------------\n");
			        break;
			    }

			    printf("Enter your member ID: ");
			    scanf("%d", &memberId);
			    getchar();

			    int memberExists = 0;
			    char memberName[50] = "";
			    for (int i = 0; i < numMembers; i++) {
			        if (libraryMembers[i].id == memberId) {
			            memberExists = 1;
			            strcpy(memberName, libraryMembers[i].name);
			            break;
			        }
			    }

			    if (!memberExists) {
			        printf("Invalid member ID. Please contact the librarian.\n");
			        break;
			    }

			    int memberReservations = 0;
			    for (int i = 0; i < numOfReservations; i++) {
			        if (bookings[i].memberId == memberId) {
			            memberReservations++;
			        }
			    }

			    if (memberReservations >= 3) {
			        printf("You have reached the maximum number of bookings (3).\n");
			        break;
			    }

			    printf("Enter book ID to reserve (format: 0001): ");
			    scanf("%4s", bookIdInput);
			    if (strlen(bookIdInput) != 4 || bookIdInput[0] < '0' || bookIdInput[0] > '9') {
			        printf("Invalid book ID format. Please enter a four-digit ID (e.g., 0001).\n");
			        break;
			    }

			    isPresent = 0;
			    for (int i = 0; i < numBooks; i++) {
			        if (strcmp(books[i].id, bookIdInput) == 0) {
			            if (books[i].copies > 0) {
			                isPresent = 1;
			                bookings[numOfReservations].reservationId = numOfReservations + 1;
			                bookings[numOfReservations].memberId = memberId;
			                strcpy(bookings[numOfReservations].bookId, books[i].id);
			                strcpy(bookings[numOfReservations].date, date);

			                saveCopiesField(books[i].id, books[i].copies - 1);

			                books[i].copies -= 1;

			                printf("\nReservation successful!\n");
			                printf("----------------------------------------\n");
			                printf("Reservation Details:\n");
			                printf("Reservation ID: %d\n", bookings[numOfReservations].reservationId);
			                printf("Member: %s\n", memberName);
			                printf("Book: %s\n", books[i].title);
			                printf("Date: %s\n", date);
			                printf("----------------------------------------\n");

			                numOfReservations++;
			                storeReservationDetails();
			            } else {
			                printf("Sorry, this book is not available for reservation.\n");
			            }
			            break;
			        }
			    }

			    if (!isPresent) {
			        printf("Invalid book ID or not available. Please try again.\n");
			    }

			    break;
			}


            case 3:
                printf("\nLibrary Services Information:\n");
                printf("----------------------------------------\n");
                printf("1. Opening Hours:\n");
                printf("   Monday-Friday: 9:00 AM - 8:00 PM\n");
                printf("   Saturday: 10:00 AM - 6:00 PM\n");
                printf("   Sunday: Closed\n\n");
                printf("2. Borrowing Rules:\n");
                printf("   - Maximum 3 books per member\n");
                printf("   - Loan period: 14 days\n");
                printf("   - Late fee: $0.50 per day\n\n");
                printf("3. Contact Information:\n");
                printf("   Phone: (555) 123-4567\n");
                printf("   Email: library@example.com\n");
                printf("----------------------------------------\n");
                break;

            case 4:
                return;

            default:
                printf("Invalid choice!\n");
        }
    }
}

void staff_menu(){
    int selectedOption;

    retrieveBookInfo();
    retrieveMembersDetails();
    retrieveReservationInfo();

    while(1) {
        printf("\n=== Library Staff Menu ===\n");
        printf("1. Member Assistance\n");
        printf("2. Shelf Management\n");
        printf("3. Digital Resource Assistance\n");
        printf("4. Exit\n");
        printf("Enter choice (1-4): ");
        scanf("%d", &selectedOption);

        switch(selectedOption) {
            case 1: memberAssistance(); break;
            case 2: shelfManagement(); break;
            case 3: digitalAssistance(); break;
            case 4:
                saveBookData();
                printf("Exiting program...\n");
                return;
            default: printf("Invalid choice!\n");
        }
    }
    return;
}

void shelfManagement() {
    int selectedOption;

    while(1) {
        printf("\n=== Shelf Management ===\n");
        printf("1. View all books\n");
        printf("2. Add/Update shelf number for a book\n");
        printf("3. Back to main menu\n");
        printf("Enter choice (1-3): ");
        scanf("%d", &selectedOption);

        switch(selectedOption) {

			case 1: {
			    printf("\nBooks:\n");
			    printf("----------------------------------------\n");
			    for(int i = 0; i < numBooks; i++) {
			        char clean_ebook[5];
			        strncpy(clean_ebook, books[i].ebook_available, 4);
			        clean_ebook[4] = '\0';

			        if(strncmp(clean_ebook, "Ye", 2) == 0) {
			            strcpy(clean_ebook, "Yes");
			        } else if(strncmp(clean_ebook, "No", 2) == 0) {
			            strcpy(clean_ebook, "No");
			        }

			        printf("ID: %s\n", books[i].id);
			        printf("Title: %s\n", books[i].title);
			        printf("Author: %s\n", books[i].author);
			        printf("Copies: %d\n", books[i].copies);
			        printf("eBook Available: %s\n", clean_ebook);
			        if (books[i].shelf == 0) {
			            printf("Shelf: Not yet assigned\n");
			        } else {
			            printf("Shelf: %d\n", books[i].shelf);
			        }
			        printf("----------------------------------------\n");
			    }
			    break;
			}
			case 2: {
			    char bookId[5];
			    int shelf;
			    int bookFound = 0;

			    printf("Enter book ID (4 digits): ");
			    scanf("%4s", bookId);

			    FILE *file = fopen("books.txt", "r");
			    if (file == NULL) {
			        printf("Error opening file.\n");
			        break;
			    }

			    FILE *tempFile = fopen("temp_books.txt", "w");
			    if (tempFile == NULL) {
			        printf("Error opening temporary file.\n");
			        fclose(file);
			        break;
			    }

			    char line[256];
			    char id[5], title[100], author[100], ebook_available[5];
			    int copies, currentShelf;

			    while (fgets(line, sizeof(line), file)) {
			        line[strcspn(line, "\n")] = 0;

			        for(int i = 0; line[i]; i++) {
			            if(!isprint(line[i]) && line[i] != ',' && line[i] != '\n') {
			                line[i] = '\0';
			                break;
			            }
			        }

			        int fieldsRead = sscanf(line, "%4[^,],%99[^,],%99[^,],%d,%4[^,],%d",
			               id, title, author, &copies, ebook_available, &currentShelf);

			        for(int i = 0; ebook_available[i]; i++) {
			            if(!isprint(ebook_available[i])) {
			                ebook_available[i] = '\0';
			                break;
			            }
			        }

			        if (strcmp(id, bookId) == 0) {
			            bookFound = 1;
			            printf("Current record: %s\n", line);

			            printf("Enter new shelf number: ");
			            scanf("%d", &shelf);

			            fprintf(tempFile, "%s,%s,%s,%d,%s,%d\n",
			                    id, title, author, copies, ebook_available, shelf);
			        } else {
			            if (fieldsRead == 6) {
			                fprintf(tempFile, "%s,%s,%s,%d,%s,%d\n",
			                        id, title, author, copies, ebook_available, currentShelf);
			            } else {
			                fprintf(tempFile, "%s,%s,%s,%d,%s\n",
			                        id, title, author, copies, ebook_available);
			            }
			        }
			    }

			    fclose(file);
			    fclose(tempFile);

			    if (!bookFound) {
			        printf("Book with ID %s not found.\n", bookId);
			        remove("temp_books.txt");
			    } else {
			        remove("books.txt");
			        rename("temp_books.txt", "books.txt");
			        printf("Shelf number updated to %d for book %s.\n", shelf, bookId);
			    }
			    break;
			}
            case 3:
                return;

            default:
                printf("Invalid choice!\n");
        }
    }
}

void digitalAssistance() {
    int selectedOption;

    while(1) {
        printf("\n=== Digital Resource Assistance ===\n");
        printf("1. View available e-resources\n");
        printf("2. Access guide for digital resources\n");
        printf("3. Back to main menu\n");
        printf("Enter choice (1-3): ");
        scanf("%d", &selectedOption);

        switch(selectedOption) {
            case 1: {
                FILE *fp = fopen("digital_resources.txt", "r");
                if(fp == NULL) {
                    printf("Error: Cannot open digital resources list.\n");
                    break;
                }

                printf("\nAvailable Digital Resources:\n");
                printf("----------------------------------------\n");

                char resource[100];
                int count = 1;
                while(fgets(resource, sizeof(resource), fp)) {
                    resource[strcspn(resource, "\n")] = 0;
                    printf("%d. %s\n", count++, resource);
                }

                printf("----------------------------------------\n");
                fclose(fp);
                break;
            }

            case 2:
                printf("\nDigital Resources Access Guide:\n");
                printf("----------------------------------------\n");
                printf("1. Visit library website\n");
                printf("2. Login with library card\n");
                printf("3. Select desired resource\n");
                printf("4. Download or stream content\n");
                printf("----------------------------------------\n");
                break;

            case 3:
                return;

            default:
                printf("Invalid choice!\n");
        }
    }
}
