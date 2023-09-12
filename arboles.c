#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOMBRE 100
#define MAX_CAPITULOS 2

struct NodoArbol {
    char nombre[MAX_NOMBRE];
    struct NodoArbol *izquierdo;
    struct NodoArbol *derecho;
    int capitulosAgregados;
};

// Función para liberar la memoria de un árbol
void liberarArbol(struct NodoArbol *nodo) {
    if (nodo == NULL) {
        return;
    }
    liberarArbol(nodo->izquierdo);
    liberarArbol(nodo->derecho);
    free(nodo);
}

// Función para agregar un capítulo
void insertarCapitulo(struct NodoArbol *seccion, char nombre[]) {
    if (seccion->capitulosAgregados < MAX_CAPITULOS) {
        struct NodoArbol *nuevoCapitulo = (struct NodoArbol *)malloc(sizeof(struct NodoArbol));
        if (nuevoCapitulo == NULL) {
            printf("Error: No se pudo asignar memoria para el capítulo.\n");
            exit(1);
        }
        strcpy(nuevoCapitulo->nombre, nombre);
        nuevoCapitulo->izquierdo = NULL;
        nuevoCapitulo->derecho = NULL;
        nuevoCapitulo->capitulosAgregados = 0;
        if (seccion->izquierdo == NULL) {
            seccion->izquierdo = nuevoCapitulo;
        } else {
            struct NodoArbol *ultimoCapitulo = seccion->izquierdo;
            while (ultimoCapitulo->derecho != NULL) {
                ultimoCapitulo = ultimoCapitulo->derecho;
            }
            ultimoCapitulo->derecho = nuevoCapitulo;
        }
        seccion->capitulosAgregados++;
    } else {
        printf("Esta sección ya tiene el máximo de capítulos permitidos (%d).\n", MAX_CAPITULOS);
    }
}

// Función para eliminar ambos capítulos de una sección
void eliminarCapitulos(struct NodoArbol *seccion) {
    struct NodoArbol *capituloActual = seccion->izquierdo;
    while (capituloActual != NULL) {
        struct NodoArbol *temp = capituloActual->derecho;
        free(capituloActual);
        capituloActual = temp;
    }
    seccion->izquierdo = NULL;
    seccion->capitulosAgregados = 0;
}

// Función para navegar por el árbol y mostrar los elementos
void navegarArbol(struct NodoArbol *nodo, int esRaiz) {
    if (nodo == NULL) {
        return;
    }
    printf("Nombre: %s\n", nodo->nombre);
    if (esRaiz) {
        printf("Tipo: Libro\n");
    } else if (nodo->capitulosAgregados > 0) {
        printf("Tipo: Sección\n");
    } else {
        printf("Tipo: Capítulo\n");
    }
    printf("-------------\n");
    navegarArbol(nodo->izquierdo, 0); // Pasar 0 para los nodos que no son raíces
    navegarArbol(nodo->derecho, 0);
}

int main() {
    struct NodoArbol *raiz = NULL;
    char nombreLibro[MAX_NOMBRE];

    printf("Ingrese el nombre del libro (raíz): ");
    scanf("%s", nombreLibro);

    raiz = (struct NodoArbol *)malloc(sizeof(struct NodoArbol));
    if (raiz == NULL) {
        printf("Error: No se pudo asignar memoria para el libro.\n");
        return 1;
    }
    strcpy(raiz->nombre, nombreLibro);
    raiz->izquierdo = NULL;
    raiz->derecho = NULL;
    raiz->capitulosAgregados = 0;

    int opcion;
    struct NodoArbol *seccionActual = NULL;

    while (1) {
        printf("\nSeleccione una opción:\n");
        printf("1. Agregar sección (nodo interno)\n");
        printf("2. Agregar capítulo (nodo hijo)\n");
        printf("3. Eliminar capítulos (nodos hijos)\n"); // Nueva opción para eliminar capítulos
        printf("4. Navegar por el árbol\n");
        printf("5. Salir\n");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                if (seccionActual != NULL) {
                    printf("Ya ha creado una sección previamente. No puede crear otra.\n");
                } else {
                    char nombreSeccion[MAX_NOMBRE];
                    printf("Ingrese el nombre de la sección: ");
                    scanf("%s", nombreSeccion);
                    struct NodoArbol *nuevaSeccion = (struct NodoArbol *)malloc(sizeof(struct NodoArbol));
                    if (nuevaSeccion == NULL) {
                        printf("Error: No se pudo asignar memoria para la sección.\n");
                        exit(1);
                    }
                    strcpy(nuevaSeccion->nombre, nombreSeccion);
                    nuevaSeccion->izquierdo = NULL;
                    nuevaSeccion->derecho = NULL;
                    nuevaSeccion->capitulosAgregados = 0;
                    seccionActual = raiz->izquierdo = nuevaSeccion;
                }
                break;
            case 2:
                if (seccionActual == NULL) {
                    printf("Debe crear una sección antes de agregar capítulos.\n");
                } else {
                    char nombreCapitulo[MAX_NOMBRE];
                    printf("Ingrese el nombre del capítulo: ");
                    scanf("%s", nombreCapitulo);
                    insertarCapitulo(seccionActual, nombreCapitulo);
                }
                break;
            case 3:
                if (seccionActual == NULL) {
                    printf("Debe crear una sección antes de eliminar capítulos.\n");
                } else {
                    eliminarCapitulos(seccionActual);
                    printf("Se han eliminado todos los capítulos de la sección actual.\n");
                }
                break;
            case 4:
                printf("Navegación por el árbol:\n");
                navegarArbol(raiz, 1); // Pasar 1 para indicar que el nodo raíz es una raíz
                break;
            case 5:
                printf("Saliendo del programa...\n");
                liberarArbol(raiz); // Liberar la memoria del árbol antes de salir
                return 0;
            default:
                printf("Opción no válida. Por favor, ingrese una opción válida.\n");
        }
    }

    return 0;
}
