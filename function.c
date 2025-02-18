//noi khai trien ham
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "datatype.h"
#include "function.h"

Book book[MAX_BOOK];
int bookCount = 0;

// Ham luu du lieu vao file
void saveToFile() {
    FILE *file = fopen("book.bin", "wb");
    if (file == NULL) {
        perror("Error opening file for writing");
        exit(1); // Exit with an error code
    }
    if (fwrite(&bookCount, sizeof(int), 1, file) != 1) {
        perror("Error writing book count to file");
        fclose(file);
        exit(1);
    }
    if (fwrite(book, sizeof(Book), bookCount, file) != bookCount) {
        perror("Error writing books to file");
        fclose(file);
        exit(1);
    }
    fclose(file);
}

// Hàm doc du lieu tu file
void loadFromFile() {
    FILE *file = fopen("book.bin", "rb");
    if (file == NULL) {
        // File doesn't exist or error opening, handle as needed (e.g., start with an empty library)
        return;
    }
    if (fread(&bookCount, sizeof(int), 1, file) != 1) {
        perror("Error reading book count from file");
        fclose(file);
        return; // Or exit, depending on your error handling
    }
    if (bookCount > MAX_BOOK) {  // Important Check!
        fprintf(stderr, "Error: Book count in file exceeds MAX_BOOK.\n");
        bookCount = 0; // Or handle as appropriate.
        fclose(file);
        return;
    }
    if (fread(book, sizeof(Book), bookCount, file) != bookCount) {
        perror("Error reading books from file");
        fclose(file);
        return; // Or exit
    }
    fclose(file);
}

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
			saveToFile();
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
    getchar();
    do {
        isDuplicate = 0;
        printf("Title: ");
        fgets(newBook.title, sizeof(newBook.title), stdin);
    	newBook.title[strcspn(newBook.title, "\n")] = '\0';
        int i;
        for (i = 0; i < bookCount; i++) {
            if (strcmp(book[i].title, newBook.title) == 0) {
                printf("\nERROR: Book Title already exists! Please enter a unique title.\n");
                isDuplicate = 1;
                break;
            }
        }
    } while (isDuplicate);
    printf("Author: "); 
	fgets(newBook.author, sizeof(newBook.author), stdin);
    newBook.author[strcspn(newBook.author, "\n")] = '\0';
    printf("Quantity: ");
    scanf("%d", &newBook.quantity);
    printf("Price: "); 
	scanf("%d", &newBook.price);
	getchar();
    inputDate(&newBook.publication);
    strcpy(book[bookCount].bookId, newBook.bookId);
    strcpy(book[bookCount].title, newBook.title);
    strcpy(book[bookCount].author, newBook.author);
    book[bookCount].quantity = newBook.quantity;
    book[bookCount].price = newBook.price;
    book[bookCount].publication = newBook.publication;
    book[bookCount++] = newBook;
    saveToFile();
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
    if (book[i].publication.day < 1 || book[i].publication.day > 31 ||
    book[i].publication.month < 1 || book[i].publication.month > 12 ||
    book[i].publication.year < 0) {
    printf("|%-10s|%-30s|%-20s|%-10d|%-10d|INVALID DATE|\n",
           book[i].bookId, book[i].title, book[i].author,
           book[i].quantity, book[i].price);
	} else {
    printf("|%-10s|%-30s|%-20s|%-10d|%-10d|%02d/%02d/%04d|\n",
           book[i].bookId, book[i].title, book[i].author,
           book[i].quantity, book[i].price,
           book[i].publication.day, book[i].publication.month, book[i].publication.year);
	}
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
	int found = 0;
    char editId[10];
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
                printf("New Title: ");
                fgets(newTitle, sizeof(newTitle), stdin);
            	newTitle[strcspn(book[i].title, "\n")] = '\0';
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
            fgets(book[i].author, sizeof(book[i].author), stdin);
            book[i].author[strcspn(book[i].author, "\n")] = '\0';
            printf("New Quantity: ");
            scanf("%d", &book[i].quantity);
            getchar();
            printf("New Price: ");
            scanf("%d", &book[i].price);
    		inputDate(&book[i].publication); 
            printf("\nBook details updated successfully!\n");
            saveToFile();
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
       	saveToFile();
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
    saveToFile();
    displayBooks();
}

//ham tim kiem sach theo ten
void searchBookByTitle() {
	system("cls");
    printf("\n\t****SEARCH BOOK BY TITLE****\n");
    char searchTitle[30];
    getchar();
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

// Kiem tra nam nhuan
bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// Kiem tra ngay hop le
bool isValidDate(int day, int month, int year) {
    if (year < 1 || year > 9999 || month < 1 || month > 12 || day < 1) return false;
    int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (isLeapYear(year)) daysInMonth[2] = 29;
    return day <= daysInMonth[month];
}

// Ham nhap ngay tu nguoi dung
void inputDate(Date *date) {
    char inputBuffer[100];
    int num_read;
    do { 
        printf("Enter Publication Date (dd mm yyyy): ");
        if (fgets(inputBuffer, sizeof(inputBuffer), stdin) == NULL) {
            perror("Error reading input");
            return; 
        }
        inputBuffer[strcspn(inputBuffer, "\n")] = 0; 
        if (strlen(inputBuffer) == 0) { 
            printf("No input provided. Please enter the date.\n");
            continue; 
        }
        num_read = sscanf(inputBuffer, "%d %d %d", &date->day, &date->month, &date->year);
        if (num_read != 3) {
            printf("Invalid input format. Please enter numbers separated by spaces.\n");
        } else if (!isValidDate(date->day, date->month, date->year)) {
            printf("Invalid date! Please enter a valid date.\n");
        }
    } while (num_read != 3 || !isValidDate(date->day, date->month, date->year));
}




