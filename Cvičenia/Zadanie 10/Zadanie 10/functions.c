#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>
#include "helpers.h"

int random(int min, int max) {
	return rand() % (max - min + 1) + min;
}

//nacitanie a zapis do suboru
void loadData(Player* player1, Player* player2, const char *filename) {
	FILE *file;
	int i;
	file = fopen(filename, "r");
	fscanf(file, "%29s", &player1->name);
	for (i = 0; i < COUNT; i++) {
		fscanf(file, "%29s %d %d %d", &player1->army[i].name, &player1->army[i].lives, &player1->army[i].attack, &player1->army[i].defence);
	}
	fscanf(file, "%29s", &player2->name);
	for (i = 0; i < COUNT; i++) {
		fscanf(file, "%29s %d %d %d", &player2->army[i].name, &player2->army[i].lives, &player2->army[i].attack, &player2->army[i].defence);
	}
	fclose(file);
}
void write_logs(Player* playerA, Warrior *choiceA, Player* playerD, Warrior *choiceD, Player *winner, int round) {
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	int i;
	FILE *logs;
	logs = fopen("logs.txt", "a");
	if (logs == NULL) {
		printf("Subor logs.txt neexistuje!\n");
		fclose(logs);
		exit(0);
	}
	//na zaciatku sa zapise den a cas
	if (round == 1) {
		fprintf(logs, "START: %d.%d.%d %d:%d\n", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900, tm.tm_hour, tm.tm_min);
	}

	fprintf(logs, "\n*************************************************************\n");
	fprintf(logs, "\nKOLO %d:\n", round);
	fprintf(logs, "Utocil hrac %s, vybral si bojovnika %s\n", playerA->name, choiceA->name);
	fprintf(logs, "Branil sa hrac %s, vybral si bojovnika %s\n", playerD->name, choiceD->name);
	fprintf(logs, "Suboj vyhral hrac %s\n", winner->name);

	fprintf(logs, "\n\nArmada hraca %s po %d kole:\n", playerA->name, round);
	for (i = 0; i < COUNT; i++) {
		fprintf(logs, "Meno:%s Zivoty:%d Attack:%d Defence:%d\n", playerA->army[i].name, playerA->army[i].lives, playerA->army[i].attack, playerA->army[i].defence);
	}
	fprintf(logs, "\n\nArmada hraca %s po %d kole:\n", playerD->name, round);
	for (i = 0; i < COUNT; i++) {
		fprintf(logs, "Meno:%s Zivoty:%d Attack:%d Defence:%d\n", playerD->army[i].name, playerD->army[i].lives, playerD->army[i].attack, playerD->army[i].defence);
	}
	fclose(logs);
}
void WriteResults(FILE* file, Player *winner, int rounds, int heal_count[], int hits[], int misses[]) {
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	int i;
	//cas skoncenia
	fprintf(file, "KONIEC: %d.%d.%d %d:%d\n", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900, tm.tm_hour, tm.tm_min);
	fprintf(file, "\nVitaz = hrac %s\n", winner->name);
	fprintf(file, "\nZostavajuca armada hraca: %s\n", winner->name);
	for (i = 0; i < COUNT; i++) {
		if (winner->army[i].lives>0)
			fprintf(file, "Meno:%s Zivoty:%d Attack:%d Defence:%d\n", winner->army[i].name, winner->army[i].lives, winner->army[i].attack, winner->army[i].defence);
	}
	fprintf(file, "\n\n Celkovo sa odohralo %d kol\n", rounds);
	fprintf(file, "\nHrac 1 liecil svojich bojovnikov %d-krat \n", heal_count[0]);
	fprintf(file, "\nHrac 2 liecil svojich bojovnikov %d-krat \n", heal_count[1]);
	fprintf(file, "\nHrac 1 zasiahol %d-krat a minul %d-krat\n", hits[0], misses[0]);
	fprintf(file, "\nHrac 2 zasiahol %d-krat a minul %d-krat\n", hits[1], misses[1]);
}

