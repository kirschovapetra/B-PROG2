#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
/*1. Napíšte funkciu, ktorá do zadaného poľa načítava znaky, až pokým sa nenačíta znak '\n' (ten sa do poľa neuloží), 
pričom načíta maximálne max-1 znakov (kde max je zadaný parameter). Na koniec poľa zapíše znak konca reťazca '\0'. 
Výstupom funkcie je počet znakov, ktoré sa načítali.*/
void f1_nacitaj(char pole[], int max) {
	int c, i;
	i = 0;
	do {
		c = getchar();
		pole[i] = c;
		i++;
	} while (i<max-1 && c != '\n');
	pole[max-1] = '\0';
}

/*2. Funkcia má parametre pole znakov a jeho veľkosť. Naplní pole náhodne vygenerovanými veľkými písmenami 
(využite rand()%26 a "aritmetiku" znakov). Nezabudnite ukončiť reťazec.*/
void f2_nahodne(char pole[], int max) {
	int i;
	for (i = 0; i < max-1;i++) {
		pole[i] = rand() % ('Z'-'A'+1) - 'A';
	}
	pole[max-1] = '\0';
}

/*3. Funkcia má parametre pole znakov a jeho veľkosť. Naplní pole náhodne vygenerovanými veľkými 
a malými písmenami (či sa použije veľký alebo malý znak môže rozhodnúť 1 rand()).*/
void f3_male_velke(char pole[], int max) {
	int i,pism;
	for (i = 0; i < max-1; i++) {
		pism = rand() % 2;
		if (pism == 1)
			pole[i] = rand() % ('z'+'a'+1) - 'a';
		else
			pole[i] = rand() % ('Z'-'A'+1) - 'A';

	}
	pole[max-1] = '\0';
}

/*4. Funkcia má parametre pole znakov out, jeho veľkosť a jeden vstupný reťazec. Naplní pole náhodne 
vygenerovanými znakmi z reťazca (rand() bude použitý ako index v reťazci, pozor na rozsah náhodných čísel).*/
void f4_nahodne_ret(char out[],char in[],int max) {
	int i;
	for (i = 0; i < max-1; i++) {
		out[i] = in[rand() % (strlen(in))];
	}
	out[max-1] = '\0';
}

/*5. Funkcia má parametre pole znakov out, jeho veľkosť a dva vstupné reťazce. Naplní pole náhodne 
vygenerovanými znakmi z dvoch reťazcov, tak aby sa striedali (napr. fn(pole, 3+1, "EA","MV"); 
môže vygenerovať reťazce "EVA", "EMA", "AMA"...*/
void f5_nahodne_2ret(char out[],int max, char in1[],char in2[]) {
	int i;
	for (i = 0; i <max - 1; i++) {
		if (i%2==0)
			out[i] = in1[rand() % (strlen(in1))];
		else
			out[i] = in2[rand() % (strlen(in2))];
	}
	out[max - 1] = '\0';
}

/*6. Napíšte vlastné funkcie, ktoré robia nasledujúce činnosti (každá zvlášť):
		- spočíta počet výskytov daného čísla/znaku v poli
		- prepíše všetky písmená v poli na opačnú veľkosť (uppercase <--> lowercase).
		- vynechá v reťazci medzery (prepíše sa pôvodný reťazec, ktorý je argumentom funkcie)
		- vynechá v reťazci za sebou opakované znaky (čiže z "aaabbbaa" sa stane "aba")
		- vynechá v reťazci zopakované znaky (čiže z "aaabbbaa" sa stane "ab")
		- podobne ako strcmp porovná 2 reťazce, ale je case-insensitive (t.j. 'a' je to isté ako 'A')
		- vypíše reťazec odzadu
		- vstupom sú dva reťazce In a Out. Do Out reťazca sa zapíše In reťazec odzadu.
		- vstupný reťazec sa prepíše "odzadu" -> "udazdo" (bez alokácie nového poľa)
		- zistí počet slov v reťazci s použitím strtok
		- zistí počet slov v reťazci bez použitia strtok
*/
int f6_a_count(char c, char pole[]) {
	int i, count = 0;;
	for (i = 0; i < strlen(pole); i++) {
		if (pole[i]==c) {
			count++;
		}
	}
	return count;
}
void f6_b_upper_lower(char pole[]) {
	int i, count = 0;;
	for (i = 0; i < strlen(pole); i++) {
		if (pole[i]>='a') {
			pole[i] -= 32;
		}
		else {
			pole[i] += 32;
		}
	}
}

void f6_c_del_medzery(char str[]) {

}
void f6_c_del_opakovane(char str[]) {

}



