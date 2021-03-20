#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>

#include "helpers.h"

int main(int argc, char* argv[]) {
	int input = 0, output = 0, subst = 0,i;

	char *txt = NULL, *sub = NULL, *out = NULL;

	for (i = 0; i < argc; i++) {
		if (strcmp(argv[i], "-i") == 0 && argv[i + 1]!=NULL) {
			txt = read_file(argv[i + 1]);
			input = 1;
		}

		if (strcmp(argv[i], "-s") == 0 && argv[i + 1] != NULL) {
			sub = read_file(argv[i + 1]);
			subst = 1;
		}

		if (strcmp(argv[i], "-o") == 0 && argv[i + 1] != NULL) {
			out = argv[i + 1];
			output = 1;
		}
	}
	
	decide(input,subst,output,txt,sub,out);

	return 0;
}

