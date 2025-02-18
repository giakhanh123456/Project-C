//noi khai bao thu vien va struct
#include <stdbool.h>
#define MAX_BOOK 100
#ifndef DATATYPE_H
#define DATATYPE_H
//struct ngay thang nam
typedef struct {
    int day, month, year;
} Date;

typedef struct {
    char bookId[10];
    char title[30];
    char author[20];
    int quantity;
    int price;
    Date publication;
} Book;

//struct khach hang
typedef struct {
    char memberId[10];
    char name[20];
    char phone[10];
    int status;
    Book borrowedBooks[5]; 
} Member;

#endif
