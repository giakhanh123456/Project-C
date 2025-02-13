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
				break;     
            default:
            	break;
        }
        if(choice == 3) {
        	system("cls");
        	printf("\t=========THANK YOU=========\n");
        	printf("\t=========SEE YOU SOON======\n");
        	exit(0);
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
    printf("\t[4] Delete Book\n");
    printf("\t[5] Sort Book\n");
    printf("\t[6] Search Book\n");
    printf("\t[7] Return\n");
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
				deleteBook();
				break;
			case 5:
				sortBooks();
				break;
			case 6:
				searchBookByTitle();
				break;
			case 7:
				return;     
            default:
                break;
        }
	}
}   

//ham them sach
void addBook() {
	system("cls");
	printf("\n\t****ADD BOOK****\n");
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
    char back;
   	do {
        printf("\nGo back(b)? or Exit(0)?: ");
        scanf(" %c", &back);
        if (back == 'b') {
        	system("cls");
            return;
        }else if (back == '0') {
            system("cls");
            mainMenu();
        }
    } while (back != 'b' && back != '0');
}

//ham danh sach sach
void displayBooks() {
	system("cls");
	printf("\n\t****DISPLAY BOOKS****");
	if (bookCount == 0) {
        printf("\nNo books available in the library.\n\n");
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
		char back;
   	do {
        printf("\nGo back(b)? or Exit(0)?: ");
        scanf(" %c", &back);
        if (back == 'b') {
        	system("cls");
            return;
        }else if (back == '0') {
            system("cls");
            mainMenu();
        }
    } while (back != 'b' && back != '0');
}

//ham sua sach
void editBook() {
    char editId[10];
    int found = 0;
    system("cls");
    printf("\n\t****EDIT BOOK****\n");
    printf("\nEnter the Book ID to edit: ");
    scanf("%s", editId);
//tim sach theo ID
	int i;
    for(i = 0; i < bookCount; i++) {
        if (strcmp(book[i].bookId, editId) == 0) {
            found = 1;
            printf("\n Current Book Details:\n");
            printf("-------------------------\n");
            printf("Book ID: %s\n", book[i].bookId);
            printf("Title: %s\n", book[i].title);
            printf("Author: %s\n", book[i].author);
            printf("Quantity: %d\n", book[i].quantity);
            printf("Price: %d\n", book[i].price);
            printf("Publication Date: %02d/%02d/%04d\n", book[i].publication.day, book[i].publication.month, book[i].publication.year);
            printf("\n\t****UPDATE THE NEW BOOK****\n");
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
        char back;
   	do {
        printf("\nGo back(b)? or Exit(0)?: ");
        scanf(" %c", &back);
        if (back == 'b') {
        	system("cls");
            return;
        }else if (back == '0') {
            system("cls");
            mainMenu();
        }
    } while (back != 'b' && back != '0');
}

//ham xoa sach
void deleteBook() {
	system("cls");
	printf("\n\t****DELETE BOOK****\n");
    char bookId[10];
    printf("\nEnter Book ID to delete: ");
    scanf("%s", bookId);
    int index = bookId;
    int i;
    for (i = 0; i < bookCount; i++) {
        if (strcmp(book[i].bookId, bookId) == 0) {
            index = i;
            break;
        }
    }
    if (index < 0 || index > bookCount) {
        printf("\nBook ID not found!\n");
        return;
    }
    for (i = index; i < bookCount - 1; i++) {
            book[i] = book[i + 1];
        }
        bookCount--;
        printf("\nBook deleted successfully!\n");
       char back;
   	do {
        printf("\nGo back(b)? or Exit(0)?: ");
        scanf(" %c", &back);
        if (back == 'b') {
        	system("cls");
            return;
        }else if (back == '0') {
            system("cls");
            mainMenu();
        }
    } while (back != 'b' && back != '0');
}

//ham sap xep sach theo gia tien
void sortBooks() {
	system("cls");
	printf("\n\t****SORT BOOKS****\n");
    int order;
    printf("\t1. Ascending Order\n");
    printf("\t2. Descending Order\n");
    printf("\tEnter your choice: ");
    scanf("%d", &order);
    int i, j;
    for (i = 0; i < bookCount - 1; i++) {
        for (j = i + 1; j < bookCount; j++) {
            int swap = 0;
            if ((order == 1 && book[i].price > book[j].price) || (order == 2 && book[i].price < book[j].price)) {
                swap = 1;
            }
            if (swap) {
                struct Book temp = book[i];
                book[i] = book[j];
                book[j] = temp;
            }
        }
    }
    printf("\nBooks sorted successfully!\n");
    displayBooks();
}

//ham tim kiem sach theo ten
void searchBookByTitle() {
	system("cls");
    printf("\n\t****SEARCH BOOK BY TITLE****\n");
    char searchTitle[30];
    printf("\nEnter book title to search: ");
    scanf(" %s", searchTitle);
    int found = 0;
    printf("|==========|==============================|====================|==========|==========|==========|\n");
    printf("|%-10s|%-30s|%-20s|%-10s|%-10s|%-10s|\n", "Book ID", "Title", "Author", "Quantity", "Price", "Pub Date");
	printf("|==========|==============================|====================|==========|==========|==========|\n");    int i;
    for (i = 0; i < bookCount; i++) {
        if (strstr(book[i].title, searchTitle) != NULL) {
            printf("|%-10s|%-30s|%-20s|%-10d|%-10d|%02d/%02d/%04d|\n",
                   book[i].bookId, book[i].title, book[i].author,
                   book[i].quantity, book[i].price,
                   book[i].publication.day, book[i].publication.month, book[i].publication.year);
            printf("|----------|------------------------------|--------------------|----------|----------|----------|\n");
            found = 1;
        }
    }
    if (!found) {
        printf("\nNo books found with the given title!\n");
    }
        char back;
   	do {
        printf("\nGo back(b)? or Exit(0)?: ");
        scanf(" %c", &back);
        if (back == 'b') {
        	system("cls");
            return;
        }else if (back == '0') {
            system("cls");
            mainMenu();
        }
    } while (back != 'b' && back != '0');
}