//7. Vstupom funkcie je pole celých čísel, počet čísel v poli a jeden znak. Funkcia vypíše čísla z poľa oddelené zadaným znakom.
void f7_oddelovac(int pole[], int max, char c) {
	int i;
	for (i = 0; i <max; i++) 
		printf("%d %c",pole[i],c);
}
//8. Vstupom funkcie je pole reťazcov, ich počet v poli a jeden znak. Funkcia vypíše reťazce z poľa oddelené zadaným znakom.
void f8_oddelovac2(char pole[][10], int max, char c) {
	int i;
	for (i = 0; i < max; i++) 
		printf("%s %c", pole[i], c);
}
/*9. Vstupom funkcie sú 2 reťazce. Funkcia prepisuje 1. reťazec: ak v ňom natrafí na znak *, 
dosadí namiesto neho nasledujúce písmeno z druhého reťazca. Vráti smerník na (upravený) prvý reťazec. 
Príklad: printf("%s", f("*-*-*", "ABC")); //A-B-C*/
void f9(char str1[], char str2[]) {
	
}
//10. Vstupom sú 2 reťazce rovnakej dĺžky. Výstupom je počet nezhôd medzi reťazcami, t.j. počet prípadov, kedy na danej pozícii sú rôzne znaky.
int f10_nezhody(char str1[], char str2[], int max) {
	int pocet = 0,i;
	for (i = 0; i < max; i++) {
		if (str1[i] != str2[i])
			pocet++;
	}
	return pocet;
}
/*11. Vstupom sú 2 reťazce rovnakej dĺžky. Výstupom je počet nezhôd medzi reťazcami, t.j. počet prípadov, 
kedy na danej pozícii sú rôzne znaky. AK v nejakom reťazci je znak '*', v druhom môže byť hocičo a nepovažuje sa to za nezhodu. 
Priklad: f("LA*ALA", "BAJA*A") vráti 1.*/
int f11_nezhody2(char str1[], char str2[], int max) {
	int pocet = 0, i;
	for (i = 0; i < max; i++) {
		if (str1[i] == '*' || str2[i] == '*')
			continue;
		if (str1[i] != str2[i])
			pocet++;
	}
	return pocet;
}
/*12. Vstupom sú 2 reťazce. Funkcia zistí, či prvý reťazec obsahuje iba znaky z druhého reťazca 
(napr. "011001" obsahuje iba znaky z "01", taktiež z "012", ale nie z "12").*/
void f12_obsahuje(char str1[], char str2[]) {
	
}
/*13. Vstupom je reťazec, ktorý obsahuje iba hexa číslice. Predpokladáme, že sa jedná o zápis čísla 
v 16-kovej sústave od NAJVYSSEJ číslice. Výstupom funkcie je toto číslo. Príklad: f("1A") vráti 26*/

/*14. Vstupom je reťazec, ktorý obsahuje iba hexa číslice. Predpokladáme, že sa jedná o zápis čísla v 16-kovej sústave 
od NAJNIZSEJ číslice. Výstupom funkcie je toto číslo. Príklad: f("1A") vráti 161*/

/*15. Vstupom je reťazec a celé číslo x. Funkcia vypisuje reťazec znak po znaku, pričom ak natrafí na znak '*', 
vypíše nasledujúci znak (môže byť aj '*') x-krát. Príklad: f("(*.***x)", 3); vypíše: (...***xxx)*/
char f15(int x, char str[]) {
	int i, j;
	for (i = 0; i < strlen(str); i++) {
		if (str[i] == '*') {
			for (j = 0; j < x; j++) {
				printf("%c", str[i + 1]);
			}
		}
	}
	printf("\n");
}
/*16. Vstupom je reťazec a pole celých čísel. Funkcia vypisuje reťazec znak po znaku, pričom ak natrafí na znak '*', 
vypíše nasledujúci znak (môže byť aj '*') toľkokrát, aké číslo nasleduje v poli. 
Príklad: p={2,3,4,5,7,9}; f("(*.***x)", p); vypíše (..***xxxx)*/
char f16(int pole[],char str[]) {
	int i,j;
	for (i = 0; i < strlen(str);i++) {
		if (str[i]=='*') {
			for (j = 0; j < pole[i];j++) {
				printf("%c", str[i + 1]);
			}
		}
	}
	printf("\n");
}


/*17. Vstupom je číslo 0-9. Funkcia vráti znak, ktorý na anglickej klávesnici získame stlačením SHIFT-zadaná_číslica. 
Ak číslo je mimo rozsah, vráti znak '\0'. HINT: Využite statické pole znakov.*/
char f17_eng_klavesnica(int n){
	char znaky[] = {')', '!', '"', '£', '$', '%', '^', '&', '*', '(',};
	return znaky[n];
}



//18. Vstupom je znak. Výstupom je 0 ak sa nejedná o písmeno, -1 ak sa jedná o samohlásku ("aAeEiIoOuUyY"), a 1 ak sa jedná o spoluhlásku.
int f18_aky_znak(char c) {
	int i;
	char samohlasky[] = "aAeEiIoOuUyY";
	if (!alpha(c)) {
		return 0;
	}
	for (i = 0; i < strlen(samohlasky);i++) {
		if (c == samohlasky[i])
			return -1;
	}
	return 1;
}
//19. Vstupom je číslo mesiaca, funkcia vráti reťazec s jeho názvom (využite statické pole konštantných reťazcov).
char* f19_mesiac(int n) {
	char mesiace[][15] = { "Január","Február","Marec","Apríl", "Máj", "Jún","Júl" ,"August","September" ,"Október" ,"November" ,"December" };
	if (n > 12)
		return 0;
	return mesiace[n - 1];
}


int main() {

}