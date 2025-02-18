#include <stdio.h>
#include <stdlib.h>
#include "function.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	system("cls");
	system("color 3");
	loadFromFile();
	mainMenu();
	return 0;
}
