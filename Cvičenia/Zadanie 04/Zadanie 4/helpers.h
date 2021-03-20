#ifndef HELPERS_H
#define HELPERS_H

#define GRID_SIZE 10

extern int shipsTotal;

void drawAttackGrid();

int checkHit(int row, int col, int playerID);

int test(int num, int min, int max);

#ifdef _WIN32
	#define CLEAR_SCREEN()	system("cls")
#else
	#define CLEAR_SCREEN()	printf("\x1b[2J");
#endif


#endif /* HELPERS_H */
