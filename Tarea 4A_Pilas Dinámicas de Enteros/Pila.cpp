#include "Pila.h"

Pila::Pila()
{
	tope = NULL;
}

int Pila::Consultar()
{
	int num;

	/* Paso 1: Verificar si hay valores en la pila */
	if (tope == NULL)
		return -1;		// Pila vacía. No se muestra nada
	/* Paso 2: Mostrar los datos del tope */
	num = tope->dato;

	return num;
}

int Pila::Extraer()
{
	Entero* extraido;
	int num;

	/* Paso 1: Verificar si hay valores en la pila */
	if (tope == NULL)
		return -1;		// Pila vacía. No se extrae nada
	/* Paso 2: Extraer información del tope en extraido */
	extraido = tope;
	/* paso 3: Descender el tope */
	tope = tope->anterior;
	/* Paso 4: Entregar los datos extraidos */
	num = extraido->dato;
	/* Paso 5: Liberar el nodo extraido */
	delete extraido;

	return num;
}

void Pila::Insertar(int nuevo)
{
	/* Paso 1: Crear un nodo */
	nodo = new Entero;
	/* Paso 2: Registrar información */
	nodo->dato = nuevo;
	/* Paso 3: Enlace apuntarlo a tope */
	nodo->anterior = tope;
	/* Paso 4: Apuntar tope al nuevo nodo */
	tope = nodo;
}

void Pila::Mostrar()
{
	cout << "\nPILA:\n" << endl;

	if (tope == NULL)
	{
		cout << "\tPila VACIA" << endl;
		return;
	}

	nodo = tope;
	while (nodo != NULL)
	{
		cout << "\t" << nodo->dato << "\t" << nodo->anterior;
		if (nodo == tope) cout << "\t" << "<== Tope";
		cout << endl;

		nodo = nodo->anterior;
	}
}