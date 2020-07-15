# ARGS
COMPILER = gcc
WD = $(shell realpath ./../../ | sed 's/ /\\ /g')
INCLUDE = -I $(WD)
LIBRARY = -L $(WD)/lib -L $(WD)/Listas/Sencilla -L $(WD)/Listas/Ciclica
RPATH = -Wl,-rpath $(WD)/lib -Wl,-rpath $(WD)/Listas/Sencilla -Wl,-rpath $(WD)/Listas/Ciclica
FLAGS = -std=c99 -Wall -g3 $(INCLUDE) $(LIBRARY) $(RPATH)
C = $(COMPILER) $(FLAGS)
CP = $(COMPILER) $(INCLUDE) -std=c99 -Wall -g3

I = export SIMPLE_BACKUP_SUFFIX=bk; indent -gnu

# SCRPITS
.SILENT:

all: build

build: main.out
	make cleanbk

main.out: main.o liblistaciclica.so
	$C -o $@ $< -lutil -llistaciclica
	echo "[ \e[92m✓\e[0m ] $@"

main.o: main.c ListaCiclica.h
	$I $^
	$(CP) -c $<

liblistaciclica.so: ListaCiclica.c ListaCiclica.h
	$I $<
	$C -fPIC -shared -o $@ $< -lc -lvalidar -llistasencilla
	echo "[ \e[92m✓\e[0m ] $@"

clean:
	echo "$(shell rm -v -f ./*.cbk ./*.hbk ./*.out ./*.so ./*.o  | tr -d "'" | sed "s/\.\//\[ \\\e\[91m✗\\\e\[0m \] /;2,$$ s/\[/\\\n\[/")"

cleanbk: 
	echo "$(shell rm -v -f ./*.cbk ./*.hbk ./*.o | tr -d "'" | sed "s/\.\//\[ \\\e\[93m✗\\\e\[0m \] /;2,$$ s/\[/\\\n\[/")"

debug: main.out
	gdb ./$<

valgrind: main.out
	valgrind ./$<