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
	make -s build -C lib/
	make -s build -C Vectores/Arreglo/int
	make -s build -C Vectores/Vector/int/

clean:
	make -s clean -C lib/ 
	make -s clean -C Vectores/Arreglo/int/ 
	make -s clean -C Vectores/Vector/int/ 