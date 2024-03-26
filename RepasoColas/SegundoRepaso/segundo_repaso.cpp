#include "segundo_repaso.h"

Cola::Cola() : inicio(NULL), final(NULL), nodo(NULL) {}

void Cola::insertar(int nuevo) {
  nodo = new Nodo;
  nodo->entero = nuevo;
  nodo->sig = NULL;
  if (inicio == NULL) {
    inicio = nodo;
  }

  if (final != NULL) {
    final->sig = nodo;
  }
  final = nodo;
}

int Cola::extraer() {
  if (inicio == NULL) {
    return -1;
  }
  int aux;
  nodo = inicio;
  inicio = inicio->sig;
  if (inicio == NULL) {
    final = NULL;
  }
  aux = nodo->entero;
  delete nodo;
  return aux;
}

void Cola::mostrar() {
  if (inicio == NULL) {
    std::cout << "La cola está vacía" << std::endl;
  }
  nodo = inicio;
  std::cout << "===== COLA =====" << std::endl;
  while (nodo != NULL) {
    std::cout << "\t" << nodo->entero;
    if (nodo == inicio)
      std::cout << " <= Inicio";
    if (nodo == final)
      std::cout << " <= Final";
    std::cout << std::endl;
    nodo = nodo->sig;
  }
}

void menu() {
  int opc;
  Cola cola = Cola();
  do {
    std::cout << "\n1) Insertar \n2) Extraer \n3) Mostrar \n4) Salir"
              << std::endl;
    std::cout << "Ingrese una opción \n? ";
    std::cin >> opc;
    switch (opc) { 
    case 1:
      std::cout << "Ingrese un número: \n? ";
      std::cin >> opc;
      cola.insertar( opc);
      break;
    case 2:
      opc = cola.extraer();
      if(opc == -1) {
        std::cout << "La cola está llena" << std::endl;
      }else {        
        std::cout << "El valor extraído es: " << opc << std::endl;
      }
      break;
    case 3:
      cola.mostrar();
      break;
    case 4:
      std::cout << "Hasta luego" << std::endl;
      break;
    default:
      std::cout << "No se ingresó un valor válido" << std::endl;
      break;
    }
  } while (opc != 4);
}
