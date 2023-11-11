#include <stdio.h>
#include <stdlib.h>

void quicksort(double a[], int primero, int ultimo)
{
int i, j, central;
double pivote;
central = (primero + ultimo)/2;
pivote = a[central];
i = primero;
j = ultimo;
do {
while (a[i] < pivote) i++;
while (a[j] > pivote) j--;
if (i <= j)
{
double tmp;
tmp = a[i];
a[i] = a[j];
a[j] = tmp; /* intercambia a[i] con a[j] */
i++;
j--;
}
}while (i <= j);
if (primero < j)
quicksort(a, primero, j); /* mismo proceso con sublista izqda */
if (i < ultimo)
quicksort(a, i, ultimo); /* mismo proceso con sublista drcha */
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

   void quicksort(double a[], int primero, int ultimo);

    printf("Arreglo ordenado:\n");
    for (int i = 0; i < n; i++) {
        printf("%ld ", a[i]);
    }

    return 0;
}
