#include <stdio.h>
#include <stdlib.h>

void ordenacionShell(double a[], int n)
{
int intervalo, i, j, k;
intervalo = n / 2;
while (intervalo > 0)
{
for (i = intervalo; i < n; i++)
{
j = i - intervalo;
while (j >= 0)
{
k = j + intervalo;
if (a[j] <= a[k])
j = -1; /* así termina el bucle, par ordenado */
else
{
double temp;
temp = a[j];
a[j] = a[k];
a[k] = temp;
j -= intervalo;
}
}
}
intervalo = intervalo / 2;
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

   void ordenacionShelld(double a[], int n);

    printf("Arreglo ordenado:\n");
    for (int i = 0; i < n; i++) {
        printf("%ld ", a[i]);
    }

    return 0;
}
