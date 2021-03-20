#include <stdio.h>
int fact(int n) {
	int sucin = 1,i;
	for(i = 1; i <= n; i++) {
		sucin*= i;
	}
}

int cislo1(int n, int k) {
	return fact(n)/(fact(n-k)*fact(k));
}

int cislo2(int n, int k) {
	int citatel = 1, menovatel = 1, i;
	if (n - k < k) {
		k = n - k;
	}
	for (i = 1; i <= k; i++) {
		menovatel *= i;
	}
	for (i = 0; i <= k; i++) {
		citatel *= (n-i);
	}
	return citatel / menovatel;
}

//rekurzia
int cislo3(int n, int k) {
	if (k < 1 || k >= n)
		return 1;
	return cislo3(n - 1, k - 1) + cislo3(n - 1, k);
}

int main() {
	int k, n;
	for (n = 0; n<=20; n++) {
		for (k = 0; k<=n; k++) {
			printf("%d ", cislo3(n, k));
		}
		printf("\n");
	}
	return 0;
}