build:
	gcc -c board.c

all:
	gcc -o L03E03 L03E03.c board.o -Wall -pedantic -Wextra

run: all
	./L03E03

test: all
	./test.sh