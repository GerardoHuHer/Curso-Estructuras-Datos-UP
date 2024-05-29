#ifndef ARBOL_H
#define ARBOL_H
#include "main.h"

enum Tree_option {
  Insertar = 1,
  Buscar,
  In_order,
  Pre_order,
  Post_order,
  Salir
};

Tree_option get_option();

template <typename T> class Arbol {
public:
  struct Nodo {
    T data;
    Nodo *der;
    Nodo *izq;
  };
  Arbol() : root(NULL), nodo(NULL) {}
  Nodo *get_root() { return root; }
  void crear_nodo(const T &value) {
    nodo = new Nodo;
    nodo->data = value;
    nodo->der = NULL;
    nodo->izq = NULL;
  }

  void insertar(const Nodo*& pos){
    if(root == NULL){
      root = nodo;
      return;
    }
    if(nodo->data < pos->data){
      if(pos->izq == NULL){
        pos->izq = nodo;
        return;
      }
      insertar(pos->izq);
      return;
    }
    if(nodo->data > pos->data){
      if(pos->der == NULL){
        pos->der = nodo;
        return;
      }
      insertar(pos->der);
      return;
    }
    delete nodo;
  }

  Nodo* buscar(const T& value, const Nodo*& pos){
    if(value == pos->data){
      return pos;
    }
    if(value < pos->dato){
      if(pos->izq == NULL){
        return NULL;
      } else{
        return buscar(value, pos->izq);
      }
    }
    if(value > pos->dato){
      if(pos->der == NULL){
        return NULL;
      } else{
        return buscar(value, pos->der);
      }
    }
    return NULL;
  }

  void in_order(const Nodo*& pos){
    if(pos->izq != NULL){
      in_order(pos->izq);
    }
    std::cout << "\t" << pos->data;
    if(pos->der != NULL){
      in_order(pos->der);
    }
  }
  void pre_order(const Nodo*& pos){
    std::cout << "\t" << pos->data;
    if(pos->izq != NULL){
      pre_order(pos->izq);
    }
    if(pos->der != NULL){
      pre_order(pos->der);
    }
  }
  void post_order(const Nodo*& pos){
    if(pos->izq != NULL){
      post_order(pos->izq);
    }
    if(pos->der != NULL){
      post_order(pos->der);
    }
    std::cout << "\t" << pos->data;
  }

private:
  Nodo *root, *nodo;
};

template <typename T> void menuArbol(){
  Tree_option opc;
  Arbol<T> tree = Arbol<T>();
  typename Arbol<T>::Nodo* root, *naux;
  T aux;
  while((opc = get_option()) != Salir){
    root = tree.get_root();

  } 
}
#endif
