#ifndef EJERCICIO11_H
#define EJERCICIO11_H
#include <iostream>

struct Nodo {
  std::string turno;
  Nodo* sig;
};

class Caja {
private:
  Nodo *inicio, *final, *nodo;
  std::string name;
public:
  Caja(std::string);
  void insertar(std::string);
  std::string extraer();
  bool isEmpty();
  friend std::ostream& operator<<(std::ostream& os, const Caja& a);
};

void menu();

#endif
