#ifndef HELPERS_H_INCLUDED
#define HELPERS_H_INCLUDED

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

int random(int min, int max);
void loadData(Player* player1, Player* player2, const char *filename);
void write_logs(Player* playerA, Warrior *choiceA, Player* playerD, Warrior *choiceD, Player *winner, int round);
void WriteResults(FILE *file, Player *winner, int rounds, int heal_count[], int hits[], int misses[]);

void create_warrior(Warrior *warrior, int max);
void create_group(int pos, char type[], int count, Warrior army[], int num);
void create_army(Warrior army[]);
void whitespaces(int length);
void color(Warrior warrior);
void print_warrior(Warrior warrior1, Warrior warrior2, char type[], int id);
void print_group(int pos, char type[], int count, Player player1, Player player2);
void print_army(Player player1, Player player2);
int game_over(Warrior army[]);
int find_warrior(char name[], Warrior army[]);
int can_choose(int id, Warrior *warrior);
int attack(Warrior *warriorA, Warrior *warriorD, int a, int hits[], int misses[]);
void fight(Player players[], Player *winner, int out, const char *output_name);

#endif // HELPERS_H_INCLUDED