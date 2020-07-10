# ARGS
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
.SILENT:

all: main.out
	make rmbk
	./main.out

build: main.out
	make cleanbk

main.out: main.o libarreglo.so
	$C -o $@ $< -larreglo -lutil
	echo "[ \e[92m✓\e[0m ] $@"

main.o: main.c Arreglo.h
	$I $<
	$(CP) -c $<

libarreglo.so: Arreglo.c Arreglo.h
	$I $^
	$C -fPIC -shared -o $@ $< -lc -lutil -lvalidar
	echo "[ \e[92m✓\e[0m ] $@"

clean:
	echo "$(shell rm -v -f ./*.cbk ./*.hbk ./*.out ./*.so ./*.o  | tr -d "'" | sed "s/\.\//\[ \\\e\[91m✗\\\e\[0m \] /;2,$$ s/\[/\\\n\[/")"

cleanbk: 
	echo "$(shell rm -v -f ./*.cbk ./*.hbk ./*.o | tr -d "'" | sed "s/\.\//\[ \\\e\[93m✗\\\e\[0m \] /;2,$$ s/\[/\\\n\[/")"

debug: main.out
	gdb ./$<

valgrind: main.out
	valgrind ./$<
