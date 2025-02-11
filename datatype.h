//noi khai bao thu vien va struct
#include <stdbool.h>
#define MAX_BOOK 100
//struct ngay thang nam
struct Date {
	int day, month, year;
};

//struct sach
struct Book {
	char bookId[10];
	char title[30];
	char author[20];
	int quantity;
	int price;
	struct Date publication;
};

//struct khach hang
struct Member {
	char memberId[10];
	char name[20];
	char phone[10];
	bool status;
	struct Book BorrowedBooks[];
};
