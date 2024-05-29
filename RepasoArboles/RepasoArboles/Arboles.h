#ifndef ARBOLES_H
#define ARBOLES_H
#include <iostream>

struct Nodo{
  int dato;
  Nodo* left;
  Nodo* right;
};


class Arbol {
private:
  Nodo *root, *nodo;
public:
  Arbol();
  Nodo* get_node();
  void crear_nodo(const int&);
  void insertar(Nodo* inicio);
  bool busqueda(const int&, Nodo* inicio);
  void in_order(Nodo* inicio);
  void pre_order(Nodo* inicio);
  void post_order(Nodo* inicio);
};

void menu();

#endif
