/*Nap�te funkciu, ktorej vstupom s� 2 adresy cel�ch ��sel. Funkcia prehod� obsah ulo�en� na t�chto adres�ch.
Vysk��ajte pou�i� t�to funkciu pri usporiadan� po�a (�ubovo�n�m algoritmom).*/

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