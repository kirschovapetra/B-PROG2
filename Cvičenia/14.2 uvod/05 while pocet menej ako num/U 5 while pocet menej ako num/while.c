#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int stop_number, i;
	printf("zadaj stop num\n");
	scanf("%d", &stop_number);

	i = 0;
	while (i<stop_number)
	{
		printf("%d , ", i);
		i += 2;
	}
	return 0;
}