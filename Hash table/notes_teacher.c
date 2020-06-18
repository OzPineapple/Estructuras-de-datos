/*
Sesión de trabajo de prueba - Clase Estruccutras de datos
*/

/*
1. Abierta o cerrada -> abierta.
2. ¿Cual es la funciñon hash? -> diseñar/selleccionar la función hash.

Cuando dos datos generan el mismo valor de posición se le llama colisión, hay dos opciones:
1. Sobre-escribir datos (Escritura abierta).
2. Re-hash, buscar el espacio (Escritura cerrada).
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

const int N = 100; // Guardar hasta N/3 datos

int funcion_hash( int dato ){
	return dato*dato % N;
}

int funcion_rehash( int dato, int intento){ /*Familia de funciones*/
	return (int) pow( (double) dato, (double) intento) % N;
}
/*
struct Lista{
	int dato;
	struct Lista * siguiente;
}
*/

struct TablaHash{ //Tabla hash abierta
	int datos[N];
	int libre[N]; /* 0 ocupado, 1 libre*/
	int cuantos;
};

int insertar(struct TablaHash * tabla, int dato){
	int donde = funcion_hash( dato ); /* 0(1) constante */
	if(cuantos  == N) return -1;
	if( tabla -> libre[ donde  ] == 1 ){
		tabla->dato[ donde ] = dato;
		cuantos++;
	}else{
		for(size_t i =0; tabla -> libre[donde]==0; i++){ //Buscar posición via rehash
			donde = funcion_rehash(dato, i);
		}
		tabla->dato[ donde ] = dato;
		cuantos++;
	}
}

int eliminar( struct TablaHAst * tabla, int dato ){
	int donde = funcion_hash( dato ); /* 0(1) */
	return eliminar_list( tabla->datos[ donde ], dato ); /* 0(n/N) */
}

int buscar( struct TablaHash * tabla, int dato ){
	int donde = funcion_hash( dato ); /* 0(1) */
	if( tabla -> libre[donde] ) return -1;
	else{
		if(tabla -> dato[donde] != dato ){
			while(){
				/* rehash */
			}
		}
	}
	
}

int mostrar( struct TablaHash * tabla ){
	
}

int main( int argc, char* argv[] ){
	int posicion = funcion_hash( 2020 );
	return 0;
}
