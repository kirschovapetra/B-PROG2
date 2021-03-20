#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

#define N 50 //velkost pola
#define M 2  //zaklad
#define K 3  //k-tica
#define D 3  //decimacny faktor
#define MAX_SIZE 10000 //max velkost pola

//vypis pola int
void print_int(int pole[], int size) {
	int i;
	for (i = 0; i < size; i++) {
		printf("%d ", pole[i]);
	}
	printf("\n");
}

//vypis pola int odzadu
void print_int_backwards(int pole[], int size) {
	int i;
	for (i = size-1; i >=0; i--) {
		printf("%d ", pole[i]);
	}
	printf(" ");
}

//prevod do desiatkovej sustavy
int prevod(int number[], int m, int k) {
	int sum = 0, i;
	for (i = 0; i < k; i++) {
		sum += number[i] * ((int)pow(m, k - i - 1));
	}
	return sum;
}

//prevod z desiatkovej do inej sustavy
void prevod_back(int number, int x[]) {
	int i = 0;

	while (number != 0)
	{
		x[i] = number % M; //do pola ulozim zvysok po deleni
		number = number / M;		//number vydelim dvomi a ulozim do number
		i++;
		if (number == 0)
			break;
	}
	print_int_backwards(x, K);
}

//vypis pola double - pocetnosti,delta
void print_double(double pole[], int size) {
	int i, x[K] = { 0 };
	for (i = 0; i < size; i++) {
		prevod_back(i,x);
		printf("(%d)	%.3lf\n", i, pole[i]);
	}
	printf("\n");
}

void find_max(double pole[], int size, double *max) {
	int i;
	double m;
	m = pole[0];
	for (i = 0; i < size; i++) {
		if (pole[i]>m) {
			m = pole[i];
		}
	}
	*max = m;
}

//nahodne pole
void gen(int my_array[], int size, int m) {
	int i;
	for (i = 0; i < size; i++) {
		my_array[i] = rand() % m;	// <0,m-1> rand()%(m-1-0+1)+0 == rand() % m
	}
}

void relativnePocetnosti(int my_array[], double pocetnosti[], int n) {
	int i, j, k_tica[K] = { 0 };
	for (i = 0; i <= (n - K); i++) {

		//vytvorenie k-tice
		for (j = 0; j < K; j++) {
			k_tica[j] = my_array[i + j];
		}
		pocetnosti[prevod(k_tica, M, K)] += 1.0 / (n-K+1); //desatinne cislo
	}

	print_double(pocetnosti, (int)pow(M, K));
}

int decimacia(int my_array[], int n, int d) {
	int i, j, size;
	size = n;
	for (i = 0; i < size; i++) {
		//vsetky d-te cisla prepisane na -1
		if ((i + 1) % d == 0 && i != 0) {
			my_array[i] = -1;
		}
	}
	//vymazanie vsetkych -1 z pola
	for (i = 0; i < size; i++) {
		if (my_array[i] == -1) {
			for (j = i + 1; j < size; j++) {
				my_array[j - 1] = my_array[j];
			}
			size--;
			i--;
		}
	}
	return size;
}

void rozdiel(double array1[], double array2[], double delta[], int size) {
	int i;
	for (i = 0; i < size; i++) {
		if ((array1[i] - array2[i])<0) {
			delta[i] = -1*(array1[i] - array2[i]);
		}
		else {
			delta[i] = array1[i] - array2[i];
		}
	}
}

int main() {
	int ARRAY[N] = { 0 };					//pole - nahodne
	double poc_array1[MAX_SIZE] = { 0 };	//pocetnost pred
	double poc_array2[MAX_SIZE] = { 0 };	//pocetnost po
	double delta[MAX_SIZE] = { 0 };			//rozdiel pocetnosti
	double max;
	int size;
	srand(time(NULL));
	printf("N: %d\n",N);
	printf("M: %d\n", M);
	printf("K: %d\n", K);
	printf("D: %d\n\n", K);

	//2 - generovanie nahodneho pola
	gen(ARRAY, N, M);
	printf("Nahodne pole:\n");
	print_int(ARRAY, N);

	//3 - relativne pocetnosti
	printf("K-tica:		Relativne pocetnosti:\n");
	relativnePocetnosti(ARRAY, poc_array1, N);

	//4 - decimacia
	size = decimacia(ARRAY, N, D); 
	printf("Pole po decimacii:\n");
	print_int(ARRAY, size);

	//5 - rel pocetnosti po decimacii
	printf("K-tica:		Relativne pocetnosti po decimacii:\n");
	relativnePocetnosti(ARRAY, poc_array2, size);

	//6 - delta
	rozdiel(poc_array1, poc_array2, delta, (int)pow(M, K));
	printf("K-tica:		Rozdiel rel pocetnosti:\n");
	print_double(delta, (int)pow(M, K));

	//7 - maximum
	find_max(delta, (int)pow(M, K), &max);
	printf("maximalny rozdiel = %.3f\n\n",max);
	return 0;
}