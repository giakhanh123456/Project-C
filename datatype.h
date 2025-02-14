//noi khai bao thu vien va struct
#ifndef DATATYPE_H
#define DATATYPE_H
#include <stdbool.h>
#define MAX_BOOK 100
//struct ngay thang nam
typedef struct {
    int day;
    int month;
    int year;
} Date;

typedef struct {
    char bookId[10];
    char title[30];
    char author[20];
    int quantity;
    int price;
    Date publication;
} Book;
extern Book book[MAX_BOOK];
extern int bookCount;

//struct khach hang
typedef struct {
	int memberId;
	char name[20];
	char phone[10];
	bool status;
	Book BorrowedBooks[MAX_BOOK];
} Member;

#endif
