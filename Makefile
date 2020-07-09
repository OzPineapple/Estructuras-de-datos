#make -C Lists/Generic/
	#make -C Lists/Simple/
	#make -C Lists/Double/
	#make -C Lists/Cyclic/
	#make -C Lists/Double\ Cyclic/
	#make -C Stacks/Array/
	#make -C Stacks/List/
	#make -C Stacks/Hanoi/
	#make -C Queues/Array/
	#make -C Queues/List/

all: build

build:
	make build -C lib/
	make build -C Vectores/Arreglo/int
	make build -C Vectores/Vector/int/

clean:
	make clean -C lib/ 
	make clean -C Vectores/Arreglo/int/ 
	make clean -C Vectores/Vector/int/ 