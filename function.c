//noi khai trien ham
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "datatype.h"

Book book[MAX_BOOK];
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
			saveBooksToFile();
        	system("cls");
        	printf("\t=========THANK YOU=========\n");
        	printf("\t=========SEE YOU SOON======\n");
        	exit(0);     
            default:
            	break;
        }
	}
}

//ham menu thu vien
void libraryMenu() {
	int select;
	while(1){
	system("cls");
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
                saveBooksToFile();
                break;
            case 2:
                displayBooks();
                break;
			case 3:
				editBook();
				saveBooksToFile();
				break;
			case 4:
				deleteBook();
				saveBooksToFile();
				break;
			case 5:
				sortBooks();
				saveBooksToFile();
				break;
			case 6:
				searchBookByTitle();
				break;
			case 7:
				saveBooksToFile();
				return;     
            default:
                continue;
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
    Book newBook;
	printf("\nEnter new book details:\n");
    int isDuplicate;
    do {
        isDuplicate = 0;
        printf("ID: ");
        scanf("%s", newBook.bookId);
        int i;
        for (i = 0; i < bookCount; i++) {
            if (strcmp(book[i].bookId, newBook.bookId) == 0) {
                printf("ERROR: Book ID already exists! Please enter a unique ID.\n");
                isDuplicate = 1;
                break;
            }
        }
    } while (isDuplicate);
    strcpy(book[bookCount].bookId, newBook.bookId);
    getchar();
    do {
        isDuplicate = 0;
        printf("Title: ");
        scanf(" %[^\n]", newBook.title);
        int i;
        for (i = 0; i < bookCount; i++) {
            if (strcmp(book[i].title, newBook.title) == 0) {
                printf("\nERROR: Book Title already exists! Please enter a unique title.\n");
                isDuplicate = 1;
                break;
            }
        }
    } while (isDuplicate);
    strcpy(book[bookCount].title, newBook.title);
    getchar();
    printf("Author: "); 
	scanf("%[^\n]", book[bookCount].author);
    printf("Quantity: "); 
	scanf("%d", &book[bookCount].quantity);
    printf("Price: "); 
	scanf("%d", &book[bookCount].price);
    printf("Publication Date (dd/mm/yyyy): ");
    scanf("%d %d %d", &book[bookCount].publication.day, &book[bookCount].publication.month, &book[bookCount].publication.year);
    book[bookCount] = newBook;
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
            int isDuplicate;
            char newTitle[30];
           	do {
                isDuplicate = 0;
                printf("\nNew Title: ");
                fflush(stdin);
                scanf(" %[^\n]", newTitle);
				int j;
                for (j = 0; j < bookCount; j++) {
                    if (j != i && strcmp(book[j].title, newTitle) == 0) {
                        printf("\nERROR: Book title already exists! Please enter a different title.\n");
                        isDuplicate = 1;
                        break;
                    }
                }
            } while (isDuplicate);
            strcpy(book[i].title, newTitle);
    		getchar();
            printf("New Author: ");
            scanf(" %[^\n]", book[i].author);
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
    int index = -1;
    int i;
    for (i = 0; i < bookCount; i++) {
        if (strcmp(book[i].bookId, bookId) == 0) {
            index = i;
            break;
        }
    }
    if (index == -1) {
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
                Book temp = book[i];
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
    scanf(" %[^\n]", searchTitle);
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

//ham viet danh sach vao file
void saveBooksToFile() {
    FILE *file = fopen("Book.bin", "wb");
    if (file == NULL) {
        printf("\nError: Unable to open file for writing!\n");
        return;
    }
    if (fwrite(&bookCount, sizeof(int), 1, file) != 1) {
        printf("\nError writing book count!\n");
        fclose(file);
        return;
    }
    if (fwrite(book, sizeof(Book), bookCount, file) != bookCount) {
        printf("\nError writing book list!\n");
        fclose(file);
        return;
    }
    fclose(file);
    printf("\nSuccessfully saved %d books to file!\n", bookCount);
}

//ham doc danh sach trong file
void loadBooksFromFile() {
    FILE *file = fopen("Book.bin", "rb");
    if (file == NULL) {
        printf("\nNo data file found, initializing an empty list.\n");
        return;
    }
    if (fread(&bookCount, sizeof(int), 1, file) != 1) {
        printf("\nError reading book count!\n");
        fclose(file);
        bookCount = 0;
        return;
    }
    if (bookCount > MAX_BOOK || fread(book, sizeof(Book), bookCount, file) != bookCount) {
        printf("\nError reading book list! The file may be corrupted.\n");
        fclose(file);
        bookCount = 0;
        return;
    }
    fclose(file);
    printf("\nSuccessfully loaded %d books from file!\n", bookCount);
}


