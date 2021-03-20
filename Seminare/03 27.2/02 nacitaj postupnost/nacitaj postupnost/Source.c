#define	_CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
void cisla(x,y)
{
	int a, pocet=0 ,sum = 0 ,max ,min ,greater = 0 ,vyskyt = 0 , pocet_y = 0;
	double priemer;
	printf("Zadaj cislo: ");
	scanf("%d", &a);
	max = a;
	min = a;
	while (a != x)
	{
		printf("Zadaj cislo: ");
		scanf("%d", &a);
		pocet++;
		sum += a;

		if (a > max)
			max = a;

		if (a < min)
			min = a;

		if (a > x)
			greater++;

		if (a == y)
		{
			vyskyt = 1;
			pocet_y++;
		}
	}

	printf("pocet vsetkych cisel: %d\n",pocet);
	printf("pocet cisel vacsich ako x: %d\n", greater);
	priemer = sum / pocet;
	printf("priemer: %.2f\n", priemer);
	printf("max: %d\n", max);
	printf("min: %d\n", min);
	printf("nachadza sa y?: %d\n", vyskyt);
	printf("y sa nachadza %d-krat\n", pocet_y);
}

int main()
{
	int a, b;
	printf("Zadaj x: ");
	scanf("%d", &a);
	printf("Zadaj y: ");
	scanf("%d", &b);
	cisla(a,b);
	return 0;
}