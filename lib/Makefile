# Varaibles
COPILADOR = gcc
BANDERAS = -std=c99 -Wall -g3
C = $(COPILADOR) $(BANDERAS)

I = export SIMPLE_BACKUP_SUFFIX=bk; indent -gnu

# SCRPITS
all: main.out
	make cleanbk
	./main.out

build: main.out
	make cleanbk
	echo "\e[38;05;112;01mLibrerias del proyecto construidas correctamente\e[0m"

main.out: main.o libutil.so libvalidar.so	
	$C -o $@ $^ -Wl,-rpath=./

main.o: main.c validar.h util.h
	$I $<
	$C -c $<

libvalidar.so: validar.c validar.h
	$I $<
	$C -fPIC -shared -o $@ $< -lc

libutil.so: util.c util.h
	$I $<
	$C -fPIC -shared -o $@ $< -lc

clean:
	rm -f ./*.cbk ./*.hbk ./*.out ./*.so ./*.o

cleanbk:
	rm -f ./*.cbk ./*.hbk ./*.o