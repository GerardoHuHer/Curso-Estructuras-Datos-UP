#include "ejercicio11.h"
#include <csetjmp>
#include <string>

Caja::Caja(std::string name)
    : name(name), inicio(NULL), final(NULL), nodo(NULL) {}

bool Caja::isEmpty(){
  return inicio != NULL; 
}

void Caja::insertar(std::string nuevo) {
  nodo = new Nodo;
  nodo->turno = nuevo;
  nodo->sig = NULL;
  if (inicio == NULL) {
    inicio = nodo;
  }
  if (final != NULL) {
    final->sig = nodo;
  }
  final = nodo;
}

std::string Caja::extraer() {
  if (inicio == NULL) {
    return " ";
  }
  std::string aux;
  nodo = inicio;
  aux = nodo->turno;
  inicio = nodo->sig;
  if (inicio == NULL) {
    final = NULL;
  }
  delete nodo;
  return aux;
}

std::ostream &operator<<(std::ostream &os, const Caja &a) {
  Nodo *nodo = a.inicio;
  if(a.inicio == NULL){
    os << "\t\nCaja Vacía" << std::endl;
  }
  std::cout << "\t ========== Caja: " << a.name << " ==========" << std::endl;
  while (nodo != NULL) {
    os << "\t" << nodo->turno;
    if (nodo == a.inicio)
      std::cout << " <= Inicio";
    if (nodo == a.final)
      std::cout << " <= Final";
    std::cout << std::endl;
    nodo = nodo->sig;
  }
  return os;
}

void menu() {
  int opc;
  std::string ret;
  bool bloqueo = false;
  int cont{1};
  int contd{1};
  Caja C20("C20"), C25("C25"), D10("D10");
  do {
    std::cout
        << "\n1) Insertar \n2) Extraer \n3) Mostrar \n4) Bloquear \n5) Salir"
        << std::endl;
    std::cout << "Ingrese una opción: \n? ";
    std::cin >> opc;
    switch (opc) {
    case 1:
      if (!bloqueo) {
        std::string counts = std::to_string(cont);
        if (cont < 10) {
          C20.insertar("CC-0" + counts);
          C25.insertar("RR-0" + counts);
        } else {
          C20.insertar("CC-" + counts);
          C25.insertar("RR-" + counts);
        }
        cont++;
      } else {
        std::string countds = std::to_string(contd);
        D10.insertar("DD-" + countds);
        contd++;
      }
      break;
    case 2:
      if (!bloqueo) {
        std::cout
            << "Ingrese la fila de la que desea extraer: \t\n1: C20 \t2: C25"
            << std::endl;
        std::cin >> opc;
        switch (opc) {
        case 1:
          ret = C20.extraer();
          if (ret == " ")
            std::cout << "\t\nLa fila C20 ya estaba vacía" << std::endl;
          else
            std::cout << "\t\nSe ha extraído el turno :" << ret << std::endl;
          break;
        case 2:
          ret = C25.extraer();
          if (ret == " ")
            std::cout << "\t\nLa fila C25 ya estaba vacía" << std::endl;
          else
            std::cout << "\t\nSe ha extraído el turno :" << ret << std::endl;
          break;
        default:
          std::cout << "No se ingresó una opción válida" << std::endl;
          break;
        }
      } else {
        ret = D10.extraer();
        if (ret == " ")
          std::cout << "\t\nLa fila D20 ya estaba vacía" << std::endl;
        else
          std::cout << "\t\nSe ha extraído el turno :" << ret << std::endl;
      }
      break;
    case 3:
      std::cout << "FILA CC-20" << std::endl;
      std::cout << "\t"<< C20 << std::endl;
      std::cout << std::endl;
      std::cout << "FILA CC-25" << std::endl;
      std::cout << "\t"<< C25 << std::endl;
      std::cout << std::endl;
      std::cout << "FILA DD-10" << std::endl;
      std::cout << "\t"<< D10 << std::endl;
      std::cout << std::endl;
      break;
    case 4:
      std::cout << "Se han bloqueado las cajas C25 y C20" << std::endl;
      bloqueo = true;
      do{
        ret = C20.extraer();
        if(ret != " "){
          D10.insertar(ret);
        }
        ret = C25.extraer();
        if(ret != " "){
          D10.insertar(ret);
        }
      }while(C20.isEmpty() || C25.isEmpty());
      std::cout << "Se están movimiendo los clientes a la fila D10" << std::endl;
      break;
    case 5:
      std::cout << "Hasta luego" << std::endl;
      break;
    default:
      std::cout << "Ingrese una opción válida" << std::endl;
      break;
    }
  } while (opc != 5);
}
