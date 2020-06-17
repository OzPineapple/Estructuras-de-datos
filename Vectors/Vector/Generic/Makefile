# ARGS
COMPILER = gcc
WD = $(shell realpath ./../../../ | sed 's/ /\\ /g')
INCLUDE = -I $(WD)
LIBRARY = -L ./ -L $(WD)/lib
RPATH = -Wl,-rpath ./ -Wl,-rpath $(WD)/lib
FLAGS = -std=c99 -Wall -g3 $(LIBRARY) $(INCLUDE) $(RPATH)
C = $(COMPILER) $(FLAGS)
CP = $(COMPILER) $(INCLUDE) -std=c99 -Wall -g3

I = export SIMPLE_BACKUP_SUFFIX=bk; indent -gnu

# SCRPITS
all: main.out 
	./main.out

main.out: main.o libgenericvector.so
	$C -o $@ $< -lgenericvector -lutil -lvalidate

main.o: main.c GenericVector.h
	$I $<
	$(CP) -c $<

libgenericvector.so: libgenericvector.c GenericVector.h
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
