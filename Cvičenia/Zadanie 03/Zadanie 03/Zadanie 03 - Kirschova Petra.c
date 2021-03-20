#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//test ci patri cislo do intervalu
int test(int num, int min, int max) {
	if (num>=min && num<=max)
		return 1;
	else
		return 0;
}

//del 4 a nie 100 alebo del 4 aj 100 aj 400
int prestupny_rok(int rok) {
	if (rok % 4 == 0 && ((rok % 100 != 0) || ((rok % 100 == 0) && (rok % 400 == 0))))
		return 1;
	return 0;
}

int pocet_dni_mesiaca(int mesiac, int rok) {
	if (mesiac == 2 && prestupny_rok(rok) == 1) //ak je rok prestupny, februar ma 29 dni
		return 29;
	return 28 + (mesiac + (mesiac / 8)) % 2 + 2 % mesiac + 2 * (1 / mesiac);
}

int prvy_den(int mesiac, int rok) {
	int a, y, m;
	a = (14 - mesiac) / 12;
	y = rok - a;
	m = mesiac + 12 * a - 2;
	return (y + y / 4 - y / 100 + y / 400 + (31 * m) / 12) % 7; //pondelok = 0
}

void print_mesiac(int mesiac, int rok) {
	int medzery, i;
	int dni_array[31];
	switch (mesiac) { //vypis mesiacov slovne
	case 1:
		printf("\nJanuar ");
		break;
	case 2:
		printf("\nFebruar ");
		break;
	case 3:
		printf("\nMarec ");
		break;
	case 4:
		printf("\nApril ");
		break;
	case 5:
		printf("\nMaj ");
		break;
	case 6:
		printf("\nJun ");
		break;
	case 7:
		printf("\nJul ");
		break;
	case 8:
		printf("\nAugust ");
		break;
	case 9:
		printf("\nSeptember ");
		break;
	case 10:
		printf("\nOktober ");
		break;
	case 11:
		printf("\nNovember ");
		break;
	case 12:
		printf("\nDecember ");
		break;
	} 
	printf("%d\n",rok);
	printf("MO TU WE TH FR SA SU\n");
	medzery = prvy_den(mesiac, rok); //odsadenie

	for (i = 0; i<pocet_dni_mesiaca(mesiac, rok); i++) //ulozim si dni mesiaca do pola
		dni_array[i] = i + 1;

	for (i = 0; i < medzery; i++) //vypis medzier - odsadenie
		printf("   ");

	//vypis pola, pocitam dni aj s odsadenim, preto zacinam na i=medzery
	for (i = medzery; i < medzery + pocet_dni_mesiaca(mesiac, rok); i++) {
		if (i % 7 == 0 && i>0) //aby boli tyzdne pod sebou - ak je pondelok, tak do druheho riadku
			printf("\n");
		printf("%*d ",2, dni_array[i - medzery]); //pri vypise odpocitam medzery, lebo 1.den mesiaca = 0. polozka pola
	}
	printf("\n\n");
}

void print_rok(int rok) {
	int i;
	for (i = 1; i <= 12; i++) {
		print_mesiac(i, rok);
	}
}

int pocet_dni_medzi(int den1, int mesiac1, int rok1, int den2, int mesiac2, int rok2) {
	int dni = 0, i, mesiace = 0, roky = 0;

	if (rok1 == rok2) {
		if (mesiac1 == mesiac2) {	//ten isty mesiac a den
			dni = abs(den2 - den1);
		}
		else {						//rovnaky rok, iny mesiac
			dni = pocet_dni_mesiaca(mesiac1, rok1) - den1 + den2;
			for (i = mesiac1 + 1; i < mesiac2; i++) {
				mesiace += pocet_dni_mesiaca(i, rok1);
			}
		}
	}
	else {							//rozny mesiac aj rok
		dni = pocet_dni_mesiaca(mesiac1, rok1) - den1 + den2;
		for (i = mesiac1 + 1; i <=12; i++) { //mesiace v prvom zadanom datume
			mesiace += pocet_dni_mesiaca(i, rok1);
		}
		for (i = 1; i < mesiac2; i++) {     //mesiace v druhom zadanom datume
			mesiace += pocet_dni_mesiaca(i, rok2);
		}
		for (i = rok1 + 1; i < rok2; i++) { //roky medzi 1. a 2. datumom (rok v datume 1 a datume 2 nezapocitavam)
			roky += (prestupny_rok(i) == 1) ? 366 : 365; //ak je prestupny, tak ma 366 dni
		}
	}
	return dni + mesiace + roky;
}

