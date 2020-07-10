DIRS = lib/ \
Vectores/Arreglo/int \
Vectores/Vector/int/ \
Listas/Generica/ \
# Listas/Sencilla/ \
# Listas/Doble/ \
# Listas/Ciclica/ \
# Listas/Doble\ Ciclica/ \
# Pilas/Arreglo/ \
# Pilas/Lista/ \
# Pilas/Hanoi/ \
# Colas/Arreglo/ \
# Colas/Lista/

.SILENT:

all: build

build:
	for dir in ${DIRS} ; do \
		echo $$dir; \
		make build -C $$dir; \
		echo ; \
	done

clean:
	for dir in ${DIRS} ; do \
		echo $$dir; \
		make clean -C $$dir; \
		echo ; \
	done