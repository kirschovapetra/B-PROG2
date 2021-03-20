#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "helpers.h"

char sub_words[MAX_LEN][MAX_WORD_LEN] = { { '\0' } };
int length_s = 0;

//vypis
void print_text(char *text, char *sifra) {
	printf("\nTEXT:\n\n");
	printf("%s", text);

	printf("\n\nPRAVIDLA SIFROVANIA:\n");
	printf("%s", sifra);
}

//rozdelenie retazca na podretazce, ulozenie do pola
int split(char *str, char pole[MAX_LEN][MAX_WORD_LEN]) {
	char *tok;
	char d[3] = { '=','\n','\0' }; //delimitre
	int pos = 0;
	
	tok = strtok(str, d); //prvy token od zaciatku textu
	while (tok != NULL) {
		strcpy(pole[pos],tok); //do pola na poziciu pos sa zapise token
		pos++;
		tok = strtok(NULL, d); //vsetky ostatne tokeny od aktualnej pozicie
	}
	return pos;
}

//desifrovanie
void replace_all(char *text, char words_s[MAX_LEN][MAX_WORD_LEN]) {
	char *p = text,*pos;
	int length, i;

	for (i = 0; i < (length_s - 1); i += 2) {//prechadzam pole words_s kde su ulozene pravidla sifrovania
		p = text;							//ak boli vsetky slova words_s[i] nahradene, tak sa testuje dalsie slovo od zaciatku textu								
		start:
		while ((pos = strstr(p, words_s[i])) != NULL) { //pos sa nastavi na prvy vyskyt podretazca words_s[i] v texte
			length = 0;
			while (isalpha(pos[length])) {				//dlzka slova v texte po najblizsiu medzeru/bodku/...
				length++;
			}
			if (length == (int)strlen(words_s[i])) {	//test ci je slovo zacinajuce na pos naozaj slovo words_s (ich dlzky sa rovnaju)
				strncpy(pos, words_s[i + 1], (int)strlen(words_s[i + 1])); //do textu sa nakopiruje zasifrovane slovo - od pos az po koniec slova 
			}
			else { //ak slovo nie je to, ktore hladame, tak sa posunie dalej a v nasledujucom cykle sa testuju iba slova od novej pozicie
				p += length;
				goto start;
			}
		}

	}
}

//koniec - vypisy
void decide(int input, int subst, int output, char *txt, char *sub, char *out) {

	//neboli zadane obidva parametre -sub -i
	if (input == 0 || subst == 0) {
		printf("Nezadali ste spravne parametre\n");
	}
	//subory neexistuju
	else if (txt == NULL || sub == NULL) {
		if (txt==NULL)
			printf("Subor -i neexistuje\n");
		if (sub == NULL)
			printf("Subor -s neexistuje\n");
	}
	else {
		print_text(txt, sub);

		length_s = split(sub, sub_words);
		replace_all(txt, sub_words);

		//zapis do suboru
		if (output == 1) {
			if (out != NULL) {
				printf("\nZapis do suboru\n");
				write_file(out, txt);
			}
			else
				printf("\nZapis sa nepodaril\n");
		}
		//vypis na obrazovku
		else {
			printf("\n\nDESIFROVANY TEXT:\n%s\n", txt);
		}
	}
	
}