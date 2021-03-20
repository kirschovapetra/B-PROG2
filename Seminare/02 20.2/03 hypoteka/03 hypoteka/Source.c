#include <stdio.h>
#include <math.h>
double splatka(double urok_miera_pa, int mesiace, double istina)
{
	double vysledok;
	double urok_miera = urok_miera_pa / 12;
	if (urok_miera == 0)
	{
		vysledok = istina / mesiace;
	}
	else
	{
		vysledok = (urok_miera*istina) / (1 - pow(1 + urok_miera, -mesiace));
	}
	return vysledok;
}

int main()
{
	double miera = 0.0;
	while (miera <= 0.1)
	{
		printf("%5.1lf %% %10.2lf EUR\n",
			miera * 100, splatka(miera, 36, 100000));
		miera += .01;
	}

	return 0;
}