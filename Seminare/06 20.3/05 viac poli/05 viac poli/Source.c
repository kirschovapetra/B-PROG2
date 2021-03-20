#include <stdio.h>

void print(int pole[], int n) {
	int i;
	for (i = 0; i < n; i++) {
		printf("%d ", pole[i]);
	}
	printf("\n");
}

int nachadza_sa(const int pole[], int n, int x) {
	int i;
	for (i = 0; i < n; i++) {
		if (pole[i] == x) {
			return 1;
		}
	}
	return 0;
}

/*Funkcia m· na vstupe 2 polia(poleA, poleB) a veækosù n.Polia ch·peme ako vektory hodnÙt.
Funkcia vypoËÌta skal·rny s˙Ëin vektorov poleA a poleB(t.j.s˙Ëet poleA[i] * poleB[i] cez vöetky i).*/
void f1_skalarny_sucin(int poleA[], int poleB[], int n) {
	int i;
	for (i = 0; i < n; i++) {
		poleA[i] *= poleB[i];
	}
}

/*Funkcia m· na vstupe 2 polia(poleA, poleB) a veækosù n.Polia ch·peme ako vektory hodnÙt.
Funkcia zistÌ, Ëi vektory poleA a poleB s˙ rovnakÈ(t.j.poleA[i] == poleB[i] pre vöetky i).*/
int f2_porovnanie(int poleA[], int poleB[], int n) {
	int i;
	for (i = 0; i < n; i++) {
		if (poleA[i] != poleB[i])
			return 0;
	}
	return 1;
}

/*Funkcia m· na vstupe 2 polia(poleIn a poleOut) a veækosù n.Do poæa poleOut skopÌruje prvky z poæa poleIn.
Predpokladajte, ûe polia sa neprekr˝vaj˙.*/
void f3_copy(int poleIN[], int poleOUT[], int n) {
	int i;
	for (i = 0; i < n; i++) {
		poleOUT[i] = poleIN[i];
	}
}
//TODO
/*Funkcia m· na vstupe 2 polia(poleIn a poleOut) a veækosù n.
Do poleOut zapÌöte prvky z poleIn usporiadane(poleIn nesmiete zmeniù).*/
void f4_copy_sort(int poleIN[], int poleOUT[], int n) {
	int i,j;
	for (i = 0; i < n; i++) {
		for (j = i; j < n; j++) {
		}
	}
}

/*Funkcia m· na vstupe 2 polia(poleIn a poleOut) a veækosù n.
Do poleOut zapÌöte prvky z poleIn v opaËnom poradÌ(poleIn nesmiete zmeniù).*/
void f5_copy_reverse(int poleIN[], int poleOUT[], int n) {
	int i;
	for (i = 0; i <n; i++) {
		poleOUT[i] = poleIN[n-1-i];
	}
}

/*Do poleOut zapÌöe vöetky prvky z poleIn v‰Ëöie ako x(v pÙvodnom poradÌ).Vr·ti nov˝ poËet prvkov poleOut.*/
int f6_copy_vacsieakox(int poleIN[], int poleOUT[], int n, int x) {
	int i, j = 0;
	for (i = 0; i <n; i++) {
		if (poleIN[i]> x) {
			poleOUT[j] = poleIN[i];
			j++;
		}
	}
	return j;
}

/*Funkcia m· na vstupe 3 polia(poleOut, poleA, poleB) a veækosù n.Polia ch·peme ako vektory hodnÙt.
Funkcia zapÌöe do poleOut s˙Ëet vektorov poleA a poleB(poleOut[i] = poleA[i] + poleB[i], pre vöetky i).*/
void f7_sucet(int poleOUT[],int poleA[],int poleB[], int n) {
	int i;
	for (i = 0; i <n; i++) {
		poleOUT[i] = poleA[i] + poleB[i];
	}
}


/*Funkcia m· na vstupe 2 polia(poleA, poleB) a veækosù n.Polia ch·peme ako vektory hodnÙt.
Funkcia pripoËÌta k - n·sobok vektora poleB do vektora poleA(poleA[i] = poleA[i] + k*poleB[i], pre vöetky i).*/
void f8_k_nasobok(int poleA[], int poleB[], int n, int k) {
	int i;
	for (i = 0; i <n; i++) {
		poleA[i] = poleA[i] + k*poleB[i];
	}
}

/*Funkcia m· na vstupe 3 polia(poleOut, poleA, poleB), veækosti nA a nB.Pole poleOut musÌ maù dostatoËn˙ kapacitu, 
t.j.min(nA, nB).Ch·peme poleA a poleB ako mnoûiny.Do poleOut napÌöte ich prienik(t.j.bud˙ tam iba prvky, 
ktorÈ s˙ aj v poleA aj v poleB).Vr·ùte poËet prvkov poleOut.*/
int f9_prienik(int poleOUT[], int poleA[], int poleB[], int nA,int nB) {
	int i, j,n,ind = 0;
	if (nA < nB)
		n = nA;
	else
		n = nB;
	for (i = 0; i <n; i++) {
		for (j = 0; j < n;j++) {
			if (poleA[i] == poleB[j] && !nachadza_sa(poleOUT,n, poleA[i])) {
				poleOUT[ind] = poleA[i];
				ind++;
			}
		}
	}
	return ind;
}

