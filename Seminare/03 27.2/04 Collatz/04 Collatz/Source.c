#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
int A_collatz_next(int x0)
{
	if (x0 % 2 == 0)
		return (x0 / 2);
	return (3 * x0 + 1);
}

void BC_collatz_print_count(x0)
{
	int i,x,count;
	printf("%d ", x0);
	x = A_collatz_next(x0);
	count = 0;
	for (i = x0; x != 1; i++)
	{
		printf("%d ", x);
		x = A_collatz_next(x);
		count++;
	}
	printf("1 \n");
	printf("%d\n",count+2);
}
int main()
{
	printf("%d\n",A_collatz_next(10));
	printf("%d\n", A_collatz_next(9));
	BC_collatz_print_count(10);
	return 0;
}