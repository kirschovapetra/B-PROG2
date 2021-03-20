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
	int a, b, x, y, z, d;
	printf("Zadaj 2 cisla:\n");

	scanf_s("%i", &a);
	scanf_s("%i", &b);

	x = a / b;
	y = a%b;
	z = b;

	d = gcd(y, z);
	y = y / d;
	z = z / d;

	printf("vysledok = %i + %i/%i", x, y, z);
	return 0;
}

