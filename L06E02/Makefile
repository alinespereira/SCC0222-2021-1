PROGRAM=L06E02

debug:
	gcc -o $(PROGRAM) $(PROGRAM).c -Wall -pedantic -Wextra -g

all:
	gcc -o $(PROGRAM) $(PROGRAM).c -Wall -pedantic -Wextra

run: all
	./$(PROGRAM)

test: all
	./test.sh $(PROGRAM)

leak: debug
	valgrind --leak-check=full -s ./$(PROGRAM)