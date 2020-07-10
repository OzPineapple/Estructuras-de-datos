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

main.out: main.o libutil.so libvalidar.so	
	$C -o $@ $^ -Wl,-rpath=./
	echo "[ \e[92m✓\e[0m ] $@"

main.o: main.c validar.h util.h
	$I $<
	$C -c $<

libvalidar.so: validar.c validar.h
	$I $<
	$C -fPIC -shared -o $@ $< -lc
	echo "[ \e[92m✓\e[0m ] $@"

libutil.so: util.c util.h
	$I $<
	$C -fPIC -shared -o $@ $< -lc
	echo "[ \e[92m✓\e[0m ] $@"

clean:
	echo "$(shell rm -v -f ./*.cbk ./*.hbk ./*.out ./*.so ./*.o  | tr -d "'" | sed "s/\.\//\[ \\\e\[91m✗\\\e\[0m \] /;2,$$ s/\[/\\\n\[/;$$ a \\\\\n")"

cleanbk: 
	echo "$(shell rm -v -f ./*.cbk ./*.hbk ./*.o | tr -d "'" | sed "s/\.\//\[ \\\e\[93m✗\\\e\[0m \] /;2,$$ s/\[/\\\n\[/;$$ a \\\\\n")"