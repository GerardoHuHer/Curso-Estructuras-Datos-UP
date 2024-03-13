#include "colasCirc.h"

void menu() {
  int opc;
  do {
    std::cout << "Ingrese la opción deseada: \n? ";
    std::cin >> opc;
    switch (opc) {
    default:
      std::cout << "No se ingresó una opción válida" << std::endl;
      break;
    }
  } while (opc != 0);
}
