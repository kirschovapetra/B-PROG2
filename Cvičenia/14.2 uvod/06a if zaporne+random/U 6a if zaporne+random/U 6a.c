#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> 	
#include <time.h>		

int main()
{
	int a,vysledok, nahodne_cislo;

	printf("Zadaj cislo\n");
	scanf("%d",&a);
	if (a > 0)
	{
		printf("Cislo %d je vacsie ako 0\n", a);
	}
	else
	{
		printf("Cislo %d je mensie ako 0\n", a);
		srand(time(NULL));
		nahodne_cislo = rand() % (1000 - a) + a;
		vysledok = a + nahodne_cislo;
		printf("%d + %d = %d\n", a, nahodne_cislo, vysledok);
		printf("Cislo %d je teraz vacsie ako 0\n", vysledok);
	}
	return 0;
}
