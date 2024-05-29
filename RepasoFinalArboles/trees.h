#ifndef TREES_H
#define TREES_H
#include <iostream>

class Arbol {

public:
  struct Nodo {
    int dato;
    Nodo *izq, *der;
  };
  Arbol();
  Nodo *get_root();
  void crear_nodo(const int &);
  void insertar(Nodo *);
  Nodo *busqueda_in_order(const int &, Nodo *);
  void in_order(Nodo *);
  void pre_order(Nodo *);
  void post_order(Nodo *);

private:
  Nodo *nodo, *raiz;
};

void menu();

#endif
