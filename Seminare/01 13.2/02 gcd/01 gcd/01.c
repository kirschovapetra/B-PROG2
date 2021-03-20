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
	int x, y, d;

	printf("2 cisla:\n");
	scanf_s("%d", &x);
	scanf_s("%d", &y);

	d = gcd(x, y);

	printf("gcd = %d\n", d);
	return 0;
}