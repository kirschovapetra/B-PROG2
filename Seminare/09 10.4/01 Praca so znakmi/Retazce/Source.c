#include <stdio.h>
#include <ctype.h>
#include <string.h>
/*1. Nap�te si kr�tky program, ktor� v cykle na��tava znaky a vypisuje ich na obrazovku(cez scanf / printf s "%c" maskou, 
alebo cez getchar / putchar).*/
void f1_nacitaj() {
	char c;
	int i;
	for (i = 0;i<10;i++) {
		c = getchar();
		putchar(c);
	}
}

//2. Nap�te si kr�tky program, ktor� v cykle prejde a vyp�e v�etky znaky ASCII tabu�ky.
void f2_ascii() {
	int i;
	for (i = 0; i < 256; i++) 
		printf("%d = %c\n", i, i);
}

/*3. Nap�te(a otestujte) vlastn� funkciu na zistenie, �i zadan� znak je slovensk� p�smeno, 
kde za slovensk� p�smen� nepova�ujte q, w, x, Q, W, X*/
int f3_je_slovenske(char c) {
	int i;
	char nie[] = {'q','w','x','Q','W','X'};
	if (!isalpha(c))
		return 0;
	for (i = 0; i < 6;i++) {
		if (c == nie[i])
			return 0;
	}
	return 1;
}



/*4. Nap�te(a otestujte) vlastn� funkciu, ktor� skonvertuje znak na ��slicu v 16 - kovej s�stave
(kde 'a' / 'A' = 10, 'z' / 'Z' = 35).Funkcia m� teda vstup typu char a v�stup typu int.Ak znak nie je alfanumerick�, funkcia vr�ti - 1.*/
int f4_konvertuj(char c) {
	return 0;
}



/*4. Vytvorte si vlastn� funkciu, ktorej vstupom je pole znakov (smern�k) a jeho kapacita max. Do po�a na��tavajte znaky zo vstupu
(pomocou funkcie getchar() alebo scanf("%c")), k�m nenaraz�te na koniec riadku '\n', koniec s�boru (scanf zlyh�, getchar vr�ti EOF), 
alebo nana��tate max-1 znakov. Znak '\n' do re�azca nevkladajte, re�azec uko�te znakom '\0'.*/
void f5_nacitaj(char pole[], int max) {
	int c,i;
	i = 0;
	do {
		c = getchar();
		pole[i] = c;
		i++;
	} while (i<max && c!='\n');
}

int main() {
	char pole[10];
	int i;
	f2_ascii();

	printf("\na je slovenske? %d\n", f3_je_slovenske('a'));
	printf("Q je slovenske? %d\n", f3_je_slovenske('Q'));
	printf("0 je slovenske? %d\n", f3_je_slovenske('0'));


	f5_nacitaj(pole, 10);
	for (i = 0; i < 10; i++)
		printf("%c",pole[i]);
	printf("\n");
	return 0;
}