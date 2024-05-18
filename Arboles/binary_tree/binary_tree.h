#ifndef BINARY_TREE_H
#define BINARY_TREE_H
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

template <typename T> class Tree {
public:
  // Struct that defines each node
  struct Node {
    T data;
    Node *left;
    Node *right;
  };
  // Constructor
  Tree() : root(NULL), nodo(NULL) {}

  void CrearNodo(const T &value) {
    nodo = new Node;
    nodo->data = value;
    nodo->left = NULL;
    nodo->right = NULL;
  }

  void insertar(Node *start) {

    if (root == NULL) { // Si el árbol está vacío, se inserta en la raíz
      root = nodo;
      return;
    }

    if (nodo->data < start->data) { // Valor es menor, se inserta a la izquierda
      if (start->left ==
          NULL) { // Si el espacio izquierdo es NULL, se inserta el nodo
        start->left = nodo;
        return;
      } else { // Si el izquierdo ya está ocupado, se vuelve a repetir el
               // procedimiento en ese nodo hasta que encuentre espacio
        insertar(start->left);
        return;
      }
    }

    if (nodo->data > start->data) { // Valor es mayor, se inserta a la derecha
      if (start->right ==
          NULL) { // Si el espacio derecho es NULL, se inserta el nodo
        start->right = nodo;
        return;
      } else {
        insertar(start->right);
        return;
      }
    }

    std::cout << "Ya existe " << nodo->data << " en el árbol. No se insertó"
              << std::endl;
    delete nodo;
    return;
  }

  Node *consultar_root() { return root; }

  void in_order(Node *inicio) {
    if (inicio->left != NULL)
      in_order(inicio->left);
    std::cout << "\t" << inicio->data;
    if (inicio->right != NULL)
      in_order(inicio->right);
  }

  void post_order(Node *inicio) {
    if (inicio->left != NULL)
      pre_order(inicio->left);
    if (inicio->right != NULL)
      pre_order(inicio->right);
    std::cout << "\t" << inicio->data;
  }

  void pre_order(Node *inicio) {

    std::cout << "\t" << inicio->data;
    if (inicio->left != NULL)
      pre_order(inicio->left);
    if (inicio->right != NULL)
      pre_order(inicio->right);
  }

  void display(Node *start, int contador) {
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

  Node *busqueda_in_order(T num, Node *inicio) {
    if (num < inicio->data) {
      return busqueda_in_order(num, inicio->left);
    } else if (num > inicio->data) {
      return busqueda_in_order(num, inicio->right);
    } else if (num == inicio->data) {
      return inicio;
    } else {
      return NULL;
    }
  }

private:
  Node *nodo;
  Node *root;
};

void menu();
template <typename T> void llenado_con_archivo(Tree<T> &tree) {
  Tree<int>::Node* node = NULL;
  std::string nombreArchivo = "insertar.txt";
  std::ifstream archivo(nombreArchivo);
  std::string linea;

  if (archivo.is_open()) {
    while (std::getline(archivo, linea)) {
      std::istringstream iss(linea);
      T valor;
      while (iss >> valor) {
        tree.CrearNodo(valor);
        node = tree.consultar_root();
        tree.insertar(node);
      }
    }
    archivo.close();
  } else {
    std::cerr << "No se pudo abrir el archivo: " << nombreArchivo << std::endl;
  }
}

#endif
