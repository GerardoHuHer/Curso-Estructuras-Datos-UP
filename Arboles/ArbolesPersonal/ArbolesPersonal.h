#ifndef ARBOLESPERSONAL_H
#define ARBOLESPERSONAL_H
#include <iostream>

template <typename T> class Tree {
public:
  struct Nodo {
    T dato;
    Nodo *left, *right;
    Nodo(T value) : dato(value), left(nullptr), right(nullptr) {}
  };
  Tree() : root(NULL) {}
  void insert(T value){
    root = insert_recursive(root, value);
  }

  bool search(T value){
    return search_recurisive(root, value);
  }

  void in_order_traversal(){
    std::cout << "In-order traversal: ";
    in_order_recursive(root);
    std::cout << std::endl;
  }

private:
  Nodo *root;
  Nodo *nodo;

  Nodo *insert_recursive(Nodo *current, T value) {
    if (current == nullptr) {
      return new Nodo(value);
    }

    if (value < current->dato) {
      current->left = insert_recursive(current->left, value);
    } else {

      current->right = insert_recursive(current->right, value);
    }
    return current;
  }

  bool search_recurisive(Nodo *current, T value) {
    if (current == nullptr) {
      return false;
    }
    if (value == current->dato) {
      return true;
    } else if (value < current->dato) {
      return search_recurisive(current->left, value);
    } else {
      return search_recurisive(current->right, value);
    }
  }

  void in_order_recursive(Nodo *current) {
    if (current != nullptr) {
      in_order_recursive(current->left);
      std::cout << current->dato << " ";
      in_order_recursive(current->right);
    }
  }

};

void menu();

class Coche{
private:
  std::string placa;
  int ruedas;
  std::string color;
  std::string marca;
public:
  friend std::ostream& operator<<(std::ostream&, Coche&);
  friend std::istream& operator>>(std::istream&, Coche&);
  friend bool operator<(Coche&, Coche&);
  friend bool operator>(Coche&, Coche&);
};

#endif
