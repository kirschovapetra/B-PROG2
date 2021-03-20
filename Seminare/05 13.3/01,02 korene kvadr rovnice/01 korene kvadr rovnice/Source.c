#include <math.h>
#include <stdio.h>

int poc_korenov(double a, double b, double c) {
	double D,x1,x2;
	D = b*b - 4 * a*c;
	if (D<0) {
		return 0;
	}
	else if (D == 0) {
		return 1;
	}
	else {
		x1 = (-b + sqrt(b*b - 4 * a*c)) / (2*a);
		x2 = (-b - sqrt(b*b - 4 * a*c)) / (2*a);
		return 2;
	}
}

int kvadr(double a, double b, double c, double *px1,double *px2) {
	double x1, x2;
	int pocet;
	pocet = poc_korenov(1,-3,4.5,&x1,&x2);
	*px1 = x1;
	*px2 = x2;
}

int main() {

}