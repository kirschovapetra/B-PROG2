//Vstupom(parametrom) ka�dej funkcie je pole s kvantifik�torom const a jeho d�ka(+�al�ie potrebn� parametre).

#include <stdio.h>
const int A[10] = { 1,3,5,7,1,-1,0,4,7,9 };


//Vyp�e prv�ch n prvkov po�a.
void f1_print(const int pole[], int n) {
	int i;
	for (i = 0; i < n;i++) {
		printf("%d ", pole[i]);
	}
	printf("\n");
}

//Vypo��ta(tzn.n�jde hodnotu a vr�ti ju cez return) minimum z n ��sel v poli.
int f2_min(const int pole[], int n) {
	int i, min;
	min = pole[0];
	for (i = 0; i < n; i++) {
		if (pole[i]<min) {
			min = pole[i];
		}
	}
	return min;
}

//Vypo��ta maximum z n ��sel v poli.
int f3_max(const int pole[], int n) {
	int i, max;
	max = pole[0];
	for (i = 0; i < n; i++) {
		if (pole[i]>max) {
			max = pole[i];
		}
	}
	return max;
}

//Vypo��ta priemer z n ��sel v poli.
double f4_priemer(const int pole[], int n) {
	int i,sum = 0;
	for (i = 0; i < n; i++) {
		sum += pole[i];
	}
	return sum / n;
}

//Vypo��ta s��in v�etk�ch n ��sel v poli
double f5_sucin(const int pole[], int n) {
	int i, sucin = 1;
	for (i = 0; i < n; i++) {
		sucin *= pole[i];
	}
	return sucin;
}

//Vypo��ta po�et ��sel v poli, ktor� patria do nejak�ho intervalu[a, b].
int f6_pocet(const int pole[], int n,int a, int b) {
	int i, pocet = 0;
	for (i = 0; i < n; i++) {
		if (pole[i]>=a && pole[i]<=b)
			pocet++;
	}
	return pocet;
}

//TODO
//N�jde druh� najv��� / najmen�� prvok po�a
int f7_max2(const int pole[], int n) {
	int i, max,max2;
	max = pole[0];
	max2 = pole[0];
	for (i = 0; i < n; i++) {
		if (pole[i]>max) {
			max = pole[i];
		}
	}

	for (i = 0; i < n; i++) {
		if (pole[i]>max2 && max2<max) {
			max2 = pole[i];
		}
	}
	return max2;
}

//Vyp�e v�etky ��sla v poli, ktor� s� v��ie ako dan� ��slo x
void f8_vacsie_x(const int pole[], int n, int x) {
	int i;
	for (i = 0; i < n; i++) {
		if (pole[i]>x)
			printf("%d ", pole[i]);
	}
	printf("\n");
}

//Zist� po�et ��sel v poli, ktor� s� men�ie ako dan� ��slo x.
int f9_pocet_mensie_x(const int pole[], int n, int x) {
	int i,pocet = 0;
	for (i = 0; i < n; i++) {
		if (pole[i] < x)
			pocet++;
	}
	return pocet;
}

//Zist� po�et v�skytov ��sla x v poli.
//Zist�, �i sa ��slo x v poli nach�dza.Pozn.: Ak si sprav�te spr�vne predo�l� funkciu, tak t�to vlastne m�te tie� hotov�...
int f10_pocet_x(const int pole[], int n, int x) {
	int i, pocet = 0;
	for (i = 0; i < n; i++) {
		if (pole[i] == x)
			pocet++;
	}
	return pocet;
}

//Zist�, �i pole je usporiadan�(od najmen�ieho prvku).
int f11_usporiadanie(const int pole[], int n) {
	int i;
	for (i = 0; i < n-1; i++) {
		if (pole[i] > pole[i + 1])
			return 0;
	}
	return 1;
}

/*Zist�, �i pole intervalov je usporiadan�
(2 verzie: usporiadan� pod�a spodnej hranice intervalu, alebo od najkrat�ieho intervalu).
Interval predstavuj� v�dy 2 po sebe id�ce prvky po�a(t.j.ve�kos� po�a mus� by� p�rna).*/

int f12_intervaly_a(const int pole[], int n) {
	int i;
	for (i = 0; i < n - 2; i+=2) {
		if (pole[i] > pole[i + 2])
			return 0;
	}
	return 1;
}

int f12_intervaly_b(const int pole[], int n) {
	int i, max = 0;
	for (i = 0; i < n-3; i += 2) {
		if ((pole[i + 1] - pole[i]) > (pole[i+3]-pole[i+2]))
			return 0;
	}
	return 1;
}

//TODO
//Zist�, �i pole n ��sel predstavuje permut�ciu, t.j.je tam ka�d� ��slo od 1 po n pr�ve raz.
int f13_permutacia(const int pole[], int n) {
	int i, j,pocet;
	for (i = 0; i < n; i++) {
		pocet = 0;
		for (j = 0; j < n; j++) {
			if (pole[j] == i) 
				pocet++;
		}
		if (pocet == 1)
			return 1;
	}
	return 0;
}

//Zist�, �i pole n ��sel je mno�ina, t.j.ka�d� ��slo je v poli pr�ve raz.
int f14_prave_raz(const int pole[], int n) {
	int i, j;
	for (i = 0; i < n; i++) {
		for (j = i + 1; j < n; j++) {
			if (pole[i] == pole[j])
				return 0;
		}
	}
	return 1;
}

int main() {
	int k = 5,n = 10;
	int a = 2, b = 7, x = 3;
	f1_print(A, k);
	printf("%d\n",f2_min(A, n));
	printf("%d\n", f3_max(A, n));
	printf("%.2f\n", f4_priemer(A, n));
	printf("%.2f\n", f5_sucin(A, n));
	printf("%d\n", f6_pocet(A, n, a, b));
	printf("%d\n", f7_max2(A, n));
	f8_vacsie_x(A, n, x);
	printf("%d\n", f9_pocet_mensie_x(A, n, x));
	printf("%d\n", f10_pocet_x(A, n, x));
	printf("%d\n", f11_usporiadanie(A, n));
	printf("%d\n", f12_intervaly_a(A, n));
	printf("%d\n", f12_intervaly_b(A, n));
	printf("%d\n", f13_permutacia(A, n));
	printf("%d\n", f14_prave_raz(A, n));

	

	return 0;
}