#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

//testovacie velke pole
#define MEGA 100000000
int mega[MEGA];

//cielova funkcia, odstrani duplikaty z pola
int unikaty(int data[], int *pN)
{
	//znacime si pocet platnych miest
	int nove_platne = 0;
	int i;

	//prechadzame prvky
	for (i = 0; i < *pN; i++)
	{
		//ak sa nenachadzaju medzi doteraz platnymi
		if (!obsahuje(data, nove_platne, data[i]))
		{
			//tak su unikatne a pridame ich
			data[nove_platne] = data[i];
			nove_platne++;
		}
	}

	//vratime novu velkost pola (2 sposoby, aj ako vysledok, aj cez smernik)
	*pN = nove_platne;
	return nove_platne;
}

//pomocna funkcia z prednasky
void vypis_pole(const int pole[], int n)
{
	int i;
	printf("Velkost pola: %i\n", n);
	for (i = 0; i < n; i++)
	{
		printf("%i ", pole[i]);
	}
	printf("\n");
}

//zisti, ci x je v poli data velkosti n
int obsahuje(int data[], int n, int x)
{
	int i;
	for (i = 0; i < n; i++)
	{
		if (data[i] == x)
			return 1;
	}
	return 0;
}

//generuje do pola n hodnot v rozsahu 0 - m-1
void generuj(int data[], int n, int m)
{
	int i;
	for (i = 0; i < n; i++)
	{
		data[i] = rand() % m;
	}
}

int main() {
	//testovacie male pole a jeho velkost
	int pole[] = { 1,4,2,2,1,5,4,3 };
	int n = sizeof(pole) / sizeof(pole[0]);

	//velkost velkeho testovacieho pola
	int nm = MEGA;

	//test pre male pole
	vypis_pole(pole, n);
	unikaty(pole, &n);
	vypis_pole(pole, n);

	//test pre mega pole
	generuj(mega, nm, 1000);
	printf("V mega poli: %i\n", nm);
	unikaty(mega, &nm);
	printf("V mega poli: %i\n", nm);


	return 0;
}

