#include <stdio.h>
#include <stdlib.h>

// Definición de la estructura de un nodo de la lista
struct Nodo {
    int info;
    struct Nodo* Liga;
};

typedef struct Nodo Nodo;

// Función de búsqueda secuencial recursiva en una lista desordenada
void Secuencial_lista_desordenada_recursivo(Nodo* P, int X) {
    // Caso base: la lista es NULL (NIL)
    if (P == NULL) {
        printf("La información no se encuentra en la lista\n");
        return;
    }

    // Caso recursivo: comparar el elemento actual con X
    if ((P->info) != X) {
        // Llamada recursiva con el siguiente nodo en la lista
        Secuencial_lista_desordenada_recursivo(P->Liga, X);
    } else {
        // Se encontró el elemento
        printf("La información se encuentra en la lista\n");
    }
}

int main() {
    // Crear una lista de ejemplo
    Nodo nodo3 = {3, NULL};
    Nodo nodo2 = {2, &nodo3};
    Nodo nodo1 = {1, &nodo2};

    // Pedir al usuario que ingrese el valor a buscar
    int valor;
    printf("Ingrese el valor que desea buscar: ");
    scanf("%d", &valor);

    // Llamar a la función de búsqueda con el primer nodo de la lista y el valor ingresado por el usuario
    Secuencial_lista_desordenada_recursivo(&nodo1, valor);

    return 0;
}
