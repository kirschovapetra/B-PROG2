#include <stdio.h>
#include <memory.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS


/*1 - Vytvorte funkciu, ktorej vstupom je pole cel�ch ��sel a jeho d�ka.
Funkcia dynamicky alokuje pole dostato�nej ve�kosti a prekop�ruje do� obsah vstupn�ho po�a
(m��ete vyu�i� �tandardn� funkciu memcpy).Vr�ti smern�k na alokovan� pole.*/
int* f1_copy(int pole[],int n){
	int *pole2;
	pole2 = (int*)malloc(n * sizeof(int));
	if (pole2 != NULL)
		memcpy(pole2, pole, n * sizeof(int));
	return pole2;
}

/*2 - Nap�te a otestujte funkciu, ktor� na��tava zo vstupu ��sla do po�a typu double, 
ktor� dynamicky alokuje a postupne zv��uje.Funkcia sa zastav�, ke� na��ta ��slo 0, t�to 0 ale 
neuklad� do po�a.Funkcia vr�ti smern�k na alokovan� pole a ve�kos� po�a(nepriamo, pomocou smern�ka).*/
double* f2_nacitaj(int *size) {
	double *pole, num;
	int n = 0;
	pole = (double*)malloc((n+1)*sizeof(double));
	do {
		printf("Zadaj cislo rozne od 0: ");
		scanf_s("%lf", &num);
		if (num == 0.0)
			break;
		pole[n] = num;
		n++;
		pole = realloc(pole, (n + 1) * sizeof(double));
	}
	while (num != 0.0);
	*size = n;
	return pole;
}

/*3 - Nap�te a otestujte funkciu, ktorej vstupom je pole ��sel.Funkcia pole rozdel� na �seky, 
pri�om ka�d� �sek je ukon�en� nulou.Smern�ky na za�iatky jednotliv�ch �sekov ulo�� do dynamick�ho po�a smern�kov, 
ktor� pod�a potreby roz�iruje.Na koniec po�a smern�kov ulo�� smern�k NULL.Vr�ti smern�k na dynamick� pole smern�kov
(ukazuj�cich na za�iatky slov).
Nap�te si zvl᚝ funkciu, ktor� postupnosti ��sel z takto zadan�ho po�a smern�kov vyp�e
(viete, �e ka�d� postupnos� kon�� nulou), ka�d� na in� riadok.*/
int f3(int pole[]) {
	return 1;
}


/*4 - Nap�te funkciu, ktor� vytvor� dynamicky dvojrozmern� pole po�adovanej ve�kosti i riadkov a j st�pcov.
Pole napln� nulami a vr�ti.*/
int* f4_fill_pole(int i, int j) {
	int *pole;
	pole = (int*)calloc(i * j,sizeof(int));
	return pole;
}


void vypis_pole1(int pole[], int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		printf("%i ", pole[i]);
	}
	printf("\n");
}

void vypis_pole2(double pole[], int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		printf("%.2lf ", pole[i]);
	}
	printf("\n");
}

int main() {
	int pole1[10] = {0,1,2,3,4,5,6,7,8,9};
	int *pole2,size = 0;
	double *pole3;
	int n;
	//f1
	printf("Zadaj n");
	scanf_s("%d", &n);
	pole2 = f1_copy(pole1, n);
	vypis_pole1(pole2, n);
	free(pole2);

	//f2
	pole3 = f2_nacitaj(&size);
	vypis_pole2(pole3,size);
	free(pole3);

	//f3 f3(pole[]);

	//f4
	return 0;
}