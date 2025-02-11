//noi khai trien ham
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "datatype.h"

struct Book book[MAX_BOOK];
int bookCount = 0;

//ham menu chinh
void mainMenu(){
	int choice;
	while(1){
	system("cls");
    printf("***Library Management System Using C***\n");
    printf("\n\t   CHOOSE THE ROLE\n");
    printf("\t======================\n");
    printf("\t[1] Library Management\n");
    printf("\t[2] Customer Management\n");
    printf("\t[3] Exit\n");
    printf("\t======================\n");
    printf("\tEnter your choice: ");
    scanf("%d", &choice);
    switch (choice) {
            case 1:
            	system("cls");
                libraryMenu();
                break;
            case 2:
            	system("cls");
                break;
			case 3:
				exit(0);     
            default:
                printf("Invalid choice! Please try again.\n");
        }
	}
}

//ham menu thu vien
void libraryMenu(){
	int select;
	while(1){
    printf("***Library Management System Using C***\n");
    printf("\n\t\tMENU\n");
    printf("\t======================\n");
    printf("\t[1] Add Book\n");
    printf("\t[2] Display Book List\n");
    printf("\t[3] Edit Book\n");
    printf("\t[4] Return\n");
    printf("\t======================\n");
    printf("\tEnter your choice: ");
    scanf("%d", &select);
    switch (select) {
            case 1:
                addBook();
                break;
            case 2:
                displayBooks();
                break;
			case 3:
				editBook();
				break;
			case 4:
				return;     
            default:
                printf("Invalid choice! Please try again.\n");
        }
	}
}   

//ham them sach
void addBook() {
	int back;
	system("cls");
		if (bookCount >= MAX_BOOK) {
        	printf("\nThe library is full!\n");
        	return;
        }
	printf("\nEnter new book details:\n");
    printf("Book ID: "); 
	scanf("%s", book[bookCount].bookId);
    printf("Title: "); 
	scanf("%s", book[bookCount].title);
    printf("Author: "); 
	scanf("%s", book[bookCount].author);
    printf("Quantity: "); 
	scanf("%d", &book[bookCount].quantity);
    printf("Price: "); 
	scanf("%d", &book[bookCount].price);
    printf("Publication Date (dd/mm/yyyy): ");
    scanf("%d %d %d", &book[bookCount].publication.day, &book[bookCount].publication.month, &book[bookCount].publication.year);
    bookCount++;
    printf("Book added successfully!\n\n");
    do {
    printf("\nEnter 0 to go back to the main menu: ");
    scanf("%d", &back);
    if (back == 0){
    	system("cls");
    	}
	}while(back != 0);
}

//ham danh sach sach
void displayBooks() {
	int released;
	system("cls");
	if (bookCount == 0) {
        printf("No books available in the library.\n\n");
    	}else{
	printf("\n\t\t**** All Book ****\n\n");
	printf("|==========|==============================|====================|==========|==========|==========|\n");
    printf("|%-10s|%-30s|%-20s|%-10s|%-10s|%-10s|\n", "Book ID", "Title", "Author", "Quantity", "Price", "Pub Date");
    printf("|==========|==============================|====================|==========|==========|==========|\n");
    int i;
    for(i = 0; i < bookCount; i++) {
    	printf("|%-10s|%-30s|%-20s|%-10d|%-10d|%02d/%02d/%04d|\n",
               book[i].bookId, book[i].title, book[i].author,
               book[i].quantity, book[i].price,
               book[i].publication.day, book[i].publication.month, book[i].publication.year);
        printf("|----------|------------------------------|--------------------|----------|----------|----------|\n");
			}
		}
		do {
		printf("\nEnter 0 to go back to the main menu: ");
    	scanf("%d", &released);
    	if (released == 0){
    	system("cls");
    	}
	}while(released != 0);
}

//ham sua sach
void editBook() {
	int exit;
    char editId[10];
    int found = 0;
    system("cls");
    printf("\nEnter the Book ID to edit: ");
    scanf("%s", editId);
//tim sach theo ID
	int i;
    for(i = 0; i < bookCount; i++) {
        if (strcmp(book[i].bookId, editId) == 0) {
            found = 1;
            printf("\nCurrent Book Details:\n");
            printf("Book ID: %s\n", book[i].bookId);
            printf("Title: %s\n", book[i].title);
            printf("Author: %s\n", book[i].author);
            printf("Quantity: %d\n", book[i].quantity);
            printf("Price: %d\n", book[i].price);
            printf("Publication Date: %02d/%02d/%04d\n", book[i].publication.day, book[i].publication.month, book[i].publication.year);
            printf("\nEnter new details:\n");
            printf("New Title: ");
            scanf("%s", book[i].title);
            printf("New Author: ");
            scanf("%s", book[i].author);
            printf("New Quantity: ");
            scanf("%d", &book[i].quantity);
            printf("New Price: ");
            scanf("%d", &book[i].price);
            printf("New Publication Date (dd/mm/yyyy): ");
            scanf("%d %d %d", &book[i].publication.day, &book[i].publication.month, &book[i].publication.year);
            printf("\nBook details updated successfully!\n");
        }
    }
    if (!found) {
        printf("\nBook ID not found!\n");
    }
    do {
		printf("\nEnter 0 to go back to the main menu: ");
    	scanf("%d", &exit);
    if (exit == 0){
    	system("cls");
    	}
	}while(exit != 0);
}

