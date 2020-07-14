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

struct Arbol * eliminar( struct Arbol * raiz, int dato ){
	struct Arbol * nodo_a_eliminar = NULL;
	struct Arbol * padre_del_nodo_a_eliminar = NULL;
	if( raiz == NULL ){
		return 0x0;
	}
	/*Localizar al nodo */
	nodo_a_eliminar = raiz;
	while(nodo_a_eliminar != dato){
		padre_del_nodo_a_eliminar = nodo_a_eliminar;
		if( dato < nodo_a_eliminar->dato){
			nodo_a_eliminar = nodo_a_eliminar->izquierda;
		}else{
			nodo_a_eliminar = nodo_a_eliminar->derecha;
		}
		if(nodo_a_eliminar == NULL){
			break;
		}
		if(nodo_a_eliminar == NULL ){ /* No estaba en el árbol*/
			return raiz;
		}
	}

	/* Hacer preguntas al dato */
	/* caso: El nodo a eliminar es una hoja… */
	if(nodo_a_eliminar == NULL && nodo_a_elimianr->isquierda == NULL){
		if(padre_del_nodo_a_eliminar->dato > nodo_a_eliminar->dato){
			padre_del_nodo_a_eliminar->izquierda = NULL;
		}else{
			padre_del_nodo_a_eliminar->derecha = NULL;
		}
		free( nodo_a_eliminar );
		return raiz;
	}

	/* Caso: Sólo hay un hijo */
	if(nodo_a_eliminar->dercha == NULL ){
		if(padre_del_nodo_a_eliminar->dato > nodo_a_eliminar->dato){
			padre_del_nodo_a_eliminar->izquierda = nodo_a_eliminar->izquierdo;
		}else{
			padre_del_nodo_a_eliminar->derecha = nodo_a_eliminar->izquierdo;
		}
		free( nodo_a_eliminar );
		return raiz;
	}

	if(nodo_a_eliminar->izquierda == NULL ){
		if(padre_del_nodo_a_eliminar->dato > nodo_a_eliminar->dato){
			padre_del_nodo_a_eliminar->izquierda = nodo_a_eliminar->derecha;
		}else{
			padre_del_nodo_a_eliminar->derecha = nodo_a_eliminar->derecha;
		}
		free( nodo_a_eliminar );
		return raiz;
	}

	/* Caso: Tengo izquierdo y derecho… */


	/*localiza el dato*/
	struct Arbol * lugar_a_eliminar = buscar( raiz, dato );
	if( lugar_a_eliminar == NULL){
		return raiz;
	}
	lugar_a_eliminar

	/*
	 *  padre(?)
	 *	\
	 *	 \
	 *	  x
	 *	 / \
	 *	/   \
	 *  izq(?) der(?)
	 * */
	/* Buscar un substituto */
	/* ¿Criterio?, Bucar al más chico de la derecha */
	/* Caso especial:
	 * 		Y
	 *	       /
	 *	      /
	 *	     
	*/
}

int main(void){

	struct Arbol * arbol = NULL;

	arbol = insertar( arbol, 10 );
	arbol = insertar( arbol, 100 );
	arbol = insertar( arbol, 15 );
	arbol = insertar( arbol, 150 );

	arbol = eliminar( arbol, 50 );

	return 0;
}
