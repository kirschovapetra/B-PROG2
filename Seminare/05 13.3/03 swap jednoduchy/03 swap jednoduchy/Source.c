/*Napíšte funkciu, ktorej vstupom sú 2 adresy celıch èísel. Funkcia prehodí obsah uloenı na tıchto adresách.
Vyskúšajte poui túto funkciu pri usporiadaní po¾a (¾ubovo¾nım algoritmom).*/

void swap(int *n1, int *n2) {
	int tmp;
	tmp = *n1;
	*n1 = *n2;
	*n2 = tmp;
}

int main() {
	int pole[5] = {2,-1,8,3,5};
	for (i = 0; i < 5;i++) {
		for (j = 1; j < i; j++) {
			if (pole[j-1]>pole[j]) {
				swap(&pole[j - 1], &pole[j]);
			}
		}
	}
	for (i = 0; i < 5; i++) {
		printf(pole[i]);
	}
	return 0;
}