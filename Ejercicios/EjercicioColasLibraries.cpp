#include "EjercicioColasLibraries.h"
#include <queue>
#include <string>

Option get_option() {
  int opc;
  std::cout << "\n1. Formar \n2. Extraer \n3. Consultar \n4. Salir"
            << std::endl;
  std::cout << "Ingrese la opción deseada \n> ";
  std::cin >> opc;

  return static_cast<Option>(opc);
}

void menu() {
  Option opc;
  std::string turno;
  char caja;
  std::queue<std::string> cola_A;
  std::queue<std::string> cola_B;
  std::queue<std::string> cola_C;
  int contador = 1;
  std::queue<std::string> cola;
  while ((opc = get_option()) != Option::Salir) {
    switch (opc) {
    case Option::Formar:
      if (cola_A.size() <= cola_B.size() && cola_A.size() <= cola_C.size()) {
        cola_A.push("A" + std::to_string(contador));
        contador++;
        break;
      } else if (cola_B.size() <= cola_A.size() &&
                 cola_B.size() < cola_C.size()) {
        cola_B.push("B" + std::to_string(contador));
        contador++;
        break;
      } else {
        cola_C.push("C" + std::to_string(contador));
        contador++;
        break;
      }
      break;

    case Option::Extraer:
      std::cout << "Ingrese la cola que desea atender: A/B/C \n> ";
      std::cin >> caja;
      if (caja == 'A' || caja == 'a') {
        if (cola_A.empty()) {
          std::cout << "La cola está vacía" << std::endl;
        } else {
          std::cout << "El cliente: " << cola_A.front() << " se ha ido"
                    << std::endl;
          cola_A.pop();
        }
      }
      if (caja == 'B' || caja == 'b') {

        if (cola_B.empty()) {
          std::cout << "La cola está vacía" << std::endl;
        } else {
          std::cout << "El cliente: " << cola_B.front() << " se ha ido"
                    << std::endl;
          cola_B.pop();
        }
      }
      if (caja == 'C' || caja == 'c') {

        if (cola_C.empty()) {
          std::cout << "La cola está vacía" << std::endl;
        } else {
          std::cout << "El cliente: " << cola_C.front() << " se ha ido"
                    << std::endl;
          cola_C.pop();
        }
      } else {
        std::cout << "No se ha encontrado una opción válida" << std::endl;
      }

      break;

    case Option::Mostrar:
      std::cout << "Cola A:" << std::endl;
      if (cola_A.empty()) {
        std::cout << "\t-La cola está vacía-" << std::endl;
      } else {
        std::cout << "\tInicio: " << cola_A.front() << std::endl;
        std::cout << "\tFinal: " << cola_A.back() << std::endl;
      }
      std::cout << "Cola B:" << std::endl;
      if (cola_B.empty()) {
        std::cout << "\t-La cola está vacía-" << std::endl;
      } else {
        std::cout << "\tInicio: " << cola_B.front() << std::endl;
        std::cout << "\tFinal: " << cola_B.back() << std::endl;
      }
      std::cout << "Cola C:" << std::endl;
      if (cola_C.empty()) {
        std::cout << "\t-La cola está vacía-" << std::endl;
      } else {
        std::cout << "\tInicio: " << cola_C.front() << std::endl;
        std::cout << "\tFinal: " << cola_C.back() << std::endl;
      }
      break;
    }
  }
}
