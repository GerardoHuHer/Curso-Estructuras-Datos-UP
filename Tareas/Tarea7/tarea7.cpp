#include "tarea7.h"
Lista::Lista() : head(nullptr), final(nullptr), nodo(nullptr) {}

void Lista::insertar_inicio(const int &nuevo) {
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

void Lista::insertar_intermedio(const int &nuevo) {
  Nodo *nodo_anterior;

  if (head == nullptr) {
    insertar_inicio(nuevo); // Lista vacía
    return;
  }
  if (head->dato >= nuevo) {
    insertar_inicio(nuevo);
    return;
  }
  if (final->dato <= nuevo) {
    insertar_final(nuevo);
    return;
  }
  nodo_anterior = head;
  while (nodo_anterior != final) {
    if (nodo_anterior->dato < nuevo) {

      nodo = new Nodo;

      nodo->dato = nuevo;

      nodo->sig = nodo_anterior->sig;
      nodo_anterior->sig = nodo;

      if (nodo == final) {
        final = nodo; // Si anterior es el último nodo
      }
      return;
    }
    nodo_anterior = nodo_anterior->sig;
  }
  return;
}

void Lista::insertar_final(const int &nuevo) {
  // Paso 1: Verificar si está vacío y si es así insertar al inicio.
  if (head == nullptr) {
    insertar_inicio(nuevo);
    return;
  }
  // Paso 2: Crear un nuevo nodo.
  nodo = new Nodo;
  // Paso 3: Asignar el nuevo dato al campo dato
  nodo->dato = nuevo;
  // Paso 4: Asignar la dirección.
  nodo->sig = nullptr;
  // Paso 5: Cambiar el enlace del nodo final al nuevo nodo.
  final->sig = nodo;
  // Paso 6: Cambiar final por el nuevo nodo
  final = nodo;
  return;
}

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

const int Lista::extraer_inicio() {
  if (head == nullptr) {
    return 0;
  }
  int extraida = 0;
  // Paso 1: Localizar nodo señalado por head inicial.
  nodo = head;
  // Paso 2: Tomamos la información del nodo extraer.
  extraida = nodo->dato;
  // Paso 3: Apuntar head al siguiente de head
  if (head == final) {
    final = nullptr;
  }
  head = nodo->sig;
  // Paso 4: Liberamos el nodo
  delete nodo;
  return extraida;
}

const int Lista::extraer_intermedio(const int &pos) {
  if (head == nullptr) {
    return -1;
  }
  int num;
  if (head->dato == pos) {
    num = extraer_inicio();
    return num;
  }
  if (final->dato == pos) {
    num = extraer_final();
    return num;
  }
  int extraida;
  bool encontrada = false;
  Nodo *nodo_anterior = nullptr;
  nodo = head;
  while (nodo != nullptr) {
    if (nodo->dato == pos) {
      encontrada = true;
      break;
    }
    nodo_anterior = nodo;
    nodo = nodo->sig;
  }
  if (!encontrada) {
    return -2;
  }
  extraida = nodo->dato;
  nodo_anterior->sig = nullptr;
  delete nodo;
  return extraida;
}

const int Lista::extraer_final() {
  if (head == nullptr) {
    return -1;
  }
  int extraida = 0;
  if (head == final) {
    extraida = extraer_inicio();
    return extraida;
  }
  // Paso 1: Localizar el nodo final y su anterior
  Nodo *nodo_anterior = nullptr;
  nodo = head;
  while (nodo != final) {
    nodo_anterior = nodo;
    nodo = nodo->sig;
  }
  // Paso 2: Extraer información
  extraida = nodo->dato;
  // Paso 3: Apuntar nodo anterior a nulo
  nodo_anterior->sig = nullptr;
  // Paso 4: Apuntar final al nodo anterior
  final = nodo_anterior;
  // Paso 5: Liberar nodo
  delete nodo;
  return extraida;
}

const Option enter_option() {
  int opc;
  std::cout << "Ingrese la opción deseada: \n"
            << " 1 - Insertar\n"
            << " 2 - Extraer\n"
            << " 3 - Extraer inicio\n"
            << " 4 - Extraer final\n"
            << " 5 - Mostrar\n"
            << " 6 - Salir\n? ";
  std::cin >> opc;
  return static_cast<Option>(opc);
}

void menu() {
  Option opc;
  int ret, pos;
  Lista list = Lista();
  while ((opc = enter_option()) != Option::EXIT) {
    switch (opc) {
    case Option::INSERTAR:
      std::cout << "Ingrese el número que desea ingresar: \n? ";
      std::cin >> pos;
      list.insertar_intermedio(pos);
      break;
    case Option::EXTRAER:
      std::cout << "Ingrese el número que desea extraer \n? ";
      std::cin >> pos;
      ret = list.extraer_intermedio(pos);
      if (ret == -1)
        std::cout << "La lista está vacía" << std::endl;
      if (ret == -2)
        std::cout << "No está ese número en la lista" << std::endl;
      else
        std::cout << "El número extraído es " << ret << std::endl;
      break;
    case Option::EXTRAER_INICIO:
      ret = list.extraer_inicio();
      if (ret == -1)
        std::cout << "La lista está vacía" << std::endl;
      if (ret == -2)
        std::cout << "No está ese número en la lista" << std::endl;
      else
        std::cout << "El número extraído es " << ret << std::endl;
      break;
    case Option::EXTRAER_FINAL:
      ret = list.extraer_final();
      if (ret == -1)
        std::cout << "La lista está vacía" << std::endl;
      if (ret == -2)
        std::cout << "No está ese número en la lista" << std::endl;
      else
        std::cout << "El número extraído es " << ret << std::endl;
      break;
    case Option::DISPLAY:
      list.display();
      break;
    default:
      std::cout << "Hasta luego" << std::endl;
      break;
    }
  }
}
