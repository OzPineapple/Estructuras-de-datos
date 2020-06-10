# ARGS
SOURCE = ./libutil.c ./libvalidate.c ./util.h ./validate.h
BIN = ./libvalidate.so ./libutil.so ./main.out ./main.o
COMPILER = gcc
FLAGS = -std=c99 -Wall -g3
C = $(COMPILER) $(FLAGS)

I = export SIMPLE_BACKUP_SUFFIX=bk; indent -gnu

# SCRPITS
all: main.out 
	./main.out

main.out: main.o libutil.so libvalidate.so	
	$C -o $@ $^ -Wl,-rpath=./

main.o: main.c validate.h util.h
	$I $<
	$C -c $<

libvalidate.so: libvalidate.c validate.h
	$I $<
	$C -fPIC -shared -o $@ $< -lc

libutil.so: libutil.c util.h
	$I $<
	$C -fPIC -shared -o $@ $< -lc

clean:
	rm $(BIN) ./*cbk

delbk:
	rm ./*.cbk