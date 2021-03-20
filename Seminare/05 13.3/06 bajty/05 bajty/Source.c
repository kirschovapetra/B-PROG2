/*Nap�te funkciu, ktorej vstupom je adresa typu (void*) a size - ve�kos� �daju v bajtoch. 
Funkcia vyp�e postupne bajty na danej adrese v hexadecim�lnom tvare. 
Pou�ite t�to funkciu na v�pis premenn�ch r�zneho typu (napr. unsigned int i = 0xdeadbeef; double pi = 3.14), 
pr�padne vysk��ajte aj so smern�kom na funkciu/pole.*/

#include <stdio.h>

void fun(void *p, int size) {
	int i;
	int *ptr =(int*) p;
	for (i = 0; i < size;i++) {
		printf("%x ", ptr);
		*ptr++;
	}
}



int main() {
	int a;
	fun(&a,8);
	return 0;
}