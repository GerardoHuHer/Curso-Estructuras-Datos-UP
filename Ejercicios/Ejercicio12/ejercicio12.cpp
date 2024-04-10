#include "ejercicio12.h"

Lista::Lista() : head(nullptr), final(nullptr), nodo(nullptr) {}

void Lista::insertar_inicio(const std::string &nuevo) {
  // Paso 1: Crear nuevo nodo
  nodo = new Nodo;
  // Pase 2: Llenar campos de información
  nodo->dato = nuevo;
  // Paso 3: Llenar el campo de enlace.
  nodo->sig = head;
  // Paso 4: Igualar la cabecera a dirección del nodo nuevo
  head = nodo;
  // Paso 5: Si es primer nodo igualar el final a dirección del nodo nuevo
  if (final == nullptr)
    final = nodo;
}

int Lista::insertar_intermedio(std::string nuevo, std::string pos) {
  Nodo *nodo_anterior;
  bool encontrado = false;

  if (head == nullptr) {
    insertar_inicio(nuevo); // Lista vacía
    return -1;
  }

  nodo_anterior = head;

  while (nodo_anterior != final) {
    if (nodo_anterior->dato == pos) {
      encontrado = true;

      nodo = new Nodo;

      nodo->dato = nuevo;

      nodo->sig = nodo_anterior->sig;
      nodo_anterior->sig = nodo;

      if (nodo == final) {
        final = nodo; // Si anterior es el último nodo
      }
      return 0;
    }
    nodo_anterior = nodo_anterior->sig;
  }
  if (encontrado == false) {
    insertar_final(nuevo);
    return -2; // No se encontró
  }
  return 0;
}

int Lista::insertar_final(std::string) {}

void Lista::display() {
  if (head == nullptr) {
    std::cout << "\nLISTA VACÍA" << std::endl;
    return;
  }
  nodo = head;
  std::cout << "\nLISTA" << std::endl;
  while (nodo != nullptr) {
    std::cout << "\t" << nodo->dato;
    if (nodo == head)
      std::cout << " <= HEAD";
    if (nodo == final)
      std::cout << " <= FINAL";
    std::cout << std::endl;
    nodo = nodo->sig;
  }
}

Option enter_option() {
  int opc;
  std::cout << "Ingrese la opción deseada: \n"
            << " 1 - Insertar al principio\n"
            << " 2 - Insertar al final\n"
            << " 3 - Insertar\n"
            << " 4 - Mostrar\n"
            << " 5 - Salir\n? ";
  std::cin >> opc;
  return static_cast<Option>(opc);
}

void menu() {
  Option opc;
  std::string ret;
  int retn;
  Lista list = Lista();
  while ((opc = enter_option()) != Option::EXIT) {
    switch (opc) {
    case Option::INSERTAR_INICIO:
      std::cout << "Ingrese el nombre que desea insertar: \n? ";
      std::cin >> ret;
      list.insertar_inicio(ret);
      break;
    case Option::INSERTAR_FINAL:
      break;
    case Option::INSERTAR:
      break;
    case Option::DISPLAY:
      list.display();
      break;
    default:
      break;
    }
  }
}
