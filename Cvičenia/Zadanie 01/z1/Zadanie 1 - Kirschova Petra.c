#include <stdio.h>
#include <time.h>    
#include <stdlib.h>

//generator nahodneho cisla
int random( int min,int max) {
	int r;
	r = rand() % (max - min + 1) + min;
	return r;
}

int main() {
	int hrac_a, hrac_b, m, kolo;
	float priemer, sum_a, sum_b;

	hrac_a = 0;
	hrac_b = 0;
	sum_a = 0;
	sum_b = 0;
	kolo = 0;
	srand(time(NULL));

	while (hrac_a <= 400 && hrac_b <= 400) {
		kolo += 1;
		printf("KOLO %d\n", kolo);

		//nahodny pocet metrov - pripocita sa k predchadzajucemu stavu a
		m = random(0, 1);
		hrac_a += m;
		printf("hrac A: %d\n", hrac_a);

		//nahodny pocet metrov - pripocita sa k predchadzajucemu stavu b
		m = random(0, 25);
		hrac_b += m;
		printf("hrac B: %d\n", hrac_b);

		printf("\n");

		//prekazky a - vrati sa na start
		if (hrac_a > 0 && hrac_a < 400) {
			if (hrac_a % 50 == 0) {
				hrac_a = 0;
				printf("Hrac A vrat sa spat na start\n");
			}
		}

		//prekazky b - vrati sa na start
		if (hrac_b > 0 && hrac_b < 400) {
			if (hrac_b % 50 == 0) {
				hrac_b = 0;
				printf("Hrac B vrat sa spat na start\n");
			}
		}
	}

	//podmienka na vyhru a
	if (hrac_a >= 400 && hrac_b < 400) {
		printf("Gratulujem, vyhrava hrac A\n");
	}

	//podmienka na vyhru b
	if (hrac_b >= 400 && hrac_a < 400) {
		printf("Gratulujem, vyhrava hrac B\n");
	}

	//pripad keby sa obaja hraci dostanu naraz do ciela - vyhrava ten, ktory presiel viac metrov
	if (hrac_b >= 400 && hrac_a >= 400) {
		if (hrac_a > hrac_b) {
			printf("Gratulujem, vyhrava hrac A\n");
		}
		if (hrac_b > hrac_a) {
			printf("Gratulujem, vyhrava hrac B\n");
		}
		if (hrac_b == hrac_a) {
			printf("REMIZA\n");
		}
	}

	//priemerny pocet metrov prejdenych za kolo
	sum_a = hrac_a;
	sum_b = hrac_b;

	priemer = sum_a / kolo;
	printf("Hrac A presiel priemerne %f metrov za 1 kolo\n", priemer);

	priemer = sum_b / kolo;
	printf("Hrac B presiel priemerne %f metrov za 1 kolo\n", priemer);

	return 0;
}

