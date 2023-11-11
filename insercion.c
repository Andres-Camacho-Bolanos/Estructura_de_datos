#include <stdio.h>
#include <stdlib.h>

void ordInsercion (int a[], int n)
{
int i, j;
int aux;
for (i = 1; i < n; i++)
{
/* indice j explora la sublista a[i-1]..a[0] buscando la
posicion correcta del elemento destino, lo asigna a a[j] */
j = i;
aux = a[i];
/* se localiza el punto de inserción explorando hacia abajo */
while (j > 0 && aux < a[j-1])
{
/* desplazar elementos hacia arriba para hacer espacio */
a[j] = a[j-1];
j--;
}
a[j] = aux;
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

   void ordInsercion(int a[], int n);

    printf("Arreglo ordenado:\n");
    for (int i = 0; i < n; i++) {
        printf("%ld ", a[i]);
    }

    return 0;
}
