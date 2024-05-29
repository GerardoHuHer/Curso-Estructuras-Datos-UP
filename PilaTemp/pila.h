#ifndef PILA_H
#define PILA_H
#include <iostream>

template<typename  T> class Pila{
public:
  struct Node{
    T data;
    Node* anterior;
  };

  Pila(): tope(NULL){}
  T extraer(){
    Node* aux;
    T extraido;
    if(tope == NULL){
      return NULL;
    }
    aux = tope;
    extraido = tope->data;
    delete aux;
    return extraido;
  }

  void insert(const T& inserta){
    nodo = new Node; 
    nodo->data = inserta;
    nodo->anterior = tope;
    tope = nodo;
    return;
  }

private:
  Node* tope, *nodo;
};

void menu();
#endif
