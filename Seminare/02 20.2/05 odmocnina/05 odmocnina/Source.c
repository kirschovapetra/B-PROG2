#include <stdio.h>
#include <math.h>
double odmocnina(double x)
{

	double a, b, c = 0, c_last = -1;
	if (x <= 0.0)
		return 0.0;

	if (x <= 1.0)
	{
		a = x; b = 1.0;
	}
	else
	{
		a = 1.0; b = x;
	}

	while (c != c_last)
	{
		c_last = c;
		c = (a + b) / 2.0;
		if (c*c >= x)
		{
			b = c;
		}
		else
		{
			a = c;
		}
	}
	return c;
}

int main()
{
	printf("%f\n", odmocnina(2.0));
	printf("%f\n", sqrt(2.0));
}