/*Funkcia m· na vstupe 3 polia(poleOut, poleA, poleB), veækosti nA a nB.Pole poleOut musÌ maù dostatoËn˙ kapacitu(nA + nB).
Ch·peme poleA a poleB ako mnoûiny.Do poleOut napÌöte ich zjednotenie(t.j.bud˙ tam iba prvky, 
ktorÈ s˙ alebo v poleA alebo v poleB).Vr·ùte poËet prvkov poleOut.*/
int f10_zjednotenie(int poleOUT[], int poleA[], int poleB[], int nA, int nB) {
	int i, ind = 0;
	for (i = 0; i <nA; i++) {
		if (!nachadza_sa(poleOUT, nA, poleA[i])) {
			poleOUT[ind] = poleA[i];
			ind++;
		}
		
	}
	for (i = 0; i <nB; i++) {
		if (!nachadza_sa(poleOUT, nB, poleA[i])) {
			poleOUT[ind] = poleB[i];
			ind++;
		}
	}
	return ind;
}

/*Funkcia m· na vstupe 3 polia(poleOut, poleA, poleB), veækosti nA a nB.Pole poleOut musÌ maù dostatoËn˙ kapacitu(nA).
Ch·peme poleA a poleB ako mnoûiny.Do poleOut napÌöte ich rozdiel(t.j.bud˙ tam iba prvky, ktorÈ s˙ v poleA a nie s˙ v poleB).
Vr·ùte poËet prvkov poleOut.*/
int f11_rozdiel(int poleOUT[], int poleA[], int poleB[], int nA, int nB) {
	int i, ind = 0;
	for (i = 0; i <nA; i++) {
		if (!nachadza_sa(poleB, nB, poleA[i]) && !nachadza_sa(poleOUT, nA, poleA[i])) {
			poleOUT[ind] = poleA[i];
			ind++;
		}
	}
	return ind;
}

/*Funkcia m· na vstupe 3 polia(poleOut, poleA, poleB), veækosti nA a nB.Pole poleOut musÌ maù dostatoËn˙ kapacitu(nA + nB).
poleA a poleB ako mnoûiny.Do poleOut napÌöte ich symetrick˝ rozdiel(t.j.bud˙ tam iba prvky, ktorÈ s˙ v poleA a nie s˙ 
v poleB alebo s˙ v poleB a nie s˙ v poleA).Vr·ùte poËet prvkov poleOut.*/
int f12_sym_rozdiel(int poleOUT[], int poleA[], int poleB[], int nA, int nB) {
	int i, ind = 0;
	for (i = 0; i <nA; i++) {
		if (!nachadza_sa(poleOUT, nA, poleA[i])) {
			if (!nachadza_sa(poleB, nB, poleA[i]) || !nachadza_sa(poleA, nA, poleB[i])) {
				poleOUT[ind] = poleA[i];
				ind++;
			}
		}
	}
	return ind;
}

/*Funkcia m· na vstupe pole intervalov(iba na ËÌtanie) a rovnako veækÈ pole ËÌsel typu double.
Funkcia vypoËÌta veækosù intervalu a zapÌöe ju do poæa typu double na rovnak˙ pozÌciu ako m· interval v poli intervalov.*/

int main() {
	int poleA[10] = { 1,2,3,4,5 };
	int poleB[10] = { 4,3,2,1,0 };
	int poleOUT[10] = { 0 };
	int n = 5, x = 2,k = 2,size;
	printf("A: ");
	print(poleA, n);
	printf("B: ");
	print(poleB, n);
	printf("\n");

	f1_skalarny_sucin(poleA, poleB, n);
	printf("\nSkalarny sucin A = A*B\n");
	print(poleA, n);

	printf("\nporovnanie A,B %d\n",f2_porovnanie(poleA, poleB, n));
	printf("porovnanie A,A %d\n", f2_porovnanie(poleA, poleA, n));

	f3_copy(poleA, poleOUT, n);
	printf("\nCopy A\n");
	print(poleOUT, n);

	/*f4_copy_sort(poleB, poleOUT, n);
	printf("\nCopy sort B\n");
	print(poleOUT, n);*/

	f5_copy_reverse(poleA, poleOUT, n);
	printf("\nCopy A reverse A\n");
	print(poleOUT, n);

	size = f6_copy_vacsieakox(poleB, poleOUT, n, x);
	printf("\nCopy B vacsie ako %d\n",x);
	print(poleOUT, size);

	f7_sucet(poleOUT, poleA, poleB, n);
	printf("\nSucet A+B\n");
	print(poleOUT, n);

	f8_k_nasobok(poleA, poleB, n, k);
	printf("\nSucet A+%d*B\n",k);
	print(poleA, n);

	n = f9_prienik(poleOUT, poleA, poleB, n, n);
	printf("\nPrienik A,B\n");
	print(poleOUT, n);

	/*f10_zjednotenie(poleOUT, poleA, poleB, n, n);
	f11_rozdiel(poleOUT, poleA, poleB, n, n);
	f12_sym_rozdiel(poleOUT, poleA, poleB, n, n);*/

	return 0;
}