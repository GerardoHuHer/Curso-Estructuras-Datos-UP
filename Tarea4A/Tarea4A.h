#pragma once
#include <iostream>

struct Entero{
  int dato;
  Entero* anterior;
};

class Pila{
public:
  Pila();
  int Extraer();
  void Insertar(int);
  void Mostrar();
  friend void depurar(Pila, Pila);
private:
  Entero* tope;
  Entero* nodo;
};

void menu();
