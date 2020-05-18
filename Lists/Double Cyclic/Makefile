cr: c r

cd: b d

cv: b v 

c:
	gcc -x c -std=c99 -o Tester.out Tester.c
r:
	./Tester.out
b:
	gcc -x c -std=c99 -o Tester.out -ggdb Tester.c
d:
	gdb Tester.out
v: 
	valgrind ./Tester.out
