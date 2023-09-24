#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

// Número máximo de nodos en el grafo
#define V 6

// Función para encontrar el vértice con la distancia mínima no incluido en el conjunto de nodos visitados
int minDistance(int dist[], bool sptSet[]) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++) {
        if (!sptSet[v] && dist[v] < min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

// Función para imprimir la solución
void printSolution(int dist[]) {
    printf("Vértice   Distancia desde el origen\n");
    for (int i = 0; i < V; i++) {
        printf("%d \t\t %d\n", i, dist[i]);
    }
}

// Función que implementa el algoritmo de Dijkstra para encontrar el camino más corto desde un vértice origen
void dijkstra(int graph[V][V], int src) {
    int dist[V];     // La distancia más corta desde src a i
    bool sptSet[V];  // Conjunto de vértices cuya distancia más corta aún no se ha calculado

    // Inicializa todas las distancias como infinito y sptSet[] como falso
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        sptSet[i] = false;
    }

    // La distancia del vértice origen a sí mismo siempre es 0
    dist[src] = 0;

    // Encuentra el camino más corto para todos los vértices
    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, sptSet);

        // Marca el vértice seleccionado como visitado
        sptSet[u] = true;

        // Actualiza la distancia de los vértices adyacentes al vértice seleccionado
        for (int v = 0; v < V; v++) {
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && (dist[u] + graph[u][v] < dist[v])) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // Imprime la solución
    printSolution(dist);
}

int main() {
    int graph[V][V] = {
        {0, 4, 0, 0, 0, 0},
        {4, 0, 8, 0, 0, 0},
        {0, 8, 0, 7, 0, 4},
        {0, 0, 7, 0, 9, 14},
        {0, 0, 0, 9, 0, 10},
        {0, 0, 4, 14, 10, 0}
    };

    dijkstra(graph, 0);

    return 0;
}
