#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[]){
	int nums[5];
	nums[0] = -1;
	nums[1] = -2;
	nums[2] = 0;
	nums[3] = 5;
	nums[4] = 7;

	for(int i=0; i<5; i+=1){
		printf("&nums[%i] = %p\n",i,(void*)  &nums[i]);
	}

	int** pointers = calloc(5, sizeof(int*));
	for(int i=0; i<5; i+=1){
		*(pointers + i) =(int*) &nums[i];
	       printf("pointer + %i = %p\n", i, *(pointers + i));	
	}
	free(pointers);
}
