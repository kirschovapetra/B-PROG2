#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include "helpers.h"
				   //1,2,3,4,5,6,7,8,9 lod
int ship_sizes[9] = {5,4,4,3,3,3,2,2,1};

/*
5 11111
4 2222
4 3333
3 444
3 555
3 666
2 77
2 88
1 9
*/


extern int deployment_grid[GRID_SIZE][GRID_SIZE];

int attack_grid[GRID_SIZE][GRID_SIZE] = { { 0 } };

//generovanie nahodneho cisla
int random(int min, int max) {
	return rand() % (max - min + 1) + min;
}

//test ci patri cislo do intervalu
int test(int num, int min, int max) {
	if (num >= min && num <= max)
		return 1;
	else
		return 0;
}

void drawAttackGrid() {
	int i, j;
	printf("  0 1 2 3 4 5 6 7 8 9\n");
	for (i = 0; i < GRID_SIZE; i++) {
		printf("%d ", i);
		for (j = 0; j < GRID_SIZE; j++) {
			if (attack_grid[i][j] == 0) {  //0 == nezasiahnute miesto
				printf(". ");
			}
			else if (attack_grid[i][j]<0) //zaporne == netrafil
				printf("~ ");
			else {
				printf("%d ", attack_grid[i][j]); //trafil
			}
		}
		printf("\n");
	}
}

void drawDeploymentGrid() {
	int i, j;
	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	printf("  0 1 2 3 4 5 6 7 8 9\n");
	for (i = 0; i < GRID_SIZE; i++) {
		SetConsoleTextAttribute(hConsole, white);
		printf("%d ", i);
		for (j = 0; j < GRID_SIZE; j++) {
			if (deployment_grid[i][j]!=0)
				SetConsoleTextAttribute(hConsole, red);
			else
				SetConsoleTextAttribute(hConsole, white);
			printf("%d ", deployment_grid[i][j]);
		}
		printf("\n");
	}
	SetConsoleTextAttribute(hConsole, white);
}

void getPositionHuman(int *p_row, int *p_col) {
	printf("Zadajte suradnice: ");
	scanf("%d %d", p_row, p_col);
}

void getPositionAI(int *p_row, int *p_col, int hit) {
	int num, old_row, old_col;

repeat:
	//ak predtym netrafil, tak budu nove suradnice nahodne
	if (hit == 0) {
		*p_row = random(0,GRID_SIZE-1);
		*p_col = random(0, GRID_SIZE-1);
	}
	//ak trafil, tak triafa v okoli bodu
	else {
		old_row = *p_row;
		old_col = *p_col;
		num = random(1, 4);
		switch (num) {
		case 1:
			old_col++;
			break;
		case 2:
			old_col--;
			break;
		case 3:
			old_row++;
			break;
		case 4:
			old_row--;
			break;
		}
		*p_row = old_row;
		*p_col = old_col;
	}
	//ak trafil uz zasiahnuty bod, tak generuje nove suradnice
	if (attack_grid[*p_row][*p_col] != 0) 
		goto repeat;
}

int checkHit(int row, int col, int playerID) {
	//hrac moze zasiahnut len prazdne policko
	if (attack_grid[row][col] == 0) {

		//ak zasiahne lod, zapise sa index hraca
		if (deployment_grid[row][col] != 0) {
			attack_grid[row][col] = playerID;

			//zmensi sa dlzka trafenej lode o 1
			ship_sizes[deployment_grid[row][col]-1]--;

			//ak je dlzka lode stale vacsia ako 0 tak return 1
			if (ship_sizes[deployment_grid[row][col] - 1] != 0) {
				return 1;
			}
			//ak bola potopena cela, return 2
			else {
				return 2;
			}		
		}
		//ak netrafil -index hraca
		else {
			attack_grid[row][col] = -playerID;
			return 0;
		}
	}
	else {
		return 0;
	}
}

//deployment_grid sa naplni nulami
void fillDeploymentGrid() {
	int i, j;
	for (i = 0; i < GRID_SIZE; i++) {
		for (j = 0; j < GRID_SIZE; j++) {
			deployment_grid[i][j] = 0;
		}
	}
}

int checkPlacement_left(int row, int col, int ship_size) {
	int i, new_col;
	new_col = col - ship_size + 1;
	//ci koniec lode lezi v poli
	if (test(new_col, 0, GRID_SIZE - 1) == 0) {
		return 0;
	}
	else {
		for (i = col; i >= (col - ship_size + 1); i--) {
			//volna pozicia
			if (deployment_grid[row][i] != 0 ||
				//riadok nad a pod volny
				deployment_grid[row - 1][i] != 0 || deployment_grid[row + 1][i] != 0 ||
				//pozicia pred a za lodou volna
				deployment_grid[row][col + 1] != 0 || deployment_grid[row][new_col - 1] != 0 ||
				//rohy volne
				deployment_grid[row - 1][new_col - 1] != 0 || deployment_grid[row + 1][new_col - 1] != 0 ||
				deployment_grid[row - 1][col + 1] != 0 || deployment_grid[row + 1][col + 1] != 0) {
				return 0;
			}
		}
	}
	return 1;
}

