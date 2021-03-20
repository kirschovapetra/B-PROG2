#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> 	
#include <time.h>		

int main()
{
	int a;
	printf("zadaj cislo\n");
	scanf("%d", &a);
	while (a != 0)
	{
		printf("zadaj cislo\n");
		scanf("%d",&a);
		if (a==0)
			break;
	}
	printf("zadal si 0 - koniec cyklu\n");
	return 0;
}