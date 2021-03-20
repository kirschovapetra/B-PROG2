#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
int is_prime(int n)
{
	int i, p;
	for (i=3;i*i<=n;i++)
	{
		if (n%i == 0)
			return 0;
	}
	return 1;
}

int next_prime(int n)
{
	int i;
	if (n < 2)
		return 2;
	for (i = n % 2 == 0 ? n + 1 : n + 2; !is_prime(i); i += 2)
		return i;

	return 0;
}

int count_primes(int min, int max)
{
	int i,count=0;
	for (i = next_prime(min); i <= max; i=next_prime(i))
		if (is_prime(i) == 1 && i>0)
			count++;
	return count;
}
int main()
{
	int x,a,b;
	printf("zadaj cislo: ");
	scanf("%d",&x);
	printf("najblizsie prvocislo k cislu %d je %d\n", x, next_prime(x));
	printf("zadaj max a min: ");
	scanf("%d %d", &a, &b);
	printf("prvocisiel v intervale<%d,%d> je %d\n",a,b, count_primes(a,b));
	return 0;
}