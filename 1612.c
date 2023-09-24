#include <stdio.h>
#include <stdlib.h>

// Definición de la estructura del nodo del árbol binario de búsqueda
typedef struct Nodo {
    int valor;
    struct Nodo* izquierdo;
    struct Nodo* derecho;
} Nodo;

// Clase para el árbol binario de búsqueda
typedef struct ArbolBinario {
    Nodo* raiz;
} ArbolBinario;

// Función para crear un nuevo nodo de árbol
Nodo* crearNodo(int valor) {
    Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
    nuevoNodo->valor = valor;
    nuevoNodo->izquierdo = NULL;
    nuevoNodo->derecho = NULL;
    return nuevoNodo;
}

// Función para insertar un valor en el árbol de manera recursiva
Nodo* insertarRecursivo(Nodo* nodo, int valor) {
    if (nodo == NULL) {
        return crearNodo(valor);
    }

    if (valor <= nodo->valor) {
        nodo->izquierdo = insertarRecursivo(nodo->izquierdo, valor);
    } else {
        nodo->derecho = insertarRecursivo(nodo->derecho, valor);
    }

    return nodo;
}

// Función para insertar un valor en el árbol
void insertar(ArbolBinario* arbol, int valor) {
    arbol->raiz = insertarRecursivo(arbol->raiz, valor);
}

// Función para buscar un valor en el árbol de manera iterativa
Nodo* buscarIterativo(Nodo* raiz, int buscado) {
    int dato;
    int encontrado = 0;
    Nodo* raizSub = raiz;
    dato = buscado;

    while (!encontrado && raizSub != NULL) {
        if (dato == raizSub->valor) {
            encontrado = 1;
        } else if (dato < raizSub->valor) {
            raizSub = raizSub->izquierdo;
        } else {
            raizSub = raizSub->derecho;
        }
    }

    return raizSub;
}

int main() {
    ArbolBinario arbol;
    arbol.raiz = NULL;

    // Insertar valores en el árbol
    insertar(&arbol, 50);
    insertar(&arbol, 30);
    insertar(&arbol, 70);
    insertar(&arbol, 20);
    insertar(&arbol, 40);
    insertar(&arbol, 60);
    insertar(&arbol, 80);

    int valorABuscar = 60;

    // Buscar un valor en el árbol de manera iterativa
    Nodo* nodoEncontrado = buscarIterativo(arbol.raiz, valorABuscar);

    if (nodoEncontrado != NULL) {
        printf("El valor %d se encontró en el árbol.\n", valorABuscar);
    } else {
        printf("El valor %d no se encontró en el árbol.\n", valorABuscar);
    }

    // Liberar la memoria del árbol (debe implementarse)

    return 0;
}
