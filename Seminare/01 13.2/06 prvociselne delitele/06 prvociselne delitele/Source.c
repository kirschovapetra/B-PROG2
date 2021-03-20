#include <stdio.h>

int prvoc(cislo)
{
	int i;
	i = 2;

	while (i<cislo)
	{
		if (cislo%i == 0)
		{
			return 0;
		}

		i++;
	}
	return 1;
}

int main()
{
	int x, d, i, n;
	printf("Zadaj cislo \n");
	scanf_s("%i", &x);

	i = 1;
	while (i<x)
	{
		n = prvoc(i);
		if ((n == 1) && (x%i == 0))
		{
			printf("%i\n", i);
		}
		i++;
	}
	return 0;
}
