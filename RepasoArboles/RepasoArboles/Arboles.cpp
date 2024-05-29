#include "Arboles.h"

Arbol::Arbol() : nodo(NULL), root(NULL) {}

Nodo *Arbol::get_node() { return root; }

void Arbol::crear_nodo(const int &value) {
  nodo = new Nodo;
  nodo->dato = value;
  nodo->left = NULL;
  nodo->right = NULL;
}

void Arbol::insertar(Nodo *inicio) {
  if (root == NULL) {
    root = nodo;
    return;
  }
  if (nodo->dato < inicio->dato) {
    if (inicio->left == NULL) {
      inicio->left = nodo;
      return;
    } else {
      insertar(inicio->left);
      return;
    }
  }
  if (nodo->dato > inicio->dato) {
    if (inicio->right == NULL) {
      inicio->right = nodo;
      return;
    } else {
      insertar(inicio->right);
      return;
    }
  }
  delete nodo;
  return;
}

bool Arbol::busqueda(const int &value, Nodo *inicio) {
  if (value < inicio->dato) {
    if (inicio->left == NULL) {
      return false;
    } else {
      return busqueda(value, inicio->left);
    }
  } else if (value > inicio->dato) {
    if (inicio->right == NULL) {
      return false;
    } else {
      return busqueda(value, inicio->right);
    }
  } else if (value == inicio->dato) {
    return true;
  } else {
    return false;
  }
}

void Arbol::in_order(Nodo *inicio) {
  if (inicio->left != NULL) {
    in_order(inicio->left);
  }
  std::cout << "\t" << inicio->dato;
  if (inicio->right != NULL) {
    in_order(inicio->right);
  }
}

void Arbol::post_order(Nodo *inicio) {
  if (inicio->left != NULL) {
    post_order(inicio->left);
  }
  if (inicio->right != NULL) {
    post_order(inicio->right);
  }
  std::cout << "\t" << inicio->dato;
}

void Arbol::pre_order(Nodo *inicio) {
  std::cout << "\t" << inicio->dato;
  if (inicio->left != NULL) {
    pre_order(inicio->left);
  }
  if (inicio->right != NULL) {
    pre_order(inicio->right);
  }
}

void menu() {
  Arbol tree = Arbol();
  Nodo *raiz;
  int opc;
  int aux;
  bool val;
  do {
    std::cout
        << "\n\n1. Insertar\n2. Buscar\n3. Imprimir In-Order\n4. Imprimir "
           "Pre-Order\n5. Imprimir Post-Order\n6. Salir"
        << std::endl;
    std::cout << "Ingrese la opción deseada \n> ";
    std::cin >> opc;
    raiz = tree.get_node();
    switch (opc) {
    case 1:
      std::cout << "Ingrese el número que desea ingresar en el árbol \n> ";
      std::cin >> aux;
      tree.crear_nodo(aux);
      raiz = tree.get_node();
      tree.insertar(raiz);
      break;
    case 2:
      if (raiz == NULL) {
        std::cout << "El árbol está vacío" << std::endl;
      } else {
        std::cout << "Ingrese el valor que desea buscar \n> ";
        std::cin >> aux;
        raiz = tree.get_node();
        val = tree.busqueda(aux, raiz);
        if (val) {
          std::cout << "Valor encontrado" << std::endl;
        } else {
          std::cout << "Valor no encontrado en el árbol" << std::endl;
        }
      }
      break;
    case 3:
      if (raiz == NULL) {
        std::cout << "El árbol está vacío" << std::endl;
      } else {
        tree.in_order(raiz);
      }
      break;
    case 4:
      if (raiz == NULL) {
        std::cout << "El árbol está vacío" << std::endl;
      } else {
        tree.pre_order(raiz);
      }
      break;
    case 5:
      if (raiz == NULL) {
        std::cout << "El árbol está vacío" << std::endl;
      } else {
        tree.post_order(raiz);
      }
      break;
    case 6:
      std::cout << "Hasta luego" << std::endl;
      break;
    default:
      std::cout << "No se ingresó un valor válido" << std::endl;
      break;
    }
  } while (opc != 6);
}
