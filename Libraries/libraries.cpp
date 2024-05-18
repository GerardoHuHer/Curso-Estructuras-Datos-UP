#include "libraries.h"


Persona::Persona(int num, std::string nombre){
  this->id = num;
  this->name = nombre;
}

Option get_option(){
  int opc;
  std::cout << "\n1- Insertar \n2- Extraer \n3- Consultar \n4- Tamaño \n5- Salir";
  std::cout << "Ingrese la opción deseada \n> ";
  std::cin >> opc;
  return static_cast<Option>(opc);
}

void menu(){
  std::stack<Persona> pila;
  Option opc;
  int id; 
  std::string name;
  while((opc = get_option()) != Option::Salir){
    switch (opc) {
      case Option::Insertar:

        Persona aux = Persona()
        pila.push()
        break;
    }
  }
}
