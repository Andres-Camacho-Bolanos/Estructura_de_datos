#include <stdio.h>
#include <stdlib.h>

#define MAX_GOLES 10

// Definición de la estructura para representar un gol
struct Gol {
    int minuto;
    struct Gol* siguiente;
};

// Función para agregar un gol a la lista
struct Gol* agregarGol(struct Gol* cabeza, int minuto) {
    struct Gol* nuevoGol = (struct Gol*)malloc(sizeof(struct Gol));
    if (nuevoGol == NULL) {
        printf("Error: No se pudo asignar memoria para el gol.\n");
        exit(1);
    }
    nuevoGol->minuto = minuto;
    nuevoGol->siguiente = NULL;

    // Si la lista está vacía, el nuevo gol se convierte en la cabeza de la lista
    if (cabeza == NULL) {
        cabeza = nuevoGol;
    } else {
        // Encontrar el último gol en la lista
        struct Gol* ultimo = cabeza;
        while (ultimo->siguiente != NULL) {
            ultimo = ultimo->siguiente;
        }
        // Agregar el nuevo gol al final de la lista
        ultimo->siguiente = nuevoGol;
    }

    return cabeza;
}

// Función para imprimir la lista de goles
void imprimirGoles(struct Gol* cabeza) {
    struct Gol* actual = cabeza;
    while (actual != NULL) {
        printf("Gol en el minuto %d\n", actual->minuto);
        actual = actual->siguiente;
    }
}

int main() {
    struct Gol* listaGoles = NULL;
    int minuto;
    int golesIngresados = 0;

    printf("Ingrese los minutos en los que se marcan los goles (hasta el minuto 90). Hay un límite de 10 goles.:\n");

    do {
        printf("Minuto: ");
        scanf("%d", &minuto);

        if (minuto >= 1 && minuto <= 90) {
            listaGoles = agregarGol(listaGoles, minuto);
            golesIngresados++;
        } else if (minuto != 0) {
            printf("Minuto no válido. Debe estar entre 1 y 90.\n");
        }

        if (golesIngresados >= MAX_GOLES) {
            printf("Se han ingresado el máximo de %d goles.\n", MAX_GOLES);
            break;
        }

    } while (minuto != 0);

    // Si se llegó al minuto 90 sin alcanzar el límite de goles, se agrega un gol en el minuto 90.
    if (minuto == 0 && golesIngresados < MAX_GOLES) {
        listaGoles = agregarGol(listaGoles, 90);
    }

    printf("Lista de goles en el partido:\n");
    imprimirGoles(listaGoles);

    // Liberar la memoria de la lista de goles
    while (listaGoles != NULL) {
        struct Gol* temp = listaGoles;
        listaGoles = listaGoles->siguiente;
        free(temp);
    }

    return 0;
}
