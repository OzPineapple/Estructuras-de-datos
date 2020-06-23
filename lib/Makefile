# Varaibles
COPILADOR = gcc
BANDERAS = -std=c99 -Wall -g3
C = $(COPILADOR) $(BANDERAS)

I = export SIMPLE_BACKUP_SUFFIX=bk; indent -gnu

# SCRPITS
all: main.out
	make clean_bk
	./main.out

dev: main.out
	./main.out

main.out: main.o util.so validar.so	
	$C -o $@ $^ -Wl,-rpath=./

main.o: main.c validar.h util.h
	$I $<
	$C -c $<

validar.so: validar.c validar.h
	$I $<
	$C -fPIC -shared -o $@ $< -lc

util.so: util.c util.h
	$I $<
	$C -fPIC -shared -o $@ $< -lc

clean:
	rm -f ./*.cbk ./*.hbk ./*.out ./*.so ./*.o

clean_bk:
	rm -f ./*.cbk ./*.hbk ./*.o