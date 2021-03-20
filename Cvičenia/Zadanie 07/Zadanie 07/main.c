#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "helpers.h"

int main() {
	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	zobraz(osemsmerovka, VYSKA, SIRKA);
	printf("\n");
	zobrazZoznamSlov(zoznamSlov, POCET_SLOV,-1);
	if (getchar() == '\n')
		CLEAR_SCREEN();
	
	vylusti(osemsmerovka, zoznamSlov, VYSKA, SIRKA, POCET_SLOV);
	zobraz(osemsmerovka, VYSKA, SIRKA);
	SetConsoleTextAttribute(hConsole, white);

	
	printf("\nTajnicka:\n");
	tajnicka(osemsmerovka, VYSKA, SIRKA);

	printf("\n\n");
	return 0;
} 