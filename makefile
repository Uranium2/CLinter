CC=gcc
CFLAGSDEBUG=-W -Wall -std=c99 -pedantic -g
CFLAGS=-W -Wall -std=c99 -pedantic
LDFLAGS=
EXEC=linter
SRC=$(wildcard src/*.c)
SRC+=$(wildcard src/*/*.c)

debug:
	$(CC) -o $(EXEC) $(SRC) $(CFLAGSDEBUG)

all:
	$(CC) -o test/$(EXEC) $(SRC) $(CFLAGS)

clean:
	rm -rf *.o $(EXEC)
