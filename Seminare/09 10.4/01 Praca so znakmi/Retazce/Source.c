#include <stdio.h>
#include <ctype.h>
#include <string.h>
/*1. Napíšte si krátky program, ktorý v cykle naèítava znaky a vypisuje ich na obrazovku(cez scanf / printf s "%c" maskou, 
alebo cez getchar / putchar).*/
void f1_nacitaj() {
	char c;
	int i;
	for (i = 0;i<10;i++) {
		c = getchar();
		putchar(c);
	}
}

//2. Napíšte si krátky program, ktorý v cykle prejde a vypíše všetky znaky ASCII tabu¾ky.
void f2_ascii() {
	int i;
	for (i = 0; i < 256; i++) 
		printf("%d = %c\n", i, i);
}

/*3. Napíšte(a otestujte) vlastnú funkciu na zistenie, èi zadaný znak je slovenské písmeno, 
kde za slovenské písmená nepovažujte q, w, x, Q, W, X*/
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



/*4. Napíšte(a otestujte) vlastnú funkciu, ktorá skonvertuje znak na èíslicu v 16 - kovej sústave
(kde 'a' / 'A' = 10, 'z' / 'Z' = 35).Funkcia má teda vstup typu char a výstup typu int.Ak znak nie je alfanumerický, funkcia vráti - 1.*/
int f4_konvertuj(char c) {
	return 0;
}



/*4. Vytvorte si vlastnú funkciu, ktorej vstupom je pole znakov (smerník) a jeho kapacita max. Do po¾a naèítavajte znaky zo vstupu
(pomocou funkcie getchar() alebo scanf("%c")), kým nenarazíte na koniec riadku '\n', koniec súboru (scanf zlyhá, getchar vráti EOF), 
alebo nanaèítate max-1 znakov. Znak '\n' do reazca nevkladajte, reazec ukoète znakom '\0'.*/
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