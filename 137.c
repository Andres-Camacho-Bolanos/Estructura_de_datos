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

// Función para calcular la altura de un árbol
int calcularAltura(NodoArbol* arbol) {
    // Caso base: si el árbol es nulo, su altura es 0
    if (arbol == NULL) {
        return 0;
    }
    
    // Calcular la altura de los subárboles izquierdo y derecho recursivamente
    int alturaIzquierdo = calcularAltura(arbol->izquierdo);
    int alturaDerecho = calcularAltura(arbol->derecho);
    
    // La altura del árbol es el máximo de las alturas de los subárboles más uno
    return (alturaIzquierdo > alturaDerecho) ? alturaIzquierdo + 1 : alturaDerecho + 1;
}

int main() {
    // Crear un árbol de ejemplo
    NodoArbol* arbol = crearNodo(1);
    arbol->izquierdo = crearNodo(2);
    arbol->derecho = crearNodo(3);
    arbol->izquierdo->izquierdo = crearNodo(4);
    arbol->izquierdo->derecho = crearNodo(5);

    // Calcular la altura del árbol
    int altura = calcularAltura(arbol);

    printf("La altura del árbol es %d.\n", altura);

    // Liberar la memoria del árbol

    return 0;
}
