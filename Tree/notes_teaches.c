/* -- mode de ejemplo --*/

#include <stdlib.h>

struct ListaDoble {
	int dato;
	struct ListaDoble * siguiente;
	struct ListaDoble * anterior;
};

struct Arlbol{
	int dato;
	struct Arbol * izquierda; /* Diagonal */
	struct Arbol * derecha; /* Diagonal */
};
/*
 * Al punto de partida se le conoce como la raíz del árbol.
 * A los elementos a los que se puede llegar: nodo.
 * Si los nodos, ya no tienen a donde ir. (izquierda == NULL y derecha == NULL) nodos hoja.
 * A la ruta de raíz a las hojas: Ramas.
 * Estructura recursiva:
 * Árbol, es un nodo, con dos sub arboles, el sub árbol derecho, y el izquierdo.
 * 
*/

/*
 *	/
 *	\
 *	 \
 *	  \
 *	  /
 *           .
 *        /   \
 *             .
 *      /       \
 *     /         \
 *    /           \
 *   /             \
 *
 * */

struct Arbol * crear_arbol( int dato ){
	struct Arbol * nuevo = NULL;
	nuevo = ( struct Arbol *  ) malloc( sizeof( struct  Arbol * ) );
	if( nuevo == NULL){
		return NULL;
	}

	nuevo->dato = dato;
	nuevo->izquierda = NULL;
	nuevo->derecha = NULL;

	return nuevo;
}

/* Insertar en árbol: 
 * BTS Binary Search Tree - Árbol Binario de Búsqueda.
 * Criterio:
 * 	Si es más pequeño que la raíz, va a la izquierda.
 * 	Si es más grande que la raíz, va a la derecha.
 * Punto de partida: raíz
 * Fácil: No se permiten repetidos.
 *
 * Ejemplo: raíz = 100 (3.14 < 100)
 * 		  /   \
 * 		10    200
 *	       /  \
 *	     3.14 11
 * */
struct arbol * insertar( struct Arbol * raiz, int dato ) {
	if( raiz == NULL  ){
		return crear_arbol(dato);
	}

	if( dato > raiz -> dato ){
		raiz -> derecha = insertar( raiz -> derecha, dato );
	} else if( raiz -> dato > dato ){
		raiz -> izquierda = insertar( raiz -> izquierda, dato );
	}

	return raiz;
}

int main(void){

	struct Arbol * arbol = NULL;

	arbol = insertar( arbol, 10 );
	arbol = insertar( arbol, 100 );
	arbol = insertar( arbol, 15 );
	arbol = insertar( arbol, 150 );

	return 0;
}
