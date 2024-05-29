#ifndef REPASOARBOLES_H
#define REPASOARBOLES_H
#include <iostream>

enum class Option {
  INSERTAR = 1,
  IN_ORDER,
  PRE_ORDER,
  POST_ORDER,
  DISPLAY,
  SEARCH,
  EXIT
};

Option get_option();

template <typename T> class Binary_tree {
public:
  struct Nodo {
    T data;
    Nodo *left;
    Nodo *right;
  };

  Binary_tree<T>() : root(NULL), nodo(NULL) {}

  void create_node(const T &value) {
    nodo = new Nodo;
    nodo->data = value;
    nodo->left = NULL;
    nodo->right = NULL;
  }

  void insert(Nodo *start) {
    if (root == NULL) {
      root = nodo;
      return;
    }
    if (nodo->data < start->data) {
      if (start->left == NULL) {
        start->left = nodo;
        return;
      } else {
        insert(start->left);
        return;
      }
    }
    if (nodo->data > start->data) {
      if (start->right == NULL) {
        start->right = nodo;
        return;
      }
    } else {
      insert(start->right);
      return;
    }
    delete nodo;
    return;
  }

  Nodo *get_root() { return root; }

  void in_order(Nodo *start) {
    if (start->left != NULL) {
      in_order(start->left);
    }
    std::cout << "\t" << start->data;
    if (start->right != NULL) {
      in_order(start->right);
    }
  }

  void pre_order(Nodo *start) {
    std::cout << "\t" << start->data;
    if (start->left != NULL) {
      in_order(start->left);
    }
    if (start->right != NULL) {
      in_order(start->right);
    }
  }

  void post_order(Nodo *start) {
    if (start->left != NULL) {
      in_order(start->left);
    }
    if (start->right != NULL) {
      in_order(start->right);
    }
    std::cout << "\t" << start->data;
  }

  void display(Nodo *start, int contador) {
    if (start == NULL) {
      return;
    }
    display(start->right, contador + 1);
    for (int i = 0; i < contador; i++) {
      std::cout << "\t";
    }
    std::cout << start->data << std::endl;
    display(start->left, contador + 1);
  }

  Nodo *search_in_order(const T &search, Nodo *start) {
    if (search < start->data) {
      return search_in_order(search, start->left);
    } else if (search > start->data) {
      return search_in_order(search, start->right);
    } else if (search == start->data) {
      return start;
    } else {
      return NULL;
    }
  }

private:
  Nodo *root, *nodo;
};

template <typename T> void menu() {
  Binary_tree<T> tree = Binary_tree<T>();
  Option opc;
  T search, ret;
  typename Binary_tree<T>::Nodo *root = NULL;
  typename Binary_tree<T>::Nodo *aux = NULL;
  while ((opc = get_option()) != Option::EXIT) {
    switch (opc) {
      root = tree.get_root();
    case Option::INSERTAR:
      std::cout << "Ingrese el valor que desea insertar: \n> ";
      std::cin>> ret;
      tree.create_node(ret);
      root = tree.get_root();
      tree.insert(root);
      break;
    case Option::DISPLAY:
      if(root == NULL){
        std::cout << "Árbol vació" << std::endl;
      } else{
        tree.display(root, 0 );
      }
      break;
    case Option::IN_ORDER:
      if(root == NULL){
        std::cout << "Árbol vació" << std::endl;
      } else{
        std::cout << "In-Order" << std::endl;
        tree.in_order(root);
        std::cout << std::endl << std::endl;

      }
      break;
    case Option::POST_ORDER:
      if(root == NULL){
        std::cout << "Árbol vació" << std::endl;
      } else{
        std::cout << "Post-Order" << std::endl;
        tree.post_order(root);
        std::cout << std::endl << std::endl;

      }
      break;
    case Option::PRE_ORDER:
      if(root == NULL){
        std::cout << "Árbol vació" << std::endl;
      } else{
        std::cout << "Pre-Order" << std::endl;
        tree.pre_order(root);
        std::cout << std::endl << std::endl;

      }
      break;
    case Option::SEARCH:
      if(root == NULL){
        std::cout << "Árbol vació" << std::endl;
      } else{
        std::cout << "Ingrese el valor que desea buscar: \n> ";
        std::cin >> search;
        aux = tree.search_in_order(search, root );
        if(aux == NULL){
          std::cout << "No se encontro el valor: \n" << "\t" << search << std::endl; 
        } else{
          tree.in_order(aux);
          std::cout<<std::endl<<std::endl;
        }

      }
      break;
    case Option::EXIT:
      std::cout << "Hasta luego";
      break;

    default:
      std::cout << "Ingrese una opción válida" << std::endl;
      break;
    }
  }
}

#endif
