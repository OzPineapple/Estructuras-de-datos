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
all: main.out
	make rmbk
	./main.out

build: main.out
	make cleanbk
	echo "\e[38;05;112;01mLibrerias del arreglo construidas correctamente\e[0m"

main.out: main.o libarreglo.so
	$C -o $@ $< -larreglo -lutil

main.o: main.c Arreglo.h
	$I $<
	$(CP) -c $<

libarreglo.so: Arreglo.c Arreglo.h
	$I $^
	$C -fPIC -shared -o $@ $< -lc -lutil -lvalidar

clean:
	rm -f ./*.so ./*.o ./*.out ./*.cbk ./*.hbk

cleanbk:
	rm -f ./*.cbk ./*.hbk

debug: main.out
	gdb ./$<

valgrind: main.out
	valgrind ./$<
