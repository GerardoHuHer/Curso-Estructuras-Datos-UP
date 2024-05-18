#include "binary_tree.h"

#include <iostream>

void menu() {
  Tree<int> tree = Tree<int>();
  int opc, ret, search;
  Tree<int>::Node* root = NULL;
  Tree<int>::Node* aux = NULL;

  do {
    std::cout << "\n0. Lectura Archivo \n1. Insertar \n2. In-Order \n3. Pre-Order \n4. Post-Order \n5. Mostrar \n6. Buscar \n7. Salir" << std::endl;
    std::cout << "Ingrese una opción válida: \n> ";
    std::cin >> opc;
    switch (opc) {
      root = tree.consultar_root();
      case 0:
        llenado_con_archivo(tree);
        break;
      case 1:
        std::cout << "Ingrese el número que desea insertar: \n> ";
        std::cin >> ret;
        tree.CrearNodo(ret);
        root = tree.consultar_root();
        tree.insertar(root);
        break;
      case 2:
        if(root == NULL){
          std::cout << "\t\nArbol vacío";
        } else {
          std::cout << "Recorrido In-Order" << std::endl;
          tree.in_order(root);
          std::cout << std::endl << std::endl;
        }
        break;
      case 3:
        if(root == NULL){
          std::cout << "\t\nArbol vacío";
        } else {
          std::cout << "Recorrido Pre-Order" << std::endl;
          tree.pre_order(root);
          std::cout << std::endl << std::endl;
        }
        break;
      case 4:
        if(root == NULL){
          std::cout << "\t\nArbol vacío";
        } else {
          std::cout << "Recorrido Post-Order" << std::endl;
          tree.post_order(root);
          std::cout << std::endl << std::endl;
        }
        break;

      case 5: 
        if(root == NULL){
          std::cout << "\t\nÁrbol vacío";
        } else {
          std::cout << std::endl << std::endl;
          tree.display(root,0 );
          std::cout << std::endl << std::endl;
        }
        break;
      case 6: 
        if(root == NULL){
          std::cout << "\t\nÁrbol vacío";
        } else {
          std::cout << "Ingrese el número que quiere buscar \n> ";
          std::cin >> search;
          aux = tree.busqueda_in_order(search,root);
          if(aux == NULL){
            std::cout << "No se encontró el valor " << search << " en el árbol" << std::endl;
          } else {
            tree.in_order(aux);
            std::cout << std::endl << std::endl;
          }
        }
        break;
      case 7:
        std::cout << "Hasta luego";
        break;
      default: 
        std::cout << "No se ingresó una opción válida" << std::endl;
        break;
    }
  } while (opc != 7);
}
