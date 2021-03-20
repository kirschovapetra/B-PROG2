#include <stdio.h>
#define N 1000000000
char _pole[N] = {0};

void sito(int n) {
	int p, i;
	for (p = 2; p*p <= n; p++) {
		if (_pole[p] == 1) {
			continue;
		}
		for (i = p*p; i < n; i += p) {
			_pole[i] = 1;
		}
	}
}

int pocet(int n) {
	int i,count=0;
	for (i = 2; i < n; i++) {
		if (_pole[i] == 0) {
			count++;
		}
	}
	return count;
}

int main() {
	sito(N);
	printf("Pocet prvocisel mensich ako %d je %d\n",N,pocet(N));
	return 0;
}