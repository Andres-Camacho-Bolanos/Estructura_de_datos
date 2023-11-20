#include <stdio.h>
#include <string.h>

#define TABLE_SIZE 100

// Función de hash por módulo (división)
unsigned int hashFunction(char *key) {
    unsigned int hash = 0;
    int length = strlen(key);

    for (int i = 0; i < length; i++) {
        hash = hash + key[i];
    }

    return hash % TABLE_SIZE;
}

int main() {
    char input[100];

    printf("Ingrese una cadena: ");
    scanf("%s", input);

    unsigned int hashValue = hashFunction(input);

    printf("La clave \"%s\" tiene un valor hash de: %u\n", input, hashValue);

    return 0;
}
