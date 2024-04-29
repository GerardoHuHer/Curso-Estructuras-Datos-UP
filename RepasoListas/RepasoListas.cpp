#include "RepasoListas.h"

void menu_listaC() {
  Option opc;
  ListaCircular<int> lista = ListaCircular<int>();
  int aux, pos;
  std::string ret;
  while ((opc = enter_option()) != Option::Salir) {
    switch (opc) {
    case Option::Insertar_inicio:
      std::cout << "Ingrese el valor que desea ingresar: \n> ";
      std::cin >> aux;
      lista.insertar_inicio(aux);
      break;
    case Option::Insertar_intermedio:
      std::cout << "Ingrese el valor que desea ingresar: \n> ";
      std::cin >> aux;
      lista.display_inicio();
      std::cout << "Ingrese la posición donde lo desea ingresar: \n> ";
      std::cin >> pos;
      lista.insertar_intermedio(aux, pos);
      break;
    case Option::Insertar_final:
      std::cout << "Ingrese el valor que desea ingresar: \n> ";
      std::cin >> aux;
      lista.insertar_final(aux);
      break;
    case Option::Extraer_inicio:
      ret =
          lista.extraer_inicio() ? "Se extrajo correctamente" : "No se extrajo";
      std::cout << ret << std::endl;
      break;
    case Option::Extraer_intermedio:
      lista.display_inicio();
      std::cout << "Ingrese la posición donde lo desea extraer: \n> ";
      std::cin >> pos;
      lista.extraer_intermedio(pos);
      break;
    case Option::Extraer_final:
      ret =
          lista.extraer_final() ? "Se extrajo correctamente" : "No se extrajo";
      std::cout << ret << std::endl;
      break;
    case Option::Mostrar_inicio:
      lista.display_inicio();
      break;
    case Option::Mostrar_check:
      lista.display_check();
      break;
    case Option::Busqueda:
      std::cout << "Ingrese el valor que desea buscar \n> ";
      std::cin >> pos;
      ret = lista.busqueda(pos) ? "El valor buscado se encuentra en la lista"
                                : "El valor buscado no está dentro de la lista";
      std::cout << ret << std::endl;
      break;
    default:
      std::cout << "No se ha ingresado un valor válido" << std::endl;
      break;
    }
  }
}

template<typename T>
void menu_lista() {
  Option_menu opc;
  Lista_option ret;
  T valor;
  T pos;
  Lista<T> lista = Lista<T>();
  while ((opc = menu_enter_option()) != Option_menu::Exit) {
    switch (opc) {

    case Option_menu::Insertar_Inicio:
      std::cout << "Ingrese el valor que desea ingresar \n> ";
      std::cin >> valor;
      lista.insertar_inicio(valor);
      break;
    case Option_menu::Insertar_Intermedio:
      std::cout << "Ingrese el valor que desea ingresar \n> ";
      std::cin >> valor;
      lista.display();
      std::cout << "Ingrese la posición donde desea ingresar \n> ";
      std::cin >> pos;
      lista.insertar_intermedio(valor, pos);
      break;
    case Option_menu::Insertar_Final:
      std::cout << "Ingrese el valor que desea ingresar \n> ";
      std::cin >> valor;
      lista.insertar_final(valor);
      break;
    case Option_menu::Extraer_Inicio:
      ret = lista.extraer_inicio();
      if (ret == Lista_option::Empty) {
        std::cout << "La lista está vacía" << std::endl;
      }
      if (ret == Lista_option::Found) {
        std::cout << "Se extrajo el valor correctamente" << std::endl;
      }
      break;
    case Option_menu::Extraer_Intermedio:
      lista.display();
      std::cout << "Ingrese el valor que desea extraer \n> ";
      std::cin >> valor;
      ret = lista.extraer_intermedio(valor);
      if (ret == Lista_option::Empty) {
        std::cout << "La lista está vacía" << std::endl;
      }
      if (ret == Lista_option::Not_found) {
        std::cout << "No se encontró el valor que desea extraer" << std::endl;
      }
      if (ret == Lista_option::Found) {
        std::cout << "Se extrajo el valor correctamente" << std::endl;
      }
      break;
    case Option_menu::Extraer_Final:
      ret = lista.extraer_final();
      if (ret == Lista_option::Empty) {
        std::cout << "La lista está vacía" << std::endl;
      }
      if (ret == Lista_option::Found) {
        std::cout << "Se extrajo el valor correctamente" << std::endl;
      }
      break;
    case Option_menu::Buscar:
      ret = lista.busqueda(valor);
      if (ret == Lista_option::Empty) {
        std::cout << "La lista está vacía";
      } else {
        std::cout << "Ingrese el valor que desea buscar \n> ";
        std::cin >> valor;
        if (ret == Lista_option::Not_found) {
          std::cout << "No se encontró el valor" << std::endl;
        }
        if (ret == Lista_option::Found) {
          std::cout << "El valor está dentro de la lista" << std::endl;
        }
      }
      break;
    case Option_menu::Mostrar:
      lista.display();
      break;
    default:
      std::cout << "No se ingresó un valor válido" << std::endl;
      break;
    }
  }
}

void run() {
  Menu_prin opc;
  while ((opc = enter_option_princ()) != Menu_prin::Terminar) {
    switch (opc) {
    case Menu_prin::Normales:
      menu_lista<int>();
      break;
    case Menu_prin::Circulares:
      menu_listaC();
      break;
    default:
      std::cout << "No se ingresó una opción válida" << std::endl;
      break;
    }
  }
}

Option enter_option() {
  int opc;
  std::cout
      << "\n1. Insertar inicio \n2. Insertar intermedio \n3. Insertar_final "
         "\n4. Extraer_inicio \n5. Extraer_intermedio \n6. Extraer_final\n7. "
         "Mostrar_inicio \n8. Mostrar_check\n9. Busqueda\n10. Salir"
      << std::endl;
  std::cout << "Ingrese la opción deseada: \n> ";
  std::cin >> opc;
  return static_cast<Option>(opc);
}

Option_menu menu_enter_option() {
  int opc;
  std::cout << "\n1. Insertar inicio \n2. Insertar intermedio \n3. Insertar "
               "final \n4. Extraer inicio \n5. Extraer intermedio \n6. Extraer "
               "final \n7. Buscar \n8. Mostrar \n9. Salir"
            << std::endl;
  std::cout << "Ingrese la opción desesada \n> ";
  std::cin >> opc;
  return static_cast<Option_menu>(opc);
}

Menu_prin enter_option_princ() {
  int opc;
  std::cout << "\n1. Listas Normales \n2. Listas circulares \n3. Salir"
            << std::endl;
  std::cout << "Ingrese la opción deseada: \n> ";
  std::cin >> opc;
  return static_cast<Menu_prin>(opc);
}
