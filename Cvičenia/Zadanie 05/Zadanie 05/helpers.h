#ifndef HELPERS_H
#define HELPERS_H

#define GRID_SIZE 10
#define red 12
#define green 10
#define yellow 14
#define white 15


extern int shipsTotal;

void drawAttackGrid();

void drawDeploymentGrid();

void fillDeploymentGrid();

int checkPlacement_left(int row, int col, int ship_size);

int checkPlacement_right(int row, int col, int ship_size);

int checkPlacement_up(int row, int col, int ship_size);

int checkPlacement_down(int row, int col, int ship_size);

void randomShips();

void getPositionHuman(int *row, int *col);

void getPositionAI(int *row, int *col, int hit);

int checkHit(int row, int col, int playerID);

int test(int num, int min, int max);

int input();

void Human_vs_Human();

void Human_vs_AI();

void AI_vs_AI();


#ifdef _WIN32
	#define CLEAR_SCREEN()	system("cls")
#else
	#define CLEAR_SCREEN()	printf("\x1b[2J");
#endif


#endif /* HELPERS_H */
