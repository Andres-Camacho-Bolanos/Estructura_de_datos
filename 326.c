#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definición de la estructura del nodo de la pila
struct StackNode {
    char digit;
    struct StackNode *next;
};

// Definición de la estructura del nodo de la cola
struct QueueNode {
    char digit;
    struct QueueNode *next;
};

// Función para inicializar una pila
void initializeStack(struct StackNode **top) {
    *top = NULL;
}

// Función para insertar un dígito en la pila
void push(struct StackNode **top, char digit) {
    struct StackNode *newNode = (struct StackNode *)malloc(sizeof(struct StackNode));
    if (newNode == NULL) {
        perror("Error al asignar memoria para el nodo de la pila");
        exit(EXIT_FAILURE);
    }
    newNode->digit = digit;
    newNode->next = *top;
    *top = newNode;
}

// Función para eliminar y obtener el dígito superior de la pila
char pop(struct StackNode **top) {
    if (*top == NULL) {
        fprintf(stderr, "La pila está vacía\n");
        exit(EXIT_FAILURE);
    }
    char digit = (*top)->digit;
    struct StackNode *temp = *top;
    *top = (*top)->next;
    free(temp);
    return digit;
}

// Función para inicializar una cola
void initializeQueue(struct QueueNode **front, struct QueueNode **rear) {
    *front = *rear = NULL;
}

// Función para insertar un dígito en la cola
void enqueue(struct QueueNode **front, struct QueueNode **rear, char digit) {
    struct QueueNode *newNode = (struct QueueNode *)malloc(sizeof(struct QueueNode));
    if (newNode == NULL) {
        perror("Error al asignar memoria para el nodo de la cola");
        exit(EXIT_FAILURE);
    }
    newNode->digit = digit;
    newNode->next = NULL;
    if (*rear == NULL) {
        *front = *rear = newNode;
    } else {
        (*rear)->next = newNode;
        *rear = newNode;
    }
}

// Función para eliminar y obtener el dígito frontal de la cola
char dequeue(struct QueueNode **front, struct QueueNode **rear) {
    if (*front == NULL) {
        fprintf(stderr, "La cola está vacía\n");
        exit(EXIT_FAILURE);
    }
    char digit = (*front)->digit;
    struct QueueNode *temp = *front;
    if (*front == *rear) {
        *front = *rear = NULL;
    } else {
        *front = (*front)->next;
    }
    free(temp);
    return digit;
}

// Función para liberar la memoria de la pila y la cola
void freeStackAndQueue(struct StackNode *top, struct QueueNode *front) {
    while (top != NULL) {
        struct StackNode *temp = top;
        top = top->next;
        free(temp);
    }

    while (front != NULL) {
        struct QueueNode *temp = front;
        front = front->next;
        free(temp);
    }
}

int main() {
    FILE *file;
    char filename[] = "numeros.txt";
    char line[100];

    struct StackNode *stack1, *stack2;
    struct QueueNode *queue1, *queue2;

    initializeStack(&stack1);
    initializeStack(&stack2);
    initializeQueue(&queue1, &queue2);

    file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error al abrir el archivo para lectura");
        exit(EXIT_FAILURE);
    }

    while (fgets(line, sizeof(line), file)) {
        // Leer números línea por línea desde el archivo
        int i = strlen(line) - 1;
        while (i >= 0 && (line[i] == '\n' || line[i] == '\r')) {
            i--;
        }

        for (; i >= 0; i--) {
            push(&stack1, line[i]);
        }

        // Realizar la suma dígito a dígito
        char carry = 0;
        while (stack1 != NULL || stack2 != NULL || carry != 0) {
            char digit1 = stack1 != NULL ? pop(&stack1) - '0' : 0;
            char digit2 = stack2 != NULL ? pop(&stack2) - '0' : 0;
            char sum = digit1 + digit2 + carry;

            carry = sum / 10;
            sum %= 10;

            enqueue(&queue1, &queue2, sum + '0');
        }

        // Copiar el resultado de la suma a stack2
        while (queue1 != NULL) {
            push(&stack2, dequeue(&queue1, &queue2));
        }
    }

    fclose(file);

    printf("La suma de los números enteros es:\n");
    while (stack2 != NULL) {
        printf("%c", pop(&stack2));
    }
    printf("\n");

    // Liberar memoria
    freeStackAndQueue(stack1, queue1);
    freeStackAndQueue(stack2, queue2);

    return 0;
}
