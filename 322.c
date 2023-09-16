#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definición de la estructura del nodo de la lista enlazada
struct Node {
    char word[50];
    struct Node *next;
};

// Función para agregar una palabra al final de la lista enlazada
void addWord(struct Node **head, const char *word) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        perror("Error al asignar memoria para el nodo");
        exit(EXIT_FAILURE);
    }
    strcpy(newNode->word, word);
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node *current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Función para eliminar una palabra de la lista enlazada
void deleteWord(struct Node **head, const char *word) {
    if (*head == NULL) {
        printf("La lista está vacía. No se puede eliminar.\n");
        return;
    }

    if (strcmp((*head)->word, word) == 0) {
        struct Node *temp = *head;
        *head = (*head)->next;
        free(temp);
        printf("'%s' eliminada de la lista.\n", word);
        return;
    }

    struct Node *current = *head;
    while (current->next != NULL && strcmp(current->next->word, word) != 0) {
        current = current->next;
    }

    if (current->next != NULL) {
        struct Node *temp = current->next;
        current->next = current->next->next;
        free(temp);
        printf("'%s' eliminada de la lista.\n", word);
    } else {
        printf("'%s' no se encontró en la lista.\n", word);
    }
}

// Función para imprimir la lista enlazada
void printList(struct Node *head) {
    struct Node *current = head;
    while (current != NULL) {
        printf("%s ", current->word);
        current = current->next;
    }
    printf("\n");
}

// Función para escribir la lista enlazada en un archivo
void writeToFile(struct Node *head, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        perror("Error al abrir el archivo para escritura");
        exit(EXIT_FAILURE);
    }

    struct Node *current = head;
    while (current != NULL) {
        fprintf(file, "%s ", current->word);
        current = current->next;
    }

    fclose(file);
    printf("Lista escrita en el archivo '%s'.\n", filename);
}

// Función principal
int main() {
    struct Node *wordList = NULL;
    char filename[] = "palabras.txt";

    // Abrir el archivo para lectura
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error al abrir el archivo para lectura");
        exit(EXIT_FAILURE);
    }

    char word[50];

    // Leer palabras del archivo y agregarlas a la lista enlazada
    while (fscanf(file, "%s", word) != EOF) {
        addWord(&wordList, word);
    }

    fclose(file);

    printf("Palabras en el archivo:\n");
    printList(wordList);

    // Agregar nuevas palabras
    addWord(&wordList, "nueva1");
    addWord(&wordList, "nueva2");

    printf("Palabras después de agregar nuevas palabras:\n");
    printList(wordList);

    // Eliminar una palabra
    deleteWord(&wordList, "Centurión");

    printf("Palabras después de eliminar 'Centurión':\n");
    printList(wordList);

    // Escribir la lista en el archivo
    writeToFile(wordList, filename);

    // Liberar memoria de la lista enlazada
    while (wordList != NULL) {
        struct Node *temp = wordList;
        wordList = wordList->next;
        free(temp);
    }

    return 0;
}
