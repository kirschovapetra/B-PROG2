/*
Budete rozv�ja� zdrojov� k�d zadania �. 4 a prid�te do hry nasledovn�:

- menu s v�berom hern�ho m�du (ok)
- mo�nos� n�hodn�ho rozmiestnenia lod� pred za�iatkom hry (!)
- nov� funkcie na z�skanie s�radn�c strely (vyu��vanie smern�kov)
- notifik�ciu o potopen� celej lode
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "helpers.h"

int main()
{
	int menu_mode, ships_mode;

	//vyber rozmiestnenia
	printf("1 - Nahodne rozmiestnenie\n");
	printf("2 - Fixne rozmiestnenie\n");
	printf("Zadajte rozmiestnenie lodi:");

ships_start:

	scanf("%d",&ships_mode);
	switch (ships_mode) {
	case 1:
		printf("\n1 - Nahodne rozmiestnenie\n\n");
		randomShips();
		drawDeploymentGrid();
		break;
	case 2:
		printf("\n2 - Fixne rozmiestnenie\n");
		break;
	default:
		printf("Zadajte znovu\n");
		goto ships_start;
		break;
	}
	printf("\n");
	//vyber modu
	printf("1 - Human vs. Human\n");
	printf("2 - Human vs.Computer\n");
	printf("3 - Computer vs.Computer\n");
	printf("Vyberte si herny mod: ");

menu_start:

	scanf("%d", &menu_mode);
	switch (menu_mode) {
	case 1:
		printf("1 - Human vs. Human\n");
		Human_vs_Human();
		break;
	case 2:
		printf("2 - Human vs.Computer\n");
		Human_vs_AI();
		break;
	case 3:
		printf("3 - Computer vs.Computer\n");
		AI_vs_AI();
		break;
	default:
		printf("Zadajte znovu\n");
		goto menu_start;
		break;
	}
	
	return 0;
}

