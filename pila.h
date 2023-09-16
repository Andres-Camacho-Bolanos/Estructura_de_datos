#ifndef STACK_H
#define STACK_H

#define MAX_STACK_SIZE 100 // Cambia el tamaño máximo de la pila según tus necesidades

// Estructura de la pila
typedef struct {
    int top;
    int elements[MAX_STACK_SIZE];
} Stack;

// Funciones para operar en la pila

// Inicializar la pila
void initStack(Stack *stack);

// Verificar si la pila está vacía
int isEmpty(Stack *stack);

// Verificar si la pila está llena
int isFull(Stack *stack);

// Añadir un elemento a la pila
void push(Stack *stack, int item);

// Consultar el elemento en la parte superior de la pila
int peek(Stack *stack);

// Mover la posición hacia abajo (hacia elementos más recientes)
void moveDown(Stack *stack);

// Eliminar el elemento en la parte superior de la pila
void pop(Stack *stack);

#endif
