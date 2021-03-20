#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>

#ifdef _WIN32
#define CLEAR_SCREEN()	system("cls")
#else
#define CLEAR_SCREEN()	printf("\x1b[2J");
#endif

#define WHITE 15
#define RED 12

#define COUNT 7
#define CARODEJNICI 1
#define JAZDCI 1
#define RYTIERI 2
#define PESIACI 3

typedef
struct _warrior {
	int lives;
	int defence;
	int attack;
	char name[30];
} Warrior;

typedef
struct _player {
	char name[30];
	Warrior army[COUNT];
} Player;

int random(int min, int max) {
	return rand() % (max - min + 1) + min;
}


//vytvorenie armady
void create_warrior(Warrior *warrior,int max) {
	scanf("%s", &(warrior->name));
	warrior->lives = 5;

	here:
	warrior->defence = random(1, max);
	warrior->attack = max - (warrior->defence);
	if (warrior->attack == 0 || warrior->defence == 0)
		goto here;	
}

void create_group(int pos, char type[],int count,Warrior army[],int num) {
	int i;
	for (i = pos; i < pos + count; i++) {
		printf("%s %d: ",type, i - pos + 1);
		create_warrior(&army[i], num);
	}
}

void create_army(Warrior army[]) {
	int pos,sum = 0;
	pos = 0;
	//kuzelnik
	create_group(pos, "Carodejnik", CARODEJNICI,army,10);
	pos += CARODEJNICI;
	//jazdec
	create_group(pos, "Jazdec", JAZDCI, army,8);
	pos += JAZDCI;
	//rytieri
	create_group(pos, "Rytier", RYTIERI, army,6);
	pos += RYTIERI;
	//pesiaci
	create_group(pos, "Pesiak", PESIACI, army,4);
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

void print_warrior(Warrior warrior1, Warrior warrior2,char type[],int id) {
	HANDLE console;
	console = GetStdHandle(STD_OUTPUT_HANDLE);

	color(warrior1);
	printf("%s %d",type,id);
	whitespaces((int)strlen(type)-3);

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
	printf("ARMADA HRACA %s:",player1.name);
	whitespaces((int)strlen(player1.name)+9);
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
int can_choose(int id,Warrior *warrior ) {
	if (id==-1 || warrior->lives<=0)
		return 0;
	return 1;
}


//suboj
int attack(Warrior *warriorA, Warrior *warriorD, int a) {
	int DEF, ATT, X;
	ATT = warriorA->attack;
	DEF = warriorD->defence;
	
	printf("Suboj %s vs %s\n", warriorA->name, warriorD->name);
	printf("Utoci %s\n", warriorA->name);

	X = random(1, ATT + DEF);
	if (X>DEF) {
		printf("Zasah!\n");
		printf("Vyhrava %s\n", warriorA->name);
		(warriorD->lives)--;
		return a;
	}
	else {
		printf("Utok bol odrazeny\n");
		printf("Vyhrava %s\n", warriorD->name);
		(warriorA->lives)--;
		return 1 - a;
	}
}

char* fight(Player players[]) {
	char names[2][30];
	char heal[30];
	char str[10];
	int winner;
	int i, a, wA_ind, wD_ind, heal_ind, round = 0;
	//wA_ind == index bojovnika, ktory utoci
	//wD_ind == index bojovnika, ktory sa brani
	//heal_ind == index bojovnika, ktorz bude lieceny


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
		if (!can_choose(wD_ind, &players[1-a].army[wD_ind])) {
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
					goto clear;
				}
				else {
					printf("Hrac %d - toho hraca si vybrat nemozete!\n", a + 1);
					goto heal_again1;
				}
			}
		}

		if (wD_ind == 0) {
			printf("Hrac %d - Chcete liecit bojovnika? (ano/nie) ",1-a+1);
			scanf("%s",&str);
			if (strcmp("ano",str)==0) {
				heal_again2:
				printf("Ktoreho bojovnika chcete liecit? ");
				scanf("%s", &heal);
				heal_ind = find_warrior(heal, players[1-a].army);
				if (heal_ind!=-1) {
					(players[1 - a].army[heal_ind].lives)++;
					(players[1 - a].army[0].lives)--;
					goto clear;
				}
				else {
					printf("Hrac %d - toho hraca si vybrat nemozete!\n", 1-a + 1);
					goto heal_again2;
				}
			}
		}
		winner = attack(&players[a].army[wA_ind], &players[1 - a].army[wD_ind], a);
		a = winner;

		clear:
		Sleep(5000);
		CLEAR_SCREEN();
		print_army(players[0], players[1]);
	}


	printf("Koniec hry\n");
	if (game_over(players[0].army))
		return players[1].name;

	return players[0].name;
}

int main() {
	Player players[2];
	char *winner;
	int i;
	srand(time(NULL));

	//mena hracov
	for (i = 0; i < 2; i++) {
		printf("Hrac %d - Zadajte meno: ", i + 1);
		scanf("%s", &players[i].name);
		create_army(players[i].army);
		printf("\n");
	}

	CLEAR_SCREEN();
	print_army(players[0], players[1]);

	//po skonceni bitky sa do prem. winner zapise meno vitaza
	winner = fight(players);
	printf("Vitazom sa stava %s!\n", winner);

	return 0;
}
