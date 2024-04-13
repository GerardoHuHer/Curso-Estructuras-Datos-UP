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

const int Lista::insertar_intermedio(const std::string &nuevo,
                                     const std::string &pos) {
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

const int Lista::insertar_final(const std::string &nuevo) {
  // Paso 1: Verificar si está vacío y si es así insertar al inicio.
  if (head == nullptr) {
    insertar_inicio(nuevo);
    return -1;
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
  return 0;
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

const std::string Lista::extraer_inicio() {
  if (head == nullptr) {
    return "";
  }
  std::string extraida = "";
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

const std::string Lista::extraer_intermedio(const std::string &pos) {
  if (head == nullptr) {
    return "";
  }
  std::string extraida;
  if (head == final) {
    extraida = extraer_inicio();
    return extraida;
  }
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
  extraida = nodo->dato;
  nodo_anterior->sig = nullptr;
  delete nodo;
  if (!encontrada) {
    return "NE";
  }
  return extraida;
}
const std::string Lista::extraer_final() {
  if (head == nullptr) {
    return "";
  }
  std::string extraida = "";
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
            << " 1 - Insertar al principio\n"
            << " 2 - Insertar al final\n"
            << " 3 - Insertar\n"
            << " 4 - Insertar al principio\n"
            << " 5 - Insertar al final\n"
            << " 6 - Insertar\n"
            << " 7 - Mostrar\n"
            << " 8 - Salir\n? ";
  std::cin >> opc;
  return static_cast<Option>(opc);
}

void menu() {
  Option opc;
  std::string ret, pos;
  int codigo;
  Lista list = Lista();
  while ((opc = enter_option()) != Option::EXIT) {
    switch (opc) {
    case Option::INSERTAR_INICIO:
      std::cout << "Ingrese el nombre que desea insertar: \n? ";
      std::cin >> ret;
      list.insertar_inicio(ret);
      break;
    case Option::INSERTAR_FINAL:

      std::cout << "Ingrese el nombre que desea insertar: \n? ";
      std::cin >> ret;
      codigo = list.insertar_final(ret);
      if (codigo == -1) {
        std::cout << "Lista vacía se insertó al inicio" << std::endl;
      }
      if (codigo == 0) {
        std::cout << "Se insertó correctamente" << std::endl;
      }
      break;
    case Option::INSERTAR:

      std::cout << "Ingrese el nombre que desea insertar: \n? ";
      std::cin >> ret;
      list.display();
      std::cout << "Detrás de que palabra desea insertar la palabra: \n? ";
      std::cin >> pos;
      codigo = list.insertar_intermedio(ret, pos);
      if (codigo == -1) {
        std::cout << "Lista vacía se insertó al inicio" << std::endl;
      }
      if (codigo == -2) {
        std::cout << "No se encontró el valor, se insertó al final"
                  << std::endl;
      }
      if (codigo == 0) {
        std::cout << "Se insertó correctamente" << std::endl;
      }
      break;
    case Option::DISPLAY:
      list.display();
      break;
    case Option::EXTRAER_INICIO:
      ret = list.extraer_inicio();
      if (ret == "") {
        std::cout << "La lista está vacía" << std::endl;
      } else {
        std::cout << "La palabra extraída es " << ret << std::endl;
      }
      break;
    case Option::EXTRAER_FINAL:
      ret = list.extraer_final();
      if (ret == "") {
        std::cout << "La lista está vacía" << std::endl;
      } else {
        std::cout << "La palabra extraída es " << ret << std::endl;
      }
      break;
    case Option::EXTRAER:
      std::cout << "Ingrese la palabra que desea extraer: \n? ";
      std::cin >> pos;
      ret = list.extraer_intermedio(pos);
      if (ret == "") {
        std::cout << "La lista está vacía" << std::endl;
      } else if (ret == "NE") {
        std::cout << "No se encontró la palabra" << std::endl;
      } else {
        std::cout << "La palabra extraída es " << ret << std::endl;
      }
      break;
    default:
      std::cout << "Hasta luego" << std::endl;
      break;
    }
  }
}
