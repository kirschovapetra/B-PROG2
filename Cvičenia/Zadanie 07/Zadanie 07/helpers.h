//	POPIS:
//	Subor obsahujuci:
//		* deklaracie premennych
//		* deklaracie pouzivatelskych funkcii, ktore su implementovane v functions.c
//		* pomocne makra

#ifndef HELPERS_H
#define HELPERS_H

#include "data_info.h"

// deklaracie premennych
extern char osemsmerovka[VYSKA][SIRKA];
extern char zoznamSlov[POCET_SLOV][MAX_DLZKA_SLOVA];
extern int pomocne_pole[VYSKA][SIRKA];

// deklaracie pouzivatelskych funkcii
int test(int num, int min, int max); 
void zobraz(char pole[VYSKA][SIRKA], int r, int c);
void zobrazZoznamSlov(char zoznam[POCET_SLOV][MAX_DLZKA_SLOVA], int poc_slov, int oznacene);
int check_up(char slovo[], char pole[VYSKA][SIRKA], int r, int c);
int check_down(char slovo[], char pole[VYSKA][SIRKA], int poz_r, int poz_c);
int check_left(char slovo[], char pole[VYSKA][SIRKA], int poz_r, int poz_c);
int check_right(char slovo[], char pole[VYSKA][SIRKA], int poz_r, int poz_c);
int check_left_up(char slovo[], char pole[VYSKA][SIRKA], int r, int c);
int check_left_down(char slovo[], char pole[VYSKA][SIRKA], int poz_r, int poz_c);
int check_right_up(char slovo[], char pole[VYSKA][SIRKA], int poz_r, int poz_c);
int check_right_down(char slovo[], char pole[VYSKA][SIRKA], int poz_r, int poz_c);
void najdiSlovo(char slovo[], char pole[VYSKA][SIRKA], int r, int c);
void vylusti(char pole[VYSKA][SIRKA], char zoznam[POCET_SLOV][MAX_DLZKA_SLOVA], int r, int c, int poc_slov);
void tajnicka(char pole[VYSKA][SIRKA], int r, int c);

#define green 10
#define white 15

// Podmieneny preklad: verzia pre WINDOWS sa lisi od LINUX verzie
// makro na premazanie obsahu konzoly
#ifdef _WIN32
#define CLEAR_SCREEN()	system("cls")
#else
#define CLEAR_SCREEN()	printf("\x1b[2J");
#endif


#endif /* HELPERS_H */
