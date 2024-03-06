#pragma once
#include <iostream>
#include <string>

struct Estudiante{
  int ID;
  std::string nombre;
  int edad;
  Estudiante *anterior;
};

class Pila{
public:
  Pila();
  Estudiante extraer();
  int insertar(Estudiante);
  void mostrar();

private:
  Estudiante* nodo, *tope;  
};

void depurar(Pila, Pila);
void menu();