//vytvorenie armady
void create_warrior(Warrior *warrior, int max) {
	scanf("%s", &(warrior->name));
	warrior->lives = 5;

here:
	warrior->defence = random(1, max);
	warrior->attack = max - (warrior->defence);
	if (warrior->attack == 0 || warrior->defence == 0)
		goto here;
}
void create_group(int pos, char type[], int count, Warrior army[], int num) {
	int i;
	for (i = pos; i < pos + count; i++) {
		printf("%s %d: ", type, i - pos + 1);
		create_warrior(&army[i], num);
	}
}
void create_army(Warrior army[]) {
	int pos, sum = 0;
	pos = 0;
	//kuzelnik
	create_group(pos, "Carodejnik", CARODEJNICI, army, 10);
	pos += CARODEJNICI;
	//jazdec
	create_group(pos, "Jazdec", JAZDCI, army, 8);
	pos += JAZDCI;
	//rytieri
	create_group(pos, "Rytier", RYTIERI, army, 6);
	pos += RYTIERI;
	//pesiaci
	create_group(pos, "Pesiak", PESIACI, army, 4);
}


//vypis
void whitespaces(int length) {
	int i;
	for (i = 0; i < 100 - length; i++)
		printf(" ");
}
void color(Warrior warrior) {
	HANDLE console;
	console = GetStdHandle(STD_OUTPUT_HANDLE);
	if (warrior.lives == 0)
		SetConsoleTextAttribute(console, RED);
	else
		SetConsoleTextAttribute(console, WHITE);
}
void print_warrior(Warrior warrior1, Warrior warrior2, char type[], int id) {
	HANDLE console;
	console = GetStdHandle(STD_OUTPUT_HANDLE);

	color(warrior1);
	printf("%s %d", type, id);
	whitespaces((int)strlen(type) - 3);

	color(warrior2);
	printf("%s %d\n", type, id);

	color(warrior1);
	printf("MENO:%s", warrior1.name);
	whitespaces((int)strlen(warrior1.name));

	color(warrior2);
	printf("MENO:%s\n", warrior2.name);

	color(warrior1);
	printf("ZIVOTY:%d", warrior1.lives);
	whitespaces(3);

	color(warrior2);
	printf("ZIVOTY:%d\n", warrior2.lives);

	color(warrior1);
	printf("OBRANA:%d", warrior1.defence);
	whitespaces(3);

	color(warrior2);
	printf("OBRANA:%d\n", warrior2.defence);

	color(warrior1);
	printf("UTOK:%d", warrior1.attack);
	whitespaces(1);

	color(warrior2);
	printf("UTOK:%d\n\n", warrior2.attack);

	SetConsoleTextAttribute(console, WHITE);
}
void print_group(int pos, char type[], int count, Player player1, Player player2) {
	int i;
	for (i = pos; i < pos + count; i++) {
		print_warrior(player1.army[i], player2.army[i], type, i - pos + 1);
	}
}
void print_army(Player player1, Player player2) {
	int pos;
	printf("ARMADA HRACA %s:", player1.name);
	whitespaces((int)strlen(player1.name) + 9);
	printf("ARMADA HRACA %s:\n\n", player2.name);

	pos = 0;
	//kuzelnik
	print_group(pos, "Carodejnik", CARODEJNICI, player1, player2);
	pos += CARODEJNICI;
	//jazdec
	print_group(pos, "Jazdec", JAZDCI, player1, player2);
	pos += JAZDCI;
	//rytieri
	print_group(pos, "Rytier", RYTIERI, player1, player2);
	pos += RYTIERI;
	//pesiaci
	print_group(pos, "Pesiak", PESIACI, player1, player2);
}

//kedy hra skonci
int game_over(Warrior army[]) {
	int i;
	for (i = 0; i < COUNT; i++) {
		if (army[i].lives != 0)
			return 0;
	}
	return 1;
}

//vyhladaj bojovnika(jeho poziciu v poli) podla mena
int find_warrior(char name[], Warrior army[]) {
	int i;
	for (i = 0; i < COUNT; i++) {
		if (strcmp(name, army[i].name) == 0)
			return i;
	}
	return -1;
}

//ci si hrac moze daneho bojovnika vybrat
int can_choose(int id, Warrior *warrior) {
	if (id == -1 || warrior->lives <= 0)
		return 0;
	return 1;
}


//suboj
int attack(Warrior *warriorA, Warrior *warriorD, int a, int hits[], int misses[]) {
	int DEF, ATT, X,L;
	ATT = warriorA->attack;
	DEF = warriorD->defence;

	printf("Suboj %s vs %s\n", warriorA->name, warriorD->name);
	printf("Utoci %s\n", warriorA->name);

	X = random(1, ATT + DEF);
	if (X>DEF) {
		printf("Zasah!\n");
		L = random(1, warriorD->lives);
		printf("Strata = %d zivotov\n",L);
		printf("Vyhrava %s\n", warriorA->name);
		(warriorD->lives) -= L;
		hits[a]++;
		return a;
	}
	else {
		printf("Utok bol odrazeny\n");
		L = random(1, warriorA->lives);
		printf("Strata = %d zivotov\n", L);
		printf("Vyhrava %s\n", warriorD->name);
		(warriorA->lives) -= L;
		misses[a]++;
		return 1 - a;
	}
}

