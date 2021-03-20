#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include "helpers.h"

int main()
{
	int row, col, playerID, ships;
	int hit_count[9] = { 0 }; //hracov moze byt max 9
	int players,maxID,i;

	drawAttackGrid();
	
	ships = 0;
	maxID = 1;

	printf("Zadajte pocet hracov: ");
	scanf("%d", &players);
	
	//pokym nie su vsetky lode vystrielane
	while (ships < shipsTotal) {
		//opakujem tolkokrat, kolko je hracov
		for (playerID = 1; playerID <= players; playerID++) {
			//vypis stavu vsetkych hracov
			for (i = 1; i <= players; i++) {
				printf("Hrac %d: %d zasahov\n",i,hit_count[i-1]);
			}

			printf("Na rade je hrac %d\nZadajte suradnice: ", playerID);
			scanf("%d %d", &row, &col);
		
			//test ci suradnice patria do pola
			if (test(row, 0, GRID_SIZE - 1) && test(col, 0, GRID_SIZE - 1)) {

				//ak sa hrac trafil, tak sa pocet zasahov zvysi o 1
				if (checkHit(row, col, playerID)) {
					ships++;
					hit_count[playerID - 1]++;
					if (hit_count[playerID - 1] > hit_count[maxID - 1]) {
						maxID = playerID;
					}
					//ak boli trafene vsetky lode tak sa vyskoci z pola
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
	//ak je vela hracov, je dost mozne, ze nastane remiza:
	printf("Hraci s najvacsim poctom zasahov su:\n");
	for (playerID = 1; playerID <= players; playerID++) {
		if (hit_count[playerID - 1] == hit_count[maxID - 1]) {
			printf("hrac %d\n", playerID);
		}
	}
	printf("\n");
	return 0;
}
