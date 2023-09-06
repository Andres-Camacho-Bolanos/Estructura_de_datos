#include <stdio.h>
#include <stdlib.h>

// Definición de la estructura de un nodo de la pila
struct Node {
    int ficha;
    struct Node* next;
};

// Función para crear un nuevo nodo
struct Node* newNode(int ficha) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    if (node == NULL) {
        printf("Error: No se pudo asignar memoria para el nuevo nodo.\n");
        exit(1);
    }
    node->ficha = ficha;
    node->next = NULL;
    return node;
}

// Función para añadir una ficha a la pila (push)
void push(struct Node** top, int ficha) {
    struct Node* newNodePtr = newNode(ficha);
    newNodePtr->next = *top;
    *top = newNodePtr;
    printf("Se añadió una ficha de valor %d al casino.\n", ficha);
}

// Función para eliminar la última ficha de la pila (pop)
int pop(struct Node** top) {
    if (*top == NULL) {
        printf("No hay fichas en el casino. No se puede retirar una ficha.\n");
        return -1; // Devolvemos un valor especial para indicar que no se pudo retirar una ficha
    }
    struct Node* temp = *top;
    int ficha = temp->ficha;
    *top = (*top)->next;
    free(temp);
    return ficha;
}

// Función para consultar la cantidad de fichas en el casino
int countFichas(struct Node* top) {
    int count = 0;
    struct Node* current = top;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

int main() {
    struct Node* casino = NULL; // Inicializamos el casino sin fichas

    int opcion;
    int valor;

    while (1) {
        printf("\nSelecciona una opción:\n");
        printf("1. Añadir una ficha al casino.\n");
        printf("2. Consultar la cantidad de fichas en el casino.\n");
        printf("3. Eliminar la última ficha del casino.\n");
        printf("4. Salir.\n");

        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                printf("Ingresa el valor de la ficha: ");
                scanf("%d", &valor);
                push(&casino, valor);
                break;
            case 2:
                printf("Cantidad de fichas en el casino: %d\n", countFichas(casino));
                printf("Presiona Enter para continuar...");
                getchar(); // Espera a que el usuario presione Enter
                getchar(); // Captura el Enter
                break;
            case 3:
                if (casino != NULL) {
                    int ficha = pop(&casino);
                    if (ficha != -1) {
                        printf("Se retiró una ficha de valor %d del casino.\n", ficha);
                    }
                    printf("Presiona Enter para continuar...");
                    getchar(); // Espera a que el usuario presione Enter
                    getchar(); // Captura el Enter
                } else {
                    printf("No hay fichas en el casino. No se puede retirar una ficha.\n");
                    printf("Presiona Enter para continuar...");
                    getchar(); // Espera a que el usuario presione Enter
                    getchar(); // Captura el Enter
                }
                break;
            case 4:
                printf("Saliendo del programa.\n");
                exit(0);
            default:
                printf("Opción no válida. Por favor, selecciona una opción válida.\n");
        }
    }

    return 0;
}
