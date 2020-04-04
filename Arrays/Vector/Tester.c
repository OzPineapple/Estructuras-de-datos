#include <stdio.h>
#include "Vector.h"
#include "../../Globals/global_err_fun.h"

int main(int argc, char * argv[]){
	printf("Vector tester\nBy Oz Pineapple\n");
	struct Vector vector;
	int GLOBAL_ERROR_CODE = initVector(&vector,20);
	if(GLOBAL_ERROR_CODE>0){
		printf("%s",getGlobalError());
		return GLOBAL_ERROR_CODE;
	}		
	printf("Vector inited\n");
}
