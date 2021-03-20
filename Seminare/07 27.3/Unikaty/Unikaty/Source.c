#include <stdio.h>
#include <stdlib.h>

//vypis zadaneho pola
void vypis_pole(const int pole[], int n);
//generuje do pola n hodnot v rozsahu 0 - m-1
void generuj(int data[], int n, int m);

//funkcia dostane pole, najde unikatne hodnoty a vrati ako nove pole (dynamicke)
int* unikaty2(const int data[], int n, int *pU);

#define MEGA 10000000
#define HRANICA 100000

int mega[MEGA];

int main() {
	int nm = MEGA;
	int *nove, nu;

	//vypis_pole(pole, n);
	generuj(mega, nm, HRANICA);
	printf("V mega poli: %i\n", nm);
	nove = unikaty2(mega, nm, &nu);
	printf("V novom poli: %i\n", nu);

	//vypis_pole(nove, nu);	

	//dynamicke pole, je potrebne uvolnit
	free(nove);

	return 0;
}


//pre potreby qsort: funkcia na porovnanie prvkov pola zadanych adresov
int compare(void* a, void* b)
{
	return *(int*)a - *(int*)b;
}

//zmenena funkcia na zrusenie duplicit
int* unikaty2(const int data[], int n, int *pU)
{
	int *out;
	int nove_platne = 0;
	int i;

	//dynamicky alokovane vystupne pole: berieme maximalne najvacsiu potencialnu velkost
	out = (int*)malloc(n * sizeof(int));

	//vyuzijeme qsort: pozor, prehodi povodne pole
	//TODO: ako to spravit tak, aby sa povodne pole nezmenilo?
	qsort(data, n, sizeof(int), compare);

	//zapiseme prvy prvok, urcite mozeme
	out[nove_platne] = data[0];
	nove_platne++;
	for (i = 1; i < n; i++)
	{
		//kedze je to usporiadane, staci sa pozerat na posledne pridany prvok
		if (data[i] != out[nove_platne - 1])
		{
			out[nove_platne] = data[i];
			nove_platne++;
		}
	}

	//zaverecne ukony: vratime novu velkost cez smernik pU
	*pU = nove_platne;
	// a upravime velkost pola, aby sme zbytocne neminali pamat
	out = (int*)realloc(out, nove_platne * sizeof(int));
	return out;
}





void generuj(int data[], int n, int m)
{
	int i;
	for (i = 0; i < n; i++)
	{
		data[i] = rand() % m;
	}
}

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