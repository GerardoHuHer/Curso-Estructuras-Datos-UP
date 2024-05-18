#ifndef LIBRARIES_H
#define LIBRARIES_H
#include <iostream>
#include <ostream>
#include <stack> // Métodos push, pop, size, top
#include <queue> // Métodos push, pop, empty, front, back 
#include <list> // push_front, push_back, pop_front, pop_back, front, back, empty, size, begin, end

enum class Option{
  Insertar = 1,
  Extraer,
  Consultar,
  Tamano,
  Salir,
};

class Persona{
private:
  int id;
  std::string name;
public:
  Persona(int, std::string);
  friend std::ostream operator<<(std::ostream& os, Persona& per);
};

Option get_option();
void menu();

#endif
