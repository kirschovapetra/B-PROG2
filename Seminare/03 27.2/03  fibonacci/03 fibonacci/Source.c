#include <stdio.h>
void fibonacci(int n, int x0, int x1)
{
	int x, x_pred, x_predpred, i;
	x_predpred = x0;
	x_pred = x1;
	printf("%d %d ",x_pred,x_predpred);
	for (i = 3; i <= n; i++)
	{
		x = x_pred + x_predpred;
		x_predpred = x_pred;
		x_pred = x;
		printf("%d ", x);
	}
}

int main()
{
	fibonacci(7,-5,10);
	return 0;
}