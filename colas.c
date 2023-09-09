#include <stdio.h>
#include <stdlib.h>

// Definición de la estructura de un nodo en la cola
struct Node {
    int data;
    struct Node* next;
};

// Definición de la cola
struct Queue {
    struct Node* front;
    struct Node* rear;
};

// Función para crear una cola vacía
struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = queue->rear = NULL;
    return queue;
}

// Función para encolar un elemento en la cola
void enqueue(struct Queue* queue, int data) {
    // Crear un nuevo nodo
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    // Si la cola está vacía, establecer el nuevo nodo como el frente y el rear
    if (queue->rear == NULL) {
        queue->front = queue->rear = newNode;
        return;
    }

    // Agregar el nuevo nodo al final de la cola
    queue->rear->next = newNode;
    queue->rear = newNode;
}

// Función para desencolar un elemento de la cola
int dequeue(struct Queue* queue) {
    // Verificar si la cola está vacía
    if (queue->front == NULL)
        return -1; // Valor de error (la cola está vacía)

    // Guardar el valor del frente y mover el frente al siguiente nodo
    int data = queue->front->data;
    struct Node* temp = queue->front;
    queue->front = queue->front->next;

    // Si el frente se vuelve NULL, la cola está vacía, así que también actualizamos el rear
    if (queue->front == NULL)
        queue->rear = NULL;

    free(temp); // Liberar la memoria del nodo desencolado
    return data;
}

// Función para mostrar la cola actual
void displayQueue(struct Queue* queue) {
    if (queue->front == NULL) {
        printf("La lista de espera está vacía.\n");
        return;
    }

    struct Node* current = queue->front;
    printf("Clientes en la lista de espera: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct Queue* queue = createQueue();
    int choice;

    while (1) {
        printf("Bienveindo al paisa.inc\n");
        printf("Por favor, seleccione una opción:\n ");
        printf("\n1. Agregar cliente a la lista de espera\n");
        printf("2. Atender cliente\n");
        printf("3. Consultar lista de espera\n");
        printf("4. Salir\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Ingrese el número del cliente a agregar: ");
                int customer;
                scanf("%d", &customer);
                enqueue(queue, customer);
                printf("Cliente %d agregado a la lista de espera.\n", customer);
                break;

            case 2:
                if (queue->front != NULL) {
                    int customer = dequeue(queue);
                    printf("Cliente %d atendido\n", customer);
                } else {
                    printf("No hay clientes en espera.\n");
                }
                break;

            case 3:
                displayQueue(queue);
                break;

            case 4:
                printf("Gracias por comprar en el paisa.inc.\n");
                exit(0);

            default:
                printf("Opción no válida. Por favor, seleccione una opción válida.\n");
        }
    }

    return 0;
}