int checkPlacement_right(int row, int col, int ship_size) {
	int i, new_col;
	new_col = col + ship_size - 1;
	if (test(new_col, 0, GRID_SIZE - 1) == 0) {
		return 0;
	}
	else {
		for (i = col; i <= (col + ship_size - 1); i++) {
			//volna pozicia
			if (deployment_grid[row][i] != 0 ||
				//nad a pod
				deployment_grid[row - 1][i] != 0 || deployment_grid[row + 1][i] != 0 ||
				//pred a za
				deployment_grid[row][col - 1] != 0 || deployment_grid[row][new_col + 1] != 0 ||
				//rohy
				deployment_grid[row - 1][col - 1] != 0 || deployment_grid[row + 1][col - 1] != 0 ||
				deployment_grid[row - 1][new_col + 1] != 0 || deployment_grid[row + 1][new_col + 1] != 0) {
				return 0;
			}
		}
	}
	return 1;
}

int checkPlacement_up(int row, int col, int ship_size) {
	int i, new_row;
	new_row = row - ship_size + 1;
	if (test(new_row, 0, GRID_SIZE - 1) == 0) {
		return 0;
	}
	else {
		for (i = row; i >= (row - ship_size + 1); i--) {
			//volna pozicia
			if (deployment_grid[i][col] != 0 ||
				//riadok nad a pod
				deployment_grid[i][col - 1] != 0 || deployment_grid[i][col + 1] != 0 ||
				//pozicia pred a za
				deployment_grid[row + 1][col] != 0 || deployment_grid[new_row - 1][col] != 0 ||
				//rohy
				deployment_grid[new_row - 1][col - 1] != 0 || deployment_grid[new_row - 1][col + 1] != 0 ||
				deployment_grid[row + 1][col - 1] != 0 || deployment_grid[row + 1][col + 1] != 0) {
				return 0;
			}
		}
	}
	return 1;
}

int checkPlacement_down(int row, int col, int ship_size) {
	int i, new_row;
	new_row = row + ship_size - 1;
	if (test(new_row, 0, GRID_SIZE - 1) == 0) {
		return 0;
	}
	else {
		for (i = row; i <= (row + ship_size - 1); i++) {
			//pozicia
			if (deployment_grid[i][col] != 0 ||
				//nad a pod
				deployment_grid[i][col - 1] != 0 || deployment_grid[i][col + 1] != 0 ||
				//pred a za
				deployment_grid[row - 1][col] != 0 || deployment_grid[new_row + 1][col] != 0 ||
				//rohy
				deployment_grid[row - 1][col - 1] != 0 || deployment_grid[row - 1][col + 1] != 0 ||
				deployment_grid[new_row + 1][col - 1] != 0 || deployment_grid[new_row + 1][col + 1] != 0) {
				return 0;
			}
		}
	}
	return 1;
}

void randomShips() {
	int i, j, ship, row_start, col_start, orientation, check_left, check_right, check_up, check_down;
	srand(time(NULL));

	//naplnim deployment_grid nulami
	fillDeploymentGrid();

	//opakujem 9-krat, tolko mam lodi v poli ship_sizes
	for (i = 0; i < 9; i++) {

	start:

		ship = i;

		//vyberu sa nahodne suradnice
		row_start = random(0, GRID_SIZE - 1);
		col_start = random(0, GRID_SIZE - 1);

		//ak je miesto obsadene, generuju sa nove suradnice az pokym nie su spravne
		while (deployment_grid[row_start][col_start] != 0) {
			row_start = random(0, GRID_SIZE - 1);
			col_start = random(0, GRID_SIZE - 1);
		}

		//uklada sa hodnota 0/1 pre kazdy smer
		check_left = checkPlacement_left(row_start, col_start, ship_sizes[ship]);
		check_right = checkPlacement_right(row_start, col_start, ship_sizes[ship]);
		check_up = checkPlacement_up(row_start, col_start, ship_sizes[ship]);
		check_down = checkPlacement_down(row_start, col_start, ship_sizes[ship]);

		//nahodna orientacia
		orientation = random(0, 3);

		switch (orientation) {
		//0 - vodorovne dolava,col--
		case 0:
			//da sa umiestnit
			if (check_left == 1) {
				for (j = col_start; j >= (col_start - ship_sizes[ship] + 1); j--) {
					deployment_grid[row_start][j] = ship + 1;
				}
			}
			//neda sa umiestnit - spat na zaciatok a generuju sa nove suradnice
			else {
				goto start;
			}
			break;

		//1 - vodorovne doprava, col++
		case 1:
			if (check_right == 1) {
				for (j = col_start; j <= (col_start + ship_sizes[ship] - 1); j++) {
					deployment_grid[row_start][j] = ship + 1;
				}
			}
			else {
				goto start;
			}
			break;

		//2 - zvislo hore row--
		case 2:
			if (check_up == 1) {
				for (j = row_start; j >= (row_start - ship_sizes[ship] + 1); j--) {
					deployment_grid[j][col_start] = ship + 1;
				}
			}
			else {
				goto start;
			}
			break;

		//3 = zvislo dole, row++
		case 3:
			if (check_down == 1) {
				for (j = row_start; j <= (row_start + ship_sizes[ship] - 1); j++) {
					deployment_grid[j][col_start] = ship + 1;
				}
			}	
			else {
				goto start;
			}
			break;
		}
	}
}
	
