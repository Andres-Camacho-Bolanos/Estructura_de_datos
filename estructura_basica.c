#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estructura de datos para representar una actividad
typedef struct Actividad {
	int id;
	char nombre[100];
	int prioridad;
	// Aquí podrías agregar información adicional si es necesario
} Actividad;

// Lista circular doblemente enlazada para las actividades
typedef struct Node {
	Actividad dato;
	struct Node* next;
	struct Node* prev;
} Node;

// Función para agregar una actividad a la lista circular
void addActividad(Node** head, Actividad activity) {
	// Implementa la lógica para agregar la actividad a la lista
}

// Función para mostrar las actividades en la lista
void displayActividades(Node* head) {
	// Implementa la lógica para recorrer y mostrar las actividades
}

int main() {
	// Inicialización de la lista circular de actividades
	Node* head = NULL;

	// Agregar las 8 actividades predeterminadas
	Actividad actividades[] = {
    	{1, "Bañarse", 3},
    	{2, "Gimnasio", 4},
    	{3, "Comprar alimentos", 2},
    	{4, "Pasear a tu mascota", 3},
    	{5, "Trabajo", 5},
    	{6, "Proyectos personales", 4},
    	{7, "Tiempo con pareja", 5},
    	{8, "Tiempo recreativo", 3}
	};

	for (int i = 0; i < 8; i++) {
    	addActividad(&head, actividades[i]);
	}

	// Aquí puedes implementar las demás estructuras de datos y funcionalidades

	// Por ejemplo, podrías implementar la cola para las alarmas, grafos para la ruta ideal, árboles para actividades secundarias y pilas para el marcador de actividades personales.

	// Luego, puedes implementar la lógica para que el usuario interactúe con el sistema y obtenga recomendaciones de rutina.

	return 0;
}
