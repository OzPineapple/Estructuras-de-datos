# ARGS
COMPILER = gcc
WD = $(shell realpath ./../../ | sed 's/ /\\ /g')
INCLUDE = -I $(WD)
LIBRARY = -L ./ -L $(WD)/lib -L $(WD)/Vectors/Array/Int
RPATH = -Wl,-rpath ./ -Wl,-rpath $(WD)/lib -Wl,-rpath $(WD)/Vectors/Array/Int
FLAGS = -std=c99 -Wall -g3 $(INCLUDE) $(LIBRARY) $(RPATH)
C = $(COMPILER) $(FLAGS)
CP = $(COMPILER) $(INCLUDE) -std=c99 -Wall -g3

I = export SIMPLE_BACKUP_SUFFIX=bk; indent -gnu

# SCRPITS
all: main.out 
	./main.out

main.out: main.o libstackarray.so
	$C -o $@ $< -lutil -lstackarray

main.o: main.c StackArray.h
	$I $^
	$(CP) -c $<

libstackarray.so: libstackarray.c StackArray.h
	$I $<
	$C -fPIC -shared -o $@ $< -lc -lvalidate -larray

clean:
	rm -f ./*.cbk
	rm -f ./*.hbk
	rm -f ./*.out
	rm -f ./*.so 
	rm -f ./*.o

delbk:
	rm ./*.cbk
	rm ./*.hbk

debug: main.out
	gdb ./$<

valgrind: main.out
	valgrind ./$<
