#ifndef EXAMENFINAL_H
#define EXAMENFINAL_H
#include <iostream>

enum Option{
  Insertar = 1,
  Buscar, 
  In_order,
  Pre_order,
  Post_order,
  Salir
};

Option get_option();

struct Nodo;

template <typename T> class Arbol {
public:
  struct Nodo {
    T dato;
    Nodo *der, *izq;
  };
  Arbol() : nodo(NULL), root(NULL) {}
  Nodo *get_root() { return root; }
  void crear_nodo(const T &value) {
    nodo = new Nodo;
    nodo->dato = value;
    nodo->der = NULL;
    nodo->izq = NULL;
  }

  void insertar(const Nodo *&pos) {
    if (root == NULL) {
      root = nodo;
      return;
    }
    if (nodo->dato < pos->dato) {
      if (pos->izq == NULL) {
        pos->izq = nodo;
        return;
      }
      insertar(pos->izq);
      return;
    }
    if (nodo->dato > pos->dato) {
      if (pos->der == NULL) {
        pos->der = nodo;
        return;
      }
      insertar(pos->der);
      return;
    }
    delete nodo;
  }

  Nodo *busqueda(const T &value, const Nodo *&pos) {
    if (value == pos->dato) {
      return pos;
    }
    if (value < pos->dato) {
      if (pos->izq == NULL) {
        return NULL;
      }
      return busqueda(value, pos->izq);
    }
    if (value > pos->dato) {
      if (pos->der == NULL) {
        return NULL;
      }
      return busqueda(value, pos->der);
    }
    return NULL;
  }

  void in_order(const Nodo *&pos) {
    if (pos->izq != NULL) {
      in_order(pos->izq);
    }
    std::cout << "\t" << pos->dato;
    if (pos->der != NULL) {
      in_order(pos->der);
    }
  }

  void pre_order(const Nodo *&pos) {
    std::cout << "\t" << pos->dato;
    if (pos->izq != NULL) {
      pre_order(pos->izq);
    }
    if (pos->der != NULL) {
      pre_order(pos->der);
    }
  }

  void post_order(const Nodo *&pos) {
    if (pos->izq != NULL) {
      post_order(pos->izq);
    }
    if (pos->der != NULL) {
      post_order(pos->der);
    }
    std::cout << "\t" << pos->dato;
  }

private:
  Nodo *nodo, *root;
};

template<typename T> 
void menu(){
  Arbol<T> tree = Arbol<T>();
  Option opc;
  T aux;
  Nodo *naux, *root; 
  while ((opc = get_option()) != Salir){
  root = tree.get_root();
    switch (opc) {
      case Insertar:
        std::cout << "Ingrese el dato que desea ingresar a su árbol \n> ";
        std::cin >> aux;
        tree.crear_nodo(aux);
        tree.insertar(root);
        break;
      case Buscar:
        if(root == NULL){
          std::cout << "El árbol está vacío" << std::endl;
        } else {
          std::cout << "Ingresa el valor que deseas buscar \n> ";
          std::cin >> aux;
          naux = tree.busqueda(aux,root);
          if(naux == NULL){
            std::cout << "El valor buscado no se encontró" << std::endl;
          }else{
            std::cout << "El valor buscado se encontró" << std::endl;
            tree.in_order(naux);
          }
        }
        break;
        case In_order:
          tree.in_order(root);
          break;
        case Pre_order:
          tree.pre_order(root);
          break;
        case Post_order:
          tree.post_order(root);
          break;
        case Salir:
          std::cout << "Hasta luego" << std::endl;
          break;
        default:
          std::cout << "No se ingresó una opción válida" << std::endl;
          break;
    }
  }
}

#endif
