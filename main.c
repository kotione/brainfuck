#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bf.h"

#define CODE_SIZE 4096

/*
 * Brainfuck interpreter in C by kotione
 */
int
main(int argc, char *argv[])
{
	if (argc > 2) {
		fprintf(stderr, "error: too many arguments!");
		return EXIT_FAILURE;
	}
	if (argc > 1 && argv[1][0] == '-') {
		if (strcmp(argv[1], "-h") == 0) {
			printf("usage: %s [OPTION/FILE]\n", argv[0]);
			return EXIT_SUCCESS;
		}
		if (strcmp(argv[1], "-v") == 0) {
			printf("%s-"VERSION"\n", argv[0]);
			return EXIT_SUCCESS;
		}
		printf("error: unknown option %s\n", argv[1]);
		return EXIT_FAILURE;
	}

	FILE *f;
	int c, i;
	int suc;
	char code[CODE_SIZE];

	if (argc == 2) {
		f = fopen(argv[1], "r");
		if (f == NULL) {
			fprintf(stderr, "error: cannot read file %s\n", argv[1]);
			return EXIT_FAILURE;
		}
	} else
		f = stdin;
	
	for (i = 0; (c=getc(f)) != EOF && i < CODE_SIZE-1; i++)
		code[i] = c;
	code[i] = '\0';
	
	suc = execute(code);

	if (f != stdin)
		fclose(f);

	return (suc) ? EXIT_SUCCESS : EXIT_FAILURE;
}
