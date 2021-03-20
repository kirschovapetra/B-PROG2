#include <stdio.h>
#include <string.h>

/*1. [http://www.cplusplus.com/reference/clibrary/cstring/strlen/ strlen]
Vstupom funkcie je reazec, funkcia vráti poèet znakov.
Vyskúšajte, èo sa stane, ak v predošlej úlohe neukoèíte reazec znakom '\0' a zavoláte funkciu strlen.
Naprogramujte si vlastnú verziu tejto funkcie.*/
int str_len(char str[]) {
	int i = 0;
	while (str[i] != '\0') {
		i++;
	}
	return i;
}

/*2. [http://www.cplusplus.com/reference/clibrary/cstring/strcmp/ strcmp]
Vstupom funkcie sú dva reazce, vıstupom je 0, ak sú zhodné, kladné èíslo, ak prvı reazec je väèší (neskôr v lexikografickom poradí), 
záporné ak prvı je menší. Vyskúšajte si túto funkciu.
Dokáete poui túto funkciu v kombinácii s [http://www.cplusplus.com/reference/clibrary/cstdlib/qsort/ qsort] na zotriedenie 
parametrov z príkazového riadku?
Naprogramujte si vlastnú verziu tejto funkcie.*/
int str_cmp(char str1[], char str2[]) {
	int i,z;
	int n = strlen(str1);
	int m = strlen(str2);
	if (n>m) {
		z = n;
		n = m;
		m = z;
	}
	for (i = 0; i < n; i++) {
		if (str1[i] > str2[i])
			return 1;
		else
			return -1;
	}
	return 0;
}



/*3. [http://www.cplusplus.com/reference/clibrary/cstring/strchr/ strchr]
Nájde prvı vıskyt zadaného znaku v reazci, vráti pointer na túto pozíciu - vyskúšajte si príklad z cplusplus.com
Napíšte vlastnú verziu tejto funkcie, ktorá ale nevracia pointer, ale pozíciu (index) prvého vıskytu písmena, alebo -1, ak sa v reazci nenachádza.
Napíšte funkciu, ktorá vráti index posledného vıskytu písmena, alebo -1, ak sa v reazci nenachádza.
Napíšte funkciu, ktorá vráti poèet vıskytov písmena v reazci.*/
int str_chr(char c, char str[]) {
	int i,ind = -1;
	for (i = 0; i < strlen(str); i++) {
		if (c==str[i]) {
			ind = i;
		}
	}
	return -1;
}

/*4. [http://www.cplusplus.com/reference/clibrary/cstring/strstr/ strstr]
Nájde prvı vıskyt podreazca.
Vedeli by ste naprogramova vlastnú verziu s pouitím [http://www.cplusplus.com/reference/clibrary/cstring/strncmp/ strncmp] ?
Vedeli by ste naprogramova vlastnú verziu bez pouitia kniniènıch funkcií?*/
int str_str_b(char str1[], char str[]) {
	int i,j;
	for (i = 0; i < strlen(str);i++) {
		if (str[i] == str1[0]) {
			if (i + strlen(str1) > strlen(str))
				return 0;
			else {
				for (j = i; j < strlen(str1); j++) {
					if (str[j] != str1[j-i])
						return 0;
				}
			}	
		}
	}
	return 1;
}

/*5. [http://www.cplusplus.com/reference/clibrary/cstring/strtok/ strtok]
Tokenizácia stringu - rozdelí ho na podreazce, napr. keï máte èiarkami oddelené údaje, potrebujete rozdeli text na vety, slová...
Vyskúšajte si spravi program, ktorı naèíta riadok z klávesnice (pomocou fgets, pripravte dos dlhé pole na uchovanie znakov), 
rozdelí ho na slová (pomocou strtok) a vypíše slová v opaènom poradí (najjednoduchšie je uchova vısledné smerníky, 
ktoré vráti strtok do po¾a smerníkov, a to pole prejs odzadu)*/
int str_tok(char str[], int c,int n, int pole[][10]) {
	int i, poz = 0;
	for (i = 0;i<strlen(str);i++) {
		return 0;
	}

}

int main() {
	return 0;
}