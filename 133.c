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

// Función para crear el árbol espejo de un árbol dado
NodoArbol* crearArbolEspejo(NodoArbol* original) {
    // Caso base: si el árbol original es nulo, el árbol espejo también es nulo
    if (original == NULL) {
        return NULL;
    }

    // Crear el nodo raíz del árbol espejo con el mismo valor que el original
    NodoArbol* espejo = crearNodo(original->valor);

    // Recursivamente crear los subárboles espejo intercambiando izquierda y derecha
    espejo->izquierdo = crearArbolEspejo(original->derecho);
    espejo->derecho = crearArbolEspejo(original->izquierdo);

    return espejo;
}

// Función para imprimir el árbol en un recorrido en orden (solo para verificar)
void imprimirArbolEnOrden(NodoArbol* arbol) {
    if (arbol != NULL) {
        imprimirArbolEnOrden(arbol->izquierdo);
        printf("%d ", arbol->valor);
        imprimirArbolEnOrden(arbol->derecho);
    }
}

int main() {
    // Crear un árbol de ejemplo
    NodoArbol* arbolOriginal = crearNodo(1);
    arbolOriginal->izquierdo = crearNodo(2);
    arbolOriginal->derecho = crearNodo(3);
    arbolOriginal->izquierdo->izquierdo = crearNodo(4);
    arbolOriginal->izquierdo->derecho = crearNodo(5);

    printf("Árbol original (recorrido en orden): ");
    imprimirArbolEnOrden(arbolOriginal);
    printf("\n");

    // Crear el árbol espejo
    NodoArbol* arbolEspejo = crearArbolEspejo(arbolOriginal);

    printf("Árbol espejo (recorrido en orden): ");
    imprimirArbolEnOrden(arbolEspejo);
    printf("\n");

    return 0;
}
