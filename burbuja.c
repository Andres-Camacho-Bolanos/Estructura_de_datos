#include <stdio.h>
#include <stdlib.h>

void ordBurbuja2(long a[], int n) {
    int i, j;
    int indiceIntercambio;
    i = n - 1;

    while (i > 0) {
        indiceIntercambio = 0;
        
        for (j = 0; j < i; j++) {
            if (a[j + 1] < a[j]) {
                long aux = a[j];
                a[j] = a[j + 1];
                a[j + 1] = aux;
                indiceIntercambio = j;
            }
        }
        
        i = indiceIntercambio;
    }
}

int main() {
    int n;
    
    printf("Ingrese la cantidad de elementos: ");
    scanf("%d", &n);
    
    if (n <= 0) {
        printf("El tamaño del arreglo debe ser mayor que 0.\n");
        return 1; // Terminar el programa con un código de error.
    }
    
    long a[n];
    
    printf("Ingrese los elementos del arreglo:\n");
    for (int i = 0; i < n; i++) {
        printf("Elemento %d: ", i + 1);
        scanf("%ld", &a[i]);
    }

    ordBurbuja2(a, n);

    printf("Arreglo ordenado:\n");
    for (int i = 0; i < n; i++) {
        printf("%ld ", a[i]);
    }

    return 0;
}
