CC=gcc
CFLAGS=-W -Wall -ansi -pedantic
LDFLAGS=
EXEC=linter
SRC=$(wildcard */*.c)

all:
	$(CC) -o $(EXEC) $(SRC) $(CFLAGS)

clean:
	rm -rf *.o $(EXEC)
