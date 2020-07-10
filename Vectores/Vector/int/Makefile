# ARGS
COMPILER = gcc
WD = $(shell realpath ./../../../ | sed 's/ /\\ /g')
INCLUDE = -I $(WD)
LIBRARY = -L ./ -L $(WD)/lib -L $(WD)/Vectores/Arreglo/int
RPATH = -Wl,-rpath ./ -Wl,-rpath $(WD)/lib -Wl,-rpath $(WD)/Vectores/Arreglo/int
FLAGS = -std=c99 -Wall -g3 $(LIBRARY) $(INCLUDE) $(RPATH)
C = $(COMPILER) $(FLAGS)
CP = $(COMPILER) $(INCLUDE) -std=c99 -Wall -g3

I = export SIMPLE_BACKUP_SUFFIX=bk; indent -gnu

# SCRPITS
.SILENT:

all: build

build: main.out
	make cleanbk

main.out: main.o libvector.so
	$C -o $@ $< -lvector -lutil
	echo "[ \e[92m✓\e[0m ] $@"

main.o: main.c Vector.h
	$I $<
	$(CP) -c $<

libvector.so: Vector.c Vector.h
	$I $<
	$C -fPIC -shared -o $@ $< -lc -lvalidar -larreglo
	echo "[ \e[92m✓\e[0m ] $@"

clean:
	echo "$(shell rm -v -f ./*.cbk ./*.hbk ./*.out ./*.so ./*.o  | tr -d "'" | sed "s/\.\//\[ \\\e\[91m✗\\\e\[0m \] /;2,$$ s/\[/\\\n\[/")"

cleanbk: 
	echo "$(shell rm -v -f ./*.cbk ./*.hbk ./*.o | tr -d "'" | sed "s/\.\//\[ \\\e\[93m✗\\\e\[0m \] /;2,$$ s/\[/\\\n\[/")"

debug: main.out
	gdb ./$<

valgrind: main.out
	valgrind ./$<
