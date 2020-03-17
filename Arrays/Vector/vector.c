struct Vector{
	int * array;
	int size;
};

int initVector(struct * Vector, int size){
	if(size == NULL) return 400;
	(*Vector).array = (int*) malloc(sizeof(int*size));
	if((*Vector).array==NULL) return 510;
	(*Vector).size = size;
	return 0;
}	

int vectorRead(struct * Vector, int pos, int * reader){
	if(pos<0) return 401;
	if(pos>Vector->size-1) return 402;
	*reader=Vector->array[pos];
	return 0;
}

int vectorWrite(struct * Vector, int pos, int data){
	if(pos<0) return 401;
	if(pos>(*Vector).size - 1) return 402;
	(*Vector).array[pos] = data;
	return 0;	
}
