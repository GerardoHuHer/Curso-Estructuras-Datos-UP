#ifndef EXAMEN_H
#define EXAMEN_H
#include <iostream>
#include <string>

struct Producto {
  int codigo;
  std::string nombre;
  bool operator==(Producto &);
  bool operator!=(Producto &);
  bool operator>=(Producto &);
  bool operator<=(Producto &);
  bool operator<(Producto &);
  bool operator>(Producto &);
};

struct Nodo {
  Producto pro;
  int nivel;
  Nodo *izq, *der;
};

class Arbol {
public:
  Arbol();
  Nodo *get_root() const;
  void crear_nodo(const Producto &);
  void insertar(Nodo* root, int contador);
  Nodo* buscar(Producto, Nodo * pos);
  void pre_order(Nodo *);

private:
  Nodo *root, *nodo;
};

void menu();

#endif