void menu_print() {
	printf("MENU\n");
	printf("1 - Zobrazenie kalendara pre zadany mesiac vo zvolenom roku\n");
	printf("2 - Zobrazenie kalendara pre zadany rok\n");
	printf("3 - Zistenie poctu dni medzi 2 zvolenymi datumami\n");
	printf("4 - Ukoncenie programu\n\n");
}

int menu_hodnota() {
	int num;
	scanf("%d", &num);
	switch (num) {
	case 1:
		return 1;
	case 2:
		return 2;
	case 3:
		return 3;
	case 4:
		return 4;
	default:
		return 0;
	}
}

int main() {
	int num,mesiac, rok, den1, mesiac1, rok1, den2, mesiac2, rok2;
	menu_print();
	while (1) { //aby program bezal az kym si pouzivatel nezada ukoncenie programu

	start:
		printf("Zadajte volbu 1/2/3/4\n");
		num = menu_hodnota();
		switch (num) {
		case 1:
			printf("Zadali ste : 1 - Zobrazenie kalendara pre zadany mesiac vo zvolenom roku\n");
		case1_start:
			printf("Zadajte mesiac a rok: ");
			scanf("%d %d", &mesiac, &rok);

			if (test(mesiac, 1, 12) == 1) { // mesiac <1,12>
				print_mesiac(mesiac, rok);
			}
			else {
				printf("Zadali ste zly datum!\n ");
				goto case1_start; //zadava sa datum znovu, presuva sa na case1_start
			}
			break;

		case 2:
			printf("Zadali ste : 2 - Zobrazenie kalendara pre zadany rok\n");
			printf("Zadajte rok: ");
			scanf("%d", &rok);
			print_rok(rok);
			break;

		case 3:
			printf("Zadali ste : 3 - Zistenie poctu dni medzi 2 zvolenymi datumami\n");
		case3_start:
			printf("Zadajte prvy datum: ");
			scanf("%d %d %d", &den1, &mesiac1, &rok1);
			printf("Zadajte druhy datum: ");
			scanf("%d %d %d", &den2, &mesiac2, &rok2);

			//test mesiac1 a mesiac2 z <1,12> a den1 a den2 mensi ako pocet dni v danom mesiaci
			if ((test(mesiac1, 1, 12) == 1 && test(mesiac2, 1, 12) == 1) && (den1 <= pocet_dni_mesiaca(mesiac1, rok1) && den2 <= pocet_dni_mesiaca(mesiac2, rok2))) {
				
				// ak by boly datumy zadane naopak, tak sa den, mesiac, rok vymeni
				if ((rok1 > rok2) || (mesiac1 > mesiac2 && rok1 == rok2)) { 
					printf("Pocet dni medzi %d.%d.%d a %d.%d.%d je: %d\n\n", den1, mesiac1, rok1, den2, mesiac2, rok2, pocet_dni_medzi(den2, mesiac2, rok2, den1, mesiac1, rok1));
				}
				else {
					printf("Pocet dni medzi %d.%d.%d a %d.%d.%d je: %d\n\n", den1, mesiac1, rok1, den2, mesiac2, rok2, pocet_dni_medzi(den1, mesiac1, rok1, den2, mesiac2, rok2));
				}
				break;
			}
			else {
				printf("Zadali ste zly datum!\n ");
				goto case3_start; //vrati sa na case3_start
			}

		case 4:
			printf("Zadali ste : 4 - Ukoncenie programu\n\n");
			exit(0);
			break;

		default:
			printf("Zadali ste zle cislo!\n ");
			goto start; //vrati sa na start
			break;
			
		}
	}
		return 0;
}