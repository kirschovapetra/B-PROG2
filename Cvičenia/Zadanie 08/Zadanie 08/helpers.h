//	POPIS:
//	Hlavickovy subor obsahujuci:
//		* deklaracie premennych
//		* deklaracie funkcii, ktore su implementovane v file_io.c a functions.c
//		* pomocne makra

#ifndef HELPERS_H_INCLUDED
#define HELPERS_H_INCLUDED

// makra
#define MAX_LEN 10000
#define MAX_WORD_LEN 50

// deklaracie premennych
char sub_words[MAX_LEN][MAX_WORD_LEN];
int length_s;

// deklaracie funkcii zo suboru file_io.c
char* read_file(char* fname);
int write_file(char* fname, char* text);

// deklaracie funkcii zo suboru functions.c
void print_text(char *text,char *sifra);
int split(char *str, char pole[MAX_LEN][MAX_WORD_LEN]);
void replace_all(char *text, char words_s[MAX_LEN][MAX_WORD_LEN]);
void decide(int input, int subst, int output, char *txt, char *sub, char *out);

// Podmieneny preklad: verzia pre WINDOWS sa lisi od LINUX verzie
// makro na premazanie obsahu konzoly
#ifdef _WIN32
#define CLEAR_SCREEN()	system("cls")
#else
#define CLEAR_SCREEN()	printf("\x1b[2J");
#endif

#endif // HELPERS_H_INCLUDED