void Human_vs_Human() {
	int ships = 0, hit_count[2], i, playerID, row, col,value;

	drawAttackGrid();
	for (i = 0; i < 2; i++) {
		hit_count[i] = 0;
	}
	printf("\n");
	//pokym nie su vsetky lode vystrielane
	while (ships < shipsTotal) {
		//opakujem tolkokrat, kolko je hracov
		for (playerID = 1; playerID <= 2; playerID++) {
			//vypis stavu hracov
			for (i = 1; i <= 2; i++) {
				printf("Hrac %d: %d zasahov\n", i, hit_count[i - 1]);
			}
			printf("Na rade je hrac %d\n", playerID);
			getPositionHuman(&row, &col);

			//test ci suradnice patria do pola
			if (test(row, 0, GRID_SIZE - 1) && test(col, 0, GRID_SIZE - 1)) {
				value = checkHit(row, col, playerID);
				//ak sa hrac trafil, tak sa jeho pocet zasahov zvysi o 1
				if (value!=0) {
					ships++;
					hit_count[playerID - 1]++;
					//notifikacia o potopenej lodi
					if (value == 2) {
						printf("Bola potopena cela lod!\n");
						Sleep(1500);
					}
					//ak boli trafene vsetky lode tak sa hra konci
					if (ships == shipsTotal)
						break;
				}
				
				CLEAR_SCREEN();
				drawAttackGrid();
			}
			else { //ak su suradnice zle, pokracuje dalsi hrac
				printf("Nespravne suradnice!\n");
				continue;
			}
		}
	}
	printf("\n");
	for (i = 1; i <= 2; i++) {
		printf("Hrac %d: %d zasahov\n", i, hit_count[i - 1]);
	}
	if (hit_count[0]>hit_count[1])
		printf("\nVyhral Hrac 1\n");
	else
		printf("\nVyhral Hrac 2\n");
}

