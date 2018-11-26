CC=gcc
CFLAGS=-W -Wall -std=c99 -pedantic -g
LDFLAGS=
EXEC=linter
SRC=$(wildcard src/*.c)
SRC+=$(wildcard src/*/*.c)

debug:
	$(CC) -o $(EXEC) $(SRC) $(CFLAGS)

all:
	$(CC) -o test/$(EXEC) $(SRC) $(CFLAGS)

clean:
	rm -rf *.o $(EXEC)
