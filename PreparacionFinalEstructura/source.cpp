#include "repaso.h"

int main() {
  char main_opc;
  do {
    std::cout << "Quiere trabajar con arboles, grafos, salir: [a/g/s]: \n> ";
    std::cin >> main_opc;
    switch (main_opc) {
    case 'a':
      menu();
      break;
    case 'g':
      menuGrafo();
      break;
    case 's':
      std::cout << "Hasta luego" << std::endl;
      break;
    default:
      std::cout << "No se ingresó un opción válida" << std::endl;
      break;
    }
  } while (main_opc != 's');
  return 0;
}