void Human_vs_AI() {
	int ships = 0, playerID, i, value, hit_count[2] = { 0 }, row[2] = { 0 }, col[2] = { 0 }, trafil[2] = { 0 };
	
	srand(time(NULL));
	//inicializacia nahodnych pociatocnych suradnic pre hraca2 - pocitac
	row[1] = random(0, GRID_SIZE - 1);
	col[1] = random(0, GRID_SIZE - 1);

	drawAttackGrid();
	printf("Hrac 1: Clovek\nHrac 2: Pocitac\n\n");

	while (ships < shipsTotal) {
		for (playerID = 1; playerID <= 2; playerID++) {
			//na zaciatku je hodnota vynulovana
			trafil[playerID - 1] = 0;

			//vypis stavu
			for (i = 1; i <= 2; i++) {
				printf("Hrac %d: %d zasahov\n", i, hit_count[i - 1]);
			}
			printf("\nNa rade je hrac %d\n", playerID);

			switch (playerID) {
			//clovek
			case 1:
				getPositionHuman(&row[playerID - 1], &col[playerID - 1]);
				//test ci suradnice patria do pola
				if (test(row[playerID - 1], 0, GRID_SIZE - 1) && test(col[playerID - 1], 0, GRID_SIZE - 1)) {
					//value = 0 netrafil, 1 trafil ale nepotopil lod, 2 trafil a potopil lod
					value = checkHit(row[playerID - 1], col[playerID - 1], playerID);
				
					if (value != 0) { 
						ships++;
						hit_count[playerID - 1]++;

						//notifikacia o potopeni lode
						if (value == 2) {
							printf("Bola potopena cela lod!\n");
							//aby program chvilu pockal predtym,nez sa vymaze konzola
							Sleep(1500);
						}
						//ukoncenie
						if (ships == shipsTotal)
							break;
					}
					CLEAR_SCREEN();
					drawAttackGrid();
				}
				else {
					printf("Nespravne suradnice!\n");
					continue;
				}
				break;

			//pocitac
			case 2:
				//test suradnic
				if (test(row[playerID - 1], 0, GRID_SIZE - 1) && test(col[playerID - 1], 0, GRID_SIZE - 1)) {
					//value = 1/2/0
					value = checkHit(row[playerID - 1], col[playerID - 1], playerID);
					if (value != 0) {
						ships++;
						hit_count[playerID - 1]++;
						//ak trafil tak sa nastavi na 1
						trafil[playerID - 1] = 1;
					}
					//koniec
					if (ships == shipsTotal)
						break;
					printf("Suradnice su = (%d, %d)\n", row[playerID - 1], col[playerID - 1]);

					//potopenie
					if (value == 2) {
						printf("Bola potopena cela lod!\n");
					}
					Sleep(3000);
					CLEAR_SCREEN();
					drawAttackGrid();
				}
				//generovanie novych suradnic, s ktorymi sa bude pracovat v nasledujucom cykle
				getPositionAI(&row[playerID - 1], &col[playerID - 1], trafil[playerID - 1]);
				//ak su suradnice mimo pola tak sa generuju nove, az pokym nie su spravne
				while (test(row[playerID - 1],0,GRID_SIZE-1)==0 || test(col[playerID - 1], 0, GRID_SIZE - 1) == 0) {
					getPositionAI(&row[playerID - 1], &col[playerID - 1], trafil[playerID - 1]);
				}	
				break;
			}
		}
	}
	printf("\n");
	for (i = 1; i <= 2; i++) {
		printf("Hrac %d: %d zasahov\n", i, hit_count[i - 1]);
	}
	if (hit_count[0]>hit_count[1])
		printf("\nVyhral Hrac 1\n");
	else
		printf("\nVyhral Hrac 2\n");
}

void AI_vs_AI() {
	int ships = 0, playerID, i, value, hit_count[2] = { 0 }, row[2] = { 0 }, col[2] = { 0 }, trafil[2] = { 0 };
	srand(time(NULL));
	//inicializacia pociatocnych suradnic hraca 1 a 2
	row[0] = random(0, GRID_SIZE - 1);
	col[0] = random(0, GRID_SIZE - 1);
	row[1] = random(0, GRID_SIZE - 1);
	col[1] = random(0, GRID_SIZE - 1);

	drawAttackGrid();
	while (ships < shipsTotal) {
		for (playerID = 1; playerID <= 2; playerID++) {
			//hrac 1 a 2 trafil/netrafil - na zaciatu 0
			trafil[playerID - 1] = 0;

			//stav
			for (i = 1; i <= 2; i++) {
				printf("Hrac %d: %d zasahov\n", i, hit_count[i - 1]);
			}

			printf("\n\n");
			printf("Na rade je hrac %d\n", playerID);

			//ci patria suradnice do pola
			if (test(row[playerID - 1], 0, GRID_SIZE - 1) && test(col[playerID - 1], 0, GRID_SIZE - 1)) {
				
				//value = 0/1/2
				value = checkHit(row[playerID - 1], col[playerID - 1], playerID);
				if (value != 0) {
					ships++;
					hit_count[playerID - 1]++;
					trafil[playerID - 1] = 1;
				}

				if (ships == shipsTotal)
					break;

				printf("Suradnice su = (%d, %d)\n\n", row[playerID - 1], col[playerID - 1]);
				
				//potopenie
				if (value == 2) {
					printf("Bola potopena cela lod!\n");
				}

				drawAttackGrid();
				Sleep(3000);
				CLEAR_SCREEN();
			}
			//nove suradnice do dalsieho cyklu
			getPositionAI(&row[playerID - 1], &col[playerID - 1], trafil[playerID - 1]);

			//ak su suradnice mimo pola tak sa generuju znovu, pokym nie su spravne
			while (test(row[playerID - 1], 0, GRID_SIZE - 1) == 0 || test(col[playerID - 1], 0, GRID_SIZE - 1) == 0) {
				getPositionAI(&row[playerID - 1], &col[playerID - 1], trafil[playerID - 1]);
			}
		}
	}
	printf("\n");
	for (i = 1; i <= 2; i++) {
		printf("Hrac %d: %d zasahov\n", i, hit_count[i - 1]);
	}
	if (hit_count[0]>hit_count[1])
		printf("\nVyhral Hrac 1\n");
	else
		printf("\nVyhral Hrac 2\n");
}
