#include <stdio.h>

#include "bf.h"

#define ARRAY_SIZE 30000

static char array[ARRAY_SIZE];
static char *p = array;

int
execute(char *cc)
{
	int i, cycl;

	for (i = 0; cc[i] != '\0'; i++)
		switch (cc[i]) {
		case '>':
			++p;
			if (p >= array+ARRAY_SIZE) {
				fprintf(stderr, "error: buffer overflow!\n");
				return 0;
			}
			break;
		case '<':
			--p;
			if (p < array) {
				fprintf(stderr, "error: buffer overflow!\n");
				return 0;
			}
			break;
		case '+':
			++*p;
			break;
		case '-':
			--*p;
			break;
		case '.':
			putchar(*p);
			break;
		case ',':
			*p = getchar();
			break;
		case '[':
			if (!*p) {
				cycl = 1;
				do {
					i++;
					if (cc[i] == '\0') {
						fprintf(stderr, "error: loop error!\n");
						return 0;
					} else if (cc[i] == ']')
						cycl--;
					else if (cc[i] == '[')
						cycl++;
				} while (cycl);
			}
			break;
		case ']':
			if (*p) {
				cycl = 1;
				do {
					i--;
					if (i < 0) {
						fprintf(stderr, "error: loop error!\n");
						return 0;
					}
					if (cc[i] == '[')
						cycl--;
					else if (cc[i] == ']')
						cycl++;
				} while (cycl);
			}
			break;
		default:
			break;
		}
	return 1;
}
