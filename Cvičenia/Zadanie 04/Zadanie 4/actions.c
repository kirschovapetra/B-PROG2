#include <stdio.h>
#include <stdlib.h>
#include "helpers.h"

extern int deployment_grid[GRID_SIZE][GRID_SIZE];

int attack_grid[GRID_SIZE][GRID_SIZE] = { {0} };

void drawAttackGrid() {
	int i, j;
	printf("  0 1 2 3 4 5 6 7 8 9\n");
	for (i = 0; i < GRID_SIZE; i++) {
		printf("%d ", i);
		for (j = 0; j < GRID_SIZE; j++) {
			if (attack_grid[i][j] == 0) {  //0 == nezasiahnute miesto
				printf(". ");
			}
			else if (attack_grid[i][j]<0 ) //zaporne == netrafil
				printf("~ ");
			else {
				printf("%d ", attack_grid[i][j]); //trafil
			}
		}
		printf("\n");
	}
}


int checkHit(int row, int col, int playerID) {
	//hrac moze zasiahnut len prazdne policko
	if (attack_grid[row][col]==0) { 
		//ak zasiahne lod, zapise sa index hraca
		if (deployment_grid[row][col]==1) {
			attack_grid[row][col] = playerID;
			return 1;
		}
		//ak nezasiahne lod, zapise sa -index hraca
		else {
			attack_grid[row][col] = -playerID;
			return 0;
		}
	}
	return 0;
}

//test ci patri cislo do intervalu, pouzivam na testovanie ci suradnice patria do pola
int test(int num, int min, int max) {
	if (num >= min && num <= max)
		return 1;
	else
		return 0;
}
