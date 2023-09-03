#include <stdio.h>
#include <stdlib.h>

// Definición de la estructura para representar un punto en el juego de tenis
struct Punto {
    int puntos;
    struct Punto* siguiente;
};

// Función para agregar un punto al marcador
struct Punto* agregarPunto(struct Punto* inicio, int puntos) {
    struct Punto* nuevoPunto = (struct Punto*)malloc(sizeof(struct Punto));
    if (nuevoPunto == NULL) {
        printf("Error: No se pudo asignar memoria para el punto.\n");
        exit(1);
    }
    nuevoPunto->puntos = puntos;

    if (inicio == NULL) {
        nuevoPunto->siguiente = nuevoPunto; // La lista es circular, apuntando a sí misma
    } else {
        nuevoPunto->siguiente = inicio->siguiente;
        inicio->siguiente = nuevoPunto;
    }

    return nuevoPunto;
}

// Función para deshacer un punto del marcador
struct Punto* deshacerPunto(struct Punto* inicio) {
    if (inicio == NULL) {
        printf("El marcador está vacío.\n");
        return NULL;
    }

    if (inicio->siguiente == inicio) {
        free(inicio);
        return NULL;
    }

    struct Punto* ultimo = inicio;
    while (ultimo->siguiente != inicio) {
        ultimo = ultimo->siguiente;
    }

    struct Punto* temp = inicio;
    inicio = inicio->siguiente;
    ultimo->siguiente = inicio;
    free(temp);

    return inicio;
}

// Función para determinar si se ha ganado un set (al llegar a 11 puntos)
int haGanadoSet(struct Punto* inicio) {
    if (inicio == NULL) {
        return 0;
    }

    struct Punto* actual = inicio;
    int contador = 0;

    do {
        contador += actual->puntos;
        if (contador >= 11) {
            return 1;
        }
        actual = actual->siguiente;
    } while (actual != inicio);

    return 0;
}

int main() {
    struct Punto* marcador = NULL;
    int opcion;
    int puntos;

    printf("Bienvenido a Caliente.mx. Selección: Tenis de mesa.\n");

    do {
        printf("\nJugador: Igor Dabrowski.\nOpciones:\n");
        printf("1. Agregar punto\n");
        printf("2. Deshacer puntos\n");
        printf("3. Mostrar marcador\n");
        printf("4. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                printf("Ingrese la cantidad de puntos a agregar: ");
                scanf("%d", &puntos);
                marcador = agregarPunto(marcador, puntos);
                if (haGanadoSet(marcador)) {
                    printf("Igor Dabrowski ha ganado el set.\n");
                    // Reiniciar el marcador
                    while (marcador != NULL) {
                        marcador = deshacerPunto(marcador);
                    }
                }
                break;
            case 2:
                marcador = deshacerPunto(marcador);
                break;
            case 3:
                if (marcador == NULL) {
                    printf("El marcador está vacío.\n");
                } else {
                    printf("Marcador:\n");
                    struct Punto* actual = marcador;
                    do {
                        printf("%d ", actual->puntos);
                        actual = actual->siguiente;
                    } while (actual != marcador);
                    printf("\n");
                }
                break;
            case 4:
                printf("Saliendo del programa.\n");
                break;
            default:
                printf("Opción no válida. Por favor, seleccione una opción válida.\n");
        }
    } while (opcion != 4);

    // Liberar la memoria del marcador
    while (marcador != NULL) {
        marcador = deshacerPunto(marcador);
    }

    return 0;
}
