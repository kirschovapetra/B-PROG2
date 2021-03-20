#include <stdio.h>
#include <memory.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS


/*1 - Vytvorte funkciu, ktorej vstupom je pole celıch èísel a jeho dåka.
Funkcia dynamicky alokuje pole dostatoènej ve¾kosti a prekopíruje doò obsah vstupného po¾a
(môete vyui štandardnú funkciu memcpy).Vráti smerník na alokované pole.*/
int* f1_copy(int pole[],int n){
	int *pole2;
	pole2 = (int*)malloc(n * sizeof(int));
	if (pole2 != NULL)
		memcpy(pole2, pole, n * sizeof(int));
	return pole2;
}

/*2 - Napíšte a otestujte funkciu, ktorá naèítava zo vstupu èísla do po¾a typu double, 
ktoré dynamicky alokuje a postupne zväèšuje.Funkcia sa zastaví, keï naèíta èíslo 0, túto 0 ale 
neukladá do po¾a.Funkcia vráti smerník na alokované pole a ve¾kos po¾a(nepriamo, pomocou smerníka).*/
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

/*3 - Napíšte a otestujte funkciu, ktorej vstupom je pole èísel.Funkcia pole rozdelí na úseky, 
prièom kadı úsek je ukonèenı nulou.Smerníky na zaèiatky jednotlivıch úsekov uloí do dynamického po¾a smerníkov, 
ktoré pod¾a potreby rozširuje.Na koniec po¾a smerníkov uloí smerník NULL.Vráti smerník na dynamické pole smerníkov
(ukazujúcich na zaèiatky slov).
Napíšte si zvláš funkciu, ktorá postupnosti èísel z takto zadaného po¾a smerníkov vypíše
(viete, e kadá postupnos konèí nulou), kadú na inı riadok.*/
int f3(int pole[]) {
	return 1;
}


/*4 - Napíšte funkciu, ktorá vytvorí dynamicky dvojrozmerné pole poadovanej ve¾kosti i riadkov a j ståpcov.
Pole naplní nulami a vráti.*/
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