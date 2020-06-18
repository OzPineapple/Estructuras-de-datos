# ARGS
COMPILER = gcc
WD = $(shell realpath ./../../ | sed 's/ /\\ /g')
INCLUDE = -I $(WD)
LIBRARY = -L ./ -L $(WD)/lib -L $(WD)/Vectors/Vector/Int
RPATH = -Wl,-rpath ./ -Wl,-rpath $(WD)/lib -Wl,-rpath $(WD)/Vectors/Vector/Int
FLAGS = -std=c99 -Wall -g3 $(INCLUDE) $(LIBRARY) $(RPATH)
C = $(COMPILER) $(FLAGS)
CP = $(COMPILER) $(INCLUDE) -std=c99 -Wall -g3

I = export SIMPLE_BACKUP_SUFFIX=bk; indent -gnu

# SCRPITS
all: main.out 
	./main.out

main.out: main.o libstackvector.so
	$C -o $@ $< -lutil -lstackvector -lvector

main.o: main.c StackVector.h
	$I $^
	$(CP) -c $<

libstackvector.so: libstackvector.c StackVector.h
	$I $<
	$C -fPIC -shared -o $@ $< -lc -lvalidate -lvector

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