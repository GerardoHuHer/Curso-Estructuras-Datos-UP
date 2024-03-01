#include "Ejercicio7.h"
#include <string>

Pila::Pila(){
  tope = NULL;
}

void Pila::Ingresar(Persona nuevo){
  nodo = new Persona;
  *nodo = nuevo;
  nodo -> anterior = tope;
  tope = nodo;
}

Persona Pila::Extraer(){
  Persona* extra;
  Persona aux; 
  if(tope == NULL) return aux;
  extra = tope;
  tope = tope -> anterior;
  aux = *extra;
  delete extra;
  return aux;
}

void Pila::Mostrar(){
  if (tope == NULL) return;
  nodo = tope;
  while(nodo != NULL){
    std::cout <<  "-------------------------------------" << std::endl;
    std::cout << "\t" << "Clave: "<< nodo->clave << std::endl; 
    std::cout << "\t" << "Nombre: "<< nodo->nombre; 
    if(tope == nodo) 
      std::cout << "                    <= tope" << std::endl;
    if(tope != nodo) std::cout << std::endl;
    std::cout << "\t" << "Sueldo: "<< nodo->sueldo << std::endl; 
    nodo = nodo->anterior;
  }  
  std::cout <<  "-------------------------------------" << std::endl;
  delete nodo;
}

void menu(){
  Pila obj1;
  Persona ret;
  int opc {0};
  while(opc != 4){
    std::cout << "\n1) Ingresar \n2) Extraer \n3) Mostrar \n4) Salir" << std::endl;
    std::cin >> opc;
    switch (opc) {
      case 1:
      std::cout << "Ingrese la clave de su empleado: \n? ";
      std::cin >> ret.clave;
      std::cin.ignore();
      std::cout << "Ingrese el nombre de su empleado: \n? ";
      std::getline(std::cin, ret.nombre);
      std::cout << "Ingrese el sueldo de su empleado: \n? ";
      std::cin >> ret.sueldo;
      obj1.Ingresar(ret);
      break;
      case 2:
      ret = obj1.Extraer();
      std::cout << "\t" << "Clave: "<< ret.clave << std::endl; 
      std::cout << "\t" << "Nombre: "<< ret.nombre << std::endl; 
      std::cout << "\t" << "Sueldo: "<< ret.sueldo << std::endl; 
      break;
      case 3:
      obj1.Mostrar();
      break;
      case 4:
      std::cout << "Hasta luego" << std::endl;
      break;
      default:
      std::cout << "No se ingresó una opción válida" << std::endl;
      break;
    }
  }
}
