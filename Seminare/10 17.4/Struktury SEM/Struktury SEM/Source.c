//k zadaniu
#include <stdio.h>
#include <string.h>

typedef struct _config {
	char* outfile;
	char* subfile;
	char* infile;
} Config;

Config parse(int argc, char* argv[]) {
	int i;
	Config c = { NULL,NULL,NULL };
	for (i =0; i < argc;i++) {
		if (strcmp("-i", argv[i]) == 0)
			c.infile = argv[i + 1];
	}
	return c;	
}

int main(int argc, char* argv[]) {
	Config config = parse(argc, argv);
	char * data;
	if (config.infile != NULL)
		data = read_file(config.infile);
}