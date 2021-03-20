/*Napíšte funkciu, ktorej vstupom je adresa typu (void*) a size - ve¾kos údaju v bajtoch. 
Funkcia vypíše postupne bajty na danej adrese v hexadecimálnom tvare. 
Pouite túto funkciu na vıpis premennıch rôzneho typu (napr. unsigned int i = 0xdeadbeef; double pi = 3.14), 
prípadne vyskúšajte aj so smerníkom na funkciu/pole.*/

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