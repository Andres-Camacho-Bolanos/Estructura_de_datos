#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 6

// Estructura para la cola circular
struct CircularQueue {
    char names[MAX_SIZE][50];
    int front;
    int rear;
    int count;
};

// Función para inicializar la cola
void initializeQueue(struct CircularQueue *queue) {
    queue->front = 2;
    queue->rear = 2;
    queue->count = 0;
}

// Función para agregar un nombre a la cola
void enqueue(struct CircularQueue *queue, const char *name) {
    if (queue->count < MAX_SIZE) {
        strcpy(queue->names[queue->rear], name);
        queue->rear = (queue->rear + 1) % MAX_SIZE;
        queue->count++;
    } else {
        printf("La cola está llena. No se puede agregar %s\n", name);
    }
}

// Función para eliminar un elemento de la cola
void dequeue(struct CircularQueue *queue) {
    if (queue->count > 0) {
        printf("Se ha eliminado: %s\n", queue->names[queue->front]);
        queue->front = (queue->front + 1) % MAX_SIZE;
        queue->count--;
    } else {
        printf("La cola está vacía. No se puede eliminar.\n");
    }
}

int main() {
    struct CircularQueue queue;
    initializeQueue(&queue);

    enqueue(&queue, "Mar");
    enqueue(&queue, "Sella");
    enqueue(&queue, "Centurión");

    // Mostrar la cola y sus campos
    printf("Elementos de la cola:\n");
    for (int i = 0; i < queue.count; i++) {
        printf("%s\n", queue.names[(queue.front + i) % MAX_SIZE]);
    }
    printf("Frente: %d\n", queue.front);
    printf("Final: %d\n", (queue.front + queue.count - 1) % MAX_SIZE);

    enqueue(&queue, "Gloria");
    enqueue(&queue, "Generosa");
    dequeue(&queue);
    enqueue(&queue, "Positivo");
    enqueue(&queue, "Horche");

    // Eliminar todos los elementos de la cola
    while (queue.count > 0) {
        dequeue(&queue);
    }

    // Crear una lista enlazada de números enteros positivos al azar (no incluida en el código anterior)

    // Recorrer la lista para mostrar los elementos por pantalla (no incluida en el código anterior)

    // Eliminar todos los nodos que superen un valor dado (no incluida en el código anterior)

    return 0;
}
