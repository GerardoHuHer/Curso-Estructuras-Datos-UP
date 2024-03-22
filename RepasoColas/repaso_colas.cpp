#include "repaso_colas.h"

Cola::Cola(): inicio(NULL), final(NULL), nodo(NULL) {}

void Cola::insertar(Nodo nuevo){
  nodo = new Nodo;
  *nodo = nuevo;
  nodo->sig = NULL;
  if(inicio == NULL){
    inicio = nodo;
  }
  if(final != NULL){
    final -> sig = nodo;
  }
  final = nodo; 
}

std::string Cola::extraer(){
  if(inicio == NULL){
    return " ";
  }
  std::string aux;
  nodo = inicio;
  aux = nodo->titulo;
  inicio = inicio->sig; 
  if(inicio == NULL){
    final = NULL;
  }
  delete nodo;
  return aux;
}

void Cola::mostrar(){
  nodo = inicio;
  std::cout << "========== COLA ==========" << std::endl;
  std::cout << "\tAUTOR \t TITULO" << std::endl;
  while(nodo != NULL){
    std::cout << "\t" << nodo->autor << "\t" << nodo->titulo;
    if(nodo == inicio) std::cout << " <= Inicio";
    if(nodo == final) std::cout << " <= Final";
    std::cout << std::endl;
    nodo = nodo->sig;
  }
}

void menu(){
  int opc;
  Cola cola = Cola();
  std::string ret;
  Nodo aux;
  do {
    std::cout << "\n1) Insertar \n2) Extraer \n3) Mostrar \n4) Salir" << std::endl;
    std::cout << "Ingrese la opción deseada \n? ";
    std::cin >> opc;
    switch (opc) {
    case 1:
      std::cout << "Ingrese el nombre del autor \n? ";
      std::cin.ignore();
      std::getline(std::cin, aux.autor);
      std::cout << "Ingrese el título del libro \n? ";
      std::cin.ignore();
      std::getline(std::cin, aux.titulo);     
      cola.insertar(aux);
      break;
    case 2:
      ret = cola.extraer();
      if(ret == " "){
        std::cout << "La cola está vacía" << std::endl;
        break;
      }
      std::cout << "El título extraído es: " << ret << std::endl;
      break;
    case 3:
      cola.mostrar();
      break;
    case 4:
      std::cout << "Hasta luego" << ret << std::endl;
      break;
    default:
      std::cout << "Inserte un valor válido" << ret << std::endl;
      break;
    }
  
  }while (opc != 4);
}
