#include <stdio.h>
#include <string.h>
#include <windows.h>
#include "helpers.h"

int pomocne_pole[VYSKA][SIRKA] = { { 0 } };

int test(int num, int min, int max) {
	if ((num >= min) && (num <= max))
		return 1;
	return 0;
}

void zobraz(char pole[VYSKA][SIRKA], int r, int c) {
	int i, j;
	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, white);
	for (i = 0; i < r; i++) {
		for (j = 0; j < c; j++) {
			if (pomocne_pole[i][j]!=0) //nastavenie farby textu
				SetConsoleTextAttribute(hConsole, green);
			else
				SetConsoleTextAttribute(hConsole, white);
			printf("%c ", pole[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void zobrazZoznamSlov(char zoznam[POCET_SLOV][MAX_DLZKA_SLOVA], int poc_slov, int oznacene) {
	int i, j;
	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, white);
	for (i = 0; i < poc_slov; i++) {

		if (i == oznacene) //nastavenie farby
			SetConsoleTextAttribute(hConsole, green);
		else
			SetConsoleTextAttribute(hConsole, white);

		for (j = 0; j < (int)strlen(zoznam[i]);j++) {
			printf("%c", zoznam[i][j]);
		}

		if (i != poc_slov - 1) //na konci nebude ciarka
			printf(", ");
		else
			printf("\n");
	}

	SetConsoleTextAttribute(hConsole, white);
}

int check_up(char slovo[], char pole[VYSKA][SIRKA], int poz_r, int poz_c) {
	int i, length, new_r;
	length = strlen(slovo);
	new_r = poz_r - length + 1;
	if (test(new_r, 0, VYSKA - 1) == 0) {
		return 0;
	}
	else {
		for (i = poz_r; i >= (poz_r - length + 1); i--) {
			if (pole[i][poz_c] != slovo[poz_r - i]) {
				return 0;
			}
		}
	}
	return 1;
}

int check_down(char slovo[], char pole[VYSKA][SIRKA], int poz_r, int poz_c) {
	int i, length, new_r;
	length = strlen(slovo);
	new_r = poz_r + length - 1;
	if (test(new_r, 0, VYSKA - 1) == 0) {
		return 0;
	}
	else {
		for (i = poz_r; i <= (poz_r + length - 1); i++) {
			if (pole[i][poz_c] != slovo[i - poz_r]) {
				return 0;
			}
		}
	}
	return 1;
}

int check_left(char slovo[], char pole[VYSKA][SIRKA], int poz_r, int poz_c) {
	int i, length, new_c;
	length = strlen(slovo);
	new_c = poz_c - length + 1;
	if (test(new_c, 0, SIRKA - 1) == 0) {
		return 0;
	}
	else {
		for (i = poz_c; i >= (poz_c - length + 1); i--) {
			if (pole[poz_r][i] != slovo[poz_c-i]) {
				return 0;
			}
		}
	}
	return 1;
}

int check_right(char slovo[], char pole[VYSKA][SIRKA], int poz_r, int poz_c) {
	int i, length, new_c;
	length = strlen(slovo);
	new_c = poz_c + length - 1;
	if (test(new_c, 0, SIRKA - 1) == 0) {
		return 0;
	}
	else {
		for (i = poz_c; i <= (poz_c + length - 1); i++) {
			if (pole[poz_r][i] != slovo[i-poz_c]) {
				return 0;
			}
		}
	}
	return 1;
}


int check_left_up(char slovo[], char pole[VYSKA][SIRKA], int poz_r, int poz_c) {
	int i, length, new_r, new_c;
	length = strlen(slovo);
	new_r = poz_r - length + 1;
	new_c = poz_c - length + 1;
	if (test(new_r, 0, VYSKA - 1) == 0 || test(new_c, 0, SIRKA - 1) == 0) {
		return 0;
	}
	else {
		for (i = poz_r; i >= (poz_r - length + 1); i--) {
			if (pole[i][i + poz_c - poz_r] != slovo[poz_r - i]) {
				return 0;
			}
		}
	}
	return 1;
}

int check_right_down(char slovo[], char pole[VYSKA][SIRKA], int poz_r, int poz_c) {
	int i, length, new_r, new_c;
	length = strlen(slovo);
	new_r = poz_r + length - 1;
	new_c = poz_c + length - 1;
	if (test(new_r, 0, VYSKA - 1) == 0 || test(new_c, 0, SIRKA - 1) == 0) {
		return 0;
	}
	else {
		
		for (i = poz_r; i <= (poz_r + length - 1); i++) {
			if (pole[i][i + poz_c - poz_r] != slovo[i-poz_r]) {
				return 0;
			}
		}
	}
	return 1;
}

int check_right_up(char slovo[], char pole[VYSKA][SIRKA], int poz_r, int poz_c) {
	int i, length, new_r, new_c;
	length = strlen(slovo);
	new_r = poz_r - length + 1;
	new_c = poz_c + length - 1;
	if (test(new_r, 0, VYSKA - 1) == 0 || test(new_c, 0, SIRKA - 1) == 0) {
		return 0;
	}
	else {
		for (i = poz_r; i >= (poz_r - length + 1); i--) {
			if (pole[i][poz_c + poz_r - i] != slovo[poz_r - i]) {
				return 0;
			}
		}
	}
	return 1;
}

int check_left_down(char slovo[], char pole[VYSKA][SIRKA], int poz_r, int poz_c) {
	int i, length, new_r, new_c;
	length = strlen(slovo);
	new_r = poz_r + length - 1;
	new_c = poz_c - length + 1;
	if (test(new_r, 0, VYSKA - 1) == 0 || test(new_c, 0, SIRKA - 1) == 0) {
		return 0;
	}
	else {

		for (i = poz_r; i <= (poz_r + length - 1); i++) {
			if (pole[i][poz_c + poz_r - i] != slovo[i - poz_r]) {
				return 0;
			}
		}
	}
	return 1;
}


void najdiSlovo(char slovo[], char pole[VYSKA][SIRKA], int r, int c) {
	int i, j, length, k;
	length = strlen(slovo);
	for (i = 0; i < r; i++) {
		for (j = 0; j < c; j++) {
			if (pole[i][j] == slovo[0]) {
				//hore
				if (check_up(slovo, pole, i, j)) {
					for (k = i; k >= (i - length + 1); k--) {
						pomocne_pole[k][j] = 1;
					}
				}
				else if (check_down(slovo, pole, i, j)) {
					for (k = i; k <= (i + length - 1); k++) {
						pomocne_pole[k][j] = 1;
					}
				}
				else if (check_left(slovo, pole, i, j)) {
					for (k = j; k >= (j - length + 1); k--) {
						pomocne_pole[i][k] = 1;
					}
				}
				else if (check_right(slovo, pole, i, j)) {
					for (k = j; k <= (j + length - 1); k++) {
						pomocne_pole[i][k] = 1;
					}
				}
				else if (check_left_up(slovo, pole, i, j)) {
					for (k = i; k >= (i - length + 1);k--) {
						pomocne_pole[k][k + j - i] = 1;
					}
				}
				else if (check_right_down(slovo, pole, i, j)) {
					for (k = i; k <= (i + length - 1); k++) {
						pomocne_pole[k][k + j - i] = 1;
					}
				}
				else if (check_right_up(slovo, pole, i, j)) {
					for (k = i; k >= (i - length + 1); k--) {
						pomocne_pole[k][i+j-k] = 1;
					}
				}
				else if (check_left_down(slovo, pole, i, j)) {
					for (k = i; k <= (i + length - 1); k++) {
						pomocne_pole[k][i+j-k] = 7;
					}
				}
			}
		}
	}
}

void vylusti(char pole[VYSKA][SIRKA], char zoznam[POCET_SLOV][MAX_DLZKA_SLOVA], int r, int c, int poc_slov) {
	int i,j;
	for (i = 0; i < poc_slov; i++) {
		najdiSlovo(zoznam[i], pole, r, c);

		zobraz(pole, r, c);
		printf("\n");
		zobrazZoznamSlov(zoznam, poc_slov,i);

		//zobrazenie slova, ktore hladame
		printf("\nSlovo:\n");
		for (j = 0; j < (int)strlen(zoznam[i]); j++) {
			printf("%c", zoznam[i][j]);
		}
		if (getchar()=='\n')
			CLEAR_SCREEN();
	}
}

void tajnicka(char pole[VYSKA][SIRKA], int r, int c) {
	int i, j;
	for (i = 0; i < r; i++) {
		for (j = 0; j < c; j++) {
			if (pomocne_pole[i][j]==0)
				printf("%c", pole[i][j]);
		}
	}
	printf("\n");
}
