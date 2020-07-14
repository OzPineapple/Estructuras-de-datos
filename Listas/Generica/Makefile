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

.SILENT:

# SCRPITS
all: build

build: main.out
	make cleanbk

main.out: main.o libnodo.so liblista.so
	$C -o $@ $< -lutil -lnodo -llista
	echo "[ \e[92m✓\e[0m ] $@"

main.o: main.c Nodo.h
	$I $^
	$(CP) -c $<

libnodo.so: Nodo.c Nodo.h
	$I $<
	$C -fPIC -shared -o $@ $< -lc -lvalidar
	echo "[ \e[92m✓\e[0m ] $@"

liblista.so: Lista.c Lista.h Nodo.h
	$I $<
	$C -fPIC -shared -o $@ $< -lc -lvalidar -lnodo
	echo "[ \e[92m✓\e[0m ] $@"

clean:
	echo "$(shell rm -v -f ./*.cbk ./*.hbk ./*.out ./*.so ./*.o  | tr -d "'" | sed "s/\.\//\[ \\\e\[91m✗\\\e\[0m \] /;2,$$ s/\[/\\\n\[/")"

cleanbk: 
	echo "$(shell rm -v -f ./*.cbk ./*.hbk ./*.o | tr -d "'" | sed "s/\.\//\[ \\\e\[93m✗\\\e\[0m \] /;2,$$ s/\[/\\\n\[/")"

debug: main.out
	gdb ./$<

valgrind: main.out
	valgrind ./$<