all: build

build:
	make -C lib/
	make -C Vectors/Array/Int/
	make -C Vectors/Vector/Int/
	make -C Vectors/Vector/Generic/
	make -C Vectors/Vector/Int/
	make -C Lists/Generic/
	make -C Lists/Simple/
	make -C Lists/Double/
	make -C Lists/Cyclic/
	make -C Lists/Double\ Cyclic/
	make -C Stacks/Array/
	make -C Stacks/List/
	make -C Stacks/Hanoi/
	make -C Queues/Array/
	make -C Queues/List/

clean:
	make clean -C lib/ 
	make clean -C Vectors/Array/Int/ 
	make clean -C Vectors/Vector/Int/ 
	make clean -C Vectors/Vector/Generic/ 
	make clean -C Vectors/Vector/Int/ 
	make clean -C Lists/Generic/ 
	make clean -C Lists/Simple/ 
	make clean -C Lists/Double/ 
	make clean -C Lists/Cyclic/ 
	make clean -C Lists/Double\ Cyclic/ 
	make clean -C Stacks/Array/ 
	make clean -C Stacks/List/ 
	make clean -C Stacks/Hanoi/ 
	make clean -C Queues/Array/ 
	make clean -C Queues/List/ 