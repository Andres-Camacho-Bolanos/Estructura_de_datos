#include <stdio.h>
#include <stdlib.h>

// Definición de la estructura de un nodo de árbol binario de búsqueda
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

// Función para insertar un valor en el árbol binario de búsqueda de forma recursiva
NodoArbol* insertar(NodoArbol* raiz, int valor) {
    // Si la raíz es nula, creamos un nuevo nodo
    if (raiz == NULL) {
        return crearNodo(valor);
    }

    // Si el valor es menor o igual que el valor de la raíz, lo insertamos en el subárbol izquierdo
    if (valor <= raiz->valor) {
        raiz->izquierdo = insertar(raiz->izquierdo, valor);
    }
    // Si el valor es mayor, lo insertamos en el subárbol derecho
    else {
        raiz->derecho = insertar(raiz->derecho, valor);
    }

    return raiz;
}

// Función para buscar un valor en el árbol binario de búsqueda de forma recursiva
int buscar(NodoArbol* raiz, int valor) {
    // Si llegamos a un nodo nulo, el valor no se encuentra en el árbol
    if (raiz == NULL) {
        return 0;
    }

    // Si encontramos el valor en el nodo actual, retornamos verdadero
    if (raiz->valor == valor) {
        return 1;
    }

    // Si el valor es menor o igual que el valor de la raíz, buscamos en el subárbol izquierdo
    if (valor < raiz->valor) {
        return buscar(raiz->izquierdo, valor);
    }
    // Si el valor es mayor, buscamos en el subárbol derecho
    else {
        return buscar(raiz->derecho, valor);
    }
}

// Función para imprimir el árbol en orden (recorrido inorden)
void imprimirEnOrden(NodoArbol* raiz) {
    if (raiz != NULL) {
        imprimirEnOrden(raiz->izquierdo);
        printf("%d ", raiz->valor);
        imprimirEnOrden(raiz->derecho);
    }
}

int main() {
    NodoArbol* raiz = NULL;

    // Insertar valores en el árbol
    raiz = insertar(raiz, 50);
    raiz = insertar(raiz, 30);
    raiz = insertar(raiz, 70);
    raiz = insertar(raiz, 20);
    raiz = insertar(raiz, 40);
    raiz = insertar(raiz, 60);
    raiz = insertar(raiz, 80);

    // Imprimir el árbol en orden (recorrido inorden)
    printf("Árbol binario de búsqueda (inorden): ");
    imprimirEnOrden(raiz);
    printf("\n");

    // Buscar valores en el árbol
    int valorABuscar = 60;
    if (buscar(raiz, valorABuscar)) {
        printf("%d se encuentra en el árbol.\n", valorABuscar);
    } else {
        printf("%d no se encuentra en el árbol.\n", valorABuscar);
    }

    // Liberar la memoria del árbol

    return 0;
}
