
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

// Función para comprobar si dos árboles son iguales en estructura y contenido
int sonArbolesIguales(NodoArbol* arbol1, NodoArbol* arbol2) {
    // Caso base: si ambos árboles son nulos, son iguales
    if (arbol1 == NULL && arbol2 == NULL) {
        return 1;
    }
    // Si uno de los árboles es nulo y el otro no, no son iguales
    if (arbol1 == NULL || arbol2 == NULL) {
        return 0;
    }
    // Comprobar que los valores en los nodos sean iguales y recursivamente comparar subárboles
    return (arbol1->valor == arbol2->valor) &&
           sonArbolesIguales(arbol1->izquierdo, arbol2->izquierdo) &&
           sonArbolesIguales(arbol1->derecho, arbol2->derecho);
}

int main() {
    // Crear dos árboles de ejemplo
    NodoArbol* arbol1 = crearNodo(1);
    arbol1->izquierdo = crearNodo(2);
    arbol1->derecho = crearNodo(3);

    NodoArbol* arbol2 = crearNodo(1);
    arbol2->izquierdo = crearNodo(2);
    arbol2->derecho = crearNodo(3);

    // Comprobar si los árboles son iguales
    if (sonArbolesIguales(arbol1, arbol2)) {
        printf("Los árboles son iguales.\n");
    } else {
        printf("Los árboles no son iguales.\n");
    }

    // Liberar la memoria de los árboles
 
    return 0;
}
