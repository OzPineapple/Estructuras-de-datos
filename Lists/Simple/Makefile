# ARGS
COMPILER = gcc
WD = $(shell realpath ./../../ | sed 's/ /\\ /g')
INCLUDE = -I $(WD)
LIBRARY = -L ./ -L $(WD)/Lists/Generic -L $(WD)/lib
RPATH = -Wl,-rpath ./ -Wl,-rpath $(WD)/Lists/Generic -Wl,-rpath $(WD)/lib
FLAGS = -std=c99 -Wall -g3 $(INCLUDE) $(LIBRARY) $(RPATH)
C = $(COMPILER) $(FLAGS)
CP = $(COMPILER) $(INCLUDE) -std=c99 -Wall -g3

I = export SIMPLE_BACKUP_SUFFIX=bk; indent -gnu

# SCRPITS
all: main.out 
	./main.out

main.out: main.o liblistsimple.so
	$C -o $@ $< -lutil -llistsimple -llist -lnode

main.o: main.c ListSimple.h
	$I $^
	$(CP) -c $<

liblistsimple.so: liblistsimple.c ListSimple.h
	$I $<
	$C -fPIC -shared -lc -lvalidate -llist -o $@ $<

clean:
	rm -f ./*.cbk
	rm -f ./*.hbk
	rm -f ./*.out
	rm -f ./*.so 
	rm -f ./*.o

delbk:
	rm ./*.cbk
	rm ./*.hbk

debug: main.out
	gdb ./$<

valgrind: main.out
	valgrind ./$<