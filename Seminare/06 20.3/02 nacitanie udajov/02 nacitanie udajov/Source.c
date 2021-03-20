#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 100
//Z kadej funkcie vráte poèet èísel zapísanıch do po¾a(reálnu ve¾kos po¾a).

//Funkcia do zadaného po¾a naèíta n èísel zo štandardného vstupu(pomocou scanf).
int f1(int pole[],int n) {
	int i;
	for (i = 0; i < n;i++) {
		scanf("%d",&pole[i]);
	}
	return i;
}

/*Naèítavajte do po¾a zo štandardného vstupu(pomocou scanf) postupne èísla, a pokım sa nenaèíta 0, 
resp.pokia¾ sa nenaèíta n èísel.Závereènú nulu do po¾a neukladajte.*/
int f2(int pole[],int n) {
	int i = 0,num;
	do {
		scanf("%d", &num);
		pole[i] = num;
		i++;
	}
	while ((num!=0) && (i<n));
	return i;
}

/*Naèítavajte do po¾a zo štandardného vstupu(pomocou scanf) n kladnıch èísel, záporné preskakujte.
Predpokladá sa, e k dispozícii je dostatok vstupov).*/
int f3(int pole[],int n) {
	int i = 0, num;
	do {
		scanf("%d", &num);
		if (num>0) {
			pole[i] = num;
			i++;
		}
	} while ((i<n));
	return i;
}

/*Naèítavajte do po¾a zo štandardného vstupu(pomocou scanf) postupne kladné èísla, a pokım sa nenaèíta 0, 
resp.pokia¾ sa nenaèíta n èísel.Záporné èísla preskakujte.Závereènú nulu do po¾a neukladajte.*/
int f4(int pole[], int n) {
	int i = 0, num;
	do {
		scanf("%d", &num);
		if (num>0) {
			pole[i] = num;
			i++;
		}
	} while ((num != 0) && (i<n));
	return i;
}

void print_pole(int pole[], int n) {
	int i;
	for (i = 0; i < n;i++) {
		printf("%d ", pole[i]);
	}
	printf("\n");
}

int main() {

	int pole[10] = { 0 }, n = 5,size;

	printf("\n%d cisel\n", n);
	size = f1(pole, n);
	print_pole(pole, size);

	printf("\nPokym i!=0 a i<%d\n", n);
	size = f2(pole, n);
	print_pole(pole, size);

	printf("\n%d kladnych cisel\n", n);
	size = f3(pole, n);
	print_pole(pole, size);

	printf("\nkladne pokym i<%d a i!=0\n", n);
	size = f4(pole, n);
	print_pole(pole, size);
	
	return 0;
}