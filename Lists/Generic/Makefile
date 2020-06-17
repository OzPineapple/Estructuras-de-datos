# ARGS
COMPILER = gcc
WD = $(shell realpath ./../../ | sed 's/ /\\ /g')
INCLUDE = -I $(WD)
LIBRARY = -L ./ -L $(WD)/lib
RPATH = -Wl,-rpath ./ -Wl,-rpath $(WD)/lib
FLAGS = -std=c99 -Wall -g3 $(INCLUDE) $(LIBRARY) $(RPATH)
C = $(COMPILER) $(FLAGS)
CP = $(COMPILER) $(INCLUDE) -std=c99 -Wall -g3

I = export SIMPLE_BACKUP_SUFFIX=bk; indent -gnu

# SCRPITS
all: main.out 
	./main.out

main.out: main.o liblist.so libnode.so
	$C -o $@ $< -lutil -llist -lnode

main.o: main.c List.h Node.h
	$I $^
	$(CP) -c $<

liblist.so: liblist.c List.h Node.h libnode.so
	$I $<
	$C -fPIC -shared -o $@ $< -lc -lvalidate -lnode

libnode.so: libnode.c Node.h
	$I $<
	$C -fPIC -shared -o $@ $< -lc -lvalidate

clean:
	rm -f ./*.cbk
	rm -f ./*.out
	rm -f ./*.so 
	rm -f ./*.o

delbk:
	rm ./*.cbk

debug: main.out
	gdb ./$<

valgrind: main.out
	valgrind ./$<