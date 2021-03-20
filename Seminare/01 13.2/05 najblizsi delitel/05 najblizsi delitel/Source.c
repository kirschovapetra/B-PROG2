#include <stdio.h>

int del(cislo, min)
{
	int i;
	i = min;
	while (i<cislo)
	{
		if (cislo%i == 0)
			return i;
		else
			i++;
	}
}

int main()
{
	int x, y, d;
	printf("Zadaj cislo a min:\n");
	scanf_s("%i", &x);
	scanf_s("%i", &y);

	d = del(x, y);
	printf("delitel = %i\n", d);
	return 0;
}