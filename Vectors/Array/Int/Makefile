# ARGS
BIN = ./libarray.so ./main.out ./main.o
COMPILER = gcc
WD = $(shell realpath ./../../../ | sed 's/ /\\ /g')
INCLUDE = -I $(WD)
LIBRARY = -L ./ -L $(WD)/lib
RPATH = -Wl,-rpath $(WD)/lib -Wl,-rpath ./
FLAGS = -std=c99 -Wall -g3 $(LIBRARY) $(INCLUDE) $(RPATH)
C = $(COMPILER) $(FLAGS)
CP = $(COMPILER) $(INCLUDE) -std=c99 -Wall -g3

I = export SIMPLE_BACKUP_SUFFIX=bk; indent -gnu

# SCRPITS
all: main.out 
	./main.out

main.out: main.o libarray.so
	$C -o $@ $< -larray -lutil

main.o: main.c Array.h
	$I $<
	$(CP) -c $<

libarray.so: libarray.c Array.h
	$I $<
	$C -fPIC -shared -o $@ $< -lc -lutil -lvalidate

clean:
	rm $(BIN) ./*cbk

delbk:
	rm ./*.cbk

debug: main.out
	gdb ./$<

valgrind: main.out
	valgrind ./$<