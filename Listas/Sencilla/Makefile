# ARGS
COMPILER = gcc
WD = $(shell realpath ./../../ | sed 's/ /\\ /g')
INCLUDE = -I $(WD)
LIBRARY = -L $(WD)/lib -L $(WD)/Listas/Generica -L $(WD)/Listas/Sencilla
RPATH = -Wl,-rpath $(WD)/lib -Wl,-rpath $(WD)/Listas/Generica -Wl,-rpath $(WD)/Listas/Sencilla
FLAGS = -std=c99 -Wall -g3 $(INCLUDE) $(LIBRARY) $(RPATH)
C = $(COMPILER) $(FLAGS)
CP = $(COMPILER) $(INCLUDE) -std=c99 -Wall -g3

I = export SIMPLE_BACKUP_SUFFIX=bk; indent -gnu

# SCRPITS
.SILENT:

all: build

build: main.out
	make cleanbk

main.out: main.o liblistasencilla.so
	$C -o $@ $< -lutil -llistasencilla
	echo "[ \e[92m✓\e[0m ] $@"

main.o: main.c ListaSencilla.h
	$I $^
	$(CP) -c $<

liblistasencilla.so: ListaSencilla.c ListaSencilla.h
	$I $<
	$C -fPIC -shared -o $@ $< -lc -lvalidar -llista -lnodo
	echo "[ \e[92m✓\e[0m ] $@"

clean:
	echo "$(shell rm -v -f ./*.cbk ./*.hbk ./*.out ./*.so ./*.o  | tr -d "'" | sed "s/\.\//\[ \\\e\[91m✗\\\e\[0m \] /;2,$$ s/\[/\\\n\[/")"

cleanbk: 
	echo "$(shell rm -v -f ./*.cbk ./*.hbk ./*.o | tr -d "'" | sed "s/\.\//\[ \\\e\[93m✗\\\e\[0m \] /;2,$$ s/\[/\\\n\[/")"

debug: main.out
	gdb ./$<

valgrind: main.out
	valgrind ./$<