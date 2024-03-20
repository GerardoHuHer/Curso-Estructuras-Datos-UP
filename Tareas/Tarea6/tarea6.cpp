#include "tarea6.h"
#include <string>

Cola::Cola(): inicio(NULL), final(NULL), nodo(NULL){}

void Cola::insertar(const Camion& nuevo){
  nodo = new Camion();
  *nodo = nuevo;
  nodo->sig = NULL;
  if(inicio == NULL){
    inicio = nodo;
  }
  if(final != NULL){
    final->sig = nodo;
  }
  final = nodo;
}

std::string Cola::extraer(){
  if(inicio == NULL){
    return " ";
  }
  std::string aux;
  nodo = inicio;
  aux = nodo->placas;
  inicio = inicio->sig;
  if(inicio == NULL){
    final = NULL;
  }
  delete nodo;
  return aux;
}

void Cola::mostrar(){
  nodo = inicio;
  std::cout << " =============== COLA ===============" << std::endl;
  std::cout << "\tPLACAS \t PRODUCTO" << std::endl;
  while(nodo != NULL){
    std::cout << "\t" << nodo->placas << "\t" << nodo->producto;
    if(nodo == inicio) std::cout << " <= Inicio";
    if(nodo == final) std::cout << " <= Final";
    std::cout << std::endl;
    nodo = nodo->sig;
  }
}

void menu(){
  int opc;
  Camion aux;
  std::string ret;
  Cola cola = Cola();
  do {
  std::cout << " =============== MENU ===============" << std::endl;
    std::cout << "\n1) Insertar \n2) Extraer \n3) Mostrar \n4) Salir" << std::endl;
    std::cout << "Ingrese una opción \n? "; 
    std::cin >> opc;
    switch (opc) {
    case 1:
      std::cout << "Ingrese la placa del camión: \n? ";
      std::cin >> aux.placas;
      std::cout << "Ingrese el producto que lleva el camión: \n? ";
      std::cin.ignore();
      std::getline(std::cin, aux.producto);
      cola.insertar(aux);
      std::cout << "\n\tSe ha ingresado correctamente" << std::endl;
      break;
    case 2:
      ret = cola.extraer();
      if(ret == " "){
        std::cout << "\n\tLa cola está llena" << std::endl;
      }
      else{
        std::cout << "\n\tLa placa del camión extraído es: " << ret << std::endl;
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

  }while (opc != 4);
}
