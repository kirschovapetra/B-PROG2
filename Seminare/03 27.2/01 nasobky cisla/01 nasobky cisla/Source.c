#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void A_cisla(int n)
{
	int i;
	for (i = 1; i <= n; i++)
		printf("%d ", i);
}
void B_kladne_parne(int n)
{
	int i;
	for (i = 0; i * 2 <= n; i++)
	{
		printf("%d ", i * 2);
	}
}
void C_nasobky_x(int n,int x)
{
	int i;
	for (i = 0; i*x <= n; i++)
	{ 
		printf("%d ", i*x);
	}
}
void D_nasobky_ab(int x,int a, int b)
{
	int i;
	for (i = a; i <= b; i++)
	{
		if (i%x == 0)
			printf("%d ", i);
	}
}

void E_nasobky_ab2(int x, int a, int b)
{
	int i;
	for (i = a; i <= b; i++)
	{
		if (i%x==0)
			printf("%d %d\n",i/x,i);
	}
}

void E_nasobky_ab2_odzadu(int x, int a, int b)
{
	int i;
	for (i = b; i >=a; i--)
	{
		if (i%x == 0)
			printf("%d %d\n", i / x, i);
	}
}
int main()
{
	int n, x, a, b;
	printf("Zadaj n: ");
	scanf("%d",&n);
	printf("Zadaj a: ");
	scanf("%d", &a);
	printf("Zadaj b: ");
	scanf("%d", &b);
	printf("Zadaj x: ");
	scanf("%d", &x);
	printf("\n1A\n");
	A_cisla(n);
	printf("\n1B\n");
	B_kladne_parne(n);
	printf("\n1C\n");
	C_nasobky_x(n,x);
	printf("\n1D\n");
	D_nasobky_ab(x,a,b);
	printf("\n1E\n");
	E_nasobky_ab2(x,a,b);
	printf("\n1E odzadu\n");
	E_nasobky_ab2_odzadu(x, a, b);

	return 0;
}