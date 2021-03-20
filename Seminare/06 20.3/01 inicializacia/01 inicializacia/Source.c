#include <stdio.h>
#include <stdlib.h>

//Funkcia inicializuje pole hodnotami od 0 po n-1 (parameter funkcie n urËuje veækosù poæa).
void f1(int pole[],int n) {
	int i;
	for (i = 0; i < n;i++) {
		pole[i] = i;
	}
}

//Funkcia inicializuje pole hodnotami od 1 po n.
void f2(int pole[], int n) {
	int i;
	for (i = 1; i <= n; i++) {
		pole[i-1] = i;
	}
}
//Funkcia inicializuje pole hodnotami od n po 1 (zostupne).
void f3(int pole[], int n) {
	int i;
	for (i = 1; i <= n; i++) {
		pole[n- i] = i;
	}
}

//Funkcia inicializuje pole n n·hodn˝mi hodnotami. Pouûite kniûniËn˙ funkciu rand() (deklar·cia v stdlib.h).
void f4(int pole[], int n) {
	int i;
	for (i = 0; i<n ; i++) {
		pole[i] = rand()%10;
	}
}

//Funkcia inicializuje pole hodnotami rovn˝mi k-n·sobku indexu ().
void f5(int pole[], int n,int k) {
	int i;
	for (i = 0; i<n; i++) {
		pole[i] = k*i;
	}
}

//TODO:
//Funkcia inicializuje pole n p·rnymi ËÌslami v‰ËöÌmi alebo rovn˝mi parametru a.
void f6(int pole[], int n, int a) {
	int i = 0, j;
}


void print_pole(int pole[],int n) {
	int i;
	for (i = 0; i < n; i++) {
		printf("%d ",pole[i]);
	}
	printf("\n");
}

int main() {
	int pole[10] = { 0 };
	int n = 10, a = 3, k = 2;

	srand(time(NULL));

	f1(pole, n);
	printf("od 0 po %d\n",n-1);
	print_pole(pole, n);

	f2(pole, n);
	printf("od 1 po %d\n", n);
	print_pole(pole, n);

	f3(pole, n);
	printf("od %d po 1\n", n);
	print_pole(pole, n);

	f4(pole, n);
	printf("random\n");
	print_pole(pole, n);

	f5(pole, n, k);
	printf("Nasobky %d\n",k);
	print_pole(pole, n);

	/*f6(pole, n, a);
	printf("Parne cisla >= %d\n", a);
	print_pole(pole, n);*/

	return 0;
}
