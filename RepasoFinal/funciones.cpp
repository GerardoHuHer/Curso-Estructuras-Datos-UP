#include "main.h"
#include "grafo.h"
#include "arbol.h"

Tree_option get_option() {
  int opc;
  std::cout << "\n1. Insertar\n2. Buscar\n3. In Order\n4. Pre Order\n5. Post "
               "Order\n6. Salir"
            << std::endl;
  std::cout << "Ingrese la opción deseada: \n> ";
  std::cin >> opc; return static_cast<Tree_option>(opc);
}


void menu(){

  menuArbol<int>();  
}
