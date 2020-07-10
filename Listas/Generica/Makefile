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
.SILENT:

all: main.out 
	make cleanbk
	./main.out

build: main.out
	make cleanbk

main.out: main.o liblist.so libnode.so
	$C -o $@ $< -lutil -llist -lnode
	echo "[ \e[92m✓\e[0m ] $@"

main.o: main.c List.h Node.h
	$I $^
	$(CP) -c $<

liblist.so: liblist.c List.h Node.h libnode.so
	$I $<
	$C -fPIC -shared -o $@ $< -lc -lvalidate -lnode
	echo "[ \e[92m✓\e[0m ] $@"

libnode.so: libnode.c Node.h
	$I $<
	$C -fPIC -shared -o $@ $< -lc -lvalidate
	echo "[ \e[92m✓\e[0m ] $@"

clean:
	echo "$(shell rm -v -f ./*.cbk ./*.hbk ./*.out ./*.so ./*.o  | tr -d "'" | sed "s/\.\//\[ \\\e\[91m✗\\\e\[0m \] /;2,$$ s/\[/\\\n\[/")"

cleanbk: 
	echo "$(shell rm -v -f ./*.cbk ./*.hbk ./*.o | tr -d "'" | sed "s/\.\//\[ \\\e\[93m✗\\\e\[0m \] /;2,$$ s/\[/\\\n\[/")"

debug: main.out
	gdb ./$<

valgrind: main.out
	valgrind ./$<