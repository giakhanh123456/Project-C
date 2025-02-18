//noi khai bao 
#ifndef FUNCTION_H
#define FUNCTION_H
#include <stdbool.h>
#include "datatype.h">

//ham them sach
void addBook();

//ham danh sach sach
void displayBooks();

//ham menu chinh
void mainMenu();

//ham menu thu vien
void libraryMenu();

//ham sua sach
void editBook();

//ham xoa sach
void deleteBook();

//ham sap xep sach theo gia tien
void sortBooks();

//ham tim kiem sach theo ten
void searchBookByTitle();

//ham viet danh sach vao file
void saveToFile();

//ham doc danh sach trong file
void loadFromFile();

// Kiem tra nam nhuan
bool isLeapYear(int year);

// Kiem tra ngay hop le
bool isValidDate(int day, int month, int year);

// Ham nhap ngay tu nguoi dung
void inputDate(Date *date);

#endif

