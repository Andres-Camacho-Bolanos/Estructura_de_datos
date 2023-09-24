#include <stdio.h>
#include <stdlib.h>

// Definición de la estructura de un nodo de árbol binario
typedef struct NodoArbol {
    int valor;
    struct NodoArbol* izquierdo;
    struct NodoArbol* derecho;
} NodoArbol;

// Función para crear un nuevo nodo de árbol con un valor dado
NodoArbol* crearNodo(int valor) {
    NodoArbol* nuevoNodo = (NodoArbol*)malloc(sizeof(NodoArbol));
    nuevoNodo->valor = valor;
    nuevoNodo->izquierdo = NULL;
    nuevoNodo->derecho = NULL;
    return nuevoNodo;
}

// Función para contar las hojas de un árbol
int contarHojas(NodoArbol* arbol) {
    // Caso base: si el árbol es nulo, no hay hojas
    if (arbol == NULL) {
        return 0;
    }
    // Caso base: si el árbol es una hoja, hay una hoja
    if (arbol->izquierdo == NULL && arbol->derecho == NULL) {
        return 1;
    }
    // Recursivamente contar las hojas en los subárboles izquierdo y derecho
    int hojasIzquierdo = contarHojas(arbol->izquierdo);
    int hojasDerecho = contarHojas(arbol->derecho);
    // La cantidad de hojas en el árbol es la suma de las hojas en los subárboles
    return hojasIzquierdo + hojasDerecho;
}

int main() {
    // Crear un árbol de ejemplo
    NodoArbol* arbol = crearNodo(1);
    arbol->izquierdo = crearNodo(2);
    arbol->derecho = crearNodo(3);
    arbol->izquierdo->izquierdo = crearNodo(4);
    arbol->izquierdo->derecho = crearNodo(5);

    // Contar las hojas del árbol
    int cantidadHojas = contarHojas(arbol);

    printf("El árbol tiene %d hojas.\n", cantidadHojas);

    // Liberar la memoria del árbol

     return 0;
}
