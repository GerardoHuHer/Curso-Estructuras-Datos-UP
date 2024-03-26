#pragma once
#include <iostream>

struct Nodo {
  int entero;
  Nodo *sig;
};

class Cola {
private:
  Nodo* inicio, *final;
  Nodo* nodo;
public:
  Cola();
  void insertar(int);
  int extraer();
  void mostrar();
};

void menu();
