//Vstupom(parametrom) kaûdej funkcie je pole a jeho veækosù n(+Ôalöie potrebnÈ parametre).

#include <stdio.h>
void print(int pole[], int n) {
	int i;
	for (i = 0; i < n; i++) {
		printf("%d ", pole[i]);
	}
	printf("\n");
}



//ZmenÌ hodnoty prvkov na ich absol˙tne hodnoty.
void f1_abs(int pole[],int n) {
	int i;
	for (i = 0; i < n;i++) {
		if (pole[i] < 0)
			pole[i] = -1 * pole[i];
	}
}

//ZapÌöe prvky poæa v opaËnom poradÌ, t.j.prehodÌ prv˝ s posledn˝m, druh˝ s predposledn˝m, ...
void f2_swap(int pole[], int n) {
	int i,tmp;
	for (i = 0; i < (n/2); i++) {
		tmp = pole[i];
		pole[i] = pole[n - i - 1];
		pole[n - i - 1] = tmp;
	}
}

/*Odstr·ni z poæa vöetky hodnoty v‰Ëöie ako x. ZvyönÈ hodnoty popos˙va tak, 
aby boli prvky v pÙvodnom poradÌ bez medzier spÙsoben˝ch predoöl˝m krokom.Vr·ti nov˝ poËet prvkov.*/
int f3_del_vacsieakox(int pole[], int n,int x) {
	int i,j,size = n;
	for (i = 0; i < size;i++) {
		if (pole[i]>x) {
			for (j = i + 1; j < size;j++) {
				pole[j-1] = pole[j];
			}
			i--;
			size--;
		}
	}
	return size;
}

//Usporiada prvky poæa pomocou zvolenÈho algoritmu.
void f4_sort(int pole[], int n) {
	int i, j,tmp;
	for (i = 0; i < n; i++) {
		for (j = i; j < n; j++) {
			if (pole[i] > pole[j]) {
				tmp = pole[i];
				pole[i] = pole[j];
				pole[j] = tmp;
			}
		}
	}
}

//Funkcia prid· do poæa na koniec prvok x.Vr·ti nov˝ poËet prvkov.
int f5_append(int pole[], int n,int x) {
	int pocet = n;
	pole[n] = x;
	return pocet + 1;
}

/*Funkcia prid· do poæa na zaËiatok prvok x(ostatnÈ prvky teda treba popos˙vaù!- 
ako na to ? sk˙ste si popos˙vaù po jednej bunke v tabuækovom procesore).Vr·ti nov˝ poËet prvkov.*/
int f6_append_na_zaciatok(int pole[], int n, int x) {
	int i, pocet = n;
	for (i = n; i > 0;i--) {
		pole[i] = pole[i - 1];
	}
	pole[0] = x;
	return pocet + 1;
}

/*Funkcia prid· do poæa na koniec prvok x, ak takÈ ËÌslo uû v poli nie je
(ak je, tak sa s poæom niË nerobÌ).Vr·ti nov˝ poËet prvkov.*/
int f7_append_ak_nieje(int pole[], int n, int x) {
	int i, pocet = n;
	for (i = 0; i < n;i++) {
		if (pole[i] == x)
			return pocet;
	}
	pole[n] = x;
	return pocet+1;
}

/* prid· do usporiadanÈho poæa prvok x tak, aby pole zostalo usporiadanÈ
(t.j.n·jde prv˝ v‰ËöÌ prvok, vloûÌ x a ostatnÈ prvky popos˙va).Vr·ti nov˝ poËet prvkov.*/
int f8_append_usporiadane(int pole[], int n, int x) {
	int i, pocet = n,index = 0;
	for (i = 1; i < n;i++) {
		if (pole[i - 1] <= x && pole[i + 1] >= x)
			index = i;
	}
	for (i = n; i > index; i--) {
		pole[i] = pole[i - 1];
	}
	pole[index] = x;
	return pocet + 1;
}

int main() {
	int pole1[100] = { 1,6,3,4,-1,9,7,0,-1,3 };
	int pole2[100] = {2,7,3,1,9,-4,0,4,3,1};

	int x = 4, y = 5,z = 2, n = 10, size;

	printf("Pole1\n");
	print(pole1, n);
	printf("Pole2\n");
	print(pole2, n);

	f1_abs(pole1, n);
	printf("\nAbs hodnoty pole1:\n");
	print(pole1, n);

	f2_swap(pole1, n);
	printf("\nSwap pole1 0,n-1 1,n-2...\n");
	print(pole1, n);

	size = f3_del_vacsieakox(pole2, n, x);
	printf("\nDelete z pole2 >%d\n",x);
	print(pole2, size);

	f4_sort(pole1, n);
	printf("\nSort pole1\n");
	print(pole1, n);

	n = f5_append(pole1, n, x);
	printf("\nAppend %d do pole1\n",x);
	print(pole1, n);

	n = f6_append_na_zaciatok(pole1, n, x);
	printf("\nAppend %d do pole1 na zaciatok\n",x);
	print(pole1, n);

	n = f7_append_ak_nieje(pole1, n, x);
	printf("\nAppend %d do pole1 ak nie je\n", x);
	print(pole1, n);

	n = f7_append_ak_nieje(pole1, n, y);
	printf("\nAppend %d do pole1 ak nie je\n", y);
	print(pole1, n);

	f4_sort(pole1, n);
	n = f8_append_usporiadane(pole1, n, z);
	printf("\nAppend %d do pole1, usporiadane\n", z);
	print(pole1, n);

	return 0;
}