CC=gcc
CFLAGS=-W -Wall -std=c99 -pedantic -g
LDFLAGS=
EXEC=linter
SRC=$(wildcard src/*.c)

all:
	$(CC) -o $(EXEC) $(SRC) $(CFLAGS)

clean:
	rm -rf *.o $(EXEC)
