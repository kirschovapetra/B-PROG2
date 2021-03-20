#include <stdio.h>
#include <math.h>

void aritmetika(double a, double b)
{
	double plus, minus, krat, del;
	plus = a + b;
	minus = a - b;
	krat = a*b;
	del = a / b;

	printf("sucet = %f , rozdiel = %f , sucin = %f , podiel = %f\n", plus, minus, krat, del);

}

double obsah_trojuh(double x, double y, double z)
{
	double s, obsah;
	s = (x + y + z) / 2;
	obsah = sqrt(s*(s - x)*(s - y)*(s - z));
	return obsah;
}

double vrh(double v, double alpha)
{
	double alpha_rad, d;

	alpha_rad = alpha*(3.14 / 180);
	d = (v*v*sin(2 * alpha_rad)) / (9.81);

	return d;
}

double vrh_vyska(double v, double y, double alpha)
{
	double alpha_rad, d;

	alpha_rad = alpha*(3.14 / 180);
	d = (v*v*sin(2 * alpha_rad)) / (2 * 9.81)*(1 + sqrt(1 + (2 * y*9.81 / (v*v*sin(alpha_rad)*sin(alpha_rad)))));

	return d;
}

int main()
{
	double cislo1, cislo2;
	double a, b, c;
	double rychlost, vyska, uhol;

	cislo1 = 3.2;
	cislo2 = 1.5;

	a = 3.3;
	b = 4.8;
	c = 5;

	rychlost = 20;
	vyska = 30;
	uhol = 60;

	aritmetika(cislo1, cislo2);
	printf("obsah trojuholnika so stranami %.1f cm , %.1f cm, %.1f cm sa rovna %.2f cm^2\n", a, b, c, obsah_trojuh(a, b, c));
	printf("dostrel pri pociatocnej rychlosti %.2f m/s a uhle %.2f stupnov sa rovna %.2f m\n", rychlost, uhol, vrh(rychlost, uhol));
	printf("dostrel pri pociatocnej rychlosti %.2f m/s, vyske %.2f m a uhle %.2f stupnov sa rovna %.2f m\n", rychlost, vyska, uhol, vrh_vyska(rychlost, vyska, uhol));
	return 0;

}