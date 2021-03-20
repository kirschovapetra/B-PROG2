#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 100
//Z ka�dej funkcie vr�te po�et ��sel zap�san�ch do po�a(re�lnu ve�kos� po�a).

//Funkcia do zadan�ho po�a na��ta n ��sel zo �tandardn�ho vstupu(pomocou scanf).
int f1(int pole[],int n) {
	int i;
	for (i = 0; i < n;i++) {
		scanf("%d",&pole[i]);
	}
	return i;
}

/*Na��tavajte do po�a zo �tandardn�ho vstupu(pomocou scanf) postupne ��sla, a� pok�m sa nena��ta 0, 
resp.pokia� sa nena��ta n ��sel.Z�vere�n� nulu do po�a neukladajte.*/
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

/*Na��tavajte do po�a zo �tandardn�ho vstupu(pomocou scanf) n kladn�ch ��sel, z�porn� preskakujte.
Predpoklad� sa, �e k dispoz�cii je dostatok vstupov).*/
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

/*Na��tavajte do po�a zo �tandardn�ho vstupu(pomocou scanf) postupne kladn� ��sla, a� pok�m sa nena��ta 0, 
resp.pokia� sa nena��ta n ��sel.Z�porn� ��sla preskakujte.Z�vere�n� nulu do po�a neukladajte.*/
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