#include <stdio.h>
#include <stdlib.h>

void ordSeleccion (double a[], int n)
{
int indiceMenor, i, j;
/* ordenar a[0]..a[n-2] y a[n-1] en cada pasada */
for (i = 0; i < n-1; i++)
{
/* comienzo de la exploración en índice i */
indiceMenor = i;
/* j explora la sublista a[i+1]..a[n-1] */
for (j = i+1; j < n; j++)
if (a[j] < a[indiceMenor])
indiceMenor = j;
/* situa el elemento mas pequeño en a[i] */
if (i != indiceMenor){
    
    double aux = a[i];
a[i] = a[indiceMenor];
a[indiceMenor] = aux ;

         }
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

   void ordSeleccion(double a[], int n);

    printf("Arreglo ordenado:\n");
    for (int i = 0; i < n; i++) {
        printf("%ld ", a[i]);
    }

    return 0;
}
