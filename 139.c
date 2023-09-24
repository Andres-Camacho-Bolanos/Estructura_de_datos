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

// Función para mostrar todos los nodos en un nivel dado del árbol
void mostrarNodosEnNivel(NodoArbol* arbol, int nivelDeseado, int nivelActual) {
    // Caso base: si el árbol es nulo o hemos alcanzado el nivel deseado, no hacemos nada
    if (arbol == NULL || nivelActual > nivelDeseado) {
        return;
    }
    
    // Si estamos en el nivel deseado, mostramos el valor del nodo
    if (nivelActual == nivelDeseado) {
        printf("%d ", arbol->valor);
    }
    
    // Luego, llamamos recursivamente a la función para los subárboles izquierdo y derecho
    mostrarNodosEnNivel(arbol->izquierdo, nivelDeseado, nivelActual + 1);
    mostrarNodosEnNivel(arbol->derecho, nivelDeseado, nivelActual + 1);
}

int main() {
    // Crear un árbol de ejemplo
    NodoArbol* arbol = crearNodo(1);
    arbol->izquierdo = crearNodo(2);
    arbol->derecho = crearNodo(3);
    arbol->izquierdo->izquierdo = crearNodo(4);
    arbol->izquierdo->derecho = crearNodo(5);

    int nivelDeseado = 2; // Cambia el nivel deseado según tus necesidades

    printf("Nodos en el nivel %d: ", nivelDeseado);
    mostrarNodosEnNivel(arbol, nivelDeseado, 1);
    printf("\n");

    // Liberar la memoria del árbol

    return 0;
}
