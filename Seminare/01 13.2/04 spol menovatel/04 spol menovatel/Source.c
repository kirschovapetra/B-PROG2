#include <stdio.h>
int gcd(int n1, int n2)
{

	while (n1 != n2)
	{
		if (n1 > n2)
			n1 -= n2;
		else
			n2 -= n1;
	}

	return n1;
}


int main()
{
	int a, b, c, d, menovatel;
	printf("Zadaj 2 cisla a/b\n");
	scanf_s("%i", &a);
	scanf_s("%i", &b);

	printf("Zadaj 2 cisla c/d\n");
	scanf_s("%i", &c);
	scanf_s("%i", &d);
	printf("Zadane zlomky %i/%i a %i/%i\n", a, b, c, d);

	menovatel = (b*d) / gcd(b, d);
	a *= menovatel / b;
	c *= menovatel / d;

	printf("Nove zlomky %i/%i a %i/%i\n", a, menovatel, c, menovatel);
	return 0;
}