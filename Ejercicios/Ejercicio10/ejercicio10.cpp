#include "ejercicio10.h"
#include <string>

Cola::Cola() : inicio(NULL), final(NULL) {}

void Cola::insertar(std::string frase) {
  nodo = new Frase();
  nodo->frase = frase;
  nodo->sig = NULL;
  if (inicio == NULL) {
    inicio = nodo;
  }
  if (final != NULL) {
    final->sig = nodo;
  }
  final = nodo;
}

std::string Cola::extraer() {
  std::string aux;
  if (inicio == NULL) {
    return " ";
  }
  nodo = inicio;
  aux = nodo->frase;
  inicio = inicio->sig;
  if (inicio == NULL) {
    final = NULL;
  }
  delete nodo;
  return aux;
}

std::string Cola::consultar() {
  if (inicio == NULL) {
    return " ";
  }
  return inicio->frase;
}

void Cola::mostrar(){
  nodo = inicio;
  while (nodo != NULL) {
    std::cout << "\t" << nodo->frase;
    if (nodo == inicio) // Accede a inicio desde el objeto Cola pasado como argumento
      std::cout << " <= Inicio";
    if (nodo == final) // Accede a final desde el objeto Cola pasado como argumento
      std::cout << " <= Final";
    std::cout << std::endl;
    nodo = nodo->sig;
  }
}

std::ostream& operator<<(std::ostream& os, const Cola& a){
  Frase* nodo = a.inicio; // Accede a inicio desde el objeto Cola pasado como argumento
  while (nodo != NULL) {
    os << "\t" << nodo->frase;
    if (nodo == a.inicio) // Accede a inicio desde el objeto Cola pasado como argumento
      os << " <= Inicio";
    if (nodo == a.final) // Accede a final desde el objeto Cola pasado como argumento
      os << " <= Final";
    os << std::endl;
    nodo = nodo->sig;
  }
  return os;
}


void menu() {
  int opc;
  std::string ret;
  Cola cola = Cola();
  do {
    std::cout
        << "\n1) Insertar \n2) Extraer \n3) Mostrar \n4) Consultar \n5) Salir"
        << std::endl;
    std::cout << "Ingrese la opción deseada: \n? ";
    std::cin >> opc;
    switch (opc) {
    case 1:
      std::cout << "Ingrese la frase que desea ingresar: " << std::endl;
      std::cin.ignore();
      std::getline(std::cin, ret);
      cola.insertar(ret);
      break;
    case 2:
      ret = cola.extraer();
      if (ret == " ")
        std::cout << "La cola está vacía: " << std::endl;
      else 
        std::cout << "La frase extraída es: " << std::endl << "\t" << ret;
      break;
    case 3:
      // cola.mostrar();
      mostrar(cola);
      break;
    case 4:
      ret = cola.consultar();
      if (ret == " ")
        std::cout << "La cola está vacía" << std::endl;
      else 
        std::cout << "La primera frase es: " << std::endl << "\t" << ret;
      break;
    case 5:
      std::cout << "Hasta luego" << std::endl;
      break;
    default:
      std::cout << "No se ingresó una opción válida" << std::endl;
      break;
    }
  } while (opc != 5);
}

template<typename T>
void mostrar(const T& a){
  std::cout << a << std::endl;
  
}
