#include <stdio.h>
#include <stdlib.h>

// Definición de la estructura de un nodo de árbol binario
typedef struct NodoArbol {
    int Elemento;
    struct NodoArbol* SubarbolIzquierdo;
    struct NodoArbol* SubarbolDerecho;
} NodoArbol;

// Función para buscar un elemento en un árbol binario
NodoArbol* BuscarElementoEnArbolBinario(NodoArbol* Arbol, int Elemento) {
    // Inicializar un puntero al nodo actual, comenzando en la raíz del árbol
    NodoArbol* NodoActual = Arbol;

    // Mientras el nodo actual no sea nulo
    while (NodoActual != NULL) {
        // Si el elemento del nodo actual es igual al elemento que estamos buscando, lo hemos encontrado
        if (NodoActual->Elemento == Elemento) {
            return NodoActual; // Se ha encontrado el elemento en el árbol
        }
        // Si el elemento que estamos buscando es menor que el elemento del nodo actual, buscar en el subárbol izquierdo
        else if (Elemento < NodoActual->Elemento) {
            NodoActual = NodoActual->SubarbolIzquierdo;
        }
        // Si el elemento que estamos buscando es mayor que el elemento del nodo actual, buscar en el subárbol derecho
        else {
            NodoActual = NodoActual->SubarbolDerecho;
        }
    }

    // El elemento no se encontró en el árbol, devolver un valor nulo o un mensaje de error, según sea apropiado
    return NULL; // Elemento no encontrado
}

int main() {
    // Crear un árbol de ejemplo
    NodoArbol* Raiz = (NodoArbol*)malloc(sizeof(NodoArbol));
    Raiz->Elemento = 50;
    Raiz->SubarbolIzquierdo = (NodoArbol*)malloc(sizeof(NodoArbol));
    Raiz->SubarbolIzquierdo->Elemento = 30;
    Raiz->SubarbolIzquierdo->SubarbolIzquierdo = (NodoArbol*)malloc(sizeof(NodoArbol));
    Raiz->SubarbolIzquierdo->SubarbolIzquierdo->Elemento = 20;
    Raiz->SubarbolIzquierdo->SubarbolDerecho = (NodoArbol*)malloc(sizeof(NodoArbol));
    Raiz->SubarbolIzquierdo->SubarbolDerecho->Elemento = 40;
    Raiz->SubarbolDerecho = (NodoArbol*)malloc(sizeof(NodoArbol));
    Raiz->SubarbolDerecho->Elemento = 70;
    Raiz->SubarbolDerecho->SubarbolIzquierdo = (NodoArbol*)malloc(sizeof(NodoArbol));
    Raiz->SubarbolDerecho->SubarbolIzquierdo->Elemento = 60;
    Raiz->SubarbolDerecho->SubarbolDerecho = (NodoArbol*)malloc(sizeof(NodoArbol));
    Raiz->SubarbolDerecho->SubarbolDerecho->Elemento = 80;

    int ElementoABuscar = 60;

    // Buscar el elemento en el árbol
    NodoArbol* NodoEncontrado = BuscarElementoEnArbolBinario(Raiz, ElementoABuscar);

    if (NodoEncontrado != NULL) {
        printf("El elemento %d se encontró en el árbol.\n", ElementoABuscar);
    } else {
        printf("El elemento %d no se encontró en el árbol.\n", ElementoABuscar);
    }

    // Liberar la memoria del árbol (debe implementarse)

    return 0;
}
