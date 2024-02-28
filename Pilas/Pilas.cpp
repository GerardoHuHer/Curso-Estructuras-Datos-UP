#include "Pilas.h"

Pila::Pila(){
  tope = NULL;
}

int Pila::Consultar(){
  int num;
  // Paso 1: Verificar si hay valores en la pila
  if(tope == NULL)
    return -1;
  // Paso 2: Motrar los datos del tope
  num = tope->dato;
  return num;
}

void Pila::Insertar(int nuevo){
  // Paso 1: Crear nodo
  nodo = new Entero;
  // Paso 2: Registrar información
  nodo->dato = nuevo;
  // Paso 3: Enlace apuntarlo a tope
  nodo->anterior = tope;
  // Paso 4: Apuntar tope al nuevo nodo
  tope = nodo;
}

int Pila::Extraer(){
  Entero *extraido;
  int num;
  // Paso 1: Verificar si hay valores en la pila
  if(tope == NULL)
    return -1;
  // Paso 2: Extraer información del tope en extraido
  extraido = tope;
  // Paso 3: Descender tope
  tope = tope->anterior;
  //Paso 4: Entregar los datos extraídos
  num = extraido->dato;
  delete extraido;
  return num;
}
