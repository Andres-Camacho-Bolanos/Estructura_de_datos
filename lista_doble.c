#include <stdio.h>
#include <stdlib.h>

// Definición de la estructura para representar una versión
struct Version {
    int dia;
    int mes;
    int ano;
    struct Version* siguiente;
    struct Version* anterior;
};

// Función para agregar una versión al historial
struct Version* agregarVersion(struct Version* cabeza, int dia, int mes, int ano) {
    struct Version* nuevaVersion = (struct Version*)malloc(sizeof(struct Version));
    if (nuevaVersion == NULL) {
        printf("Error: No se pudo asignar memoria para la versión.\n");
        exit(1);
    }
    nuevaVersion->dia = dia;
    nuevaVersion->mes = mes;
    nuevaVersion->ano = ano;
    nuevaVersion->siguiente = NULL;

    // Si la lista está vacía, el nuevo nodo se convierte en la cabeza de la lista
    if (cabeza == NULL) {
        nuevaVersion->anterior = NULL;
        cabeza = nuevaVersion;
    } else {
        // Encontrar el último nodo en la lista
        struct Version* ultimo = cabeza;
        while (ultimo->siguiente != NULL) {
            ultimo = ultimo->siguiente;
        }
        // Agregar el nuevo nodo al final de la lista
        nuevaVersion->anterior = ultimo;
        ultimo->siguiente = nuevaVersion;
    }

    return cabeza;
}

// Función para imprimir el historial de versiones
void imprimirHistorial(struct Version* cabeza) {
    struct Version* actual = cabeza;
    while (actual != NULL) {
        printf("Fecha de la versión: %d/%d/%d\n", actual->dia, actual->mes, actual->ano);
        actual = actual->siguiente;
    }
}

// Función para eliminar una versión del historial
struct Version* eliminarVersion(struct Version* cabeza, int posicion) {
    if (cabeza == NULL) {
        printf("El historial está vacío.\n");
        return cabeza;
    }

    if (posicion < 1) {
        printf("Posición no válida.\n");
        return cabeza;
    }

    struct Version* nodoAEliminar = cabeza;

    if (posicion == 1) {
        cabeza = cabeza->siguiente;
        if (cabeza != NULL) {
            cabeza->anterior = NULL;
        }
    } else {
        int i = 1;
        while (i < posicion && nodoAEliminar != NULL) {
            nodoAEliminar = nodoAEliminar->siguiente;
            i++;
        }

        if (nodoAEliminar != NULL) {
            if (nodoAEliminar->anterior != NULL) {
                nodoAEliminar->anterior->siguiente = nodoAEliminar->siguiente;
            }
            if (nodoAEliminar->siguiente != NULL) {
                nodoAEliminar->siguiente->anterior = nodoAEliminar->anterior;
            }
            free(nodoAEliminar);
        }
    }

    return cabeza;
}

int main() {
    struct Version* historial = NULL;
    int dia, mes, ano;
    int opcion, posicion;

    printf("Historial de Versiones (Máximo 10 versiones):\n");

    do {
        printf("\nOpciones:\n");
        printf("1. Agregar una versión\n");
        printf("2. Eliminar una versión\n");
        printf("3. Mostrar historial\n");
        printf("4. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                if (historial != NULL && historial->siguiente != NULL) {
                    printf("Se ha alcanzado el límite de 10 versiones. No se pueden agregar más.\n");
                    break;
                }

                printf("Ingrese la fecha de la versión (dd/mm/aaaa): ");
                scanf("%d %d %d", &dia, &mes, &ano);
                historial = agregarVersion(historial, dia, mes, ano);
                break;
            case 2:
                printf("Ingrese la posición de la versión a eliminar (1-%d): ", posicion);
                scanf("%d", &posicion);
                historial = eliminarVersion(historial, posicion);
                break;
            case 3:
                printf("Historial de versiones:\n");
                imprimirHistorial(historial);
                break;
            case 4:
                printf("Salir del programa.\n");
                break;
            default:
                printf("Opción no válida. Por favor, seleccione una opción válida.\n");
        }
    } while (opcion != 4);

    // Liberar la memoria del historial de versiones
    while (historial != NULL) {
        struct Version* temp = historial;
        historial = historial->siguiente;
        free(temp);
    }

    return 0;
}
