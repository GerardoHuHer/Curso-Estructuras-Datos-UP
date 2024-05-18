#include "RepasoArboles.h"

Option get_option() {
  int opc;

  std::cout << "\n1. Insertar \n2. In-Order \n3. "
               "Pre-Order \n4. Post-Order \n5. Mostrar \n6. Buscar \n7. Salir"
            << std::endl;
  std::cout << "Ingrese la opción deseada \n> ";
  std::cin >> opc;
  return static_cast<Option>(opc);
}

