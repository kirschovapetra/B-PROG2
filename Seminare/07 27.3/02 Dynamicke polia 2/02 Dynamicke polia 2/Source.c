#include <stdio.h>
#include <stdlib.h>
#define CRT_SECURE_NO_WARNINGS


void vypis_pole(int pole[],int n){
	int i;
	for (i = 0; i < n; i++)
	{
		printf("%d ", pole[i]);
	}
	printf("\n");
}


/*1 - Vytvorte funkciu, ktorej vstupom je pole cel�ch ��sel a jeho d�ka.Funkcia vytvor� a vr�ti nov� dynamick� pole,
ktor� bude obsahova� iba kladn� prvky z p�vodn�ho po�a, a za ne na ukon�enie po�a prid� prvok - 1.*/
int* f1_copy_kladne(int pole[], int n, int *size) {
	int *pole2, i, poz = 0;
	pole2 = (int*)malloc((poz + 1) * sizeof(int));
	for (i = 0; i < n; i++) {
		if (pole[i]>0) {
			pole2[poz] = pole[i];
			poz++;
			pole2 = realloc(pole2, (poz + 1) * sizeof(int));
		}
	}
	pole2[poz] = -1;
	*size = poz + 1;
	return pole2;
}

/*2 - Uva�ujme polia prefixovan� d�kou : Polia maj� na za�iatku jeden prvok, ktor� hovor� o d�ke zvy�ku po�a.
Napr. {3, 2, 5, 7} znamen�, �e v poli s� platn� 3 prvky : 2, 5, 7. Najmen�ie mo�n� pole je teda{ 0 }.

a) Vytvorte funkciu na v�pis tak�hoto po�a(d�ku nevypisujte).
b) Vytvorte funkciu na vytvorenie tak�hoto po�a zo �tandardn�ho po�a.Parametrom funkcie je pole a po�et platn�ch prvkov.
Funkcia vr�ti dynamicky alokovan� pole prefixovan� d�kou s rovnak�m obsahom ako p�vodn� pole.
c) Vytvorte funkciu na pridanie prvku do prefixov�ho po�a.Vyu�ite realloc.
d) Vytvorte funkciu na spojenie dvoch prefixov�ch pol�.Vstupom funkcie s� dva prefixov� polia a v�stup je
novo - alokovan� pole, kde bud� prvky z oboch sp�jan�ch pol� ulo�en� za sebou.
e) Vytvorte funkciu na prienik dvoch prefixov�ch pol�.Vstupom funkcie s� dva prefixov� polia a v�stup je
novo - alokovan� pole, kde bud� prvky, ktor� sa nach�dzaj� v oboch vstupn�ch poliach.*/

void f2_a_vypis(int pole[]) {
	int i;
	int size = pole[0];
	for (i = 1; i <= size; i++) {
		printf("%d ", pole[i]);
	}
	printf("\n");
}

int* f2_b_generuj(int pole[], int pocet) {
	int i;
	int *pole2;
	pole2 = (int*)malloc((pocet + 1) * sizeof(int));
	pole2[0] = pocet;
	for (i = 1; i <= pocet; i++) {
		pole2[i] = pole[i - 1];
	}
	return pole2;
}

void f2_c_add(int pole[], int x) {
	int size = pole[0];
	int dlzka = size + 1;
	pole = realloc(pole, (dlzka + 1) * sizeof(int));
	pole[dlzka] = x;
	pole[0]++;
}

int* f2_d_spojenie(int pole1[], int pole2[]) {
	int size1 = pole1[0];
	int size2 = pole2[0];
	int *pole, i, j;
	pole = (int*)malloc((size1 + size2 + 1) * sizeof(int));
	pole[0] = 0;
	for (i = 1; i <= size1; i++) {
		pole[i] = pole1[i];
		pole[0]++;
	}
	for (j = i; j <= size2 + i; j++) {
		pole[j] = pole2[j - i];
		pole[0]++;
	}
	return pole;
}

int* f2_e_prienik(int pole1[], int pole2[]) {
	int size1 = pole1[0];
	int size2 = pole2[0];
	int *pole, i, j, poz;

	pole = (int*)malloc(size1 * sizeof(int));
	pole[0] = 0;
	poz = 1;
	for (i = 1; i <= size1; i++) {
		for (j = 1; j <= size2; j++) {
			if (pole1[i] == pole2[j]) {
				pole[poz] = pole1[i];
				pole[0]++;
				poz++;
			}
		}
	}

	return pole;
}



int main() {
	int pole[5] = { 0,1,-1,4,5 };
	int A[4] = { 3, 1, 2, 3 };
	int B[4] = { 3, 3, 4, 5 };
	int *pole2, n, size;
	n = 5;

	//f1
	printf("f1\n");
	pole2 = f1_copy_kladne(pole, n, &size);
	vypis_pole(pole2, size);
	free(pole2);

	//f2_a
	printf("\nf2_a\n");
	f2_a_vypis(A);

	//f2_b
	printf("\nf2_b\n");
	pole2 = f2_b_generuj(pole, n);
	f2_a_vypis(pole2);
	vypis_pole(pole2, n + 1);
	free(pole2);

	/*f2_c
	printf("\nf2_c\n");
	f2_c_add(A, 1);
	f2_a_vypis(A);*/


	//f2_d
	printf("\nf2_d\n");
	pole2 = f2_d_spojenie(A, B);
	f2_a_vypis(pole2);
	free(pole2);

	/*//f2_e
	printf("\nf2_e\n");
	pole2 = f2_e_prienik(A, B);
	f2_a_vypis(pole2);
	free(pole2);*/

	return 0;
}