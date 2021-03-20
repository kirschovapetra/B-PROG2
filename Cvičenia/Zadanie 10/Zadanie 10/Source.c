#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>

#include "helpers.h"

int main(int argc, char* argv[]) {
	Player players[2], winner;
	char input_name[30], output_name[30];
	int i, in = 0, out = 0;

	srand(time(NULL));
	for (i = 0; i < argc; i++) {
		if (strcmp(argv[i], "-i") == 0 && argv[i + 1] != NULL) {
			strcpy(input_name, argv[i + 1]);
			in = 1;
		}
		if (strcmp(argv[i], "-o") == 0 && argv[i + 1] != NULL) {
			strcpy(output_name, argv[i + 1]);
			out = 1;
		}
	}

	if (in == 0) {
		for (i = 0; i < 2; i++) {
			printf("Hrac %d - Zadajte meno: ", i + 1);
			scanf("%s", &players[i].name);
			create_army(players[i].army);
			printf("\n");
		}
	}
	else if (fopen(input_name, "r") == NULL) {
		printf("Subor -i neexistuje\n");
		exit(0);
	}
	else {
		loadData(&players[0], &players[1], input_name);

	}

	print_army(players[0], players[1]);
	fight(players, &winner, out, output_name);
	printf("Vitazom sa stava %s!\n", winner.name);
	return 0;
}