void fight(Player players[], Player *hero, int out, const char *output_name) {
	FILE *output_file;
	char names[2][30], heal[30], str[10];
	int winner, heal_count[2] = { 0 }, i, a, wA_ind, wD_ind, heal_ind, round = 0, hits[2] = { 0 }, misses[2] = { 0 };
	//wA_ind == index bojovnika, ktory utoci
	//wD_ind == index bojovnika, ktory sa brani
	//heal_ind == index bojovnika, ktory bude lieceny

	//na zaciatku sa rozhodne nahodne, kto bude utocit
	a = random(0, 1);

	while (!game_over(players[0].army) && !game_over(players[1].army)) {
		round++;

	try_again:
		//v prvom kole vyberaju obaja hraci bojovnikov
		if (round == 1) {
			for (i = 0; i < 2; i++) {
				printf("Hrac %d - Vyberte si hraca: ", i + 1);
				scanf("%s", &names[i]);
			}
		}
		//potom len porazeny
		else {
			printf("Hrac %d - Vyberte si hraca: ", 1 - a + 1);
			scanf("%s", &names[1 - a]);
		}

		//urci sa vitaz aktualneho kola, a = attack = utoci vitaz
		wA_ind = find_warrior(names[a], players[a].army);
		if (!can_choose(wA_ind, &players[a].army[wA_ind])) {
			printf("Hrac %d - toho hraca si vybrat nemozete!\n", a + 1);
			goto try_again;
		}

		wD_ind = find_warrior(names[1 - a], players[1 - a].army);
		if (!can_choose(wD_ind, &players[1 - a].army[wD_ind])) {
			printf("Hrac %d - toho hraca si vybrat nemozete!\n", 1 - a + 1);
			goto try_again;
		}

		//liecenie
		if (wA_ind == 0) {
			printf("Hrac %d - Chcete liecit bojovnika? (ano/nie) ", a + 1);
			scanf("%s", &str);
			if (strcmp("ano", str) == 0) {
			heal_again1:
				printf("Ktoreho bojovnika chcete liecit? ");
				scanf("%s", &heal);
				heal_ind = find_warrior(heal, players[a].army);
				if (heal_ind != -1) {
					(players[a].army[heal_ind].lives)++;
					(players[a].army[0].lives)--;
					heal_count[a]++;
					goto print;
				}
				else {
					printf("Hrac %d - toho hraca si vybrat nemozete!\n", a + 1);
					goto heal_again1;
				}
			}
		}
		if (wD_ind == 0) {
			printf("Hrac %d - Chcete liecit bojovnika? (ano/nie) ", 1 - a + 1);
			scanf("%s", &str);
			if (strcmp("ano", str) == 0) {
			heal_again2:
				printf("Ktoreho bojovnika chcete liecit? ");
				scanf("%s", &heal);
				heal_ind = find_warrior(heal, players[1 - a].army);
				if (heal_ind != -1) {
					(players[1 - a].army[heal_ind].lives)++;
					(players[1 - a].army[0].lives)--;
					heal_count[1 - a]++;
					goto print;
				}
				else {
					printf("Hrac %d - toho hraca si vybrat nemozete!\n", 1 - a + 1);
					goto heal_again2;
				}
			}
		}

		winner = attack(&players[a].army[wA_ind], &players[1 - a].army[wD_ind], a, hits, misses);
		write_logs(&players[a], &players[a].army[wA_ind], &players[1 - a], &players[1 - a].army[wD_ind], &players[winner], round);
		a = winner;

	print:
		print_army(players[0], players[1]);
	}

	printf("Koniec hry\n");
	if (game_over(players[0].army))
		*hero = players[1];
	else
		*hero = players[0];

	if (out == 0) {
		WriteResults(stdout, hero, round, heal_count, hits, misses);
	}

	else {
		output_file = fopen(output_name, "w");
		WriteResults(output_file, hero, round, heal_count, hits, misses);
		fclose(output_file);
	}
}

