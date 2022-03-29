/*
 ============================================================================
 Name        : fnaf.c
 Author      : Maxim Savenkov
 Version     :
 Copyright   : © Maxim Savenkov 2022
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#import <time.h>
#import <string.h>
#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define YELLOW "\x1b[33m"
#define BLUE "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN "\x1b[36m"
#define RESET "\x1b[0m"

void init();
void scup();
void msleep(int t);
void listen();
void selectM(int i, int p);
void rebootM(int i);
int v = 1;
int c = 1;
int a = 1;
void gotoxy(int x, int y) {
	printf("%c[%d;%df",0x1B,y,x);
}
short unsigned int selection = 1;

int main(void) {
	init();
}

void init() {
	system("clear");
	printf("\x1b[0m\n\n\n\n\n\n\n\n\n\n\n             |^^^^^^^^^^|");
	gotoxy(0, 0);
	system("/bin/stty raw");
	char c = 0;
	while (c != 'w') {
		c = getchar();
	}
	system("/bin/stty cooked");
	scup();
	init();
}

void scup() {
	srand(time(NULL));
	v = 0;
	c = 0;
	a = 0;
	char one[128] = "\x1b[31merror\x1b[0m";
	char two[128] = "\x1b[31merror\x1b[0m";
	char three[128] = "\x1b[31merror\x1b[0m";
	if (rand() % 6 > 3) {
		strcpy(one, "");
		a = 1;
	}
	if (rand() % 7 > 2) {
		strcpy(two, "");
		c = 1;
	}
	if (rand() % 7 > 1) {
		strcpy(three, "");
		v = 1;
	}
	selection = 1;
	system("clear");
	printf(""
			"\n system restart"
			"\n menu>>>"
			"\n"
			"\n  >>>  audio devices  %s"
			"\n       camera systems %s"
			"\n       ventilation    %s"
			"\n"
			"\n       reboot all"
			"\n       exit\n", one, two, three);
	listen();
}

void selectM(int i, int p) {
	if (i < 4) {
		gotoxy(0, i + 4);
		printf("  >>>");
	}
	else {
		gotoxy(0, i + 5);
		printf("  >>>");
	}
	if (p < 4) {
		gotoxy(0, p + 4);
		printf("     ");
	}
	else {
		gotoxy(0, p + 5);
		printf("     ");
	}
	gotoxy(0, 11);
}

void listen() {
	int c;
	system ("/bin/stty raw");
	c = getchar();
	switch(c) {
	case 115:
		if (selection < 5) {
			selectM(selection + 1, selection);
			selection++;
		}
		else {
			selectM(1, selection);
			selection = 1;
		}
		break;
	case 119:
		if (selection > 1) {
			selectM(selection - 1, selection);
			selection--;
		}
		else {
			selectM(5, selection);
			selection = 5;
		}
		break;
	case 13:
		if (selection == 5) {
			if (v && c && a) {
				system("/bin/stty cooked");
				return;
			}
			break;
		}
		else {
			rebootM(selection);
		}
		break;
	default:
		break;
	}
	//up = 279165
	//down = 279166
	//enter = 13
	//e = 101
	system ("/bin/stty cooked");
	listen();
}

void rebootM(int i) {
	srand(time(NULL));
	if (i == 4) {
		for (int j = 0; j < (5 + rand() % 4); j++) {
				gotoxy(23, i + 5);
				fflush(stdout);
				msleep(250);
				gotoxy(24, i + 5);
				fflush(stdout);
				msleep(250);
				gotoxy(25, i + 5);
				fflush(stdout);
				msleep(250);
				gotoxy(26, i + 5);
				fflush(stdout);
				msleep(250);
				gotoxy(27, i + 5);
				fflush(stdout);
				msleep(250);
			}
			gotoxy(22, 5);
			printf("         ");
			gotoxy(22, 6);
			printf("         ");
			gotoxy(22, 7);
			printf("         ");
			gotoxy(0, 11);
			fflush(stdout);
			a = 1;
			c = 1;
			v = 1;
	}
	else {
		gotoxy(22, i + 4);
		printf("         ");
		for (int j = 0; j < (3 + rand() % 3); j++) {
			gotoxy(23, i + 4);
			fflush(stdout);
			msleep(250);
			gotoxy(24, i + 4);
			fflush(stdout);
			msleep(250);
			gotoxy(25, i + 4);
			fflush(stdout);
			msleep(250);
			gotoxy(26, i + 4);
			fflush(stdout);
			msleep(250);
			gotoxy(27, i + 4);
			fflush(stdout);
			msleep(250);
		}
		gotoxy(0, 11);
		if (i == 1) {
			a = 1;
		}
		else if (i == 2) {
			c = 1;
		}
		else if (i == 3) {
			v = 1;
		}
	}
}

void msleep(int t) {
	usleep(t * 1000);
}
