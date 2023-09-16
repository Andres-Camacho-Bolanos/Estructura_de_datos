#ifndef CIRCULAR_QUEUE_H
#define CIRCULAR_QUEUE_H

#define MAX_QUEUE_SIZE 100 // Cambia el tamaño máximo de la cola según tus necesidades

// Estructura de la cola circular
typedef struct {
    int front, rear;
    int size;
    int elements[MAX_QUEUE_SIZE];
} CircularQueue;

// Funciones para operar en la cola circular

// Inicializar la cola circular
void initQueue(CircularQueue *queue);

// Verificar si la cola está vacía
int isEmpty(CircularQueue *queue);

// Verificar si la cola está llena
int isFull(CircularQueue *queue);

// Añadir un elemento a la cola
void enqueue(CircularQueue *queue, int item);

// Consultar el elemento en la posición actual
int peek(CircularQueue *queue);

// Mover la posición actual hacia adelante
void moveForward(CircularQueue *queue);

// Eliminar el elemento en la posición actual
void dequeue(CircularQueue *queue);

#endif
