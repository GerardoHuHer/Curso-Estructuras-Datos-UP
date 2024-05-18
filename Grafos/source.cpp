#include "Grafos.h"
int main() {
  setlocale(LC_ALL, "");
  int peso, opc, codigo, tam;
  char nuevo, ori, des;
  std::cout << "Número max de nodos: ";
  std::cin >> tam;
  MatrizAdy grafo(tam);
  do {
    std::cout << "=============== MENU PRINCIPAL ===============" << std::endl;
    std::cout << "\n1) Insertar Nodo \n2) Insertar Arco\n3) Mostrar \n4) Salir"
              << std::endl;
    std::cin >> opc;
    switch (opc) {
    case 1:
      std::cout << "Nodo: ";
      std::cin >> nuevo;
      codigo = grafo.insertar_nodo(nuevo);
      if (codigo == -1) {
        std::cout << "Error arreglo lleno, no se insertó el nodo" << std::endl;
      } else if (codigo == -2) {
        std::cout << "Error ya existe el nodo, no se insertó el nodo"
                  << std::endl;
      } else {
        std::cout << "\tOk. se insertó el nodo" << std::endl;
      }
      break;
    case 2:
      std::cout << "\tNodo origen (una letra): ";
      std::cin >> ori;
      std::cout << "\tNodo destino (una letra): ";
      std::cin >> des;
      std::cout << "\tPeso: ";
      std::cin >> peso;
      codigo = grafo.insertar_ady(ori, des, peso);
      if(codigo == -1){
        std::cout << "Error, arreglo vacío" << std::endl;
      } else if(codigo == -2){        
        std::cout << "Error, no existe alguno de los nodos, no se inserto" << std::endl;
      } else if(codigo == -3){
        
        std::cout << "Ya existe la adyacencia, se modifico el peso" << std::endl;
      } else{
        std::cout << "Ok. Se insertó el arco" << std::endl;
      }

      break;

    case 3:
      grafo.mostrar();
      break;
    case 4:
      std::cout << "\n\n\t\t Hasta luego";
      break;
    default:
      break;
    }
  } while (opc != 4);
  return 0;
}
