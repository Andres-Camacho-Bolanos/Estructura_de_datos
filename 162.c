#include <stdio.h>
#include <stdlib.h>

// Definición de la estructura de un nodo de árbol
typedef struct NodoArbol {
    int valor;
    struct NodoArbol* izquierdo;
    struct NodoArbol* derecho;
} NodoArbol;

// Función para crear un nuevo nodo de árbol
NodoArbol* crearNodo(int valor) {
    NodoArbol* nuevoNodo = (NodoArbol*)malloc(sizeof(NodoArbol));
    nuevoNodo->valor = valor;
    nuevoNodo->izquierdo = NULL;
    nuevoNodo->derecho = NULL;
    return nuevoNodo;
}

int calcularProfundidadMinima(NodoArbol* raiz) {
    if (raiz == NULL) {
        return 0;
    }

    int izquierda = calcularProfundidadMinima(raiz->izquierdo);
    int derecha = calcularProfundidadMinima(raiz->derecho);

    return (izquierda < derecha) ? izquierda + 1 : derecha + 1;
}

int calcularProfundidadMaxima(NodoArbol* raiz) {
    if (raiz == NULL) {
        return 0;
    }

    int izquierda = calcularProfundidadMaxima(raiz->izquierdo);
    int derecha = calcularProfundidadMaxima(raiz->derecho);

    return (izquierda > derecha) ? izquierda + 1 : derecha + 1;
}

int main() {
    // Crear un árbol de ejemplo con 5 nodos
    NodoArbol* raiz = crearNodo(1);
    raiz->izquierdo = crearNodo(2);
    raiz->derecho = crearNodo(3);
    raiz->izquierdo->izquierdo = crearNodo(4);
    raiz->izquierdo->derecho = crearNodo(5);

    // Calcular la profundidad mínima y máxima del árbol
    int profundidadMinima = calcularProfundidadMinima(raiz);
    int profundidadMaxima = calcularProfundidadMaxima(raiz);

    printf("Profundidad Mínima: %d\n", profundidadMinima);
    printf("Profundidad Máxima: %d\n", profundidadMaxima);

    // Liberar la memoria del árbol
    // (Debes implementar una función para liberar la memoria correctamente)

    return 0;
}
