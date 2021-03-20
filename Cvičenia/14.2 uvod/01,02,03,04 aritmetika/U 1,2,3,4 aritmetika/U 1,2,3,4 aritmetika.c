#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void aritmetika(int a, int b)
{
	int plus, minus, krat, del;
	plus = a + b;
	minus = a - b;
	krat = a*b;
	del = a / b;

	printf("sucet = %i , rozdiel = %i , sucin = %i , podiel = %i\n", plus, minus, krat, del);

}
int generuj(a, b)
{
	int r;
	srand(time(NULL));
	r = rand() % (b - a + 1) + a;

	return r;
}

int main()
{
	int any, x, y, d;
	printf("Zadaj dve cisla:");
	scanf("%i %i", &x, &y);

	aritmetika(x,y);
	d = generuj(1, 10);
	printf("nahodne cislo = %i\n", d);

	scanf("%i", &any);
	return 0;
}
