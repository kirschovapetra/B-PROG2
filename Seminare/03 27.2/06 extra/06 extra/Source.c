#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
void print_num(int from, int to , int step) {
	int i;
	if (step>0){
		for (i = from; i <= to; i += step) {
			printf("%d ", i);
		}
	}
	else {
		for (i = to; i >= from; i -= step) {
			printf("%d ", i);
		}
	}
	printf("\n");
}

void ap(int a0, int d,int n) {
	int i;
	for (i = 0; i <= n; i++) {
		printf("%d ", a0+i*d);
	}
	printf("\n");
}
void gp(int a0, int q, int n) {
	int i;
	for (i = 0; i <= n; i++) {
		printf("%d ", a0*pow(q,i));
	}
	printf("\n");
}

int faktorial(int n) {
	if (n >= 1)
		return (n*faktorial(n - 1));
	else
		return 1;
}

double power(int x, int n) {
	int sucin = 1, i;
	for (i = 1; i <= n;i++) {
		sucin *= i;
	}
	return sucin;
}


int main() {
	print_num(10, 0, -2);
	return 0;
}