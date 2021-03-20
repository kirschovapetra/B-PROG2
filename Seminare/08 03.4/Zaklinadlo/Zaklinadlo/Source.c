#include <stdio.h>
#define MAXZ  (17*5)

void ite_zaklinadlo(int z, char zaklinadlo[], int len)
{
	int i, code;
	static char spoluhlasky[] = "BCDFGHJKLMNPRSTVZ";
	static char samohlasky[] = "AEIOU";

	for (i = 0; i < len; i += 2)
	{
		code = z % (17 * 5); z = z / (17 * 5);
		zaklinadlo[i] = spoluhlasky[code / 5];
		zaklinadlo[i + 1] = samohlasky[code % 5];
	}
}


int main()
{
	int z1, z2;
	char zaklinadlo1[7] = { '\0' };
	char zaklinadlo2[7] = { '\0' };

	for (z1 = 0; z1 < MAXZ; z1++)
	{
		ite_zaklinadlo(z1, zaklinadlo1, 6);
		for (z2 = 0; z2 < MAXZ; z2++)
		{
			ite_zaklinadlo(z2, zaklinadlo2, 6);
			printf("%s %s\n", zaklinadlo1, zaklinadlo2);
		}
	}

	return 0;
}