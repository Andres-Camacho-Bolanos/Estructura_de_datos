#include <stdio.h>

void Binaria_recursivo(int V[], int IZQ, int DER, int X) {
    if (IZQ >= DER) {
        printf("%d No se encuentra en el arreglo\n", X);
    } else {
        int CEN = IZQ + (DER - IZQ) / 2;
        
        if (X == V[CEN]) {
            printf("El dato buscado se encuentra en la posición %d\n", CEN);
        } else {
            printf("Comparando %d con %d en la posición %d\n", X, V[CEN], CEN);
            if (X > V[CEN]) {
                printf("Buscando en la mitad derecha del arreglo\n");
                Binaria_recursivo(V, CEN + 1, DER, X);
            } else {
                printf("Buscando en la mitad izquierda del arreglo\n");
                Binaria_recursivo(V, IZQ, CEN - 1, X);
            }
        }
    }
}

int main() {
    int arreglo[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int tamaño = sizeof(arreglo) / sizeof(arreglo[0]);

    printf("Ingrese un número para buscar en el arreglo: ");
    int dato_a_buscar;
    scanf("%d", &dato_a_buscar);

    Binaria_recursivo(arreglo, 0, tamaño - 1, dato_a_buscar);

    return 0;
}
