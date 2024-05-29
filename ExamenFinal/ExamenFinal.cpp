#include "ExamenFinal.h"

Option get_option() {
  int opc;
  std::cout << "\n1. Insertar \n2. Buscar \n3. In-Order \n4. Pre-Order \n5. "
               "Post-Order \n6. Salir"
            << std::endl;
  std::cout << "Ingrese la opción deseada: \n> ";
  std::cin >> opc;
  return static_cast<Option>(opc);
}
