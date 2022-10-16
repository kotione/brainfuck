VERSION = 1.0

all: bf

bf: main.c bf.h bf.c
	$(CC) -o $@ -std=c89 -O2 -DVERSION=\"$(VERSION)\" main.c bf.c
