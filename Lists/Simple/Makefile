# ARGS
FILE = Tester
CC = gcc
INCLUDE = -I../../../
COMPILER = $(CC) -x c -std=c99 -Wall $(INCLUDE) -o Tester.out Tester.c

# SCRPITS
all: compile 
	./$(FILE).out
compile:
	$(COMPILER)
debug:
	$(COMPILER) -ggdb
	gdb ./$(FILE).out
valgrind:
	$(COMPILER) -g
	valgrind ./$(FILE).out
clean:
	rm $(FILE).out
