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
all: main.out
	make delbk
	./main.out

main.out: main.o libvector.so
	$C -o $@ $< -lvector -lutil

main.o: main.c Vector.h
	$I $<
	$(CP) -c $<

libvector.so: Vector.c Vector.h
	$I $<
	$C -fPIC -shared -o $@ $< -lc -lvalidar -larreglo

clean:
	rm -f ./*.cbk ./*.hbk ./*.out ./*.so ./*.o

delbk:
	rm -f ./*.cbk ./*.hbk

debug: main.out
	gdb ./$<

valgrind: main.out
	valgrind ./$<
